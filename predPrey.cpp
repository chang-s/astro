/*******************************************************************
** Program Name:    CS 162 - Group Project - Predator-Prey Sim
** Author:          Group 8
** Date:            November 4, 2018
** Description:     Program that allows the user to run a predator-
**                  prey simulation . The program is run by
**                  first compiling with "make" then typing
**                  "./predatorPreyGame". After that,
**                  the user can customize the simulation in terms
**                  of the size of the grid, the number of time
**                  steps to simulate, and the numbers of ants and
**                  doodlebugs to place on the board. The program
**                  ends when the user decides to quit.
*******************************************************************/

#include <iostream>
#include <ctime>
#include <random>
#include "game.hpp"
#include "menu.hpp"
#include "utils.hpp"

int main() {
	srand(time(0));

	//Extra credit acknowledgement
	printHorizontalBorder();
	std::string msg = "This is an acknowledgement that this\n";
	msg += "project includes extra credit tasks such\n";
	msg += "as options to set the size of the grid,\n";
	msg += "number of ants, and number of doodlebugs.";
	std::cout << msg << std::endl;
	printHorizontalBorder();
        std::cout << "Press enter to begin the simulation...";
        std::cin.get();
        
	//Start game with menu
	Menu predPreyMenu;
	while (predPreyMenu.mainMenu()) {}

	return 0;
}
