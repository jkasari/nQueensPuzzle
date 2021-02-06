main: board
	g++ -std=c++17 main.cpp board.o queen.o -o run

test: board
	g++ -std=c++17 test.cpp board.o queen.o -o test
	./test

board: queen
	g++ -std=c++17 board.cpp queen.o -c

queen:
	g++ -std=c++17 queen.cpp -c

clean:
	rm -rf run test *.o

.PHONY: main test board queen clean
