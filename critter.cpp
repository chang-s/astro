/******************************************************************************
 * ** Program Name:	Group Project - Critter.cpp
 * ** Author:      	Daniel Meirovitch
 * ** Date:        	October 24 2018
 * ** Description  	Implementation file for Critter
 * **				Abstract Base class also used to derive other character types
 * **				Setup variables and getters/settings for derived classes
 * ****************************************************************************/

#include "critter.hpp"
#include <string>
#include <stdlib.h>
#include <ctime>

using std::string;

/******************************************************************************
	Critter();
	Default constructor, make a new critter
*****************************************************************************/

Critter::Critter()
{
	timeSteps = 0;
	type = SpaceType::EMPTY;
	displayString = ".";
	hasMoved = false;
}

/******************************************************************************
	virtual ~Critter();
	Virtual destructor used to clean dynamic memory
*****************************************************************************/
Critter::~Critter()
{
	
}

/******************************************************************************
	DirMove move(SpaceType surType[]);
	Virtual destructor used to clean dynamic memory
*****************************************************************************/
DirMove Critter::move(SpaceType surType[])
{
	return DirMove::NO_MOVE;
	
}



/******************************************************************************
	get functions
	Multiple get functions below to retrieve value for each variable
*****************************************************************************/
int Critter::getTimeSteps()
{
	return timeSteps;
}

SpaceType Critter::getType()
{
	return type;
}

string Critter::getDisplay()
{
	return displayString;
}

bool Critter::getHasMoved()
{
	return hasMoved;
}


/******************************************************************************
	DirMove calcMoveDir()
	Generate a random direction for a critter to move in
*****************************************************************************/
DirMove Critter::calcMoveDir()
{
	//generate a random number 1 through 4
	int numDirection = (rand() % 4) + 1;
	DirMove direction;

	//based on random number, convert to a cardinal direction
	switch(numDirection)
	{
		case 1:
		{
			direction = DirMove::UP;
			break;
		}
	
		case 2:
		{
			direction = DirMove::RIGHT;
			break;
		}

		case 3:
		{
			direction = DirMove::DOWN;
			break;
		}
		
		case 4:
		{
			direction = DirMove::LEFT;
			break;
		}
	}

	//return determined direction
	return direction;

}

/******************************************************************************
	bool moveIsValid(DirMove attemptDir, SpaceType surType[])
	Checks to see if move goes to an empty location
	Returns true if space in planned direction is empty
*****************************************************************************/

bool Critter::moveIsValid(DirMove attemptDir, SpaceType surType[])
{
	bool spaceIsEmpty = false;

	//depending on direction attempting to move, see if that space is empty
	switch(attemptDir)
	{
		case DirMove::UP:
		{
			if (surType[UP_POS] == SpaceType::EMPTY)
			{
				spaceIsEmpty = true;
			}
			break;
		}
		
		case DirMove::RIGHT:
		{
			if (surType[RIGHT_POS] == SpaceType::EMPTY)
			{
				spaceIsEmpty = true;
			}
			break;
		}

		case DirMove::DOWN:
		{
			if (surType[DOWN_POS] == SpaceType::EMPTY)
			{
				spaceIsEmpty = true;
			}
			break;
		}

		case DirMove::LEFT:
		{
			if (surType[LEFT_POS] == SpaceType::EMPTY)
			{
				spaceIsEmpty = true;
			}
			break;
		}

		case DirMove::NO_MOVE:
		{
			break;
		}
	}

	//return if space is empty
	return spaceIsEmpty;

}

/******************************************************************************
	void ageCritter()
	Increase age of critter and reset bool flags to beginning of term
*****************************************************************************/

void Critter::ageCritter()
{
	timeSteps++;
	hasMoved = false;
}