#include "Application.h"
#include <string>

Application::Application()
	: m_State(MainAppState::MainApp),
	m_CurrentSubApp(AppID::InvalidApp),
	m_EventSystem(std::make_shared<EventSystem>()),
	m_QuerySystem(std::make_shared<QuerySystem>())
{
	m_QuerySystem->LinkEventSystem(m_EventSystem);
	m_ComplexNumberApp.LinkSystems(m_EventSystem, m_QuerySystem);
	m_RationalNumberApp.LinkSystems(m_EventSystem, m_QuerySystem);
	m_PolynomialApp.LinkSystems(m_EventSystem, m_QuerySystem);
}

void Application::Run()
{
	while (m_State != MainAppState::Exited)
	{

		std::system("cls");

		switch (m_State)
		{
		case MainAppState::MainApp:
			DisplayMainMenu();
			QueryState();
			break;
		case MainAppState::SubApp:			
			switch (m_CurrentSubApp)
			{
			case AppID::ComplexNumber:
				m_ComplexNumberApp.Run();
				m_ComplexNumberApp.Clean();
				break;
			case AppID::RationalNumber:
				m_RationalNumberApp.Run();
				m_RationalNumberApp.Clean();
				break;
			case AppID::Polynomial:
				m_PolynomialApp.Run();
				m_PolynomialApp.Clean();
				break;
			}

			m_State = MainAppState::MainApp;
			m_CurrentSubApp = AppID::InvalidApp;
			break;
		}
	}
}

void Application::Clean()
{	
	m_ComplexNumberApp.Clean();
	m_RationalNumberApp.Clean();
	m_RationalNumberApp.Clean();
}

void Application::DisplayMainMenu()
{
	puts("\n\tCMPR131 Chapter 4: Complex Numbers, Rational Numbers, Polynomials by Andrew, Jaime, & Landon");
	printf("\t%s\n", std::string(110, 205).c_str());
	puts("\t1 > Complex Numbers");
	puts("\t2 > Rational Numbers");
	puts("\t3 > Polynomials");
	printf("\t%s\n", std::string(110, 196).c_str());
	puts("\t0. Exit");
	printf("\t%s\n", std::string(110, 205).c_str());
}

void Application::QueryState()
{
	m_QuerySystem->QueryChar("\n\tOption: ", "1230");
	switch (m_EventSystem->GetInput<char>())
	{
	case '1':
		m_State = MainAppState::SubApp;
		m_CurrentSubApp = AppID::ComplexNumber;
		break;
	case '2':
		m_State = MainAppState::SubApp;
		m_CurrentSubApp = AppID::RationalNumber;
		break;
	case '3':
		m_State = MainAppState::SubApp;
		m_CurrentSubApp = AppID::Polynomial;
		break;
	case '0':
		m_State = MainAppState::Exited;
		break;
	}
}
