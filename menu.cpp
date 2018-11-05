/*******************************************************************
* Program Name:    CS 162 - Group Project - Predator-Prey Sim
* Author:          Group 8 (Astro)
* Date:            November 4, 2018
* Description:     Source file for Menu class that declares the
*                  Menu class and the mainMenu function and its
*                  options. It also contains a vector with all
*                  the menu options.
*******************************************************************/

#include <vector>
#include <string>
#include <iostream>
#include "menu.hpp"
#include "utils.hpp"
#include "game.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::to_string;
using std::vector;

/*******************************************************************
* Description: Constructor that creates a new menu object 
* Arguments:   No arguments
* Returns:     No return value
*******************************************************************/
Menu::Menu(){
	// Main menu options
	genMainMenuOpts();
	// End of game menu options
	endMenuOpts.push_back("Run again");
	endMenuOpts.push_back("Exit the program");
}

/*******************************************************************
* Description: Method that presents the user with a menu for the
*              simulation
* Arguments:   No arguments
* Returns:     An integer representing the exit code of the method
*              once the simulation is over
*******************************************************************/
int Menu::mainMenu() {
	// Prints the main menu until the user selects to play or quit
	string selStr = "";
	int sel = 0; 
	while (true) {
		switch (printMenuOpts(mainMenuOpts)) {
			//Set number of steps
			case 1 : {
				do {
					cout << "Enter the number of steps (1 - 999): ";
					getline(cin, selStr);
				}while (!intCheck(selStr, sel, 1, 999, true, true)); 
				game.setSteps(sel);
				break;
			}

			// Set number of grid rows
			case 2 : { 
				int minRows = (game.getStartNumAnts() + game.getStartNumDB())/game.getGridCols()+1;
				do {
					cout << "Enter the number of grid rows (" << minRows << " - 99): ";
					getline(cin, selStr);
				}while (!intCheck(selStr, sel, minRows, 99, true, true)); 
				game.setGridRows(sel);
				break;
			}

			// Set number of grid cols
			case 3 : { 
				int minCols = (game.getStartNumAnts() + game.getStartNumDB())/game.getGridRows()+1;
				do {
					cout << "Enter the number of grid cols (" << minCols << " - 99): ";
					getline(cin, selStr);
				}while (!intCheck(selStr, sel, minCols, 99, true, true)); 
				game.setGridCols(sel);
				break;
			}

			//Set number of Ants
			case 4 : {
				int maxAnts = game.getGridRows() * game.getGridCols() - game.getStartNumDB();
				do {
					cout << "Enter the number of ants (1 - " << maxAnts << "): ";
					getline(cin, selStr);
				}while (!intCheck(selStr, sel, 1, maxAnts, true, true)); 
				game.setStartNumAnts(sel);
				break;
			}

			// Set number of doodlebugs
			case 5 : {
				int maxDB = game.getGridRows() * game.getGridCols() - game.getStartNumAnts();
				do {
					cout << "Enter the number of doodlebugs (1 - " << maxDB << "): ";
					getline(cin, selStr);
				}while (!intCheck(selStr, sel, 1, maxDB, true, true)); 
				game.setStartNumDB(sel);
				break;
			}

			// Run the simulation
			case 6 : 
				game.runSim();
				if (endMenu() == 2) { return 0; }
				else { return 1; }
				cout << "Done with this round!" <<endl;

			// Exit the simulation
			case 7 : 
				return 0;
		}
		genMainMenuOpts(); //Refresh the values displayed to the user
	}
}

/*******************************************************************
* Description: Method that prompts the user to either play again or
*              quit
* Arguments:   No arguments
* Returns:     An integer reflecting the user's choice to either
*              continue or quit
*******************************************************************/
int Menu::endMenu() {
	while (true) {
		switch (printMenuOpts(endMenuOpts)) {
			case 1 : return 1; break;
			case 2 : return 2; break;
		}
	}
}

/*******************************************************************
* Description: Method that prompts the user to select one of the
*              menu options
* Arguments:   An integer holding the value of the number of
*              options in the menu
* Returns:     An integer reflecting the user's choice
*******************************************************************/
int Menu::userSelect(int numOpts) {
	int sel = 0; string selStr;
	do {
		cout << "Select an option: ";
		getline(cin, selStr);
	}while (!intCheck(selStr, sel, 1, numOpts, true, true)); 
	return sel;
}

/*******************************************************************
* Description: Method that iterates over the menu options and
*              displays a numbered list of the options
* Arguments:   A vector of strings holding the options for the menu
* Returns:     An integer reflecting the user's menu selection
*              obtained by calling the userSelect() method
*******************************************************************/
int Menu::printMenuOpts(vector<string> &vect){
	int i = 0;
	for (string &opt : vect) {
		cout << ++i << ". " << opt << endl;
	}
	return userSelect(i);
}

/*******************************************************************
* Description: Method that adds the relevant options to the vector
*              of strings used for the predator-prey simulation
*              menu
* Arguments:   No arguments
* Returns:     No return values
*******************************************************************/
void Menu::genMainMenuOpts() {
	vector<string>().swap(mainMenuOpts); //Clean out the vector
	mainMenuOpts.push_back("Set Number of Steps: " + to_string(game.getSteps()));
	mainMenuOpts.push_back("Set Number of Grid Rows: " + to_string(game.getGridRows()));
	mainMenuOpts.push_back("Set Number of Grid Cols: " + to_string(game.getGridCols()));
	mainMenuOpts.push_back("Set Number of Ants: " + to_string(game.getStartNumAnts()));
	mainMenuOpts.push_back("Set Number of DoodleBugs: " + to_string(game.getStartNumDB()));
	mainMenuOpts.push_back("Run the Simulation");
	mainMenuOpts.push_back("Exit the program");
}
