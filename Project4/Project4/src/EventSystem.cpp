#include "EventSystem.h"

EventSystem::EventSystem()
	: m_EventQueue(),
	m_UnhandledEvent(false)
{}

void EventSystem::PushEvent(Event p_Event)
{
	m_EventQueue.push(p_Event);
	m_UnhandledEvent = true;
}

void EventSystem::ReleaseFrontEvent()
{
	m_EventQueue.pop();
}
