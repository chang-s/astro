/*******************************************************************
* Program Name:    CS 162 - Group Project - Predator-Prey Sim
* Author:          Group 8 (Astro)
* Date:            November 4, 2018
* Description:     Source file for Game class, which manges the
*                  logic of the predator-prey simulation.
*******************************************************************/

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include "game.hpp"
#include "critter.hpp"
#include "ant.hpp"
#include "db.hpp"
#include "utils.hpp"

using std::cout;
using std::endl;
using std::to_string;
using std::setw;
using std::left;
using std::vector;
using std::rand;

/*******************************************************************
* Description: Constructor that creates a new game object 
* Arguments:   No arguments
* Returns:     No return value
*******************************************************************/
Game::Game() { 
	this->userSteps = 100;
	this->gridRows = 20;
	this->gridCols = 20;
	this->startNumAnts = 100;
	this->startNumDB = 5;
	grid = nullptr;
}

/*******************************************************************
* Description: Destructor that frees the memory allocated for the
*              grid
* Arguments:   No arguments
* Returns:     No return value
*******************************************************************/
Game::~Game() {
	deleteGrid(grid);
	grid = nullptr;	
}

/*******************************************************************
* Description: Method that allocates the memory for the grid
* Arguments:   A pointer to a 2D array of Critter pointers
* Returns:     No return value
*******************************************************************/
void Game::createGrid(Critter*** &newGrid) {
	newGrid = new Critter**[gridRows];
	for (int i = 0 ; i < gridRows ; ++i) {
		newGrid[i] = new Critter*[gridCols];
		for (int j = 0 ; j < gridCols ; ++j) {
			newGrid[i][j] = nullptr;
		}
	}
}

/*******************************************************************
* Description: Method that frees the memory of the grid
* Arguments:   A pointer to a 2D array of Critter pointers
* Returns:     No return value
*******************************************************************/
void Game::deleteGrid(Critter*** &delGrid) {
	// If no grid has been created
	if (!grid) { return; }

	for (int i = 0 ; i < gridRows ; ++i) {
		for (int j = 0 ; j < gridCols ; ++j) {
			if (delGrid[i][j])
				delete delGrid[i][j];
		}
		delete [] delGrid[i];
	}
	delete [] delGrid;	
	delGrid = nullptr;
}

/*******************************************************************
* Description: Method that fills the grid with Ant and Doodlebug
*              objects
* Arguments:   A pointer to a 2D array of Critter pointers
* Returns:     No return value
*******************************************************************/
void Game::populateGrid(Critter*** &tmp) {
	int r, c; // Generic variables for coordinates
	
	// Generate the doodlebugs
	for (int i = 0 ; i < startNumDB ; ++i) {
		do { 
			r = rand() % gridRows;
			c = rand() % gridCols;
		} while (tmp[r][c]);
		tmp[r][c] = new DB(r,c);
	}	
	
	//Generate the ants
	for (int i = 0 ; i < startNumAnts ; ++i) {
		do { 
			r = rand() % gridRows;
			c = rand() % gridCols;
		} while (tmp[r][c]);
		tmp[r][c] = new Ant(r,c);
	}
}

/*******************************************************************
* Description: Method that begins the predator-prey simulation
* Arguments:   No arguments
* Returns:     No return value
*******************************************************************/
void Game::runSim() {
	// Set up initial state of grids
	createGrid(grid);
	populateGrid(grid);
	cout << "Step 0" << endl;
	printGrid();

	for ( int i = 1 ; i < userSteps+1 ; ++i ) {
		move();
		breed();
		starve();
		cout << "Step " << i << endl;
		printGrid();
	}

}

