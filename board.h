#include "queen.h"
#ifndef board_h
#define board_h

class Board {

 public:

  /**
   * Finds the best possible move for any given queen
   */
  Queen findBestMove(Queen);

 private:
  static const int32_t boardSize = 8;
  char chessBoard[boardSize][boardSize];

};

#endif // board_h
