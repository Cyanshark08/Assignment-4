#pragma once
#include <stdint.h>
#include <string>

class Complex
{
public:
	Complex();
	Complex(float p_Real);
	Complex(float p_Real, float p_Imaginary);

	void SetReal(float p_Real);
	void SetImaginary(float p_Imaginary);

	float GetReal() const;
	float GetImaginary() const;

	Complex operator-() const;

	Complex operator+(const Complex& p_Other) const;
	Complex operator-(const Complex& p_Other) const;

	Complex operator+(float p_Other) const;
	Complex operator-(float p_Other) const;

	Complex& operator+=(const Complex& p_Other);
	Complex& operator-=(const Complex& p_Other);

	Complex operator*(const Complex& p_Other) const;
	Complex operator/(const Complex& p_Other) const;

	Complex& operator*=(const Complex& p_Other);
	Complex& operator/=(const Complex& p_Other);

	Complex operator*(float p_Other) const;
	Complex operator/(float p_Other) const;

	Complex& operator*=(float p_Other);
	Complex& operator/=(float p_Other);


	bool operator==(const Complex& p_Other) const;
	bool operator!=(const Complex& p_Other) const;

	std::string to_string() const;

private:
	float m_Real, m_Imaginary;

};

