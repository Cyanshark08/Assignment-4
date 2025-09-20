#pragma once
#include "SubApp.h"
#include "Complex.h"
#include <utility>

enum class SubMenuState
{
	Exited,
	Selection,
	Single,
	Multiple
};

class ComplexNumberApp :
    public SubApp
{
public:
	ComplexNumberApp();

	void Run() override;
	void Restart() override;
	void Clean() override;

private:
	void HandleInput(char p_Input) override;

private:
	SubMenuState m_MenuState;
	Complex m_ComplexSingle;
	std::pair<Complex, Complex> m_ComplexPair;
};

