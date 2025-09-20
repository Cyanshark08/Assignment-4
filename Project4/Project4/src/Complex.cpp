#include "Complex.h"
#include <sstream>
#include <iomanip>

Complex::Complex()
    : m_Real(0.f),
    m_Imaginary(0.f)
{}

Complex::Complex(float p_Real)
    : m_Real(p_Real),
    m_Imaginary(0.f)
{
}

Complex::Complex(float p_Real, float p_Imaginary)
    : m_Real(p_Real),
    m_Imaginary(p_Imaginary)
{}

void Complex::SetReal(float p_Real)
{
    m_Real = p_Real;
}

void Complex::SetImaginary(float p_Imaginary)
{
    m_Imaginary = p_Imaginary;
}

float Complex::GetReal() const
{
    return m_Real;
}

float Complex::GetImaginary() const
{
    return m_Imaginary;
}

Complex Complex::operator-() const
{
    return Complex(-m_Real, -m_Imaginary);
}

Complex Complex::operator+(const Complex& p_Other) const
{
    return Complex(m_Real + p_Other.m_Real, m_Imaginary + p_Other.m_Imaginary);
}
Complex Complex::operator-(const Complex& p_Other) const
{
    return Complex(m_Real - p_Other.m_Real, m_Imaginary - p_Other.m_Imaginary);
}

Complex& Complex::operator+=(const Complex& p_Other)
{
    this->m_Real += p_Other.m_Real;
    this->m_Imaginary += p_Other.m_Imaginary;
    return *this;
}
Complex& Complex::operator-=(const Complex& p_Other)
{
    this->m_Real -= p_Other.m_Real;
    this->m_Imaginary -= p_Other.m_Imaginary;
    return *this;
}

Complex Complex::operator*(const Complex& p_Other) const
{
    return Complex(m_Real * p_Other.m_Real - m_Imaginary * p_Other.m_Imaginary, m_Real * p_Other.m_Imaginary + m_Imaginary * p_Other.m_Real);
}
Complex Complex::operator/(const Complex& p_Other) const
{
    return Complex((m_Real * p_Other.m_Real + m_Imaginary * p_Other.m_Imaginary) / (p_Other.m_Real * p_Other.m_Real + p_Other.m_Imaginary * p_Other.m_Imaginary),
                   (m_Imaginary * p_Other.m_Real - m_Real * p_Other.m_Imaginary) / (p_Other.m_Real * p_Other.m_Real + p_Other.m_Imaginary * p_Other.m_Imaginary));
}

Complex& Complex::operator*=(const Complex& p_Other)
{
    this->m_Real = m_Real * p_Other.m_Real - m_Imaginary * p_Other.m_Imaginary;
    this->m_Imaginary = m_Real * p_Other.m_Imaginary + m_Imaginary * p_Other.m_Real;
    return *this;
}

Complex& Complex::operator/=(const Complex& p_Other)
{
    this->m_Real = (m_Real * p_Other.m_Real + m_Imaginary * p_Other.m_Imaginary) / (p_Other.m_Real * p_Other.m_Real + p_Other.m_Imaginary * p_Other.m_Imaginary);
    this->m_Imaginary = (m_Imaginary * p_Other.m_Real - m_Real * p_Other.m_Imaginary) / (p_Other.m_Real * p_Other.m_Real + p_Other.m_Imaginary * p_Other.m_Imaginary);
    return *this;
}

Complex Complex::operator*(float p_Other) const
{
    return Complex(m_Real * p_Other, m_Imaginary * p_Other);
}

Complex Complex::operator/(float p_Other) const
{
    return Complex(m_Real / p_Other, m_Imaginary / p_Other);
}

Complex& Complex::operator*=(float p_Other)
{
    this->m_Real *= p_Other;
    this->m_Imaginary *= p_Other;
    return *this;
}

Complex& Complex::operator/=(float p_Other)
{
    this->m_Real /= p_Other;
    this->m_Imaginary /= p_Other;
    return *this;
}

std::string Complex::to_string() const
{
    std::stringstream ss;

    ss << std::fixed << std::setprecision(2) << m_Real;
    ss << std::fixed << std::setprecision(2) << (m_Imaginary >= 0 ? " + " : " - ") << std::fabsf(m_Imaginary) << "i";

    return ss.str();
}
