#include "Polynomial.h"
#include <sstream>
#include <iomanip>
#include <cmath>

Polynomial::Polynomial()
{
    coefficients = { 0.0 }; // Default polynomial: 0
}

Polynomial::Polynomial(const std::vector<double>& coefficients)
    : coefficients(coefficients)
{
    removeLeadingZeros();
}

Polynomial::Polynomial(const Polynomial& obj)
    : coefficients(obj.coefficients)
{
}

void Polynomial::setCoefficients(const std::vector<double>& coefficients)
{
    this->coefficients = coefficients;
    removeLeadingZeros();
}

const std::vector<double>& Polynomial::getCoefficients() const
{
    return coefficients;
}

void Polynomial::setDegree(size_t p_Deg)
{
    coefficients.resize(p_Deg);
}

int Polynomial::getDegree() const
{
    return coefficients.size() - 1;
}

void Polynomial::removeLeadingZeros()
{
    while (coefficients.size() > 1 && std::abs(coefficients.back()) < 1e-10)
    {
        coefficients.pop_back();
    }
}

Polynomial Polynomial::simplify() const
{
    return *this; // For polynomials, simplification is removing leading zeros (done automatically)
}

Polynomial Polynomial::negate() const
{
    std::vector<double> resultCoeffs = coefficients;
    for (double& coeff : resultCoeffs)
    {
        coeff = -coeff;
    }
    return Polynomial(resultCoeffs);
}

double Polynomial::evaluate(double x) const
{
    double result = 0;
    for (size_t i = 0; i < coefficients.size(); i++)
        result += std::pow(coefficients[i], i);

    return result;
}

Polynomial& Polynomial::operator=(const Polynomial& right)
{
    if (this != &right)
    {
        coefficients = right.coefficients;
    }
    return *this;
}

Polynomial Polynomial::operator+(const Polynomial& right) const
{
    size_t maxSize = std::max(coefficients.size(), right.coefficients.size());
    std::vector<double> resultCoeffs(maxSize, 0.0);

    for (size_t i = 0; i < maxSize; i++)
    {
        if (i < coefficients.size())
            resultCoeffs[i] += coefficients[i];
        if (i < right.coefficients.size())
            resultCoeffs[i] += right.coefficients[i];
    }

    return Polynomial(resultCoeffs);
}

Polynomial Polynomial::operator-(const Polynomial& right) const
{
    return *this + right.negate();
}

Polynomial Polynomial::operator*(const Polynomial& right) const
{
    std::vector<double> resultCoeffs(coefficients.size() + right.coefficients.size() - 1, 0.0);

    for (size_t i = 0; i < coefficients.size(); i++)
    {
        for (size_t j = 0; j < right.coefficients.size(); j++)
        {
            resultCoeffs[i + j] += coefficients[i] * right.coefficients[j];
        }
    }

    return Polynomial(resultCoeffs);
}

Polynomial Polynomial::operator*(double scalar) const
{
    std::vector<double> resultCoeffs = coefficients;
    for (double& coeff : resultCoeffs)
    {
        coeff *= scalar;
    }
    return Polynomial(resultCoeffs);
}

bool Polynomial::operator==(const Polynomial& right) const
{
    if (coefficients.size() != right.coefficients.size())
        return false;

    for (size_t i = 0; i < coefficients.size(); i++)
    {
        if (std::abs(coefficients[i] - right.coefficients[i]) > 1e-10)
            return false;
    }

    return true;
}

bool Polynomial::operator!=(const Polynomial& right) const
{
    return !(*this == right);
}

std::ostream& operator<<(std::ostream& out, const Polynomial& obj)
{
    if (obj.coefficients.empty())
    {
        out << "0";
        return out;
    }

    bool firstTerm = true;

    // Display from highest degree to lowest
    for (int i = obj.coefficients.size() - 1; i >= 0; i--)
    {
        double coeff = obj.coefficients[i];

        // Skip zero coefficients (except when it's the only term)
        if (std::abs(coeff) < 1e-10)
        {
            if (obj.coefficients.size() == 1)
            {
                out << "0";
                return out;
            }
            continue;
        }

        // Handle sign
        if (!firstTerm)
        {
            out << " + ";
        }

        // For integrals, we want to display coefficients with precision
        // Check if coefficient is effectively an integer
        if (std::abs(coeff - std::round(coeff)) < 1e-6)
        {
            out << static_cast<int>(std::round(coeff));
        }
        else
        {
            // Display with 6 decimal places, remove trailing zeros
            std::stringstream ss;
            ss << std::fixed << std::setprecision(6) << coeff;
            std::string str = ss.str();

            // Remove trailing zeros and decimal point if needed
            str.erase(str.find_last_not_of('0') + 1, std::string::npos);
            if (str.back() == '.')
                str.pop_back();

            out << str;
        }

        // Output variable part
        if (i > 0)
        {
            if (i == 1)
            {
                out << "x";
            }
            else
            {
                out << "x^" << i;
            }
        }

        firstTerm = false;
    }

    return out;
}

Polynomial operator*(double scalar, const Polynomial& poly)
{
    return Polynomial({ poly.getCoefficients()[0] * scalar, poly.getCoefficients()[1] * scalar, poly.getCoefficients()[2] * scalar });
}

double& Polynomial::operator[](size_t p_Index)
{
    return coefficients[p_Index];
}

double Polynomial::operator()(double p_X)
{
    return evaluate(p_X);
}