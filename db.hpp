/*******************************************************************
* Program Name:    CS 162 - Group Project - Predator-Prey Sim
* Author:          Group 8 (Astro)
* Date:            November 4, 2018
* Description:     Header file for Doodlebug class
*******************************************************************/

#ifndef DB_HPP
#define DB_HPP

#include "critter.hpp"

class DB : public Critter {
	public:
                // Constructor that calls the Critter class constructor
		DB(int row, int col, int critSteps = 0, int lastBreed = 0, int state = 1) 
		: Critter(row, col, critSteps, lastBreed, state) {};
                // Empty destructor
		~DB() {}
		virtual Critter* move(Direction dir) override;
		virtual Critter* breed(Direction dir) override;
};

#endif
