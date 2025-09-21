#include "Rational.h"

Rational::Rational()
{
	numerator = 0;
	denominator = 1;
}

Rational::Rational(int32_t n, int32_t d)
{
	if (d == 0)
		throw E_InvalidDenominator(n, d);

	numerator = n;
	denominator = d;
}

Rational::Rational(const Rational &obj)
{
	this->numerator = obj.numerator;
	this->denominator = obj.denominator;
}


void Rational::setNumerator(int n)
{
	numerator = n;
}

int32_t Rational::getNumerator() const
{
	return numerator;
}

void Rational::setDenominator(int d)
{
	if (d == 0)
		throw E_InvalidDenominator(numerator, d);
	denominator = d;
}

int32_t Rational::getDenominator() const
{
	return denominator;
}

Rational Rational::simplify() const
{
	Rational temp;
	int32_t gcd = Rational::gcd(numerator, denominator);

	temp.numerator = this->numerator / gcd;
	temp.denominator = this->denominator / gcd;

	// move negative to top
	if (temp.denominator < 0)
	{
		temp.numerator *= -1;
		temp.denominator *= -1;
	}

	return temp;
}

Rational Rational::negate() const
{
	return Rational(numerator * -1, denominator);
}

int32_t Rational::gcd(int32_t x, int32_t y) const
{
	if (x % y == 0)
		return y;
	else
		return gcd(y, x % y);
}

Rational Rational::operator +(const Rational &right) const
{
	Rational temp;
	temp.numerator = (this->numerator * right.denominator) + (this->denominator * right.numerator);
	temp.denominator = this->denominator * right.denominator;

	return temp.simplify();
}

Rational Rational::operator -(const Rational &right) const
{
	Rational temp;

	// multiply the numerator by the denominator, then subtract the numerators
	temp.numerator = (this->numerator * right.denominator) - (this->denominator * right.numerator);
	temp.denominator = this->denominator * right.denominator;

	return temp.simplify();
}

Rational Rational::operator *(const Rational &right) const
{
	Rational temp;
	temp.numerator = this->numerator * right.numerator;
	temp.denominator = this->denominator * right.denominator;

	return temp.simplify();
}

Rational Rational::operator /(const Rational &right) const
{
	Rational temp;

	// multiply by the reciprocal
	temp.numerator = this->numerator * right.denominator;
	temp.denominator = this->denominator * right.numerator;

	if (temp.denominator == 0)
		throw E_InvalidDenominator(temp.numerator, temp.denominator);

	return temp.simplify();
}

bool Rational::operator ==(const Rational &right) const
{
	return this->numerator * right.denominator == this->denominator * right.numerator;
}

bool Rational::operator !=(const Rational &right) const
{
	return this->numerator * right.denominator != this->denominator * right.numerator;
}

bool Rational::operator >=(const Rational &right) const
{
	return this->numerator * right.denominator >= this->denominator * right.numerator;
}

bool Rational::operator >(const Rational &right) const
{
	return this->numerator * right.denominator > this->denominator * right.numerator;
}

bool Rational::operator <=(const Rational &right) const
{
	return this->numerator * right.denominator <= this->denominator * right.numerator;
}

bool Rational::operator <(const Rational &right) const
{
	return this->numerator * right.denominator < this->denominator * right.numerator;
}



// exceptions
Rational::E_InvalidDenominator::E_InvalidDenominator(int32_t n, int32_t d)
{
	numerator = n;
	denominator = d;
}

std::string Rational::E_InvalidDenominator::getNumber() const
{
	return std::to_string(numerator) + "/" + std::to_string(denominator);
}

inline std::string Rational::E_InvalidDenominator::GetExceptionName() const
{
	return "Invalid denominator";
}

inline std::string Rational::E_InvalidDenominator::GetExceptionMessage() const
{
	return "(" + getNumber() + ") is invalid.";
}


