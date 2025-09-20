#pragma once
#include "SubApp.h"
class RationalNumberApp :
    public SubApp
{
public:
	void Run() override;
	void Restart() override;
	void Clean() override;

private:
	void HandleInput(char p_Input) override;
};

