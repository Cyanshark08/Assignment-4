#pragma once
#include "ExceptionInterface.h"
#include <iostream>
#include <string>

class Rational
{
public:
	// constructors

	/*
	* PreCondition: N/A
	* PostCondition: initialize numerator and denominator to default values
	*/
	Rational();

	/*
	* PreCondition: n and d must be integers
	* PostCondition: set the numerator to n and denominator to d
	* 
	* @param The integers to set as the numerator and denominator, respectively
	*/
	Rational(int32_t n, int32_t d);

	/*
	* PreCondition: Rational object is passed
	* PostCondition: copy the numerator and denominator of the passed object to the current object
	* 
	* @param The Rational object to copy
	*/
	Rational(const Rational &obj);

	/*
	* PreCondition: N must be an integer
	* PostCondition: set the numerator to n
	* 
	* @param The ingeger to set as the numerator
	*/
	void setNumerator(int n);

	/*
	* PreCondition: D must be an integer
	* PostCondition: set the denominator to d
	* 
	* @param The integer to set as the denominator
	*/
	void setDenominator(int d);

	/*
	* PreCondition: N/A
	* PostCondition: Return the numerator
	* 
	* @return The denominator as an integer
	*/
	int32_t getNumerator() const;

	/*
	* PreCondition: N/A
	* PostCondition: Return the denominator
	* 
	* @return the denominator as an integer
	*/
	int32_t getDenominator() const;

	/*
	* PreCondition: N/A
	* PostCondition: Return the simplified version of the Rational object
	* 
	* @return The simplified Rational object
	*/
	Rational simplify() const;

	/*
	* PreCondition: N/A
	* PostCondition: Return the Rational object multiplied by -1
	* 
	* @return The Rational object multiplied by -1
	*/
	Rational negate() const;

	// overloaded operators
	friend std::ostream &operator <<(std::ostream &out, const Rational &obj);
	Rational &operator =(const Rational &right);
	Rational operator +(const Rational &right) const;
	Rational operator -(const Rational &right) const;
	Rational operator *(const Rational &right) const;
	Rational operator /(const Rational &right) const;
	bool operator ==(const Rational &right) const;
	bool operator !=(const Rational &right) const;
	bool operator >=(const Rational &right) const;
	bool operator >(const Rational &right) const;
	bool operator <=(const Rational &right) const;
	bool operator <(const Rational &right) const;

private:

	/*
	* PreCondition: X and Y must be non-zero integers
	* PostCondition: Return the greatest common multiple of the two integers
	* 
	* @param The two integers to take the greatest common denominator
	* @return The greatest common denominator
	*/
	int32_t gcd(int32_t x, int32_t y) const;

private:
	int32_t numerator;
	int32_t denominator;
};

