#include "Polynomial.h"
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cmath>

Polynomial::Polynomial() : degree(0)
{
    coefficients = new double[1];
    coefficients[0] = 0.0;
}

Polynomial::Polynomial(int deg) : degree(deg)
{
    if (degree < 0) degree = 0;
    coefficients = new double[degree + 1];
    initializeCoefficients();
}

Polynomial::Polynomial(const std::vector<double>& coeffs) : degree(static_cast<int>(coeffs.size()) - 1)
{
    if (degree < 0) {
        degree = 0;
        coefficients = new double[1];
        coefficients[0] = 0.0;
        return;
    }

    coefficients = new double[degree + 1];
    for (int i = 0; i <= degree; i++) {
        coefficients[i] = coeffs[i];
    }
}

Polynomial::Polynomial(const Polynomial& obj) : degree(obj.degree)
{
    coefficients = new double[degree + 1];
    for (int i = 0; i <= degree; i++) {
        coefficients[i] = obj.coefficients[i];
    }
}

Polynomial::~Polynomial()
{
    delete[] coefficients;
}

void Polynomial::setCoefficient(int term, double coefficient)
{
    if (term < 0) return;

    if (term > degree) {
        resize(term);
    }

    coefficients[term] = coefficient;
}

double Polynomial::getCoefficient(int term) const
{
    if (term < 0 || term > degree) return 0.0;
    return coefficients[term];
}

int Polynomial::getDegree() const
{
    return degree;
}

void Polynomial::setDegree(int newDegree)
{
    if (newDegree < 0) newDegree = 0;
    resize(newDegree);
}

Polynomial Polynomial::operator+(const Polynomial& right) const
{
    int maxDegree = std::max(degree, right.degree);
    Polynomial result(maxDegree);

    for (int i = 0; i <= maxDegree; i++) {
        double coeff = getCoefficient(i) + right.getCoefficient(i);
        result.setCoefficient(i, coeff);
    }

    return result;
}

Polynomial Polynomial::operator-(const Polynomial& right) const
{
    int maxDegree = std::max(degree, right.degree);
    Polynomial result(maxDegree);

    for (int i = 0; i <= maxDegree; i++) {
        double coeff = getCoefficient(i) - right.getCoefficient(i);
        result.setCoefficient(i, coeff);
    }

    return result;
}

Polynomial Polynomial::operator*(const Polynomial& right) const
{
    int resultDegree = degree + right.degree;
    Polynomial result(resultDegree);

    for (int i = 0; i <= degree; i++) {
        for (int j = 0; j <= right.degree; j++) {
            double product = coefficients[i] * right.coefficients[j];
            result.coefficients[i + j] += product;
        }
    }

    return result;
}

Polynomial Polynomial::operator*(double scalar) const
{
    Polynomial result(degree);

    for (int i = 0; i <= degree; i++) {
        result.coefficients[i] = coefficients[i] * scalar;
    }

    return result;
}

Polynomial operator*(double scalar, const Polynomial& poly)
{
    return poly * scalar;
}

Polynomial Polynomial::derivative() const
{
    if (degree == 0) {
        return Polynomial();
    }

    Polynomial result(degree - 1);

    for (int i = 1; i <= degree; i++) {
        result.setCoefficient(i - 1, coefficients[i] * i);
    }

    return result;
}

Polynomial Polynomial::integral() const
{
    Polynomial result(degree + 1);

    for (int i = 0; i <= degree; i++) {
        result.setCoefficient(i + 1, coefficients[i] / (i + 1));
    }

    return result;
}

double Polynomial::evaluate(double x) const
{
    double result = 0.0;
    double power = 1.0;

    for (int i = 0; i <= degree; i++) {
        result += coefficients[i] * power;
        power *= x;
    }

    return result;
}

std::string Polynomial::toString() const
{
    if (degree == 0) {
        char buffer[20];
        sprintf_s(buffer, "%.2f", coefficients[0]);
        return std::string(buffer);
    }

    std::stringstream ss;
    bool firstTerm = true;

    for (int i = degree; i >= 0; i--) {
        if (coefficients[i] == 0.0) continue;

        if (!firstTerm) {
            ss << (coefficients[i] >= 0 ? " + " : " - ");
        }
        else if (coefficients[i] < 0) {
            ss << "-";
        }

        double absCoeff = std::abs(coefficients[i]);

        if (i == 0) {
            ss << std::fixed << std::setprecision(2) << absCoeff;
        }
        else if (i == 1) {
            if (absCoeff != 1.0) {
                ss << std::fixed << std::setprecision(2) << absCoeff;
            }
            ss << "x";
        }
        else {
            if (absCoeff != 1.0) {
                ss << std::fixed << std::setprecision(2) << absCoeff;
            }
            ss << "x^" << i;
        }

        firstTerm = false;
    }

    std::string result = ss.str();
    if (result.empty()) {
        return "0.00";
    }
    return result;
}

void Polynomial::displayEvaluation(double x) const
{
    double result = 0.0;

    std::cout << "\n";
    for (int i = degree; i >= 0; i--) {
        if (coefficients[i] == 0.0) continue;

        double termValue = coefficients[i] * std::pow(x, i);
        result += termValue;

        std::cout << "  ";
        std::cout << std::setw(12) << std::fixed << std::setprecision(2) << termValue;
        std::cout << " <- ";
        std::cout << std::setw(10) << std::fixed << std::setprecision(2) << coefficients[i];

        if (i == 0) {
            std::cout << "x^0";
        }
        else if (i == 1) {
            std::cout << "x^1";
        }
        else {
            std::cout << "x^" << i;
        }

        std::cout << "\n";
    }

    std::cout << "  " << std::string(12, '-') << "\n";
    std::cout << "  " << std::setw(12) << std::fixed << std::setprecision(2) << result << "\n";
}

Polynomial& Polynomial::operator=(const Polynomial& right)
{
    if (this != &right) {
        delete[] coefficients;
        degree = right.degree;
        coefficients = new double[degree + 1];

        for (int i = 0; i <= degree; i++) {
            coefficients[i] = right.coefficients[i];
        }
    }

    return *this;
}

void Polynomial::resize(int newDegree)
{
    if (newDegree == degree) return;

    double* newCoefficients = new double[newDegree + 1];

    for (int i = 0; i <= newDegree; i++) {
        newCoefficients[i] = 0.0;
    }

    int minDegree = std::min(degree, newDegree);
    for (int i = 0; i <= minDegree; i++) {
        newCoefficients[i] = coefficients[i];
    }

    delete[] coefficients;
    coefficients = newCoefficients;
    degree = newDegree;
}

void Polynomial::initializeCoefficients()
{
    for (int i = 0; i <= degree; i++) {
        coefficients[i] = 0.0;
    }
}