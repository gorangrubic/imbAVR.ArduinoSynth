#pragma once


#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

template<byte SIZE> 
class MonitoredArray
{

	void SetChanged(byte Position);

public:
	byte Data[SIZE * 8];

	byte State[SIZE];

	void SetValue(byte Position, byte Value);



	void SetValue(byte p1, byte v1, byte p2, byte v2);

	void SetValue(byte p1, byte v1, byte p2, byte v2, byte p3, byte v3);
	void SetValue(byte p1, byte v1, byte p2, byte v2, byte p3, byte v3, byte p4, byte v4);

	void SetValue(byte p1, byte v1, byte p2, byte v2, byte p3, byte v3, byte p4, byte v4, byte p5, byte v5);

	bool IsChanged(byte p1);
	bool IsChanged(byte p1, byte p2);
	bool IsChanged(byte p1, byte p2, byte p3);
	bool IsChanged(byte p1, byte p2, byte p3, byte p4);
	bool IsChanged(byte p1, byte p2, byte p3, byte p4, byte p5);

	void FlushChanges();

};

template<byte SIZE>
inline void MonitoredArray<SIZE>::FlushChanges()
{
	for (size_t i = 0; i < SIZE; i++)
	{
		State[i] = B00000000;
	}

}

template<byte SIZE>
inline void MonitoredArray<SIZE>::SetChanged(byte Position)
{
	byte bI = Position / 8;
	byte bP = Position % 8;

	bitWrite(State[bI], bP, 1);
}

template<byte SIZE>
inline void MonitoredArray<SIZE>::SetValue(byte Position, byte Value)
{
	bool change = (Data[Position] != Value);

	if (change) SetChanged(Position);

	Data[Position] = Value;
}

template<byte SIZE>
inline void MonitoredArray<SIZE>::SetValue(byte p1, byte v1, byte p2, byte v2)
{
	SetValue(p1, v1);
	SetValue(p2, v2);
}

template<byte SIZE>
inline void MonitoredArray<SIZE>::SetValue(byte p1, byte v1, byte p2, byte v2, byte p3, byte v3)
{
	SetValue(p1, v1);
	SetValue(p2, v2);
	SetValue(p3, v3);
}

template<byte SIZE>
inline void MonitoredArray<SIZE>::SetValue(byte p1, byte v1, byte p2, byte v2, byte p3, byte v3, byte p4, byte v4)
{
	SetValue(p1, v1);
	SetValue(p2, v2);
	SetValue(p3, v3);
	SetValue(p4, v4);
}

template<byte SIZE>
inline void MonitoredArray<SIZE>::SetValue(byte p1, byte v1, byte p2, byte v2, byte p3, byte v3, byte p4, byte v4, byte p5, byte v5)
{
	SetValue(p1, v1);
	SetValue(p2, v2);
	SetValue(p3, v3);
	SetValue(p4, v4);
	SetValue(p5, v5);
}

template<byte SIZE>
inline bool MonitoredArray<SIZE>::IsChanged(byte p1)
{
	byte bI = p1 / 8;
	byte bP = p1 % 8;

	return (bitRead(State[bI], bP) == 1);
}

template<byte SIZE>
inline bool MonitoredArray<SIZE>::IsChanged(byte p1, byte p2)
{
	return IsChanged(p1) || IsChanged(p2);
}

template<byte SIZE>
inline bool MonitoredArray<SIZE>::IsChanged(byte p1, byte p2, byte p3)
{
	return IsChanged( p1) || IsChanged( p2) || IsChanged( p3);
}

template<byte SIZE>
inline bool MonitoredArray<SIZE>::IsChanged(byte p1, byte p2, byte p3, byte p4)
{
	return IsChanged( p1) || IsChanged( p2) || IsChanged( p3) || IsChanged( p4);
}

template<byte SIZE>
inline bool MonitoredArray<SIZE>::IsChanged(byte p1, byte p2, byte p3, byte p4, byte p5)
{
	return IsChanged( p1) || IsChanged( p2) || IsChanged( p3) || IsChanged( p4) || IsChanged( p5);
}
