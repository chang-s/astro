/******************************************************************************
 * ** Program Name:	Group Project - critter.hpp
 * ** Author:      	Group 8
 * ** Date:        	October 24 2018
 * ** Description  	Header file for Critter
 * **				Abstract class that contains base functions that are 
 * **				overridden as necessary by Ant/Doodlebug
 * ****************************************************************************/

#ifndef CRITTER_HPP
#define CRITTER_HPP

#include <string>

//enum to store what type of critter it is
enum class SpaceType {INVALID, EMPTY, ANT, DBUG};
enum class DirMove {UP, RIGHT, DOWN, LEFT, NO_MOVE};

class Critter
{

	//protected to give access to derived classes
	protected:
		const int UP_POS = 0;
		const int RIGHT_POS = 1;
		const int DOWN_POS = 2;
		const int LEFT_POS = 3;
		SpaceType type;
		int timeSteps;
		bool hasMoved;
		std::string displayString;


	    
	//member funtions are public
	public:
		Critter();
		virtual ~Critter();
		virtual DirMove move(SpaceType surType[]);
		//virtual int breed();
		//virtual int starve();

		//Base class functions not to be overriden
		DirMove calcMoveDir();
		bool moveIsValid(DirMove attemptDir, SpaceType surType[]);
		void ageCritter();

		//getters
		int getTimeSteps();
		SpaceType getType();
		std::string getDisplay();
		bool getHasMoved();

};

#endif