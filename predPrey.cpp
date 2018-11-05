/*******************************************************************
* Program Name:    CS 162 - Group Project - Predator-Prey Sim
* Author:          Group 8 (Astro)
* Date:            November 4, 2018
* Description:     Program that allows the user to run a predator-
*                  prey simulation . The program is run by
*                  first compiling with "make" then typing
*                  "./predatorPreyGame". After that,
*                  the user can customize the simulation in terms
*                  of the size of the grid, the number of time
*                  steps to simulate, and the numbers of ants and
*                  doodlebugs to place on the board. The program
*                  ends when the user decides to quit.
*******************************************************************/

#include <iostream>
#include <ctime>
#include <random>
#include "game.hpp"
#include "menu.hpp"
#include "utils.hpp"

int main() {
	srand(time(0));

	// Extra credit acknowledgement
	printHorizontalBorder();
	std::cout
		<< "This is an acknowledgement that this\n"
		<< "project includes extra credit tasks such\n"
		<< "as options to set the size of the grid,\n"
		<< "number of ants, and number of doodlebugs.";
	printHorizontalBorder();
        std::cout << "Press enter to begin the simulation...";
        std::cin.get();
        
	// Start game with menu
	Menu predPreyMenu;
	while (predPreyMenu.mainMenu()) {}

	return 0;
}
