#pragma once
#include "ExceptionInterface.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

class Polynomial
{
public:
    // constructors
    Polynomial();
    Polynomial(const std::vector<double>& coefficients);
    Polynomial(const Polynomial& obj);
    ~Polynomial() = default;

    // accessors and mutators
    void setCoefficients(const std::vector<double>& coefficients);
    const std::vector<double>& getCoefficients() const;
    void setDegree(size_t p_Deg);
    int getDegree() const;

    // operations
    Polynomial simplify() const;
    Polynomial negate() const;
    double evaluate(double x) const;

    // overloaded operators
    friend std::ostream& operator<<(std::ostream& out, const Polynomial& obj);
    Polynomial& operator=(const Polynomial& right);
    Polynomial operator+(const Polynomial& right) const;
    Polynomial operator-(const Polynomial& right) const;
    Polynomial operator*(const Polynomial& right) const;
    Polynomial operator*(double scalar) const;
    bool operator==(const Polynomial& right) const;
    bool operator!=(const Polynomial& right) const;

    double& operator[](size_t p_Index);
    double operator()(double p_X);


    std::string to_string() const;

private:
    std::vector<double> coefficients;

    void removeLeadingZeros();
};

// Scalar multiplication (left scalar multiplication) - moved to cpp file
Polynomial operator*(double scalar, const Polynomial& poly);