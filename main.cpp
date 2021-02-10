#include <iostream>
#include <unistd.h>
#include "board.h"
#include "queen.h"
using namespace std;

int32_t boardSize = 8;
int32_t row = 0;
int32_t col = 0;
int32_t choiceQueen = 0;
int32_t oldQueen = 0;
int32_t queenCount = 0;

int main() {
  Board chessBoard;
  vector<Queen> queens;
  for (int i = 0; i < boardSize; ++i) {
    Queen elizabeth(0, i);
    queens.push_back(elizabeth);
    chessBoard.update(queens);
  }

  int cycle = 0;
  while (chessBoard.keepTrying(queens)) {
    cycle++;
    choiceQueen = chessBoard.queenToMove(queens);
    if(oldQueen == choiceQueen) {
      queenCount++;
      if(queenCount == 3) {
        choiceQueen += 1;
        queenCount = 0;
      }
    }
    oldQueen = choiceQueen;



    row = chessBoard.findBestMove(queens[choiceQueen]).first;
    col = chessBoard.findBestMove(queens[choiceQueen]).second;
    queens[choiceQueen].moveTo(row, col);
    chessBoard.update(queens);
    cout << chessBoard << endl;
    cout << "  ";
    for(int i = 0; i < 7; ++i) {
      cout << chessBoard.underAttackBy(Square(queens[i].row(), queens[i].col())) << " - ";
    }
    cout << chessBoard.underAttackBy(Square(queens[7].row(), queens[7].col())) << endl;
    usleep(1000000);
  //  }
  }
 // cout << chessBoard << endl;

 // Queen mary(4,3);
 // vector<Square> moves = chessBoard.potentialMoves(mary);
 // for(int i = 0; i < moves.size(); ++i) {
 //   chessBoard.markBoard(moves[i]);
 // }
 // cout << chessBoard << endl;


 // return 0;
}