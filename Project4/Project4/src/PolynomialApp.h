#pragma once
#include "SubApp.h"
#include "Polynomial.h"
#include <utility>

class PolynomialApp :
    public SubApp
{
public:
    PolynomialApp();
    ~PolynomialApp();

    void Run() override;
    void Restart() override;
    void Clean() override;

private:
    void HandleInput(char p_Input) override;

private:
    enum class PolySubMenuState
    {
        Exited,
        Selection,
        Single,
        Multiple
    };

    PolySubMenuState m_MenuState;
    Polynomial* m_PolySingle;
    std::pair<Polynomial, Polynomial> m_PolyPair;

    void DisplaySelectionMenu();
    void DisplaySingleMenu();
    void DisplayMultipleMenu();
    void HandleSelectionInput(char p_Input);
    void HandleSingleInput(char p_Input);
    void HandleMultipleInput(char p_Input);

    // Single polynomial operations
    void EnterNumberOfTerms();
    void SpecifyCoefficients();
    void EvaluateExpression();
    void SolveDerivative();
    void SolveIntegral();
    Polynomial CalculateDerivative(const Polynomial& poly);
    Polynomial CalculateIntegral(const Polynomial& poly);

    // Multiple polynomial operations
    void EnterPolynomialCoefficients(Polynomial& poly);
    void VerifyConditionalOperators();
    void EvaluateArithmeticOperators();
    void EvaluateComplexExpression();
};