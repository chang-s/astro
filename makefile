# Format based on www.cs.bu.edu/teaching/cpp/writing-makefiles/
# *****************************************************
# G++ Variables

CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall -g

# ****************************************************
# Objects required for compilation/executable

ExecGroup: GroupMain.o simulation.o grid.o critter.o ant.o
	$(CXX) $(CXXFLAGS) -o ExecGroup GroupMain.o simulation.o grid.o critter.o ant.o

GroupMain.o: simulation.hpp

simulation.o: grid.hpp

grid.o: ant.hpp

ant.o: critter.hpp

critter.o:

clean:
		-rm *.o ExecGroup