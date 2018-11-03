/*
 * predPrey.cpp
 * This is the main driver for the game
 */

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

	//Start game with menu
	Menu predPreyMenu;
	while (predPreyMenu.mainMenu()) {}

	return 0;
}
