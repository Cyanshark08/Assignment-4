#pragma once

#include "SubApp.h"
#include "Rational.h"
#include <string>

class RationalNumberApp :
    public SubApp
{
public:
	RationalNumberApp();

	void Run() override;
	void Restart() override;
	void Clean() override;

private:
	Rational m_Rational1;
	Rational m_Rational2;
	void HandleInput(char p_Input) override;
};

