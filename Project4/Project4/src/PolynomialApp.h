#pragma once
#include "SubApp.h"
class PolynomialApp :
    public SubApp
{
public:
	void Run() override;
	void Restart() override;
	void Clean() override;

private:
	void HandleInput(char p_Input) override;
};

