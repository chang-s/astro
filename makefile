=======
# variables
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = predPrey.o game.o critter.o ant.o db.o menu.o utils.o
SRCS = predPrey.cpp game.cpp critter.cpp ant.cpp db.cpp menu.cpp utils.cpp
HEADERS = game.hpp critter.hpp ant.hpp db.hpp menu.hpp utils.hpp
EXEC = predatorPreyGame

# compilation
$(EXEC): $(OBJS) $(HEADERS)
	$(CXX) $(OBJS) -o $(EXEC)

# generation of object files
$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) -c $(@:.o=.cpp)

# cleaning
clean:
	rm *.o $(EXEC)
	
# zipping
zip:
	zip -D Group8.zip *.cpp *.hpp makefile
