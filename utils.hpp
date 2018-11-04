/*******************************************************************
** Program Name:    CS 162 - Group Project - Predatory-Prey Sim
** Author:          Group 8
** Date:            November 4, 2018
** Description:     Header file for Utils class that contains a 
**                  compilation of reusables pieces of code,
**                  including methods for input validation.
*******************************************************************/

#ifndef UTILS_HPP
#define UTILS_HPP

#include <climits>
#include <string>

using std::string;

bool floatCheck(string &str, float &retFloat, float MIN_NUM, float MAX_NUM, bool canEqlMin = 0, bool canEqlMax = 0);
bool intCheck(string &str, int &retInt, int MIN_NUM = INT_MIN, int MAX_NUM = INT_MAX, bool canEqlMin = 0, bool canEqlMax = 0);
bool yesOrNo(string qn);
void printHorizontalBorder(int width = 40, char spacer = '=');

#endif
