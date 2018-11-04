/*******************************************************************
* Program Name:    CS 162 - Group Project - Predator-Prey Sim
* Author:          Group 8 (Astro)
* Date:            November 4, 2018
* Description:     Source file for Ant class, which models the
*                  prey in the predator-prey simulation. This 
*                  class is a derived class of Critter, establshing
*                  an IS-A relationship with Critter (i.e. every
*                  Ant IS-A Critter).
*******************************************************************/

#include "critter.hpp"
#include "ant.hpp"

/*******************************************************************
* Description: Method that moves an ant to one of the four
*              adjacent cells
* Arguments:   A Direction enum value that specifies where the 
*              new ant object should be placed on the board
* Returns:     A pointer to a Critter object holding a new ant
*******************************************************************/
Critter* Ant::move(Direction dir) {
	Critter* crit = nullptr;

	// Increment tracker variables
	++this->critSteps;
	++this->lastBreed;

	// Create a new DB in the specified direction
	switch(dir) {
		case (Direction::UP) : {
			crit = new Ant(this->row-1, this->col,
						   this->critSteps, this->lastBreed);
			break;
		}
		case (Direction::RIGHT) : {
			crit = new Ant(this->row, this->col+1,
						   this->critSteps, this->lastBreed);
			break;
		}
		case (Direction::DOWN) : {
			crit = new Ant(this->row+1, this->col,
						   this->critSteps, this->lastBreed);
			break;
		}
		case (Direction::LEFT) : {
			crit = new Ant(this->row, this->col-1,
						   this->critSteps, this->lastBreed);
			break;
		}
		case (Direction::NONE) : {
			crit = new Ant(this->row, this->col,
						   this->critSteps, this->lastBreed);
			break;
		}
	}
	return crit;
}

/*******************************************************************
* Description: Method that allows an ant to breed if it meets the
*              requirements for doing so
* Arguments:   A Direction enum value that specifies where the 
*              ant object should breed on the board
* Returns:     A pointer to a Critter object holding a new ant;
*              note: the return value will be a null pointer if
*              the breed would take the ant out of bounds
*******************************************************************/
Critter* Ant::breed(Direction dir) {
	Critter* crit = nullptr;
	
	// Only breed if more than 3 steps since last breed
	if (this->lastBreed >= 3) {
		// Breed a new critter in the specified direction 
		switch(dir) {
			case (Direction::UP) :
				this->lastBreed = 0;
				crit = new Ant(row-1, col);
				break;

			case (Direction::RIGHT) :
				this->lastBreed = 0;
				crit = new Ant(row, col+1);
				break;

			case (Direction::DOWN) :
				this->lastBreed = 0;
				crit = new Ant(row+1, col);
				break;

			case (Direction::LEFT) :
				this->lastBreed = 0;
				crit = new Ant(row, col-1);
				break;

			// Don't reset breed counter
			case (Direction::NONE) :
				break;
		}
	}
	return crit;
}
