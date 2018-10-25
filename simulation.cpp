/******************************************************************************
 * ** Program Name:	Group Project - simulation.cpp
 * ** Author:      	Group 8
 * ** Date:        	October 24 2018
 * ** Description  	Simulation Implementation File, starts simulation based
 * **				on user inputs. Then controls order of events.
 * ****************************************************************************/

#include "simulation.hpp"
#include <iostream>

using std::cout;
using std::endl;

/******************************************************************************
	Simulation()
	Default constructor

	~Simulation()
	Default Destructor
*****************************************************************************/

Simulation::Simulation() : grid1(20, 20)
{

}

Simulation::~Simulation()
{

}

/******************************************************************************
	void userStart()
	Start program and get necessary info to start sim from user
*****************************************************************************/
void Simulation::userStart()
{
	maxRow = 20;
	maxCol = 20;
	addCritter(5, 5, SpaceType::ANT);
	addCritter(5, 7, SpaceType::ANT);
	addCritter(12, 13, SpaceType::ANT);
	grid1.displayGrid();

	nextStep();


}

/******************************************************************************
	void nextStep()
	Processes all of the necessary parts of a step:
	Doodlebug moves/eats, Age Doodlebug, Doodlebug breeds, Doodlebug starves,
	Ant moves, age Ants, Ant Breeds
*****************************************************************************/

void Simulation::nextStep()
{

	for (int i = 0; i < 2; i++)
	{
		Grid storedGrid = grid1;
		antMove();
		grid1.displayGrid();
		storedGrid.clearGrid();
		ageAllCritters(SpaceType::ANT);
	}
		
}


/******************************************************************************
	void antMove()
	Moves all Ants
*****************************************************************************/

void Simulation::antMove()
{
	SpaceType surrType[NUM_DIR];
	DirMove antDir;
	int newRow = 0;
	int newCol = 0;

	//go through whole grid looking for ants to move
	for (int row = 0; row < maxRow; row++)
	{
		for(int col = 0; col < maxCol; col++)
		{
			//Check if critter is ant
			if (grid1.getCritter(row, col)->getType() == SpaceType::ANT &&
				grid1.getCritter(row, col)->getHasMoved() == false)
			{
				cout << "I found an Ant to move!" << endl;
				//create the array of the position surrounding the ANT
				deterSurroundings(row, col, surrType);

				//ant determines direction to move
				antDir = grid1.getCritter(row, col)->move(surrType);

				//get new coordinates based on move
				switch(antDir)
				{
					case DirMove::UP:
					{
						cout << "Moving up" << endl;
						newRow = row - 1;
						newCol = col;
						break;
					}

					case DirMove::RIGHT:
					{
						cout << "Moving Right" << endl;
						newRow = row;
						newCol = col + 1;
						break;
					}

					case DirMove::DOWN:
					{
						cout << "Moving Down" << endl;
						newRow = row + 1;
						newCol = col;
						break;
					}

					case DirMove::LEFT:
					{
						cout << "Moving Left" << endl;
						newRow = row;
						newCol = col - 1;
						break;
					}

					case DirMove::NO_MOVE:
					{
						cout << "Not Moving" << endl;
						newRow = row;
						newCol = col;
						break;
					}
				}

				//have grid update ant positions
				grid1.moveCritter(row, col, newRow, newCol);
			}
		}
	}
	
}

/******************************************************************************
	int* deterSurroundings()
	Determine what surrounds current position
*****************************************************************************/

void Simulation::deterSurroundings(int row, int col, SpaceType *surrounds)
{
	surrounds[UP_POS] = SpaceType::INVALID;
	surrounds[RIGHT_POS] = SpaceType::INVALID;
	surrounds[DOWN_POS] = SpaceType::INVALID;
	surrounds[LEFT_POS] = SpaceType::INVALID;

	bool atBottom = false;
	bool atTop = false;
	bool atRight = false;
	bool atLeft = false;

	//check boundary conditions first
	//check if at the top of the board
	if(row == 0)
	{
		atTop = true;
		surrounds[UP_POS] = SpaceType::INVALID;
	}

	if(col == maxCol - 1)
	{
		atRight = true;
		surrounds[RIGHT_POS] = SpaceType::INVALID;
	}

	if(row == maxRow - 1)
	{
		atBottom = true;
		surrounds[LEFT_POS] = SpaceType::INVALID;
	}

	if(col == 0)
	{
		atLeft = true;
		surrounds[DOWN_POS] = SpaceType::INVALID;
	}

	//determine if there are any empty valid in-game positions
	//use logical short-circuit evaluation of AND to prevent out of bounds
	if(atTop == false)
	{
		surrounds[UP_POS] = grid1.getCritter(row - 1, col)->getType();
	}
	if(atRight == false)
	{
		surrounds[RIGHT_POS] = grid1.getCritter(row, col + 1)->getType();
	}
	if(atBottom == false)
	{
		surrounds[LEFT_POS] = grid1.getCritter(row + 1, col)->getType();;
	}
	if(atLeft == false)
	{
		surrounds[DOWN_POS] = grid1.getCritter(row, col - 1)->getType();
	}

}

/******************************************************************************
	bool addCritter(int row, int col, SpaceType type)
	Places a new Critter on a specific spot on the board
	return true if spot was empty and could place the enew critter
*****************************************************************************/

bool Simulation::addCritter(int row, int col, SpaceType type)
{
	bool placedCritter = false;

	if(grid1.getCritter(row, col)->getType() == SpaceType::EMPTY)
	{		
		grid1.setCritter(row, col, type);
		placedCritter = true;
	}

	return placedCritter;
}

/******************************************************************************
	void ageAllCritters(SpaceType type)
	End of movement, so age all Critter of specific type
*****************************************************************************/

void Simulation::ageAllCritters(SpaceType type)
{
	for(int i = 0; i < maxRow; i++)
	{
		for(int j = 0; j < maxCol; j++)
		{
			if(grid1.getCritter(i, j)->getType() == type)
			{
				grid1.getCritter(i, j)->ageCritter();
			}
		}
	}

}