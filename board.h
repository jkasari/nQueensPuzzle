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
   * Takes a queen number and finds a place for queen on the |chessBoard|.
   * Also marks the board with all the queens potential moves.
   */
  bool placeQueens(const uint32_t);


 private:
  /**
   * Tells you if a colom has room for a queen.
   */
  bool isRoomFor(const uint32_t);

  /**
   * Takes a move number and increments the queen 1 place in that
   * direction.
   */
  Square moveQueen(const uint32_t, uint32_t, uint32_t);

  /**
   * Tells you all the potential moves for that queen.
   */

  const std::vector<Square> potentialMoves(Square);

  /**
   * Takes a location and marks all the potenial moves for that queen.
   * This leaves marks in |chessBoard|.
   */
  void decreaseMoves(const std::vector<Square>);

  /**
   * Does literally the oppisite of |decreaseMoves|.
   */
  void increaseMoves(const std::vector<Square>);

  /**
   * Returns true if the move is on the board.
   */
  bool isOnBoard(const uint32_t, const uint32_t);

  static const int32_t boardSize = 8;
  bool chessBoard[boardSize][boardSize];
  char displayChessBoard[boardSize][boardSize];

};

#endif // board_h
