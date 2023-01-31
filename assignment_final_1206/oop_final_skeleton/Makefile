CXX = g++
CXXFLAGS = -std=c++11 -O2 -g
LD_FLAGS = -lncurses

MAIN = src/main.cpp
TEMPLATE_HEADER = src/Grid.h
SRC = $(wildcard src/*.cpp)
SRC := $(filter-out $(MAIN), $(SRC))
OBJS = $(SRC:.cpp=.o)
EXECUTABLE = output

.PHONY: all clean setup

all: $(EXECUTABLE)

clean:
	rm -f $(OBJS) $(EXECUTABLE)

setup:
	sudo apt-get update && sudo apt-get install libncurses5-dev libncursesw5-dev

$(EXECUTABLE): $(MAIN) $(OBJS) $(TEMPLATE_HEADER)
	$(CXX) $(CXXFLAGS) -o $@ $(MAIN) $(OBJS) $(LD_FLAGS)

$(OBJS): %.o: %.cpp $(TEMPLATE_HEADER)
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(LD_FLAGS)