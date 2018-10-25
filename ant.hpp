/******************************************************************************
 * ** Program Name:	Group Project - ant.hpp
 * ** Author:      	Group 8
 * ** Date:        	October 24 2018
 * ** Description  	Header file for Ant. Derived from base Critter
 * **				Inherits variables types, but overrides to create own move
 * ****************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include "critter.hpp"

class Ant : public Critter
{

	//No unique variables
	private:

	//member funtions are public
	//rely on Critter base class for other functions
	public:
		Ant();
		~Ant();
		DirMove move(SpaceType surType[]);
		//int breed();
};

#endif