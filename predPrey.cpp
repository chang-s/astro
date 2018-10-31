/*
 * predPrey.cpp
 * This is the main driver for the game
 */

#include <iostream>
#include <ctime>
#include <random>
#include "game.hpp"
#include "menu.hpp"

int main() {
	srand(time(NULL));
	Menu predPreyMenu;
	while (predPreyMenu.mainMenu()) {}

	std::cout << "About to exit" << std::endl;
	return 0;
}
