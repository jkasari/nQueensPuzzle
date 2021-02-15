main: board
	g++ -O3 -std=c++17 main.cpp board.o -o run

test: board
	g++ -O3 -std=c++17 test.cpp board.o -o test
	./test

board:
	g++ -O3 -std=c++17 board.cpp -c

clean:
	rm -rf run test *.o

.PHONY: main test board  clean
