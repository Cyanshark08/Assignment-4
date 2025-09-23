#include "PolynomialApp.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <cmath>

PolynomialApp::PolynomialApp()
    : m_MenuState(PolySubMenuState::Selection),
    m_PolySingle(new Polynomial())
{
}

PolynomialApp::~PolynomialApp()
{
    delete m_PolySingle;
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
            m_QuerySystem->QueryChar("\n\tOption: ", "123450");
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
    if (m_PolySingle)
    {
        *m_PolySingle = Polynomial(); // Reset to default polynomial
    }
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
        HandleMultipleInput(p_Input);
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
    puts("\tB > Multiple Polynomials");
    printf("\t%s\n", std::string(110, 205).c_str());
    puts("\t1. Enter the first polynomial (P1)");
    puts("\t2. Enter the second polynomial (P2)");
    puts("\t3. Display all operations (P1 + P2, P1 - P2, P1 * P2)");
    puts("\t4. Multiply polynomials by constant");
    puts("\t5. Evaluate complex expression");
    printf("\t%s\n", std::string(110, 196).c_str());
    puts("\t0. Return");
    printf("\t%s\n", std::string(110, 205).c_str());
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

void PolynomialApp::HandleMultipleInput(char p_Input)
{
    switch (p_Input)
    {
    case '1':
        EnterPolynomialCoefficients(m_PolyPair.first);
        break;
    case '2':
        EnterPolynomialCoefficients(m_PolyPair.second);
        break;
    case '3':
        VerifyConditionalOperators();
        break;
    case '4':
        EvaluateArithmeticOperators();
        break;
    case '5':
        EvaluateComplexExpression();
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

    std::vector<double> coefficients(numTerms, 0.0);
    m_PolySingle->setCoefficients(coefficients);

    std::cout << "\n\tPolynomial has been set with " << numTerms << " terms.";
    std::cout << "\n\tUse option 2 to specify the coefficients for each term.";
}

// Option 2: Specify coefficients
void PolynomialApp::SpecifyCoefficients()
{
    std::vector<double> coefficients = m_PolySingle->getCoefficients();
    int numTerms = coefficients.size();

    if (numTerms == 0)
    {
        std::cout << "\n\tERROR: Please use option 1 to set the number of terms first.";
        return;
    }

    std::cout << "\n\tEnter the coefficients for each term:";

    for (int termNumber = 1; termNumber <= numTerms; termNumber++)
    {
        int exponent = numTerms - termNumber;
        std::string prompt = "\n\tEnter the coefficient for term #" + std::to_string(termNumber) + ": ";
        m_QuerySystem->QueryDouble(prompt);
        coefficients[exponent] = m_EventSystem->GetInput<double>();
    }

    m_PolySingle->setCoefficients(coefficients);
    std::cout << "\n\tThe P(x) is entered: " << *m_PolySingle;
}

// Option 3: Evaluate expression
void PolynomialApp::EvaluateExpression()
{
    if (m_PolySingle->getDegree() < 0 || m_PolySingle->getCoefficients().empty())
    {
        std::cout << "\n\tERROR: Please define a polynomial first using options 1 and 2.";
        return;
    }

    std::cout << "\n\tP1(x) = " << *m_PolySingle;
    m_QuerySystem->QueryDouble("\n\n\tEnter the value of x to evaluate the polynomial: ");
    double x = m_EventSystem->GetInput<double>();

    std::vector<double> coefficients = m_PolySingle->getCoefficients();
    double totalResult = 0.0;

    std::cout << "\n\n\t";
    std::cout << std::string(50, '-') << "\n";
    std::cout << "\t|    |    |\n";

    for (int i = coefficients.size() - 1; i >= 0; i--)
    {
        double coeff = coefficients[i];
        if (std::abs(coeff) < 1e-10) continue;

        double termValue = coeff * std::pow(x, i);
        totalResult += termValue;

        std::cout << "\t| ";
        std::cout << std::scientific << std::setprecision(6) << termValue;
        std::cout << " <-    | ";
        std::cout << std::fixed << std::setprecision(2) << coeff;

        if (i == 1) std::cout << "x";
        else if (i > 1) std::cout << "x^" << i;
        else std::cout << "";

        std::cout << "    |\n";
    }

    std::cout << "\t|    |    |\n";
    std::cout << "\t" << std::string(50, '-') << "\n";
    std::cout << "\t" << std::string(20, ' ') << "+\n";
    std::cout << "\t" << std::string(50, '-') << "\n";
    std::cout << "\t** " << std::scientific << std::setprecision(6) << totalResult << " **\n";
}

// Option 4: Solve for the derivative
void PolynomialApp::SolveDerivative()
{
    if (m_PolySingle->getDegree() < 0 || m_PolySingle->getCoefficients().empty())
    {
        std::cout << "\n\tERROR: Please define a polynomial first using options 1 and 2.";
        return;
    }

    Polynomial derivative = CalculateDerivative(*m_PolySingle);
    std::cout << "\n\tPolynomial P(x) = " << *m_PolySingle;
    std::cout << "\n\n\tDerivative    = " << derivative;
}

// Option 5: Solve for the integral
void PolynomialApp::SolveIntegral()
{
    if (m_PolySingle->getDegree() < 0 || m_PolySingle->getCoefficients().empty())
    {
        std::cout << "\n\tERROR: Please define a polynomial first using options 1 and 2.";
        return;
    }

    Polynomial integral = CalculateIntegral(*m_PolySingle);
    std::cout << "\n\tPolynomial P(x) = " << *m_PolySingle;
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
    m_QuerySystem->QueryInteger("\n\tEnter the number of terms: ", 1, true);
    int numTerms = m_EventSystem->GetInput<int>();

    std::vector<double> coefficients(numTerms, 0.0);

    std::cout << "\n\tEnter coefficients for each term (from highest degree to constant term):";

    for (int i = numTerms - 1; i >= 0; i--)
    {
        std::string prompt = "\n\tCoefficient for ";
        if (i == 0) prompt += "constant term: ";
        else if (i == 1) prompt += "x: ";
        else prompt += "x^" + std::to_string(i) + ": ";

        m_QuerySystem->QueryDouble(prompt);
        coefficients[i] = m_EventSystem->GetInput<double>();
    }

    poly.setCoefficients(coefficients);
    std::cout << "\n\tPolynomial set to: " << poly;
}

void PolynomialApp::VerifyConditionalOperators()
{
    std::cout << "\n\tP1 == P2 -> (" << m_PolyPair.first << ") == (" << m_PolyPair.second << ") ? ";
    std::cout << (m_PolyPair.first == m_PolyPair.second ? "true" : "false");

    std::cout << "\n\tP1 != P2 -> (" << m_PolyPair.first << ") != (" << m_PolyPair.second << ") ? ";
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