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

	RationalNumberApp();

	void Run() override;
	void Restart() override;
	void Clean() override;

private:
	void HandleInput(char p_Input) override;

private:
	SubMenuState m_MenuState;

	Rational m_Rational1;
	Rational m_Rational2;
};

