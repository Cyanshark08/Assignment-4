#include "ComplexNumberApp.h"

ComplexNumberApp::ComplexNumberApp()
	: m_ComplexPair(std::make_pair<Complex, Complex>(0.f, 0.f)),
	m_MenuState(SubMenuState::Selection)
{}

void ComplexNumberApp::Run()
{
	while (m_MenuState != SubMenuState::Exited)
	{

		std::system("cls");

		char input{ '\0' };
		switch (m_MenuState)
		{
		case SubMenuState::Selection:
			puts("\tA complex number is a number that can be expressed in the form a + b i, where a and b are real");
			puts("\tnumbers, and i represents the \"imaginary unit\", satisfying the equation i ^ 2 = -1. Because no");
			puts("\treal number satisfies this equation, i is called an imaginary number.For the complex number");
			puts("\ta + b i, a is called the real part and b is called the imaginary part.");
			puts("");
			puts("\t1 > Complex Numbers");
			printf("\t%s\n", std::string(110, 205).c_str());
			puts("\tA > A Complex Number");
			puts("\tB > Multiple Complex Numbers");
			printf("\t%s\n", std::string(110, 196).c_str());
			puts("\t0 > Return");
			printf("\t%s\n", std::string(110, 205).c_str());
			m_QuerySystem->QueryChar("\n\tOption: ", "AB0");
			break;
		case SubMenuState::Single:
			puts("\tA > A Complex Number");
			printf("\t%s\n", std::string(110, 205).c_str());
			puts("\t1. Enter the real number");
			puts("\t2. Enter the imaginary number");
			puts("\t3. Display the complex number");
			puts("\t4. Negate the complex number");
			puts("\t5. Add (+) the complex number with a constant");
			puts("\t6. Subtract (-) the complex number with a constant");
			puts("\t7. Multiply (*) the complex number with a constant");
			puts("\t8. Divide (/) the complex number with a constant");
			printf("\t%s\n", std::string(110, 196).c_str());
			puts("\t0. Return");
			printf("\t%s\n", std::string(110, 205).c_str());
			m_QuerySystem->QueryChar("\n\tOption: ", "123456780");
			break;
		case SubMenuState::Multiple:
			puts("\tB > Multiple Complex Numbers");
			printf("\t%s\n", std::string(110, 205).c_str());
			puts("\t1. Enter complex number C1");
			puts("\t2. Enter complex number C2");
			puts("\t3. Verify condition operators (== and != ) of C1 and C2");
			puts("\t4. Evaluate arithmatic operators (+, -, * and / ) of C1 and C2");
			puts("\t5. Evaluate steps in (3 * (C1 + C2) / 7) / (C2 - C1 / 9) != (1.07109 + 0.120832i) ?");
			printf("\t%s\n", std::string(110, 196).c_str());
			puts("\t0. Return");
			printf("\t%s\n", std::string(110, 205).c_str());
			m_QuerySystem->QueryChar("\n\tOption: ", "123450");
			break;
		}

		HandleInput(m_EventSystem->GetInput<char>());
	}
}

void ComplexNumberApp::Restart()
{
}

void ComplexNumberApp::Clean()
{
	m_ComplexSingle = Complex();
	m_ComplexPair = std::make_pair<Complex, Complex>(0.f, 0.f);
	m_MenuState = SubMenuState::Selection;
}

void ComplexNumberApp::HandleInput(char p_Input)
{
	switch (m_MenuState)
	{
	case SubMenuState::Selection:

		switch (p_Input)
		{
		case 'A':
			m_MenuState = SubMenuState::Single;
			break;
		case 'B':
			m_MenuState = SubMenuState::Multiple;
			break;
		case '0':
			m_MenuState = SubMenuState::Exited;
			break;
		}

		break;
	case SubMenuState::Single:
	{
		Complex C2;
		switch (p_Input)
		{

		case '1':
			m_QuerySystem->QueryFloat("\n\n\tEnter a Number (float value) for the Real Part: ");
			m_ComplexSingle.SetReal(m_EventSystem->GetInput<float>());
			break;
		case '2':
			m_QuerySystem->QueryFloat("\n\n\tEnter a Number (float value) for the Imaginary Part: ");
			m_ComplexSingle.SetImaginary(m_EventSystem->GetInput<float>());
			break;
		case '3':
			printf("\n\t%s\n\t", m_ComplexSingle.to_string().c_str());
			break;
		case '4':
			C2 = -m_ComplexSingle;
			printf("\n\t%s\n\t", C2.to_string().c_str());
			break;
		case '5':
			m_QuerySystem->QueryFloat("\n\tEnter a value: ");
			C2 = m_ComplexSingle + Complex(m_EventSystem->GetInput<float>());
			printf("\n\t%s\n\t", C2.to_string().c_str());
			break;
		case '6':
			m_QuerySystem->QueryFloat("\n\tEnter a value: ");
			C2 = m_ComplexSingle - Complex(m_EventSystem->GetInput<float>());
			printf("\n\t%s\n\t", C2.to_string().c_str());
			break;
		case '7':
			m_QuerySystem->QueryFloat("\n\tEnter a value: ");
			C2 = m_ComplexSingle * m_EventSystem->GetInput<float>();
			printf("\n\t%s\n\t", C2.to_string().c_str());
			break;
		case '8':
			m_QuerySystem->QueryFloat("\n\tEnter a value: ");
			C2 = m_ComplexSingle / m_EventSystem->GetInput<float>();
			printf("\n\t%s\n\t", C2.to_string().c_str());
			break;
		case '0':
			m_MenuState = SubMenuState::Selection;
			break;
		}

		if(m_MenuState != SubMenuState::Selection)
			std::system("pause");
	}

		break;
	case SubMenuState::Multiple:

		switch (p_Input)
		{
		case '1':
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			break;
		case '5':
			break;
		case '0':
			m_MenuState = SubMenuState::Selection;
			break;
		}

		break;
	}
}