/*******************************************************************
* Description: Method that moves the doodlebugs then moves the ants
* Arguments:   No arguments
* Returns:     No return value
*******************************************************************/
void Game::move() {
	Direction mvDir = Direction::NONE; // Generic variables
	Critter* tmpCrit = nullptr;
	int newCol = 0, newRow = 0;

	// Doodlebugs move first
	for ( int r = 0 ; r < gridRows ; ++r ) {
		for ( int c = 0 ; c < gridCols ; ++c ) {
			if (grid[r][c] && grid[r][c]->getState() && !(grid[r][c])->getHasMoved()) {
				// Acquire a move direction (including NONE)
				mvDir = dirSelect(grid[r][c], false);
				// Move the DB object and get the new Critter
				tmpCrit = grid[r][c]->move(mvDir);
				// Get the new, post-move row/col
				newRow = tmpCrit->getRow();
				newCol = tmpCrit->getCol();

				// Delete the old spot
				delete grid[r][c];
				grid[r][c] = nullptr;

				// If doodlebug eating an ant, then delete the ant
				if(grid[newRow][newCol] && !grid[newRow][newCol]->getState())
				{
					delete grid[newRow][newCol];
					grid[newRow][newCol] = nullptr;
				}
				
				// Set the DB on the grid
				grid[newRow][newCol] = tmpCrit;
				grid[newRow][newCol]->setHasMoved(true);
		
				tmpCrit = nullptr;

			}
		}
	}

	// Ants move second
	for ( int r = 0 ; r < gridRows ; ++r ) {
		for ( int c = 0 ; c < gridCols ; ++c ) {
			// Check if its an ant
			if (grid[r][c] && !grid[r][c]->getState() && !(grid[r][c]->getHasMoved())) {
				// Acquire a move direction
				mvDir = dirSelect(grid[r][c], false);
				// Move the ant object and get the new critter
				tmpCrit = grid[r][c]->move(mvDir);
				
				// Get the new post-move row/col
				newRow = tmpCrit->getRow();
				newCol = tmpCrit->getCol();

				// Delete the old spot
				delete grid[r][c];
				grid[r][c] = nullptr;

				// Set the Ant on the grid
				grid[newRow][newCol] = tmpCrit;
				grid[newRow][newCol]->setHasMoved(true);

				tmpCrit = nullptr;
			}
		}
	}	

	// Done moving, set all back to false so they can move next turn
	for (int r = 0 ; r < gridRows ; ++r ) {
		for(int c = 0 ; c < gridCols ; ++c){
			if (grid[r][c]) {
				grid[r][c]->setHasMoved(false);
			}
		}
	}

}

/*******************************************************************
* Description: Method that allows the doodlebugs and ants to breed
* Arguments:   No arguments
* Returns:     No return value
*******************************************************************/
void Game::breed() {
	Direction breedDir = Direction::NONE;
	Critter* bredCrit = nullptr;
	int breedRow, breedCol;

	/* 
	NOTE: Specs state that "The doodlebugs will move before the ants
	each time step." I don't know if this means the DBs will breed
	before the ants as well, however, since that's the more 
	complicated case, I've written that below. If doodlebugs and ants
	can breed at the same time, condense the below sections into
	one section whereby both critters breed.
	*/

	// SKIP THE BABIES

	// Doodlebugs breed first
	for ( int r = 0 ; r < gridRows ; ++r ) {
		for ( int c = 0 ; c < gridCols ; ++c ) {
			if (grid[r][c] && grid[r][c]->getState()) {
				// Get the direction of breeding
				breedDir = dirSelect(grid[r][c], true);
				// Attempt to breed
				bredCrit = grid[r][c]->breed(breedDir);
				//Can't breed; no open spaces
				if (!bredCrit) { }
				// Breed into adjacent grid space
				else { 
					breedRow = bredCrit->getRow();
					breedCol = bredCrit->getCol();
					grid[breedRow][breedCol] = bredCrit; 
				}
				bredCrit = nullptr;
			}
		}
	}

	// Ants breed second
	for ( int r = 0 ; r < gridRows ; ++r ) {
		for ( int c = 0 ; c < gridCols ; ++c ) {
			if (grid[r][c] && !grid[r][c]->getState()) {
				// Get the direction of breeding
				breedDir = dirSelect(grid[r][c], true);
				// Attempt to breed
				bredCrit = grid[r][c]->breed(breedDir);
				// Can't breed; no open spaces
				if (!bredCrit) { }
				// Breed into adjacent grid space
				else { 
					breedRow = bredCrit->getRow();
					breedCol = bredCrit->getCol();
					grid[breedRow][breedCol] = bredCrit; 
				}
				bredCrit = nullptr;
			}
		}
	}
}

