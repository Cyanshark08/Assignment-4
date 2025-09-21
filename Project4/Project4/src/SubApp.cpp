#include "SubApp.h"

SubApp::SubApp()
	: m_AppID(AppID::InvalidApp)
{}

SubApp::SubApp(AppID p_AppID)
	: m_AppID(p_AppID)
{}

void SubApp::LinkSystems(std::shared_ptr<EventSystem> p_EventSystem, std::shared_ptr<QuerySystem> p_QuerySystem)
{
	m_EventSystem = p_EventSystem;
	m_QuerySystem = p_QuerySystem;
}

AppID SubApp::GetAppID() const
{
	return m_AppID;
}