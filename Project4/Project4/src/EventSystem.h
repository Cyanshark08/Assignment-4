#pragma once
#include "Event.h"
#include "ExceptionInterface.h"

#include <queue>

class EventSystem
{
public:
	EventSystem();

	template<typename T>
	T GetInput();

	void PushEvent(Event p_Event);

private:
	template<typename T>
	T GetFrontData() const;

	void ReleaseFrontEvent();

private:
	std::queue<Event> m_EventQueue;
	bool m_UnhandledEvent;

	template<>
	float GetFrontData() const;

	template<>
	double GetFrontData() const;

	template<>
	unsigned char GetFrontData() const;

	template<>
	unsigned short GetFrontData() const;

	template<>
	unsigned int GetFrontData() const;

	template<>
	unsigned long GetFrontData() const;

	template<>
	unsigned long long GetFrontData() const;

	template<>
	signed char GetFrontData() const;

	template<>
	short GetFrontData() const;

	template<>
	int GetFrontData() const;

	template<>
	long GetFrontData() const;

	template<>
	long long GetFrontData() const;

};

template<typename T>
inline T EventSystem::GetInput()
{
	T temp = this->GetFrontData<T>();
	this->ReleaseFrontEvent();
	return temp;
}

template<typename T>
inline T EventSystem::GetFrontData() const
{
	return m_EventQueue.front().GetInputData().GetChar();
}

template<>
inline float EventSystem::GetFrontData() const
{
	return m_EventQueue.front().GetInputData().GetFloat();
}

template<>
inline double EventSystem::GetFrontData() const
{
	return m_EventQueue.front().GetInputData().GetDouble();
}

template<>
inline unsigned char EventSystem::GetFrontData() const
{
	return m_EventQueue.front().GetInputData().GetUByte();
}

template<>
inline unsigned short EventSystem::GetFrontData() const
{
	return m_EventQueue.front().GetInputData().GetUShort();
}

template<>
inline unsigned int EventSystem::GetFrontData() const
{
	return m_EventQueue.front().GetInputData().GetUInt();
}

template<>
inline unsigned long EventSystem::GetFrontData() const
{
	return m_EventQueue.front().GetInputData().GetULong();
}

template<>
inline unsigned long long EventSystem::GetFrontData() const
{
	return m_EventQueue.front().GetInputData().GetULongLong();
}

template<>
inline signed char EventSystem::GetFrontData() const
{
	return m_EventQueue.front().GetInputData().GetByte();
}

template<>
inline short EventSystem::GetFrontData() const
{
	return m_EventQueue.front().GetInputData().GetShort();
}

template<>
inline int EventSystem::GetFrontData() const
{
	return m_EventQueue.front().GetInputData().GetInt();
}

template<>
inline long EventSystem::GetFrontData() const
{
	return m_EventQueue.front().GetInputData().GetLong();
}

template<>
inline long long EventSystem::GetFrontData() const
{
	return m_EventQueue.front().GetInputData().GetLongLong();
}

