#pragma once
#include "Event.h"
#include "ExceptionInterface.h"

#include <string>
#include <queue>

class EventSystem
{
public:
	EventSystem();

	// Preconditon:
	//  - Template arg [InputType] should be the type of data to grab from the FRONT of the Event Queue
	//  - The Event Queue should NOT be empty
	// 
	// Postcondition: returns the Input Event data as the template type [InputType] 
	template<typename InputType>
	InputType GetInput();

	// Preconditon: 
	//  - Must provied correct data type with template arg
	// 
	// Postcondition: Pushes an Event to the back of the Event Queue
	//
	// NOTE: PushEvent allocates memory for the data
	// but deallocation is handled by the EventData class
	//
	template<typename T>
	void PushEvent(T p_EventData, EventType p_EventType);

public:
	class E_EmptyEventQueue : ExceptionInterface
	{
	public:
		E_EmptyEventQueue() = default;
	
	private:
		std::string GetExceptionName() const override;
		std::string GetExceptionMessage() const override;
	};



private:
	template<typename T>
	T GetFrontData() const;

	void ReleaseFrontEvent();

private:
	std::queue<Event> m_EventQueue;
	bool m_UnhandledEvent;
};

template<typename InputType>
inline InputType EventSystem::GetInput()
{
	if (m_EventQueue.empty())
		throw E_EmptyEventQueue();

	InputType temp = this->GetFrontData<InputType>();
	this->ReleaseFrontEvent();
	return temp;
}

template<typename T>
inline void EventSystem::PushEvent(T p_EventData, EventType p_EventType)
{
	T* dataPtr = new T();
	*dataPtr = p_EventData;
	m_EventQueue.emplace(dataPtr, p_EventType);
	m_UnhandledEvent = true;
}

template<typename T>
inline T EventSystem::GetFrontData() const
{
	return m_EventQueue.front().GetInputData<T>();
}
