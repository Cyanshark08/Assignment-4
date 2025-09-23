#pragma once
#include "ExceptionInterface.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>

class Polynomial
{
public:
    // constructors
    Polynomial();
    Polynomial(int degree);
    Polynomial(const std::vector<double>& coefficients);
    Polynomial(const Polynomial& obj);

    // destructor
    ~Polynomial();

    // accessors and mutators
    void setCoefficient(int term, double coefficient);
    double getCoefficient(int term) const;
    int getDegree() const;
    void setDegree(int degree);

    // polynomial operations
    Polynomial operator+(const Polynomial& right) const;
    Polynomial operator-(const Polynomial& right) const;
    Polynomial operator*(const Polynomial& right) const;
    Polynomial operator*(double scalar) const;

    // calculus operations
    Polynomial derivative() const;
    Polynomial integral() const;
    double evaluate(double x) const;

    // utility functions
    std::string toString() const;
    void displayEvaluation(double x) const;

    // assignment operator
    Polynomial& operator=(const Polynomial& right);

private:
    double* coefficients;
    int degree;

    void resize(int newDegree);
    void initializeCoefficients();
};

// scalar multiplication (left side)
Polynomial operator*(double scalar, const Polynomial& poly);