#pragma once
#include <string>
#include "EventSystem.h"
#include <memory>

class QuerySystem
{
public:

	void InitializeEventSystem(std::shared_ptr<EventSystem> p_EventSystem);

	//PreCondition: spaces (boolean true or false)
	//PostCondition: returns a std::string including space character(s) or without space character 
	void QueryString(const std::string& prompt, bool spaces);

	//PreCondition: valid std::string of options
	//PostCondition: returns an uppercase  of the option (char)
	void  QueryChar(const std::string& prompt, const std::string& options);

	//PreCondition: valid yes (char) or no (char)
	//PostCondition: returns an uppercase  yes (char) or no (char) 
	void  QueryChar(const std::string& prompt, char yes, char no);

	//PreCondition: alphaOrDigit (boolean true or false)
	//PostCondition: returns an alphabet or a digit character
	/*char inputChar(const std::string& prompt, bool alphaOrDigit)
	{
		char input;
		do
		{
			std::cout << prompt;
			if (!(std::cin >> input))
			{
				std::cout << "ERROR: Invalid input. Must be a character type.\n";
				std::cin.clear();
				std::cin.ignore(999, '\n');
			}
			else if (alphaOrDigit && !isalpha(input))
				std::cout << "ERROR: Invalid input. Must be an alphabet character.\n";
			else if (!alphaOrDigit && !isdigit(input))
				std::cout << "ERROR: Invalid input. Must be a digit character.\n";
			else
			{
				std::cin.clear();
				std::cin.ignore(999, '\n');
				break;
			}
		} while (true);
		return input;
	} 
	*/

	//PreCondition: NA
	//PostCondition: returns any character
	void  QueryChar(const std::string& prompt);

	//PreCondition: NA
	//PostCondition: returns any integer value
	void  QueryInteger(const std::string& prompt);

	//PreCondition: posNeg (boolean true or false)
	//PostCondition: returns a positive integer value (posNeg = true) or a negative integer value (poseNeg = false)
	void  QueryInteger(const std::string& prompt, bool posNeg);

	//PreCondition: start (integer) and greater (boolean true or false)
	//PostCondition: returns an integer value greater than start or lesser than start
	void  QueryInteger(const std::string& prompt, int start, bool greater);

	//PreCondition: startRange (integer) and endRange (integer)
	//PostCondition: returns an integer value within range (startRannge and endRange)
	void  QueryInteger(const std::string& prompt, int startRange, int endRange);

	//PreCondition: NA
	//PostCondition: returns any double value
	void  QueryDouble(const std::string& prompt);

	//PreCondition: posNeg (boolean true or false)
	//PostCondition: returns a positive double value (posNeg = true) or a negative double value (poseNeg = false)
	void  QueryDouble(const std::string& prompt, bool posNeg);

	//PreCondition: start(double) and greater(boolean true or false)
	//PostCondition: returns an double value greater than start or lesser than start
	void  QueryDouble(const std::string& prompt, double start, bool posNeg);

	//PreCondition: startRange (double) and endRange (double)
	//PostCondition: returns an double value within range (startRange and endRange)
	void  QueryDouble(const std::string& prompt, double startRange, double endRange);

	//PreCondition: NA
	//PostCondition: returns any float value
	void  QueryFloat(const std::string& prompt);

	//PreCondition: posNeg (boolean true or false)
	//PostCondition: returns a positive float value (posNeg = true) or a negative float value (poseNeg = false)
	void  QueryFloat(const std::string& prompt, bool posNeg);

	//PreCondition: start(integer) and greater(boolean true or false)
	//PostCondition: returns an float value greater than start or lesser than start
	void  QueryFloat(const std::string& prompt, float start, bool posNeg);

	//PreCondition: startRange (integer) and endRange (integer)
	//PostCondition: returns an float value within range (startRannge and endRange)
	void  QueryFloat(const std::string& prompt, float startRange, float endRange);

	// PreCondition: prompt is passed as an argument
	// PostCondition: returns a c-std::string date in the proper format
	void  QueryDate(const std::string& prompt);

private:
	std::shared_ptr<EventSystem> m_EventSystem;

};

