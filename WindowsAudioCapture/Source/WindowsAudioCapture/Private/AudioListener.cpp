// Windows Audio Capture (WAC) by KwstasG (Kostas Giannakakis)
#include "AudioListener.h"
#include "WindowsAudioCapture.h"
#include <stdexcept>

AudioListener::AudioListener(int BitsPerSample, int FormatTag, int BlockAlign, int XSize)
{
    // This might break if done more than once
    HRESULT hr = CoInitialize(nullptr);
    if (FAILED(hr))
    {
        throw std::runtime_error("Failed to initialize COM library");
    }

    REFERENCE_TIME hnsRequestedDuration = m_refTimesPerSec;

    hr = CoCreateInstance(m_CLSID_MMDeviceEnumerator, NULL, CLSCTX_ALL, m_IID_IMMDeviceEnumerator, (void**)&m_pEnumerator);
    if (FAILED(hr))
    {
        throw std::runtime_error("Failed to create instance of MMDeviceEnumerator");
    }

    hr = m_pEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &m_pDevice);
    if (FAILED(hr))
    {
        throw std::runtime_error("Failed to get default audio endpoint");
    }

    hr = m_pDevice->Activate(m_IID_IAudioClient, CLSCTX_ALL, NULL, (void**)&m_pAudioClient);
    if (FAILED(hr))
    {
        throw std::runtime_error("Failed to activate audio client");
    }

    hr = m_pAudioClient->GetMixFormat(&m_pwfx);
    if (FAILED(hr))
    {
        throw std::runtime_error("Failed to get mix format");
    }

    m_pwfx->wBitsPerSample = BitsPerSample;
    m_pwfx->nBlockAlign = BlockAlign;
    m_pwfx->wFormatTag = FormatTag;
    m_pwfx->cbSize = XSize;
    m_pwfx->nAvgBytesPerSec = m_pwfx->nSamplesPerSec * m_pwfx->nBlockAlign;

    hr = m_pAudioClient->Initialize(
        AUDCLNT_SHAREMODE_SHARED,
        AUDCLNT_STREAMFLAGS_LOOPBACK,
        hnsRequestedDuration,
        0,
        m_pwfx,
        NULL);
    if (FAILED(hr))
    {
        throw std::runtime_error("Failed to initialize audio client");
    }

    hr = m_pAudioClient->GetBufferSize(&m_bufferFrameCount);
    if (FAILED(hr))
    {
        throw std::runtime_error("Failed to get buffer size");
    }

    hr = m_pAudioClient->GetService(m_IID_IAudioCaptureClient, (void**)&m_pCaptureClient);
    if (FAILED(hr))
    {
        throw std::runtime_error("Failed to get audio capture client service");
    }

    m_hnsActualDuration = (double)m_refTimesPerSec * m_bufferFrameCount / m_pwfx->nSamplesPerSec;
}

AudioListener::~AudioListener()
{
    if (m_pAudioClient)
    {
        m_pAudioClient->Stop();
    }
    CoUninitialize();
}

HRESULT AudioListener::RecordAudioStream(IAudioSink* Sink, std::atomic<bool>& Done)
{
    HRESULT hr = m_pAudioClient->Start();  // Start recording.
    if (FAILED(hr))
    {
        return hr;
    }

    BYTE *pData = nullptr;
    DWORD flags = 0;
    UINT32 packetLength = 0;
    UINT32 numFramesAvailable = 0;

    while (!Done)
    {
        Sleep(static_cast<DWORD>(m_hnsActualDuration / m_refTimesPerMS / 2));

        hr = m_pCaptureClient->GetNextPacketSize(&packetLength);
        if (FAILED(hr))
        {
            return hr;
        }

        while (packetLength != 0)
        {
            hr = m_pCaptureClient->GetBuffer(&pData, &numFramesAvailable, &flags, NULL, NULL);
            if (FAILED(hr))
            {
                return hr;
            }

            hr = Sink->CopyData(pData, numFramesAvailable);
            if (FAILED(hr))
            {
                return hr;
            }

            hr = m_pCaptureClient->ReleaseBuffer(numFramesAvailable);
            if (FAILED(hr))
            {
                return hr;
            }

            hr = m_pCaptureClient->GetNextPacketSize(&packetLength);
            if (FAILED(hr))
            {
                return hr;
            }
        }
    }

    hr = m_pAudioClient->Stop();
    return hr;
}
