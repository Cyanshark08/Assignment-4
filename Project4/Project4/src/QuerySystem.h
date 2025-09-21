#pragma once
#include <string>
#include "EventSystem.h"
#include <memory>

class QuerySystem
{
public:

	//PreCondition: N/A
	//PostCondition: Links the Query System to the proper Event System
	void LinkEventSystem(std::shared_ptr<EventSystem> p_EventSystem);

	//PreCondition: 
	// - spaces (boolean true or false)
	// - Event System must be linked
	//PostCondition: pushes an InputEvent as a (const char*) including space character(s) or without space character 
	void QueryString(const std::string& prompt, bool spaces);

	//PreCondition: 
	// - valid std::string of options
	// - Event System must be linked
	//PostCondition: pushes an InputEvent as an uppercase  of the option (char)
	void  QueryChar(const std::string& prompt, const std::string& options);

	//PreCondition: valid yes (char) or no (char)
	//PostCondition: pushes an Input Event as an uppercase [yes] (char) or [no] (char) 
	void  QueryChar(const std::string& prompt, char yes, char no);

	//PreCondition: 
	// - alphaOrDigit (boolean true or false)
	// - Event System must be linked
	//PostCondition: pushes an InputEvent as an alphabet or a digit character
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

	//PreCondition: 
	// - Event System must be linked
	//PostCondition: pushes an Input Event as any (char)
	void  QueryChar(const std::string& prompt);

	//PreCondition: 
	// - Event System must be linked
	//PostCondition: pushes an Input Event as any (int) value
	void  QueryInteger(const std::string& prompt);

	//PreCondition: 
	// - posNeg (boolean true or false)
	// - Event System must be linked
	//PostCondition: pushes an Input Event as a positive (int) value ([posNeg] = true) or a negative (int) value ([posNeg] = false)
	void  QueryInteger(const std::string& prompt, bool posNeg);

	//PreCondition: 
	// - start (integer) and greater (boolean true or false)
	// - Event System must be linked
	//PostCondition: pushes an Input Event as an integer value greater than [start] or lesser than [start]
	void  QueryInteger(const std::string& prompt, int start, bool greater);

	//PreCondition: 
	// - startRange (integer) and endRange (integer)
	// - Event System must be linked
	//PostCondition: pushes an Input Event as an (int) value within range [startRange] and [endRange]
	void  QueryInteger(const std::string& prompt, int startRange, int endRange);

	//PreCondition: 
	// - Event System must be linked
	//PostCondition: pushes an Input Event as any (double) value
	void  QueryDouble(const std::string& prompt);

	//PreCondition: 
	// - posNeg (boolean true or false)
	// - Event System must be linked
	//PostCondition: pushes an Input Event as a positive (double) value ([posNeg] = true) or a negative (double) value ([poseNeg] = false)
	void  QueryDouble(const std::string& prompt, bool posNeg);

	//PreCondition: 
	// - start(double) and greater(boolean true or false)
	// - Event System must be linked
	//PostCondition: pushes an Input Event as an (double) value greater than [start] or lesser than [start]
	void  QueryDouble(const std::string& prompt, double start, bool posNeg);

	//PreCondition: 
	// - startRange (double) and endRange (double)
	// - Event System must be linked
	//PostCondition: pushes an Input Event as an (double) value within range ([startRange] and [endRange])
	void  QueryDouble(const std::string& prompt, double startRange, double endRange);

	//PreCondition: 
	// - Event System must be linked
	//PostCondition: pushes an Input Event as any (float) value
	void  QueryFloat(const std::string& prompt);

	//PreCondition: 
	// - posNeg (boolean true or false)
	// - Event System must be linked
	//PostCondition: pushes an Input Event as a positive (float) value ([posNeg] = true) or a negative (float) value ([posNeg] = false)
	void  QueryFloat(const std::string& prompt, bool posNeg);

	//PreCondition: 
	// - start(integer) and greater(boolean true or false)
	// - Event System must be linked
	//PostCondition: pushes an Input Event as an (float) value greater than [start] or lesser than [start]
	void  QueryFloat(const std::string& prompt, float start, bool posNeg);

	//PreCondition: 
	// - startRange (integer) and endRange (integer)
	// - Event System must be linked
	//PostCondition: pushes an Input Event as an (float) value within range ([startRange] and [endRange])
	void  QueryFloat(const std::string& prompt, float startRange, float endRange);

	// PreCondition: 
	// - prompt is passed as an argument
	// - Event System must be linked
	// PostCondition: pushes an Input Event as a (const char*) date in the proper format
	void  QueryDate(const std::string& prompt);

private:
	std::shared_ptr<EventSystem> m_EventSystem;

};

