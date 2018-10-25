/******************************************************************************
 * ** Program Name:	Group Project - grid.hpp
 * ** Author:      	Group 8
 * ** Date:        	October 24 2018
 * ** Description  	Grid Header File, contains prototypes for all
 * **				methods and variables required to create, delete,
 * **				and update 2D grid of critters
 * ****************************************************************************/

#ifndef GRID_HPP
#define GRID_HPP

#include "ant.hpp"

class Grid
{

	//all member variables are private
	private:
	    Critter*** ptrGrid; //Ptr to 2D Grid of Critters   
	    int maxRow;			//store gride size
	    int maxCol;

	    //variables for checking surroundings
	    const int UP_POS = 0;
		const int RIGHT_POS = 1;
		const int DOWN_POS = 2;
		const int LEFT_POS = 3;
		const int NUM_DIR = 4;

	//member funtions are public
	public:
		Grid();
		Grid(int row, int col);
		~Grid(); //destructor to clean all dynamic memory
		Grid(const Grid &oldGrid); //copy constructor
		Grid& operator=(const Grid& other);

		Critter* getCritter(int row, int col);
		void setCritter(int row, int col, SpaceType type);
		void moveCritter(int oldX, int oldY, int newX, int newY);
		void displayGrid();
		void clearGrid();
};

#endif