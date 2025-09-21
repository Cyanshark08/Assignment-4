#pragma once
#include "EventSystem.h"
#include "QuerySystem.h"
#include <memory>

enum class AppID
{
	InvalidApp     = -1,
	ComplexNumber  = 0,
	RationalNumber = 1,
	Polynomial     = 2
};

class SubApp
{
public:
	SubApp();
	SubApp(AppID p_AppID);


	void LinkSystems(std::shared_ptr<EventSystem> p_EventSystem, std::shared_ptr<QuerySystem> p_QuerySystem);

	/*
	* The Run() method is the main method that loops the SubApp over and over until the user exits the SubApp
	* 
	* Precondition: None
	*
	* Postcondition: Resets all specific variables relating to the implementation class to their default
	*/
	virtual void Run() = 0;

	/*
	* Precondition: None
	*
	* Postcondition: Resets all specific variables relating to the implementation class to their default
	* 
	* NOTE: Does not reset any SubApp-specific members
	*/
	virtual void Restart() = 0;

	/*
	* Precondition: None
	* 
	* Postcondition: Free memory related to SubApp entity
	*/
	virtual void Clean() = 0;
	
	/*
	* Precondition: Must be initialized
	*
	* Postcondition: Returns m_AppID
	*/
	AppID GetAppID() const;

private:
	/*
	* The Purpose of HandleInput() is to do varying things
	* based on the input provided.
	*
	* This is typically used to implement a menu for each
	* SubApp entity.
	*
	* Precondition: Pass input (Must be a valid option)
	*
	* Postcondition: Do certain instructions based on input
	*/
	virtual void HandleInput(char p_Input) = 0;

protected:
	std::shared_ptr<EventSystem> m_EventSystem;
	std::shared_ptr<QuerySystem> m_QuerySystem;
	
private:
	AppID m_AppID;

};

