/*******************************************************************
** Program Name:    CS 162 - Group Project - Predator-Prey Sim
** Author:          Group 8
** Date:            November 4, 2018
** Description:     Source file for Utils class that contains a 
**                  compilation of reusables pieces of code,
**                  including methods for input validation.
*******************************************************************/

#include "utils.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include <climits>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;
using std::setfill;
using std::setw;
using std::cerr;
using std::string;
using std::getline;
using std::ifstream;
using std::ofstream;
using std::time;
using std::srand;

/*******************************************************************
** Description: Method that checks if a string is a float and if it
**              is within a certain value range
** Arguments:   An input string, a reference to a float, two floats
**              holding the minimum and maximum values, and two
**              booleans indicating whether the value can equal the
**              min or max value
** Returns:     Return true if valid float; false otherwise
*******************************************************************/
bool floatCheck(string &str, float &retFloat, float MIN_NUM, float MAX_NUM, bool canEqlMin, bool canEqlMax)
{
	bool badVal = false;
	retFloat = 0.0;
	std::size_t* pos = new std::size_t;
	try	{
		retFloat = stof(str, pos);
		if (*pos != str.length()) {
			badVal = true;
			throw std::invalid_argument("parse fail");
		} if (retFloat < MIN_NUM || (retFloat == MIN_NUM && !canEqlMin)) {
			badVal = true;
			cout << "Error: Number too small." << endl;
		} else if (retFloat > MAX_NUM || (retFloat == MAX_NUM && !canEqlMax)) {
			badVal = true;
			cout << "Error: Number too large." << endl;
		}
	} catch (std::out_of_range& e) {
		badVal = true;
		cerr << "Error: Number is out of range." << endl;
	} catch (std::invalid_argument& e) {
		badVal = true;
		cerr << "Error: Not a valid number." << endl;
	} catch (...) {
		badVal = true;
		cout << "Invalid entry." << endl;
	}
	delete pos;
	if (badVal) { return false; }
	return true;
}

/*******************************************************************
** Description: Method that checks if a string is an int and if it
**              is within a certain value range
** Arguments:   An input string, a reference to a int, two ints
**              holding the minimum and maximum values, and two
**              booleans indicating whether the value can equal the
**              min or max value
** Returns:     Return true if valid int; false otherwise
*******************************************************************/
bool intCheck(string &str, int &retInt, int MIN_NUM, int MAX_NUM, bool canEqlMin, bool canEqlMax)
{
	bool badVal = false;
	retInt = 0;
	std::size_t* pos = new std::size_t;
	try	{
		retInt = stoi(str, pos);
		if (*pos != str.length()) {
			badVal = true;
			throw std::invalid_argument("parse fail");
		} else if (retInt < MIN_NUM || (retInt == MIN_NUM && !canEqlMin)) {
			badVal = true;
			cout << "Error: Number too small." << endl;
		} else if (retInt > MAX_NUM || (retInt == MAX_NUM && !canEqlMax)) {
			badVal = true;
			cout << "Error: Number too large." << endl;
		} 
	} catch (std::out_of_range& e) {
		badVal = true;
		cerr << "Error: Number is out of range." << endl;
	} catch (std::invalid_argument& e) {
		badVal = true;
		cerr << "Error: Not a valid number." << endl;
	} catch (...) {
		badVal = true;
		cout << "Invalid entry." << endl;
	}
	delete pos;
	if (badVal) { return false; }
	return true;
}

/*******************************************************************
** Description: Method that prompts a user with a yes/no question
**              and obtains a valid response
** Arguments:   A string holding the question
** Returns:     Return true if "yes"; false if "no"
*******************************************************************/
bool yesOrNo(string question) {
	string response = "";
	do {
		cout << question << " (y/n) ";
		getline(cin, response);
	} while(response != "y" && response != "n");

	if (response == "y") { return true; }
	else { return false; }
}

/*******************************************************************
** Description: Method that prints a horizontal border
** Arguments:   An int indicating how wide the border should be and
*               a char indicating the character to print
** Returns:     No return value
*******************************************************************/
void printHorizontalBorder(int width, char spacer) {
	cout << setfill(spacer) << setw(width) << "" << endl;
	cout << setfill(' ');
	return;
}
