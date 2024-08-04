// Windows Audio Capture (WAC) by KwstasG (Kostas Giannakakis)
#pragma once

#include "IAudioSink.h"
#include <queue>
#include <mutex>

struct AudioChunk
{
    int16* chunk;
    int size;
};

class AudioSink : public IAudioSink
{
public:
    bool Dequeue(AudioChunk& Chunk);
    bool EmptyQueue();
    int CopyData(const BYTE* Data, const int NumFramesAvailable) override;
    AudioSink(int bitDepth = 16, int nChannels = 2);
    ~AudioSink();

private:
    std::queue<AudioChunk> m_queue;
    int m_bitDepth;
    int m_maxSampleVal;
    int m_nChannels;
    int m_chunkSize;
    std::mutex m_mutex;

    void Initialize();
};
