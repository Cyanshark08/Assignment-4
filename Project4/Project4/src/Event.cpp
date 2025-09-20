#include "Event.h"
#include <cstring>

Event::Event(Value p_InputData, EventType p_EventType)
	: m_InputData(p_InputData),
	m_EventType(p_EventType)
{}

Value Event::GetInputData() const
{
	return m_InputData;
}

Event Event::CreateEvent(Value p_InputData, EventType p_EventType)
{
	return { p_InputData, p_EventType };
}

Value::Value(const char* p_Str)
{
	strcpy_s(String, 100, p_Str);
}

Value::Value(char p_Char)
	: Character(p_Char)
{}

Value::Value(float p_Float)
	: Float(p_Float)
{}

Value::Value(double p_Double)
	: Double(p_Double)
{}

Value::Value(unsigned char p_UByte)
	: UByte(p_UByte)
{}

Value::Value(unsigned short p_UShort)
	: UShort(p_UShort)
{}

Value::Value(unsigned int p_UInt)
	: UInt(p_UInt)
{}

Value::Value(unsigned long p_ULong)
	: ULong(p_ULong)
{}

Value::Value(unsigned long long p_ULongLong)
	: ULongLong(p_ULongLong)
{}

Value::Value(signed char p_Byte)
	: Byte(p_Byte)
{}

Value::Value(short p_Short)
	: Short(p_Short)
{}

Value::Value(int p_Int)
	: Int(p_Int)
{}

Value::Value(long p_Long)
	: Long(p_Long)
{}

Value::Value(long long p_LongLong)
	: LongLong(p_LongLong)
{}

char Value::GetChar() const
{
	return Character;
}

float Value::GetFloat() const
{
	return Float;
}

double Value::GetDouble() const
{
	return Double;
}

unsigned char Value::GetUByte() const
{
	return UByte;
}

unsigned short Value::GetUShort() const
{
	return UShort;
}

unsigned int Value::GetUInt() const
{
	return UInt;
}

unsigned long Value::GetULong() const
{
	return ULong;
}

unsigned long long Value::GetULongLong() const
{
	return ULongLong;
}

signed char Value::GetByte() const
{
	return Byte;
}

short Value::GetShort() const
{
	return Short;
}

int Value::GetInt() const
{
	return Int;
}

long Value::GetLong() const
{
	return Long;
}

long long Value::GetLongLong() const
{
	return LongLong;
}

std::string Value::GetString() const
{
	return String;
}
