/******************************************************************************
 * ** Program Name:	Group Project - grid.cpp
 * ** Author:      	Daniel Meirovitch
 * ** Date:        	October 24 2018
 * ** Description  	Grid Implementation File
 * ** 				implementation allows to create new board, delete board,
 * **				and update 2D grid of critters
 * ****************************************************************************/


#include "grid.hpp"
#include <iostream>
#include <utility>

using std::cout;
using std::endl;
using std::swap;

/******************************************************************************
	grid(int row)
	Custom constructor to make a board of the specified row x col
	Board begins at 0,0 in the top left
*****************************************************************************/
Grid::Grid()
{
	
	maxRow = 2;
	maxCol = 2;

}

/******************************************************************************
	grid(int row, int col)
	Custom constructor to make a board of the specified row x col
	Board begins at 0,0 in the top left

*****************************************************************************/
Grid::Grid(int row, int col)
{
	//store all the row and column data
	maxRow = row;
	maxCol = col;

	//dynamically allocate the board
	ptrGrid = new Critter**[maxRow];
	for (int i = 0; i < maxRow; i++)
	{
		ptrGrid[i] = new Critter*[maxCol];
	}

	//fill board with empty spaces (plain critters)
	for (int i = 0; i < maxRow; i++)
	{
		for (int j = 0; j < maxCol; j++)
		{
			ptrGrid[i][j] = new Critter();
		}
	}

}

/******************************************************************************
	~Grid
	Destructor to remove dynamic memory allocated for board
	First delete each element of the array
	Then delete dynamic row of that array
	Then delete entire array
*****************************************************************************/

Grid::~Grid()
{
	for (int i = 0; i < maxRow; i++)
	{
		for(int j = 0; j < maxCol; j++)
		{
			delete ptrGrid[i][j];
		}

		//delete each row
		delete [] ptrGrid[i];
	}

	//delete array object
	delete [] ptrGrid;
	
}

/******************************************************************************
	Grid(const Grid &oldGrid, int maxRow, int maxCol)
	Copy constructor
	Create a new array with all of the values from the existing array
*****************************************************************************/

Grid::Grid(const Grid &oldGrid)
{
	operator=(oldGrid);
	
}

/******************************************************************************
	= Overloading
	Copy contents of array to other object
*****************************************************************************/

Grid& Grid::operator=(const Grid &oldGrid)
{
	maxRow = oldGrid.maxRow;
	maxCol = oldGrid.maxCol;
	
	//dynamically allocate the grid
	ptrGrid = new Critter**[oldGrid.maxRow];
	for (int i = 0; i < maxRow; i++)
	{
		ptrGrid[i] = new Critter*[oldGrid.maxCol];
	}

	//fill board with existing spaces
	for (int i = 0; i < oldGrid.maxRow; i ++)
	{
		for (int j = 0; j < oldGrid.maxCol; j ++)
		{
			ptrGrid[i][j] = oldGrid.ptrGrid[i][j];
		}
	}

	return *this;
}

/******************************************************************************
	Critter* getCritter(int row, int col)
	Return critter in specific position
*****************************************************************************/

Critter* Grid::getCritter(int row, int col)
{
	return ptrGrid[row][col];
	
}

/******************************************************************************
	void setCritter(int row, int col, SpaceType type)
	Make a new critter in that specific position
*****************************************************************************/

void Grid::setCritter(int row, int col, SpaceType type)
{
	//delete existing critter in position
	delete ptrGrid[row][col];

	if(type == SpaceType::ANT)
	{
		ptrGrid[row][col] = new Ant();
	}

	/*
	if(type == SpaceType::DBUG)
	{
		ptrGrid[row][col] = new DoodleBug();
	}
	*/
	
}

/******************************************************************************
	void moveCritter(int oldX, int oldY, int newX, int newY)
	Moves the critter to the new desired position by swapping the critter at
	each location
	Does this by updating the new position to have the old value, and setting
	old position back to an empty critter
*****************************************************************************/

void Grid::moveCritter(int row, int col, int newRow, int newCol)
{
	//swap positions of critters by holding value in a temp spot
	Critter* tempCritter = ptrGrid[newRow][newCol];
	ptrGrid[newRow][newCol] = ptrGrid[row][col];
	ptrGrid[row][col] = tempCritter;

	}

/******************************************************************************
	void displayGrid()
	Prints out the grid with border.
*****************************************************************************/

void Grid::displayGrid()
{
	//print out top border
	for(int i = 0; i < (maxCol + 2); i++)
	{
		//cout << '-';
		cout << i % 10;
	}
	cout << endl;

	//print out board data with | borders
	for(int i = 0; i < maxRow; i++)
	{

		//print out leftside border
		//cout << '|';
		cout << i % 10;

		//print out the whole board and its critters
		for (int j = 0; j < maxCol; j++)
		{
			cout << ptrGrid[i][j]->getDisplay();
		}

		//print out rightside border, and go to next line
		cout << '|' << endl;
	}

	//print out bottom border
	for(int i = 0; i < (maxCol + 2); i++)
	{
		cout << '-';
	}
	cout << endl;
}

/******************************************************************************
	void clearGrid()
	Set all values to Null
*****************************************************************************/

void Grid::clearGrid()
{
	for (int i = 0; i < maxRow; i++)
	{
		for(int j = 0; j < maxCol; j++)
		{
			
			ptrGrid[i][j] = NULL;
		}

		//delete [] ptrGrid[i];

	}

	//delete [] ptrGrid;

	
}