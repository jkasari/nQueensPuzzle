#include <iostream>
#include <unistd.h>
#include "board.h"
#include "queen.h"
using namespace std;

int32_t boardSize = 8;
int32_t row = 0;
int32_t col = 0;

int main() {
  Board chessBoard;
  vector<Queen> queens;
  for (int i = 0; i < boardSize; ++i) {
    Queen elizabeth(0, i);
    queens.push_back(elizabeth);
  }


  while(chessBoard.keepTrying(queens)) {
    for (int i = 0; i < boardSize; i++) {
      chessBoard.update(queens);
      cout << chessBoard << endl;
      row = chessBoard.findBestMove(queens[i]).first;
      col = chessBoard.findBestMove(queens[i]).second;
      queens[i].moveTo(row, col);
      usleep(100000);
    }
  }
  return 0;
}