#include "EventSystem.h"

EventSystem::EventSystem()
	: m_EventQueue(),
	m_UnhandledEvent(false)
{}

void EventSystem::ReleaseFrontEvent()
{
	if(m_UnhandledEvent)
	{
		m_EventQueue.pop();
		m_UnhandledEvent = !m_EventQueue.empty();
	}
}

std::string EventSystem::E_EmptyEventQueue::GetExceptionName() const
{
	return "Empty Event Queue";
}

std::string EventSystem::E_EmptyEventQueue::GetExceptionMessage() const
{
	return "Event retrieval failed because Event Queue is Empty!";
}
