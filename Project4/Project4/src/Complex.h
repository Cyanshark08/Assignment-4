#pragma once
#include <stdint.h>
#include <string>

class Complex
{
public:
	Complex();
	Complex(float p_Real);
	Complex(float p_Real, float p_Imaginary);

	//Precondition: None
	//Postcondition: Sets real part
	void SetReal(float p_Real);

	//Precondition: None
	//Postcondition: Sets imaginary part
	void SetImaginary(float p_Imaginary);

	//Precondition: None
	//Postcondition: Gets real part
	float GetReal() const;

	//Precondition: None
	//Postcondition: gets imaginary part
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

	//Precondition: None
	//Postcondition: returns complex number as an std::string
	std::string to_string() const;

private:
	float m_Real, m_Imaginary;

};

