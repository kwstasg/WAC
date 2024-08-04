// Windows Audio Capture (WAC) by KwstasG (Kostas Giannakakis)
#pragma once
#define WIN32_LEAN_AND_MEAN

#include <mmdeviceapi.h>
#include <Audioclient.h>
#include "IAudioSink.h"
#include <atomic>
#include <wrl/client.h>

class AudioListener
{
public:
    AudioListener(int BitsPerSample, int FormatTag, int BlockAlign, int XSize);
    ~AudioListener();
    HRESULT RecordAudioStream(IAudioSink*, std::atomic<bool>&);

private:

    WAVEFORMATEX* m_pwfx = NULL;
    Microsoft::WRL::ComPtr<IAudioClient> m_pAudioClient;
    Microsoft::WRL::ComPtr<IAudioCaptureClient> m_pCaptureClient;
    Microsoft::WRL::ComPtr<IMMDeviceEnumerator> m_pEnumerator;
    Microsoft::WRL::ComPtr<IMMDevice> m_pDevice;

    UINT32 m_bufferFrameCount = 0;
    REFERENCE_TIME m_hnsActualDuration = 0;

    const int m_refTimesPerMS   = 1000;
    const int m_refTimesPerSec  = 1000;

    const CLSID m_CLSID_MMDeviceEnumerator  = __uuidof(MMDeviceEnumerator);
    const IID m_IID_IMMDeviceEnumerator     = __uuidof(IMMDeviceEnumerator);
    const IID m_IID_IAudioClient            = __uuidof(IAudioClient);
    const IID m_IID_IAudioCaptureClient     = __uuidof(IAudioCaptureClient);
};
