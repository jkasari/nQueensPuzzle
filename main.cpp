#include <iostream>
#include <unistd.h>
#include <string>
#include "board.h"
using namespace std;


int main(int argc, char** argv) {
  uint32_t sizeOfBoard = stoul(argv[1]);
  Board chessBoard(sizeOfBoard);
  chessBoard.placeQueens(0);
  cout << endl << chessBoard << endl;
  return 0;
}