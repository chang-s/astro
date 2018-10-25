/******************************************************************************
 * ** Program Name:	Group Project - Main
 * ** Author:      	Group 8
 * ** Date:        	October 24 2018
 * ** Description  	Main file for Group Project
 * ****************************************************************************/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <climits>
#include "simulation.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;


//Main to launch menu and create simulation
int main()
{
	srand(time(NULL));

	Simulation sim1;
	sim1.userStart();

	return 0;
}