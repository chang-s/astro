So mine hasMy current version has 4 different main classes currently:

Critter - Base for Ant
Ant - Derived from critter, overrides the move function
*DoodleBug - Not yet implemented
Grid - Stores the 2D Array of Critter Pointers and gives functions to manipulate
Simulation - Actually generates the grid and handles the turns/moves

Parts of the simulation I actually implemented so far are just AntMove and Aging Critters

The Grid completely filled with Critter Pointers, and base critters just show up
as empty spaces when we print/evaluate whether a spot is available to move to. 

Once we find a spot to move to, we swap the Ant Pointer with the empty Critter 
Pointer. We also flip a flag to record the Ant as having moved so we don't
accidently move it twice if the Ant gets cycled again later in the array

For anyone wanting to test, try out the simulation userStart and nextSteps function.

It is hardcoded to a 20 x 20 grid for now, but that can be changed later.
