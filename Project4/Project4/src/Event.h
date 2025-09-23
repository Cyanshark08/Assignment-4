#pragma once
#include <stdint.h>
#include <string>
#include <memory>

enum class EventType
{
	InputEvent
};

class Event
{
public:
	class EventData
	{
	public:
		EventData() = default;
		EventData(void* p_Data);

		EventData(const EventData& p_Dap_EventDatata);
		

		/*
		* Precondition:
		*  - must not be empty (m_Data cannot be nullptr)
		*  - must provide correct type with template arg T
		* 
		* Postcondition: returns copy of data as type T
		*/
		template<typename T>
		T GetData() const;

		/*
		* Precondition:
		*  - Data must be allocated and casted to (void*)
		*
		* Postcondition: stores a pointer to data
		* 
		* NOTE: Data will be destroyed after the instance 
		* goes out of scope (deletes in destructor)
		*/
		void SetData(void* p_Data);

		~EventData();

	private:
		void* m_Data;
	};

public:
	Event(void* p_EventData, EventType p_EventType);

	Event(const Event& p_Event);

	/*
	* Precondition:
	*  - EventData must contain data
	*  - must provide correct type with template arg T
	*
	* Postcondition: returns copy of data as type T
	*/
	template<typename T>
	T GetInputData() const;

private:
	EventData m_EventData;
	EventType m_EventType;
};

template<typename T>
inline T Event::GetInputData() const
{
	return m_EventData.GetData<T>();
}

template<typename T>
inline T Event::EventData::GetData() const
{
	return *(T*)(m_Data);
}
