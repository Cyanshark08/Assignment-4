#pragma once
#include "SubApp.h"
#include "Polynomial.h"
#include <utility>

enum class PolynomialMenuState
{
    Exited,
    Selection,
    Single,
    Multiple
};

class PolynomialApp : public SubApp
{
public:
    PolynomialApp();

    void Run() override;
    void Restart() override;
    void Clean() override;

private:
    void HandleInput(char p_Input) override;

    void HandleSinglePolynomial(char option);
    void HandleMultiplePolynomials(char option);

    void EnterNumberOfTerms();
    void SpecifyCoefficients();
    void EvaluateExpression();
    void SolveDerivative();
    void SolveIntegral();

    void EnterTwoPolynomials();
    void PerformPolynomialOperations();

private:
    PolynomialMenuState m_MenuState;
    Polynomial m_SinglePolynomial;
    std::pair<Polynomial, Polynomial> m_PolynomialPair;
    int m_NumberOfTerms;
};