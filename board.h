#include "queen.h"
#ifndef board_h
#define board_h

class Board {

  friend std::ostream& operator<<(std::ostream&, const Board&);

 public:
  Board();

  /**
   * This is just for tests!!!!! Tells you what char is currently
   * at a given location on a board.
   */
  char testBoard(uint32_t, uint32_t);

  /**
   * This goes over all the queens in play and populates the
   * board with them. Using '@' to mark their loactions.
   */
  void update(std::vector<Queen>);

  /**
   * Finds the best possible move for any given queen
   */
  Queen findBestMove(Queen);


 private:
  /**
   * This cleans the board of any markings left over.
   */
  void cleanBoard(void);

  /**
   * This leaves an '@' char where a queen currently is.
   */
  void markBoard(Queen);
  static const int32_t boardSize = 8;
  char chessBoard[boardSize][boardSize];

};

#endif // board_h
