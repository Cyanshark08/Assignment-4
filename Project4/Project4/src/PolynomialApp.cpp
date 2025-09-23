#include "PolynomialApp.h"
#include <iostream>
#include <iomanip>
#include <string>

PolynomialApp::PolynomialApp()
    : m_MenuState(PolynomialMenuState::Selection),
    m_SinglePolynomial(),
    m_PolynomialPair(std::make_pair(Polynomial(), Polynomial())),
    m_NumberOfTerms(0)
{
}

void PolynomialApp::Run()
{
    while (m_MenuState != PolynomialMenuState::Exited)
    {
        std::system("cls");

        switch (m_MenuState)
        {
        case PolynomialMenuState::Selection:
            std::cout << "\n\tA polynomial is an expression consisting of variables(also called indeterminates) and\n";
            std::cout << "\tcoefficients, that involves only the operations of addition, subtraction, multiplication,\n";
            std::cout << "\tand non-negative integer exponentiation of variables.\n\n";

            std::cout << "\t3> Polynomials\n";
            std::cout << "\t" << std::string(110, '-') << "\n";
            std::cout << "\tA> A Polynomial\n";
            std::cout << "\tB> Multiple Polynomials\n";
            std::cout << "\t" << std::string(110, '-') << "\n";
            std::cout << "\t0> return\n";
            std::cout << "\t" << std::string(110, '-') << "\n";
            m_QuerySystem->QueryChar("\n\tOption: ", "AB0");
            break;

        case PolynomialMenuState::Single:
            std::cout << "\n\t# A> Single Polynomial\n";
            std::cout << "\t" << std::string(110, '-') << "\n";
            std::cout << "\t1. Enter the number of terms\n";
            std::cout << "\t2. Specify the coefficients\n";
            std::cout << "\t3. Evaluate expression\n";
            std::cout << "\t4. Solve for the derivative\n";
            std::cout << "\t5. Solve for the integral\n";
            std::cout << "\t" << std::string(110, '-') << "\n";
            std::cout << "\t0. return\n";
            std::cout << "\t" << std::string(110, '-') << "\n";
            m_QuerySystem->QueryChar("\n\tOption: ", "012345");
            break;

        case PolynomialMenuState::Multiple:
            std::cout << "\n\tB> Two Polynomials\n";
            std::cout << "\t" << std::string(110, '-') << "\n";
            std::cout << "\t1. Enter two polynomials\n";
            std::cout << "\t2. Perform operations (+, -, *, scalar multiplication)\n";
            std::cout << "\t" << std::string(110, '-') << "\n";
            std::cout << "\t0. return\n";
            std::cout << "\t" << std::string(110, '-') << "\n";
            m_QuerySystem->QueryChar("\n\tOption: ", "012");
            break;
        }

        HandleInput(m_EventSystem->GetInput<char>());
    }
}

void PolynomialApp::Restart()
{
    Clean();
}

void PolynomialApp::Clean()
{
    m_SinglePolynomial = Polynomial();
    m_PolynomialPair = std::make_pair(Polynomial(), Polynomial());
    m_NumberOfTerms = 0;
    m_MenuState = PolynomialMenuState::Selection;
}

void PolynomialApp::HandleInput(char p_Input)
{
    switch (m_MenuState)
    {
    case PolynomialMenuState::Selection:
        switch (p_Input)
        {
        case 'A':
            m_MenuState = PolynomialMenuState::Single;
            break;
        case 'B':
            m_MenuState = PolynomialMenuState::Multiple;
            break;
        case '0':
            m_MenuState = PolynomialMenuState::Exited;
            break;
        }
        break;

    case PolynomialMenuState::Single:
        HandleSinglePolynomial(p_Input);
        break;

    case PolynomialMenuState::Multiple:
        HandleMultiplePolynomials(p_Input);
        break;
    }
}

void PolynomialApp::HandleSinglePolynomial(char option)
{
    switch (option)
    {
    case '1':
        EnterNumberOfTerms();
        break;
    case '2':
        SpecifyCoefficients();
        break;
    case '3':
        EvaluateExpression();
        break;
    case '4':
        SolveDerivative();
        break;
    case '5':
        SolveIntegral();
        break;
    case '0':
        m_MenuState = PolynomialMenuState::Selection;
        break;
    }

    if (m_MenuState != PolynomialMenuState::Selection && option != '0')
    {
        std::cout << "\n\n";
        std::system("pause");
    }
}

void PolynomialApp::HandleMultiplePolynomials(char option)
{
    switch (option)
    {
    case '1':
        EnterTwoPolynomials();
        break;
    case '2':
        PerformPolynomialOperations();
        break;
    case '0':
        m_MenuState = PolynomialMenuState::Selection;
        break;
    }

    if (m_MenuState != PolynomialMenuState::Selection && option != '0')
    {
        std::cout << "\n\n";
        std::system("pause");
    }
}

void PolynomialApp::EnterNumberOfTerms()
{
    m_QuerySystem->QueryInteger("\n\tEnter the number of terms(1..100) for the polynomial: ", 1, 100);
    m_NumberOfTerms = m_EventSystem->GetInput<int>();
    m_SinglePolynomial.setDegree(m_NumberOfTerms - 1);

    std::cout << "\n\tNumber of terms set to: " << m_NumberOfTerms;
}

