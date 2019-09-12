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
