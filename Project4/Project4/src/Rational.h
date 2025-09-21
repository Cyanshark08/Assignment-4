#pragma once
#include "ExceptionInterface.h"
#include <string>

class Rational
{
public:
	// constructors
	Rational();
	Rational(int32_t n, int32_t d);
	Rational(const Rational &obj);

	void setNumerator(int n);
	void setDenominator(int d);
	int32_t getNumerator() const;
	int32_t getDenominator() const;

	Rational simplify() const;
	Rational negate() const;
	std::string to_string() const;

	// exceptions
	class E_InvalidDenominator : public ExceptionInterface
	{
	public:
		E_InvalidDenominator(int32_t n, int32_t d);
		std::string getNumber() const;

	private:
		int32_t numerator;
		int32_t denominator;

		std::string GetExceptionName() const override;
		std::string GetExceptionMessage() const override;
	};

	// overloaded operators
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
	int32_t gcd(int32_t x, int32_t y) const;

private:
	int32_t numerator;
	int32_t denominator;
};