void PolynomialApp::SpecifyCoefficients()
{
    if (m_NumberOfTerms == 0) {
        std::cout << "\n\tERROR: Please enter the number of terms first (Option 1).";
        return;
    }

    std::cout << "\n";
    for (int i = 0; i < m_NumberOfTerms; i++) {
        std::string prompt = "\tEnter the coefficient for term #" + std::to_string(i + 1) + ": ";
        m_QuerySystem->QueryDouble(prompt);
        double coeff = m_EventSystem->GetInput<double>();
        m_SinglePolynomial.setCoefficient(m_NumberOfTerms - 1 - i, coeff);
    }

    std::cout << "\n\tThe P(x) is entered: " << m_SinglePolynomial.toString();
}

void PolynomialApp::EvaluateExpression()
{
    if (m_NumberOfTerms == 0) {
        std::cout << "\n\tERROR: Please specify the polynomial first (Options 1 and 2).";
        return;
    }

    std::cout << "\n\tP1(x) = " << m_SinglePolynomial.toString();
    m_QuerySystem->QueryDouble("\n\tEnter the value of x to evaluate the polynomial: ");
    double x = m_EventSystem->GetInput<double>();

    m_SinglePolynomial.displayEvaluation(x);
}

void PolynomialApp::SolveDerivative()
{
    if (m_NumberOfTerms == 0) {
        std::cout << "\n\tERROR: Please specify the polynomial first (Options 1 and 2).";
        return;
    }

    Polynomial derivative = m_SinglePolynomial.derivative();

    std::cout << "\n\tPolynomial(x) = " << m_SinglePolynomial.toString();
    std::cout << "\n\tDerivative = " << derivative.toString();
}

void PolynomialApp::SolveIntegral()
{
    if (m_NumberOfTerms == 0) {
        std::cout << "\n\tERROR: Please specify the polynomial first (Options 1 and 2).";
        return;
    }

    Polynomial integral = m_SinglePolynomial.integral();

    std::cout << "\n\tPolynomial(x) = " << m_SinglePolynomial.toString();
    std::cout << "\n\tIntegral = " << integral.toString();
}

void PolynomialApp::EnterTwoPolynomials()
{
    // First polynomial
    m_QuerySystem->QueryInteger("\n\tEnter the number of terms(1..100) for the first polynomial (P1): ", 1, 100);
    int terms1 = m_EventSystem->GetInput<int>();
    Polynomial p1(terms1 - 1);

    std::cout << "\n";
    for (int i = 0; i < terms1; i++) {
        std::string prompt = "\tEnter the coefficient for term #" + std::to_string(i + 1) + ": ";
        m_QuerySystem->QueryDouble(prompt);
        double coeff = m_EventSystem->GetInput<double>();
        p1.setCoefficient(terms1 - 1 - i, coeff);
    }

    std::cout << "\n\tThe first polynomial (P1) is entered: " << p1.toString();

    // Second polynomial
    m_QuerySystem->QueryInteger("\n\tEnter the number of terms(1..100) for the second polynomial (P2): ", 1, 100);
    int terms2 = m_EventSystem->GetInput<int>();
    Polynomial p2(terms2 - 1);

    std::cout << "\n";
    for (int i = 0; i < terms2; i++) {
        std::string prompt = "\tEnter the coefficient for term #" + std::to_string(i + 1) + ": ";
        m_QuerySystem->QueryDouble(prompt);
        double coeff = m_EventSystem->GetInput<double>();
        p2.setCoefficient(terms2 - 1 - i, coeff);
    }

    std::cout << "\n\tThe second polynomial (P2) is entered: " << p2.toString();

    m_PolynomialPair = std::make_pair(p1, p2);
}

void PolynomialApp::PerformPolynomialOperations()
{
    Polynomial p1 = m_PolynomialPair.first;
    Polynomial p2 = m_PolynomialPair.second;

    if (p1.getDegree() < 0 || p2.getDegree() < 0) {
        std::cout << "\n\tERROR: Please enter two polynomials first (Option 1).";
        return;
    }

    std::cout << "\n\tP1 = " << p1.toString();
    std::cout << "\n\tP2 = " << p2.toString();

    // Addition
    Polynomial sum = p1 + p2;
    std::cout << "\n\n\tAddition of polynomials";
    std::cout << "\n\t-> P1 + P2 = " << sum.toString();

    // Subtraction
    Polynomial diff = p1 - p2;
    std::cout << "\n\n\tSubtraction of polynomials";
    std::cout << "\n\t-> P1 - P2 = " << diff.toString();

    // Multiplication
    Polynomial product = p1 * p2;
    std::cout << "\n\n\tMultiplication of polynomials";
    std::cout << "\n\t-> P1 * P2 = " << product.toString();

    // Scalar multiplication
    m_QuerySystem->QueryDouble("\n\n\tEnter a constant value: ");
    double scalar = m_EventSystem->GetInput<double>();

    Polynomial scalarP1 = p1 * scalar;
    Polynomial scalarP2 = scalar * p2;

    std::cout << "\n\t" << scalar << " * P1 = " << scalarP1.toString();
    std::cout << "\n\tP2 * " << scalar << " = " << scalarP2.toString();
}