#pragma once

#include "SubApp.h"
#include <string>

class RationalNumberApp :
    public SubApp
{
public:
	// constructors
	RationalNumberApp();
	RationalNumberApp(int32_t n, int32_t d);
	RationalNumberApp(const RationalNumberApp &obj);

	void Run() override;
	void Restart() override;
	void Clean() override;

	void setNumerator(int n);
	void setDenominator(int d);
	int32_t getNumerator() const;
	int32_t getDenominator() const;

	RationalNumberApp simplify() const;
	RationalNumberApp negate() const;
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
	RationalNumberApp operator +(const RationalNumberApp &right) const;
	RationalNumberApp operator -(const RationalNumberApp &right) const;
	RationalNumberApp operator *(const RationalNumberApp &right) const;
	RationalNumberApp operator /(const RationalNumberApp &right) const;
	bool operator ==(const RationalNumberApp &right) const;
	bool operator !=(const RationalNumberApp &right) const;
	bool operator >=(const RationalNumberApp &right) const;
	bool operator >(const RationalNumberApp &right) const;
	bool operator <=(const RationalNumberApp &right) const;
	bool operator <(const RationalNumberApp &right) const;




private:
	int32_t numerator;
	int32_t denominator;

	int32_t gcd(int32_t x, int32_t y) const;
	void HandleInput(char p_Input) override;
};

