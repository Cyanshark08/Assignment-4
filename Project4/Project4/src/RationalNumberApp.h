#pragma once

#include "SubApp.h"
#include "Rational.h"
#include <iostream>
#include <string>

class RationalNumberApp :
    public SubApp
{
public:

	enum class SubMenuState
	{
		Exited,
		Selection,
		Single,
		Multiple
	};

	/*
	* PreCondition: N/A
	* PostCondition: Initialize the menuState to selection
	*/
	RationalNumberApp();

	/*
	* PreCondition: N/A
	* PostCondition: Display the menu depending on the menuState
	*/
	void Run() override;

	/*
	* PreCondition: N/A
	* PostCondition: Reset the menuState to selection
	*/
	void Restart() override;

	/*
	* PreCondition: N/A
	* PostCondition: Reset the menuState to selection
	*/
	void Clean() override;

private:
	/*
	* PreCondition: p_Input must be the user's char option
	* PostCondition: Carry out specific actions corresponding to the user's option
	* 
	* @param The user's char option
	*/
	void HandleInput(char p_Input) override;

private:
	SubMenuState m_MenuState;

	Rational m_Rational1;
	Rational m_Rational2;
};

