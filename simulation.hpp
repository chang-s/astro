/******************************************************************************
 * ** Program Name:	Group Project - simulation.hpp
 * ** Author:      	Group 8
 * ** Date:        	October 24 2018
 * ** Description  	Simulation Header File, contains prototypes for all
 * **				functions to manage simulation by moving critters and
 * **				updating board state
 * ****************************************************************************/

#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "grid.hpp"
#include <vector>

class Simulation
{

	//all member variables are private
	private:
	    Grid grid1;
	    int maxRow;
	    int maxCol;

	    struct Location
	    {
	    	int row = 0;
	    	int col = 0;
	    };

	    std::vector<Location> activeAnts;

	    //variables for checking surroundings
	    const int UP_POS = 0;
		const int RIGHT_POS = 1;
		const int DOWN_POS = 2;
		const int LEFT_POS = 3;
		const int NUM_DIR = 4;

	//member funtions are public
	public:
		Simulation();
		~Simulation(); //destructor to clean all dynamic memory

		void userStart();
		void nextStep();
		void updateAntVector();
		void antMove();
		void deterSurroundings(int row, int col, SpaceType *surrounds);
		bool addCritter(int row, int col, SpaceType type);
		void ageAllCritters(SpaceType type);
};

#endif