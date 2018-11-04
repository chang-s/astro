/*******************************************************************
** Program Name:    CS 162 - Group Project - Predator-Prey Sim
** Author:          Group 8
** Date:            November 4, 2018
** Description:     Header file for Ant class
*******************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include "critter.hpp"

class Ant : public Critter {
	private:

	protected:

	public:
                // constructor that calls the Critter class constructor
		Ant(int row, int col, int critSteps = 0, int lastBreed = 0, int state = 0) 
		: Critter(row, col, critSteps, lastBreed, state) {};
                // empty destructor
		~Ant() {}
		virtual Critter* move(Direction dir) override;
		virtual Critter* breed(Direction dir) override;
};

#endif
