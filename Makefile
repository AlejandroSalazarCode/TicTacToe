CXXFLAGS = -Wall -g -std=c++11

all: main.o TicTacToe.o player.o
	g++ $(CXXFLAGS) -o TicTacToe main.o TicTacToe.o player.o

main.o: main.cpp TicTacToe.h player.h
	g++ $(CXXFLAGS) -c main.cpp

TicTacToe.o: TicTacToe.cpp TicTacToe.h
	g++ $(CXXFLAGS) -c TicTacToe.cpp

player.o: player.cpp player.h
	g++ $(CXXFLAGS) -c player.cpp

clean:
	@rm -f *.o TicTacToe

