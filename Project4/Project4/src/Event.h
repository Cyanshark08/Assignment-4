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
		
		template<typename T>
		T GetData() const;

		void SetData(void* p_Data);

		~EventData();

	private:
		void* m_Data;
	};

public:
	Event(void* p_EventData, EventType p_EventType);

	Event(const Event& p_Event);

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
