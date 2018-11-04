/*******************************************************************
* Program Name:    CS 162 - Group Project - Predator-Prey Sim
* Author:          Group 8 (Astro)
* Date:            November 4, 2018
* Description:     Header file for Ant class
*******************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"

class Ant : public Critter {
	public:
                // Constructor that calls the Critter class constructor
		Ant(int row, int col, int critSteps = 0, int lastBreed = 0, int state = 0) 
		: Critter(row, col, critSteps, lastBreed, state) {};
                // Empty destructor
		~Ant() {}
		virtual Critter* move(Direction dir) override;
		virtual Critter* breed(Direction dir) override;
};

#endif
