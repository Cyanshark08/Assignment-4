#include "RationalNumberApp.h"


RationalNumberApp::RationalNumberApp()
{
	m_MenuState = SubMenuState::Selection;
}

void RationalNumberApp::Run()
{
	while (m_MenuState != SubMenuState::Exited)
	{
		std::system("cls");
		char input{ '\0' };

		switch (m_MenuState)
		{
		case SubMenuState::Selection: // display sub menu for selection
			std::cout << "\n\tA rational number is a number that can be written as a fraction, a/b, where a is numerator and";
			std::cout << "\n\tb is denominator. Rational numbers are all real numbers, and can be positive or negative. A";
			std::cout << "\n\tnumber that is not rational is called irrational. Most of the numbers that people use in everyday";
			std::cout << "\n\tlife are rational.These include fractions, integers and numbers with finite decimal digits.";
			std::cout << "\n\tIn general, a number that can be written as a fraction while it is in its own form is rational.";

			std::cout << "\n\n\t2. Rational Numbers Menu";
			std::cout << "\n\t" << std::string(110, 205);
			std::cout << "\n\t\tA. A Rational Number";
			std::cout << "\n\t\tB. Multiple Rational Numbers";
			std::cout << "\n\t" << std::string(110, 196);
			std::cout << "\n\t\t0. Return";
			std::cout << "\n\t" << std::string(110, 205);
			m_QuerySystem->QueryChar("\n\t\tOption: ", "AB0");
			break;

		case SubMenuState::Single: // single rational number menu
			std::cout << "\n\tA. A Rational Number";
			std::cout << "\n\t" << std::string(110, 205);
			std::cout << "\n\t\t1. Enter the numerator";
			std::cout << "\n\t\t2. Enter the denominator";
			std::cout << "\n\t\t3. Display the rational number";
			std::cout << "\n\t\t4. Simplify the rational number";
			std::cout << "\n\t\t5. Negate the rational number";
			std::cout << "\n\t\t6. Add (+) the rational number with a constant";
			std::cout << "\n\t\t7. Subtract (-) the rational number with a constant";
			std::cout << "\n\t\t8. Multiply (*) the rational number with a constant";
			std::cout << "\n\t\t9. Divide (/) the rational number with a constant";
			std::cout << "\n\t" << std::string(110, 196);
			std::cout << "\n\t\t0. Return";
			std::cout << "\n\t" << std::string(110, 205);
			m_QuerySystem->QueryChar("\n\t\tOption: ", "0123456789");
			break;

		case SubMenuState::Multiple: // multiple rational numbers menu
			std::cout << "\n\tB. Multiple Rational Numbers";
			std::cout << "\n\t" << std::string(110, 205);
			std::cout << "\n\t\t1. Enter rational number R1";
			std::cout << "\n\t\t2. Enter rational number R2";
			std::cout << "\n\t\t3. Verify condition operators (==, !=, >=, >, <= and <) of R1 and R2";
			std::cout << "\n\t\t4. Evaluate arithmetic operators (+, - , * and /) of R1 and R2";
			std::cout << "\n\t\t5. Evaluate (3 * (R1 + R2) / 7) / (R2 - R1 / 9) >= 621/889";
			std::cout << "\n\t" << std::string(110, 196);
			std::cout << "\n\t\t0. Return";
			std::cout << "\n\t" << std::string(110, 205);
			m_QuerySystem->QueryChar("\n\tOption: ", "123450");
			break;
		}

		HandleInput(m_EventSystem->GetInput<char>());
	}
}

void RationalNumberApp::Restart()
{
}

void RationalNumberApp::Clean()
{
	m_Rational1 = Rational();
	m_Rational2 = Rational();
	m_MenuState = SubMenuState::Selection;
}

