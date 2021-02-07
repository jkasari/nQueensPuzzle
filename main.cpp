#include <iostream>
#include <unistd.h>
#include "board.h"
#include "queen.h"
using namespace std;

int32_t boardSize = 8;
int32_t row = 0;
int32_t col = 0;
int32_t choiceQueen = 0;

int main() {
  Board chessBoard;
  vector<Queen> queens;
  for (int i = 0; i < boardSize; ++i) {
    Queen elizabeth(0, i);
    queens.push_back(elizabeth);
  }

  while (chessBoard.keepTrying(queens)) {
    chessBoard.update(queens);
    cout << chessBoard << endl;

    choiceQueen = chessBoard.queenToMove(queens);
    row = chessBoard.findBestMove(queens[choiceQueen]).first;
    col = chessBoard.findBestMove(queens[choiceQueen]).second;
    queens[choiceQueen].moveTo(row, col);
    usleep(1000000);
  }
  return 0;
}