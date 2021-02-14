#include <iostream>
#include <unistd.h>
#include "board.h"
using namespace std;


int main() {
  Board chessBoard;
  chessBoard.placeQueens(0);
  cout << endl << chessBoard << endl;
  return 0;
}