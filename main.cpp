#include <iostream>
#include <unistd.h>
#include "board.h"
using namespace std;


int main() {
  Board chessBoard;
  for(int i = 0; i < 8; ++i) {
    chessBoard.placeQueen(i);
    cout << i << " - ";
  }
  cout << endl << chessBoard << endl;
  return 0;
}