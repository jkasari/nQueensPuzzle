#include "queen.h"
#ifndef board_h
#define board_h

class Board {

  friend std::ostream& operator<<(std::ostream&, const Board&);

 public:
  Board();


  /**
   * This goes over all the queens in play and populates the
   * board with them/
   */
  void update(std::vector<Queen>);

  /**
   * Finds the best possible move for any given queen
   */
  Queen findBestMove(Queen);


 private:
  /**
   * This leaves an '#' logo where a queen currently is.
   */
  void markBoard(Queen);
  static const int32_t boardSize = 8;
  char chessBoard[boardSize][boardSize];

};

#endif // board_h
