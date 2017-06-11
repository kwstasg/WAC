//Windows Audio Capture (WAC) by KwstasG (Kostas Giannakakis)
#pragma once

typedef unsigned char BYTE;
class IAudioSink
{
public:
	virtual ~IAudioSink() {}
	virtual int CopyData(const BYTE* Data, const int NumFramesAvailable) = 0;
};