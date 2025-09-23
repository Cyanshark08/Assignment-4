#pragma once
#include "ComplexNumberApp.h"
#include "RationalNumberApp.h"
#include "PolynomialApp.h"
#include "QuerySystem.h"
#include "EventSystem.h"
#include <memory>

enum class MainAppState
{
	MainApp,
	SubApp,
	Exited
};

class Application
{
public:

	Application();

	/*
	* Precondition: None
	*
	* Postcondition: Initializes main application loop; handles each SubApp
	*/
	void Run();

	/*
	* Precondition: None
	*
	* Postcondition: Cleans all SubApps
	*/
	void Clean();

private:
	void DisplayMainMenu();
	void QueryState();

private:
	MainAppState m_State;
	AppID m_CurrentSubApp;
	ComplexNumberApp m_ComplexNumberApp;
	RationalNumberApp m_RationalNumberApp;
	PolynomialApp m_PolynomialApp;  // Changed from pointer to object

	std::shared_ptr<QuerySystem> m_QuerySystem;
	std::shared_ptr<EventSystem> m_EventSystem;
};