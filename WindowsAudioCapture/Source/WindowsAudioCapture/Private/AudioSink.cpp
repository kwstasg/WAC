// Windows Audio Capture (WAC) by KwstasG (Kostas Giannakakis)
#include "AudioSink.h"
#include "WindowsAudioCapture.h"
#include <cstring>

AudioSink::AudioSink(int bitDepth, int nChannels) 
    : m_bitDepth(bitDepth), m_nChannels(nChannels), m_chunkSize(0)
{
    Initialize();
}

AudioSink::~AudioSink()
{
    std::lock_guard<std::mutex> lock(m_mutex);
    while (!m_queue.empty())
    {
        delete[] m_queue.front().chunk;
        m_queue.pop();
    }
}

void AudioSink::Initialize()
{
    m_maxSampleVal = (1 << (m_bitDepth - 1)) - 1;
}

bool AudioSink::Dequeue(AudioChunk& Chunk)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    if (m_queue.empty())
        return false;

    Chunk = m_queue.front();
    m_queue.pop();
    return true;
}

bool AudioSink::EmptyQueue()
{
    std::lock_guard<std::mutex> lock(m_mutex);

    while (!m_queue.empty())
    {
        delete[] m_queue.front().chunk;
        m_queue.pop();
    }

    return true;
}

int AudioSink::CopyData(const BYTE* Data, const int NumFramesAvailable)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    if (Data == nullptr)
    {
        AudioChunk chunk;
        chunk.size = 0;
        chunk.chunk = nullptr;
        m_queue.push(chunk);
        return 0;
    }

    int chunkSize = NumFramesAvailable * m_nChannels;
    AudioChunk chunk;
    chunk.size = chunkSize;
    chunk.chunk = new int16[chunkSize];
    std::memcpy(chunk.chunk, Data, chunkSize * sizeof(int16));

    bool nonZero = false;

    for (int i = 0; i < chunkSize; ++i)
    {
        if (chunk.chunk[i] == -1 || chunk.chunk[i] == 1)
        {
            chunk.chunk[i] = 0;
        }
        if (chunk.chunk[i] != 0)
        {
            nonZero = true;
        }
    }

    if (nonZero)
    {
        m_queue.push(chunk);
    }
    else
    {
        delete[] chunk.chunk;
    }

    return 0;
}
