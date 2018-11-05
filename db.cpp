/*******************************************************************
* Program Name:    CS 162 - Group Project - Predator-Prey Sim
* Author:          Group 8 (Astro)
* Date:            November 4, 2018
* Description:     Source file for Doodlebug class, which models
*                  the predator in the predator-prey simulation.
*                  This class is a derived class of Critter,
*                  establshing an IS-A relationship with Critter 
*                  (i.e. every Doodlebug IS-A Critter).
*******************************************************************/

#include "critter.hpp"
#include "db.hpp"

/*******************************************************************
* Description: Method that moves an doodlebug to one of the four
*              adjacent cells and, if necessary, allows to eat an
*              ant at that location
* Arguments:   A Direction enum value that specifies where the 
*              doodlebug object should move to
* Returns:     A pointer to a Critter object holding a new
*              doodlebug
*******************************************************************/
Critter* DB::move(Direction dir) {
	Critter* crit = nullptr;

	// Increment tracker variables
	++this->critSteps;
	++this->lastBreed;
	++this->state;

	// Create a new DB in the specified direction
	switch(dir) {
		// DBs state gets reset to 1 (by default) because it ate
		case (Direction::EATUP) :
			crit = new DB(this->row-1, this->col,
						  this->critSteps, this->lastBreed,1);
			break;

		case (Direction::EATRIGHT) :
			crit = new DB(this->row, this->col+1,
						  this->critSteps, this->lastBreed,1);
			break;

		case (Direction::EATDOWN) :
			crit = new DB(this->row+1, this->col,
						  this->critSteps, this->lastBreed,1);
			break;

		case (Direction::EATLEFT) :
			crit = new DB(this->row, this->col-1,
						  this->critSteps, this->lastBreed,1);
			break;

		// Pass on the current DBs state since DB didnt eat
		case (Direction::UP) :
			crit = new DB(this->row-1, this->col,
						  this->critSteps, this->lastBreed,
						  this->state);
			break;

		case (Direction::RIGHT) :
			crit = new DB(this->row, this->col+1,
						  this->critSteps, this->lastBreed,
						  this->state);
			break;

		case (Direction::DOWN) :
			crit = new DB(this->row+1, this->col,
						  this->critSteps, this->lastBreed,
						  this->state);
			break;

		case (Direction::LEFT) :
			crit = new DB(this->row, this->col-1,
						  this->critSteps, this->lastBreed,
						  this->state);
			break;

		case (Direction::NONE) :
			crit = new DB(this->row, this->col,
						  this->critSteps, this->lastBreed,
						  this->state);
			break;
	}
	return crit;
}

/*******************************************************************
* Description: Method that allows a doodlebug to breed if it meets
*              the requirements for doing so
* Arguments:   A Direction enum value that specifies where the 
*              doodlebug object should breed on the board
* Returns:     A pointer to a Critter object holding a new
*              doodlebug
*              note: the return value will be a null pointer if
*              the breed would take the doodlebug out of bounds
*******************************************************************/
Critter* DB::breed(Direction dir) {
	Critter* crit = nullptr;
	
	// Only breed if more than 8 steps since last breed
	if (this->lastBreed >= 8) {
		// Breed a new critter in the specified direction
		switch(dir) {
			case (Direction::UP) :
				this->lastBreed = 0;
				crit = new DB(row-1, col);
				break;

			case (Direction::RIGHT) :
				this->lastBreed = 0;
				crit = new DB(row, col+1);
				break;

			case (Direction::DOWN) :
				this->lastBreed = 0;
				crit = new DB(row+1, col);
				break;

			case (Direction::LEFT) :
				this->lastBreed = 0;
				crit = new DB(row, col-1);
				break;

			// Don't reset breed counter 
			case (Direction::NONE) :
				break;
		}
	} 
	return crit;
}
