#pragma once
#include <stdint.h>
#include <string>

enum class EventType
{
	InputEvent
};

union Value
{
public:
	Value() = default;

	Value(const char* p_Str);
	Value(char p_Char);
	Value(float p_Float);
	Value(double p_Double);
	Value(unsigned char p_UByte);
	Value(unsigned short p_UShort);
	Value(unsigned int p_UInt);
	Value(unsigned long p_ULong);
	Value(unsigned long long p_ULongLong);
	Value(signed char p_Byte);
	Value(short p_Short);
	Value(int p_Int);
	Value(long p_Long);
	Value(long long p_LongLong);


	char GetChar() const;
	float GetFloat() const;
	double GetDouble() const;
	unsigned char GetUByte() const;
	unsigned short GetUShort() const;
	unsigned int GetUInt() const;
	unsigned long GetULong() const;
	unsigned long long GetULongLong() const;
	signed char GetByte() const;
	short GetShort() const;
	int GetInt() const;
	long GetLong() const;
	long long GetLongLong() const;
	std::string GetString() const;

private:
	char Character;
	float Float;
	double Double;
	unsigned char UByte;
	unsigned short UShort;
	unsigned int UInt;
	unsigned long ULong;
	unsigned long long ULongLong;
	signed char Byte;
	short Short;
	int Int;
	long Long;
	long long LongLong;
	char* String;
};

class Event
{
public:
	Event(Value p_InputData, EventType p_EventType);

	Value GetInputData() const;

public:
	static Event CreateEvent(Value p_InputData, EventType p_EventType);

private:
	Value m_InputData;
	EventType m_EventType;

};


