//Windows Audio Capture (WAC) by KwstasG (Kostas Giannakakis)
#include "WindowsAudioCapture.h"
#include "AudioSink.h"

AudioSink::AudioSink()
{
}

AudioSink::~AudioSink()
{
}

bool AudioSink::Dequeue(AudioChunk& Chunk)
{
	std::lock_guard<std::mutex> lock(m_mutex);

	if (m_queue.size() == 0)
		return false;

	Chunk = m_queue.front();
	m_queue.pop();
	return true;

}

bool AudioSink::EmptyQueue(AudioChunk& Chunk)
{
	//std::lock_guard<std::mutex> lock(m_mutex);

	while (m_queue.size() > 0)
	{
		Chunk = m_queue.front();
		m_queue.pop();
	}

	return true;

}

int AudioSink::CopyData(const BYTE* Data, const int NumFramesAvailable)
{
	std::lock_guard<std::mutex> lock(m_mutex);

	AudioChunk chunk;
	if (Data == NULL)
	{
		chunk.size = 0;
		m_queue.push(chunk);
		return 0;
	}
	chunk.size		= NumFramesAvailable * 2;
	chunk.chunk		= new int16[chunk.size];
	int multiplier	= sizeof(int16) / sizeof(unsigned char);
	std::memcpy(chunk.chunk, Data, chunk.size * multiplier);
	bool nonZero	= false;

	for (int i = 0; i < chunk.size; i++)
	{
		if (chunk.chunk[i] == -1 || chunk.chunk[i] == 1)
		{
			chunk.chunk[i] = 0;
		}
		if (chunk.chunk[i] != 0)
		{
			nonZero = true;
			//UE_LOG(LogTemp, Log, TEXT("NumFramesAvailable: %d, Sample number %d, Sample value %hi"), NumFramesAvailable, i, chunk.chunk[i]);
		}
	}

	if (nonZero)
	{
		m_queue.push(chunk);
	}

	return 0;
}
