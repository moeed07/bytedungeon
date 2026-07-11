CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude

SRC = src/main.cpp
OUT = roguelike

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)
