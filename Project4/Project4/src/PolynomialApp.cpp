#include "PolynomialApp.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <cmath>

PolynomialApp::PolynomialApp()
    : m_MenuState(PolySubMenuState::Selection),
    m_PolySingle(),
    m_PolyPair(std::make_pair<Polynomial>(Polynomial(), Polynomial()))
{
}

void PolynomialApp::Run()
{
    while (m_MenuState != PolySubMenuState::Exited)
    {
        std::system("cls");

        switch (m_MenuState)
        {
        case PolySubMenuState::Selection:
            DisplaySelectionMenu();
            m_QuerySystem->QueryChar("\n\tOption: ", "AB0");
            break;
        case PolySubMenuState::Single:
            DisplaySingleMenu();
            m_QuerySystem->QueryChar("\n\tOption: ", "123450");
            break;
        case PolySubMenuState::Multiple:
            DisplayMultipleMenu();
            std::system("pause");
            m_EventSystem->PushEvent<char>('\0', EventType::InputEvent);
            m_MenuState = PolySubMenuState::Selection;
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
    m_PolySingle = Polynomial();
    m_PolyPair = std::make_pair(Polynomial(), Polynomial());
    m_MenuState = PolySubMenuState::Selection;
}

void PolynomialApp::HandleInput(char p_Input)
{
    switch (m_MenuState)
    {
    case PolySubMenuState::Selection:
        HandleSelectionInput(p_Input);
        break;
    case PolySubMenuState::Single:
        HandleSingleInput(p_Input);
        break;
    case PolySubMenuState::Multiple:
        break;
    }
}

void PolynomialApp::DisplaySelectionMenu()
{
    puts("\tIn mathematics, a polynomial is a mathematical expression consisting of indeterminates");
    puts("\t(also called variables) and coefficients, that involves only the operations of addition,");
    puts("\tsubtraction, multiplication, and positive-integer powers of variables. An example of a");
    puts("\tpolynomial of a single indeterminate x is x^2 - 4x + 7.");
    puts("");
    puts("\t3 > Polynomials");
    printf("\t%s\n", std::string(110, 205).c_str());
    puts("\tA > A Polynomial");
    puts("\tB > Multiple Polynomials");
    printf("\t%s\n", std::string(110, 196).c_str());
    puts("\t0 > Return");
    printf("\t%s\n", std::string(110, 205).c_str());
}

void PolynomialApp::DisplaySingleMenu()
{
    puts("\tA > A Polynomial");
    printf("\t%s\n", std::string(110, 205).c_str());
    puts("\t1. Enter the number of terms");
    puts("\t2. Specify the coefficients");
    puts("\t3. Evaluate expression");
    puts("\t4. Solve for the derivative");
    puts("\t5. Solve for the integral");
    printf("\t%s\n", std::string(110, 196).c_str());
    puts("\t0. Return");
    printf("\t%s\n", std::string(110, 205).c_str());
}

void PolynomialApp::DisplayMultipleMenu()
{
    std::cout << "\n\tB. Two Polynomials";
    std::cout << "\n\t" << std::string(110, 205);

    std::cout << "\n\tPolynomial 1:\n\t";
    EnterPolynomialCoefficients(m_PolyPair.first);

    std::cout << "\n\n\tPolynomial 2:\n\t";
    EnterPolynomialCoefficients(m_PolyPair.second);

    std::cout << "\n";
    std::cout << "\n\t\tAddition of polynomials        -> P1 + P2 = " << (m_PolyPair.first + m_PolyPair.second);
    std::cout << "\n\t\tSubtration of polynomials      -> P1 - P2 = " << (m_PolyPair.first - m_PolyPair.second);
    std::cout << "\n\t\tMultiplication of polynomials  -> P1 * P2 = " << (m_PolyPair.first * m_PolyPair.second);

    m_QuerySystem->QueryDouble("\n\n\tInput a constant value: ");
    float value = m_EventSystem->GetInput<double>();

    std::cout << "\n\tP1 * " << value << " = " << m_PolyPair.first * value;
    std::cout << "\n\tP2 * " << value << " = " << m_PolyPair.second * value << std::endl;

}

void PolynomialApp::HandleSelectionInput(char p_Input)
{
    switch (p_Input)
    {
    case 'A':
        m_MenuState = PolySubMenuState::Single;
        break;
    case 'B':
        m_MenuState = PolySubMenuState::Multiple;
        break;
    case '0':
        m_MenuState = PolySubMenuState::Exited;
        break;
    }
}

void PolynomialApp::HandleSingleInput(char p_Input)
{
    switch (p_Input)
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
        m_MenuState = PolySubMenuState::Selection;
        break;
    }

    if (m_MenuState != PolySubMenuState::Selection)
    {
        std::cout << "\n\n";
        std::system("pause");
    }
}

// Option 1: Enter number of terms (1-100)
void PolynomialApp::EnterNumberOfTerms()
{
    m_QuerySystem->QueryInteger("\n\tEnter the number of terms(1..100) for the polynomial: ", 1, 100);
    int numTerms = m_EventSystem->GetInput<int>();

    m_PolySingle.setDegree(numTerms);

    std::cout << "\n\tPolynomial has been set with " << numTerms << " terms.";
    std::cout << "\n\tUse option 2 to specify the coefficients for each term.";
}

// Option 2: Specify coefficients
void PolynomialApp::SpecifyCoefficients()
{
    if (m_PolySingle.getCoefficients().size() == 0)
    {
        std::cout << "\n\tERROR: Please use option 1 to set the number of terms first.";
        return;
    }

    std::cout << "\n\tEnter the coefficients for each term:";

    for (int i = 0; i < m_PolySingle.getCoefficients().size(); i++)
    {
        std::string prompt = "\n\tEnter the coefficient for term #" + std::to_string(i + 1) + ": ";
        m_QuerySystem->QueryDouble(prompt);
        m_PolySingle[i] = m_EventSystem->GetInput<double>();
    }
    std::cout << "\n\tThe P(x) is entered: " << m_PolySingle;
}

// Option 3: Evaluate expression
void PolynomialApp::EvaluateExpression()
{
    if (m_PolySingle.getDegree() < 0 || m_PolySingle.getCoefficients().empty())
    {
        std::cout << "\n\tERROR: Please define a polynomial first using options 1 and 2.";
        return;
    }

    std::cout << "\n\tP1(x) = " << m_PolySingle;
    m_QuerySystem->QueryDouble("\n\n\tEnter the value of x to evaluate the polynomial: ");
    double x = m_EventSystem->GetInput<double>();
    double totalResult = 0.0;

    puts("");

    for (int i = m_PolySingle.getCoefficients().size() - 1; i >= 0; i--)
    {
        if(i == 0)
        {
            std::cout << "\n\t+" << std::fixed << std::setprecision(2) << std::right << std::setw(9) << m_PolySingle[i] * std::pow(x, i) << " <- " << std::fixed << std::setprecision(2) << m_PolySingle[i] << "x^" << i;
            totalResult += m_PolySingle[i] * std::pow(x, i);
            break;
        }

        std::cout  << "\n\t" << std::fixed << std::setprecision(2) << std::right << std::setw(10) << m_PolySingle[i] * std::pow(x, i) << " <- " << std::fixed << std::setprecision(2) << m_PolySingle[i] << "x^" << i;
        totalResult += m_PolySingle[i] * std::pow(x, i);
    }

    std::cout << "\n\t----------------------------------\n\t";
    std::cout << std::setprecision(2) << std::fixed << totalResult;
}

// Option 4: Solve for the derivative
void PolynomialApp::SolveDerivative()
{
    if (m_PolySingle.getDegree() < 0 || m_PolySingle.getCoefficients().empty())
    {
        std::cout << "\n\tERROR: Please define a polynomial first using options 1 and 2.";
        return;
    }

    Polynomial derivative = CalculateDerivative(m_PolySingle);
    std::cout << "\n\tPolynomial P(x) = " << m_PolySingle;
    std::cout << "\n\n\tDerivative    = " << derivative;
}

// Option 5: Solve for the integral
void PolynomialApp::SolveIntegral()
{
    if (m_PolySingle.getDegree() < 0 || m_PolySingle.getCoefficients().empty())
    {
        std::cout << "\n\tERROR: Please define a polynomial first using options 1 and 2.";
        return;
    }

    Polynomial integral = CalculateIntegral(m_PolySingle);
    std::cout << "\n\tPolynomial P(x) = " << m_PolySingle;
    std::cout << "\n\n\tIntegral     = " << integral << " + C";
}

Polynomial PolynomialApp::CalculateDerivative(const Polynomial& poly)
{
    std::vector<double> coeffs = poly.getCoefficients();
    if (coeffs.size() <= 1) return Polynomial({ 0.0 });

    std::vector<double> derivativeCoeffs(coeffs.size() - 1);
    for (size_t i = 1; i < coeffs.size(); i++)
    {
        derivativeCoeffs[i - 1] = coeffs[i] * i;
    }
    return Polynomial(derivativeCoeffs);
}

Polynomial PolynomialApp::CalculateIntegral(const Polynomial& poly)
{
    std::vector<double> coeffs = poly.getCoefficients();
    std::vector<double> integralCoeffs(coeffs.size() + 1, 0.0);

    for (size_t i = 0; i < coeffs.size(); i++)
    {
        integralCoeffs[i + 1] = coeffs[i] / (i + 1);
    }
    return Polynomial(integralCoeffs);
}

// Existing functions (modified to work with new structure)
void PolynomialApp::EnterPolynomialCoefficients(Polynomial& poly)
{
    m_QuerySystem->QueryInteger("\tEnter the number of terms: ", 1, true);
    int numTerms = m_EventSystem->GetInput<int>();

    poly.setDegree(numTerms);

    std::cout << "\t\tEnter coefficients for each term (from highest degree to constant term):";
    std::cout << "\n";
    for (int i = numTerms - 1; i >= 0; i--)
    {
        std::string prompt = "\t\t\tCoefficient for ";
        if (i == 0) prompt += "constant term: ";
        else if (i == 1) prompt += "x: ";
        else prompt += "x^" + std::to_string(i) + ": ";

        m_QuerySystem->QueryDouble(prompt);
        poly[i] = m_EventSystem->GetInput<double>();
    }
    std::cout << "\n\tPolynomial set to: " << poly;
}

void PolynomialApp::VerifyConditionalOperators()
{
    std::cout << "\n\tP1 == P2 . (" << m_PolyPair.first << ") == (" << m_PolyPair.second << ") ? ";
    std::cout << (m_PolyPair.first == m_PolyPair.second ? "true" : "false");

    std::cout << "\n\tP1 != P2 . (" << m_PolyPair.first << ") != (" << m_PolyPair.second << ") ? ";
    std::cout << (m_PolyPair.first != m_PolyPair.second ? "true" : "false");
}

void PolynomialApp::EvaluateArithmeticOperators()
{
    std::cout << "\n\tAddition: P1 + P2 = (" << m_PolyPair.first << ") + (" << m_PolyPair.second
        << ") = " << (m_PolyPair.first + m_PolyPair.second);

    std::cout << "\n\tSubtraction: P1 - P2 = (" << m_PolyPair.first << ") - (" << m_PolyPair.second
        << ") = " << (m_PolyPair.first - m_PolyPair.second);

    std::cout << "\n\tMultiplication: P1 * P2 = (" << m_PolyPair.first << ") * (" << m_PolyPair.second
        << ") = " << (m_PolyPair.first * m_PolyPair.second);
}

void PolynomialApp::EvaluateComplexExpression()
{
    Polynomial temp1 = m_PolyPair.first + m_PolyPair.second;
    Polynomial temp2 = 3.0 * temp1;
    Polynomial temp3 = m_PolyPair.first * m_PolyPair.second;
    Polynomial result = temp2 - temp3;

    std::cout << "\n\tExpression: (3 * (P1 + P2)) - (P1 * P2)";
    std::cout << "\n\tStep 1: P1 + P2 = (" << m_PolyPair.first << ") + (" << m_PolyPair.second
        << ") = " << temp1;
    std::cout << "\n\tStep 2: 3 * (P1 + P2) = 3 * (" << temp1 << ") = " << temp2;
    std::cout << "\n\tStep 3: P1 * P2 = (" << m_PolyPair.first << ") * (" << m_PolyPair.second
        << ") = " << temp3;
    std::cout << "\n\tStep 4: (3 * (P1 + P2)) - (P1 * P2) = (" << temp2 << ") - (" << temp3
        << ") = " << result;
    std::cout << "\n\tFinal Result: " << result;
}