//Windows Audio Capture (WAC) by KwstasG (Kostas Giannakakis)
#include "WindowsAudioCapture.h"
#include "AudioListener.h"

HRESULT ThrowOrExit(HRESULT hr)
{
	return hr;
}

AudioListener::AudioListener(int BitsPerSample, int FormatTag, int BlockAlign, int XSize)
{
	// This might break if done more than once
	CoInitialize(nullptr);

	HRESULT hr;
	REFERENCE_TIME hnsRequestedDuration = m_refTimesPerSec;

	hr = CoCreateInstance(m_CLSID_MMDeviceEnumerator, NULL,CLSCTX_ALL, m_IID_IMMDeviceEnumerator,(void**)&m_pEnumerator);

	if (hr)	throw hr;

	hr = m_pEnumerator->GetDefaultAudioEndpoint(
		//eCapture, eConsole, &pDevice); //set this to capture from default recording device instead of render device
		eRender, eConsole, &m_pDevice);
	if (hr)	throw hr;

	hr = m_pDevice->Activate(m_IID_IAudioClient, CLSCTX_ALL,NULL, (void**)&m_pAudioClient);
	if (hr)	throw hr;

	hr = m_pAudioClient->GetMixFormat(&m_pwfx);
	if (hr)	throw hr;

	m_pwfx->wBitsPerSample = BitsPerSample;
	m_pwfx->nBlockAlign = BlockAlign;
	m_pwfx->wFormatTag = FormatTag;
	m_pwfx->cbSize = XSize;
	m_pwfx->nAvgBytesPerSec = m_pwfx->nSamplesPerSec * m_pwfx->nBlockAlign;

	hr = m_pAudioClient->Initialize(
		//AUDCLNT_SHAREMODE_EXCLUSIVE,
		AUDCLNT_SHAREMODE_SHARED,
		//0, //set this instead of loopback to capture from default recording device
		AUDCLNT_STREAMFLAGS_LOOPBACK,
		hnsRequestedDuration,
		0,
		m_pwfx,
		NULL);
	if (hr)	throw hr;

	// Get the size of the allocated buffer.
	hr = m_pAudioClient->GetBufferSize(&m_bufferFrameCount);
	if (hr)	throw hr;

	hr = m_pAudioClient->GetService(m_IID_IAudioCaptureClient,(void**)&m_pCaptureClient);
	if (hr) throw hr;


	// Calculate the actual duration of the allocated buffer.
	m_hnsActualDuration = (double)m_refTimesPerSec *
	m_bufferFrameCount / m_pwfx->nSamplesPerSec;
}
AudioListener::~AudioListener()
{
}
HRESULT AudioListener::RecordAudioStream(IAudioSink* Sink, bool& Done)
{
	HRESULT hr;
	BYTE *pData;
	DWORD flags;
	UINT32 packetLength = 0;
	UINT32 numFramesAvailable;

	hr = m_pAudioClient->Start();  // Start recording.
	if (hr) throw hr;

	// Each loop fills about half of the shared buffer.
	while (!Done)
	{
		// Sleep for half the buffer duration.
		Sleep(m_hnsActualDuration / m_refTimesPerMS / 2);

		hr = m_pCaptureClient->GetNextPacketSize(&packetLength);
		if (hr)
			return ThrowOrExit(hr);

		while (packetLength != 0)
		{
			// Get the available data in the shared buffer.
			hr = m_pCaptureClient->GetBuffer(&pData,&numFramesAvailable,&flags, NULL, NULL);
			if (hr) throw hr;

			//if (flags & AUDCLNT_BUFFERFLAGS_SILENT)
			//{
			//	pData = NULL;  // Tell CopyData to write silence.
			//}

			// Copy the available capture data to the audio sink.
			hr = Sink->CopyData(pData, numFramesAvailable);
			if (hr) throw hr;

			hr = m_pCaptureClient->ReleaseBuffer(numFramesAvailable);
			if (hr) throw hr;

			hr = m_pCaptureClient->GetNextPacketSize(&packetLength);
			if (hr) throw hr;
		}
	}

	hr = m_pAudioClient->Stop();  // Stop recording.
	if (hr) throw hr;
	return hr;
}