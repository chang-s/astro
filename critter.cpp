/*******************************************************************
** Program Name:    CS 162 - Group Project - Predator-Prey Sim
** Author:          Group 8 (Astro) 
** Date:            November 4, 2018
** Description:     Source file for Critter class. This class is an
**                  abstract class, and in the context of this
**                  program has two derived classes: Ant and 
**                  Doodlebug. These classes represent the prey and
**                  predator, respectively, in this simulation.
*******************************************************************/

#include "critter.hpp"

// Overloaded constructor
Critter::Critter(int row, int col, int critSteps, int lastBreed, int state) {
	this->row = row;
	this->col = col;
	this->critSteps = critSteps;
	this->lastBreed = lastBreed;
	this->state = state;
	hasMoved = false;
}

// Empty destructor
Critter::~Critter() {

}

