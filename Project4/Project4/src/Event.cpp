#include "Event.h"

Event::Event(void* p_EventData, EventType p_EventType)
	: m_EventType(p_EventType)
{
	m_EventData.SetData(p_EventData);
}

Event::Event(const Event& p_Event)
{
	m_EventData = p_Event.m_EventData;
	m_EventType = p_Event.m_EventType;
}

Event::EventData::EventData(void* p_Data)
{
	m_Data = p_Data;
}

Event::EventData::EventData(const EventData& p_EventData)
	: m_Data(p_EventData.m_Data)
{}

void Event::EventData::SetData(void* p_Data)
{
	m_Data = p_Data;
}

Event::EventData::~EventData()
{
	delete m_Data;
}
