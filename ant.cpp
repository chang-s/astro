/******************************************************************************
 * ** Program Name:	Group Project - ant.cpp
 * ** Author:      	Group 8
 * ** Date:        	October 24 2018
 * ** Description  	Implementation file for Ant
 * **				Has custom move and breed functions
 * ****************************************************************************/

#include "ant.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

using std::string;
using std::cout;
using std::endl;

/******************************************************************************
	Ant()
	Default constructor, intialize relevant stats
*****************************************************************************/

Ant::Ant() : Critter()
{
	type = SpaceType::ANT;
	displayString = "O";
}

/******************************************************************************
	~Ant()
	Destructor to clean up dynamic memory
*****************************************************************************/
Ant::~Ant()
{

}

/******************************************************************************
	int move()
	Overriden function
	Tries to move in a random direction
	If space is empty and valid than move and return direction, else do not move
	and return a NOMOVE
*****************************************************************************/
DirMove Ant::move(SpaceType surType[])
{
	DirMove attemptDir = calcMoveDir();
	DirMove finalDir = DirMove::NO_MOVE;

	if(moveIsValid(attemptDir, surType) == true)
	{

		finalDir = attemptDir;
	}

	hasMoved = true;
	return finalDir;

}