/*******************************************************************
* Description: Method that removes doodlebugs if they have starved,
*              i.e. not eaten an ant in the alloted time
* Arguments:   No arguments
* Returns:     No return value
*******************************************************************/
void Game::starve() {
	for ( int r = 0 ; r < gridRows ; ++r ) {
		for ( int c = 0 ; c < gridCols ; ++c ) {
			// Kill doodlebug if 3 steps pass without eating
			if (grid[r][c] && grid[r][c]->getState() >= 4) {
				delete grid[r][c];
				grid[r][c] = nullptr;
			}
		}
	}
}

/*******************************************************************
* Description: Method that checks the directions a critter can move
*              that are in bounds and not already occupied
* Arguments:   A pointer to a 2D array of Critter pointers and
*              a boolean that tracks breeding of a Critter
* Returns:     A Direction enum value indicating direction to move
*******************************************************************/
Direction Game::dirSelect(Critter* &crit, bool breedCall) {
	vector<Direction> dirVec;
	int r = crit->getRow(),
		c = crit->getCol();
	
	// Directions available during a normal move
	if (crit && crit->getState() && !breedCall) {
		// Directions a doodlebug can move to eat ants
		/*
		Checks:
		- boundaries
		- if something is occupying the space (to up or left) on new grid (other DB ate it)
		- if there's an ant around it; has to check oldGrid for ants (they haven't moved yet)
		*/
		if (r > 0 && grid[r-1][c] && !(grid[r-1][c]->getState()))
			dirVec.push_back(Direction::EATUP);
		if (c < gridCols-1 && grid[r][c+1] && !(grid[r][c+1]->getState()))
			dirVec.push_back(Direction::EATRIGHT);
		if (r < gridRows-1 && grid[r+1][c] && !(grid[r+1][c]->getState()))
			dirVec.push_back(Direction::EATDOWN);
		if (c > 0 && grid[r][c-1] && !(grid[r][c-1]->getState()))
			dirVec.push_back(Direction::EATLEFT);
	}

	// Doodlebug moves without eating, Ant moves, both breed
	if (dirVec.empty() || breedCall) {
		if (r > 0 && !grid[r-1][c])
			dirVec.push_back(Direction::UP);
		if (c < gridCols-1 && !grid[r][c+1])
			dirVec.push_back(Direction::RIGHT);
		if (r < gridRows-1 && !grid[r+1][c])
			dirVec.push_back(Direction::DOWN);
		if (c > 0 && !grid[r][c-1])
			dirVec.push_back(Direction::LEFT);
	}
	
	// If the critter can't move or breed anywhere
	if (dirVec.empty()) { return Direction::NONE; }

	// Return a random pre-approved direction
	return (dirVec[rand() % dirVec.size()]);
}

/*******************************************************************
* Description: Method that prins the current state of the grid
* Arguments:   No arguments
* Returns:     No return values
*******************************************************************/
void Game::printGrid() {
	printHorizontalBorder(2*gridCols+2, '_');
	for (int i = 0; i < gridRows ; ++i) {
		cout << setw(2) << left << "|";
		for (int j = 0 ; j < gridCols ; ++j) {
			if (!grid[i][j]) { // Empty spaces
				cout << setw(2) << left << " ";
			} else if (!grid[i][j]->getState()) { // Ants
				cout << setw(2) << left << "O";
			} else if (grid[i][j]->getState()) { // Doodlebugs
				cout << setw(2) << left << "X";
			}
		}
		cout << setw(2) << left << "|" << endl;
	}
	printHorizontalBorder(2*gridCols+2, '_');
}
