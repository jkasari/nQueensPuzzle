#include "queen.h"
#include <vector>
#include <utility>
#ifndef board_h
#define board_h


using Square = std::pair<int8_t, int8_t>;

class Board {

  friend std::ostream& operator<<(std::ostream&, const Board&);

 public:
  Board();

  /**
   * This is just for tests!!!!! Tells you what char is currently
   * at a given location on a board.
   */
  char testBoard(int32_t, uint32_t);

  /**
   * This goes over all the queens in play and populates the
   * board with them. Using '@' to mark their loactions.
   */
  void update(std::vector<Queen>);

  /**
   * Finds the best possible move for any given queen
   */
  Square findBestMove(Queen);



 private:
  /**
   * Finds the index of the smallest value in an vector.
   */
  int32_t findSmallestIndex(std::vector<int32_t>);

  /**
   * This cleans the board of any markings left over.
   */
  void cleanBoard(void);

  /**
   * This leaves an '@' char where a queen currently is.
   */
  void markBoard(Queen);

  /**
   * This gives you the number of other queens that can
   * attack any given location.
   */
  int32_t underAttackBy(Square);

  /**
   * Returns true if a position is on a the board and
   * false if it is off the board.
   */
  bool isOnBoard(int32_t, uint32_t);

  /**
   * Takes a queen and tells you all the okay places
   * to move it on a live board accounting for other
   * queens.
   */
  std::vector<Square> potentialMoves(Queen);

  static const int32_t boardSize = 8;
  char chessBoard[boardSize][boardSize];

};

#endif // board_h
