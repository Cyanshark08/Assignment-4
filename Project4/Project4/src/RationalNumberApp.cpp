#include "RationalNumberApp.h"

void RationalNumberApp::Run()
{
}

void RationalNumberApp::Restart()
{
	this->Clean();
}

void RationalNumberApp::Clean()
{
	numerator = 0;
	denominator = 1;
}

RationalNumberApp::RationalNumberApp()
{
	numerator = 0;
	denominator = 1;
}

RationalNumberApp::RationalNumberApp(int32_t n, int32_t d)
{
	if (d == 0)
		throw E_InvalidDenominator(n, d);

	numerator = n;
	denominator = d;
}

RationalNumberApp::RationalNumberApp(const RationalNumberApp &obj)
{
	this->numerator = obj.numerator;
	this->denominator = obj.denominator;
}


void RationalNumberApp::setNumerator(int n)
{
	numerator = n;
}

int32_t RationalNumberApp::getNumerator() const
{
	return numerator;
}

void RationalNumberApp::setDenominator(int d)
{
	if (d == 0)
		throw E_InvalidDenominator(numerator, d);
	denominator = d;
}

int32_t RationalNumberApp::getDenominator() const
{
	return denominator;
}

RationalNumberApp RationalNumberApp::simplify() const
{
	RationalNumberApp temp;
	int32_t gcd = RationalNumberApp::gcd(numerator, denominator);

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

RationalNumberApp RationalNumberApp::negate() const
{
	return RationalNumberApp(numerator * -1, denominator);
}

int32_t RationalNumberApp::gcd(int32_t x, int32_t y) const
{
	if (x % y == 0)
		return y;
	else
		return gcd(y, x % y);
}

RationalNumberApp RationalNumberApp::operator +(const RationalNumberApp &right) const
{
	RationalNumberApp temp;
	temp.numerator = (this->numerator * right.denominator) + (this->denominator * right.numerator);
	temp.denominator = this->denominator * right.denominator;

	return temp.simplify();
}

RationalNumberApp RationalNumberApp::operator -(const RationalNumberApp &right) const
{
	RationalNumberApp temp;

	// multiply the numerator by the denominator, then subtract the numerators
	temp.numerator = (this->numerator * right.denominator) - (this->denominator * right.numerator);
	temp.denominator = this->denominator * right.denominator;

	return temp.simplify();
}

RationalNumberApp RationalNumberApp::operator *(const RationalNumberApp &right) const
{
	RationalNumberApp temp;
	temp.numerator = this->numerator * right.numerator;
	temp.denominator = this->denominator * right.denominator;

	return temp.simplify();
}

RationalNumberApp RationalNumberApp::operator /(const RationalNumberApp &right) const
{
	RationalNumberApp temp;

	// multiply by the reciprocal
	temp.numerator = this->numerator * right.denominator;
	temp.denominator = this->denominator * right.numerator;

	if (temp.denominator == 0)
		throw E_InvalidDenominator(temp.numerator, temp.denominator);

	return temp.simplify();
}

bool RationalNumberApp::operator ==(const RationalNumberApp &right) const
{
	return this->numerator * right.denominator == this->denominator * right.numerator;
}

bool RationalNumberApp::operator !=(const RationalNumberApp &right) const
{
	return this->numerator * right.denominator != this->denominator * right.numerator;
}

bool RationalNumberApp::operator >=(const RationalNumberApp &right) const
{
	return this->numerator * right.denominator >= this->denominator * right.numerator;
}

bool RationalNumberApp::operator >(const RationalNumberApp &right) const
{
	return this->numerator * right.denominator > this->denominator * right.numerator;
}

bool RationalNumberApp::operator <=(const RationalNumberApp &right) const
{
	return this->numerator * right.denominator <= this->denominator * right.numerator;
}

bool RationalNumberApp::operator <(const RationalNumberApp &right) const
{
	return this->numerator * right.denominator < this->denominator * right.numerator;
}

void RationalNumberApp::HandleInput(char p_Input)
{
}

// exceptions
RationalNumberApp::E_InvalidDenominator::E_InvalidDenominator(int32_t n, int32_t d)
{
	numerator = n;
	denominator = d;
}

std::string RationalNumberApp::E_InvalidDenominator::getNumber() const
{
	return std::to_string(numerator) + "/" + std::to_string(denominator);
}

inline std::string RationalNumberApp::E_InvalidDenominator::GetExceptionName() const
{
	return "Invalid denominator";
}

inline std::string RationalNumberApp::E_InvalidDenominator::GetExceptionMessage() const
{
	return "(" + getNumber() + ") is invalid.";
}


