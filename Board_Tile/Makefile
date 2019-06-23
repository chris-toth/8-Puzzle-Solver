CC = g++
CFLAGS = -g -Wall

All: A
	
A: Board_Tile.o Sliding_Solver.o main.o
	$(CC) $(CFLAGS) -o main Board_Tile.o Sliding_Solver.o main.o

Board_Tile.o: Board_Tile.cpp Board_Tile.h
	$(CC) $(CFLAGS) -c Board_Tile.cpp

Sliding_Solver.o: Board_Tile.h Sliding_Solver.h Sliding_Solver.cpp
	$(CC) $(CFLAGS) -c Sliding_Solver.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -rf *.o
	rm -f main