void RationalNumberApp::HandleInput(char p_Input)
{
	switch (m_MenuState)
	{
	case SubMenuState::Selection:

		switch (p_Input)
		{
		case 'A': // single
			m_MenuState = SubMenuState::Single;
			break;
		case 'B': // multiple
			m_MenuState = SubMenuState::Multiple;
			break;
		case '0': // return
			m_MenuState = SubMenuState::Exited;
			break;
		}
		break;

	case SubMenuState::Single:
	{
		Rational R2;
		switch (p_Input)
		{

		case '1': // set numerator
			// get the integer to set as the numerator
			m_QuerySystem->QueryInteger("\n\tEnter an integer for the numerator: ");
			m_Rational1.setNumerator(m_EventSystem->GetInput<int>());
			std::cout << "\n\tSuccessfully set the numerator";
			break;

		case '2': // set denominator
			// get the integer to set ast the denominator
			m_QuerySystem->QueryInteger("\n\tEnter an integer for the denominator: ");
			m_Rational1.setDenominator(m_EventSystem->GetInput<int>());
			std::cout << "\n\tSuccessfully set the denominator";
			break;

		case '3': // display the rational number
			std::cout << "\n\tRational number R1 = " << m_Rational1;
			break;

		case '4': // normalize the rational number
			R2 = m_Rational1.simplify();
			std::cout << "\n\tNormalized rational number R2 (copy of R1): ";
			std::cout << "\n\n\t" << R2;
			break;

		case '5': // negate the rational number
			R2 = m_Rational1.negate();
			std::cout << "\n\tNegated rational number R2 (copy of R1):";
			std::cout << "\n\n\t-(" << m_Rational1 << ") = " << R2;
			break;

		case '6': // add with a constant
		{
			R2 = m_Rational1;
			// get the integer to add
			m_QuerySystem->QueryInteger("\n\tEnter an integer value: ");
			int32_t value = m_EventSystem->GetInput<int>();
			Rational temp(value, 1);

			std::cout << "\n\n\tR2 + Value: ";
			std::cout << "\n\t(" << R2 << ") + (" << value << ") = " << R2 + temp;

			std::cout << "\n\n\tValue + R2: ";
			std::cout << "\n\t(" << value << ") + (" << R2 << ") = " << temp + R2;
			break;
		}
		case '7': // subtract with a constant
		{
			R2 = m_Rational1;
			// get the integer to subtract
			m_QuerySystem->QueryInteger("\n\tEnter an integer value: ");
			int32_t value = m_EventSystem->GetInput<int>();
			Rational temp(value, 1);

			std::cout << "\n\n\tR2 - Value: ";
			std::cout << "\n\t(" << R2 << ") - (" << value << ") = " << R2 - temp;

			std::cout << "\n\n\tValue - R2: ";
			std::cout << "\n\t(" << value << ") - (" << R2 << ") = " << temp - R2;
			break;
		}
		case '8': // multiply with a constant
		{
			R2 = m_Rational1;
			// get the integer to multiply
			m_QuerySystem->QueryInteger("\n\tEnter an integer value: ");
			int32_t value = m_EventSystem->GetInput<int>();
			Rational temp(value, 1);

			std::cout << "\n\n\tR2 * Value: ";
			std::cout << "\n\t(" << R2 << ") * (" << value << ") = " << R2 * temp;

			std::cout << "\n\n\tValue * R2: ";
			std::cout << "\n\t(" << value << ") * (" << R2 << ") = " << temp * R2;
			break;
		}
		case '9': // divide with a constant
		{
			R2 = m_Rational1;
			// get the integer to divide
			m_QuerySystem->QueryInteger("\n\tEnter an integer value: ");
			int32_t value = m_EventSystem->GetInput<int>();
			Rational temp(value, 1);

			std::cout << "\n\n\tR2 / Value: ";
			std::cout << "\n\t(" << R2 << ") / " << value << " = " << R2 / temp;

			std::cout << "\n\n\tValue / R2: ";
			std::cout << "\n\t" << value << " / (" << R2 << ") = " << temp / R2;
			break;
		}
		case '0': // return
			m_MenuState = SubMenuState::Selection;
			break;
		}

		if (m_MenuState != SubMenuState::Selection)
		{
			std::cout << "\n\n";
			std::system("pause");
		}
		break;
	}
	case SubMenuState::Multiple:
	{
		break;
	}
	}
}