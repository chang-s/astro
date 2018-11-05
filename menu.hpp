/*******************************************************************
* Program Name:    CS 162 - Group Project - Predator-Prey Sim
* Author:          Group 8 (Astro)
* Date:            November 4, 2018
* Description:     Header file for Menu class that declares the
*                  Menu class and the mainMenu function and its
*                  options. It also contains a vector with all
*                  the menu options.
*******************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>
#include "game.hpp"

using std::vector; 
using std::string;

class Menu {
	private:
		Game game;
		vector<string> mainMenuOpts;
		vector<string> endMenuOpts;

	public:
		Menu();
		int mainMenu();
		int endMenu();
		int userSelect(int numOpts);
		int printMenuOpts(vector<string> &vect);
		void genMainMenuOpts(); // Needed to refresh values displayed
};

#endif
