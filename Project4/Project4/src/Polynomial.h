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

    /*
    * PreCondition: N/A
    * PostCondition: initialize the private members to default values
    */
    Polynomial();

    /*
    * PreCondition: vector of coefficients is passed
    * PostCOndition: copy the passed vector to the current vector
    */
    Polynomial(const std::vector<double>& coefficients);

    /*
    * PreCondition: Polynomial object is passed
    * PostCondition: Copy the polynomial object to the current object
    */
    Polynomial(const Polynomial& obj);

    /*
    * PreCondition: N/A
    * PostConition: free the memory
    */
    ~Polynomial() = default;

    // accessors and mutators
    /*
    * PreCondition: vector of coefficient is passed
    * PostCondition: set the number of coefficients 
    * 
    * @param The number of coefficient sof the polynomial
    */
    void setCoefficients(const std::vector<double>& coefficients);

    /*
    * PreCondition: N/A
    * PostCondition: Return the number of coefficients in the polynomal
    * 
    * @return The number of coefficients in the polynomial
    */
    const std::vector<double>& getCoefficients() const;

    /*
    * PreCondition: p_Deg must be a positive integer
    * PostCondition: set the degree to p_Deg
    * 
    * @param The integer to set as the degree
    */
    void setDegree(size_t p_Deg);

    /*
    * PreCondition: N/A
    * PostCondition: Return the highest degree of the polynomial
    * 
    * @return The highest degree of the polynomail as an integer
    */
    int getDegree() const;

    // operations

    /*
    * PreCondition: N/A
    * PostCondition: Return the simplified polynomial (no leading zeroes)
    * 
    * @return The simplified class
    */
    Polynomial simplify() const;

    /*
    * PreCondition: N/A
    * PostCondition: Return the negated polynomial (multiplied by -1)
    * 
    * @Return The class multiplied by -1
    */
    Polynomial negate() const;

    /*
    * PreCondition: X must be a double
    * PostCondition: Return the evaluated expression as a double
    * 
    * @param The double to evalualte the expression
    * @return The value of the polynomial when X is plugged in
    */
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