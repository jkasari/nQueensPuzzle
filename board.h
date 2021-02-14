#include <vector>
#include <utility>
#ifndef board_h
#define board_h


using Square = std::pair<int8_t, int8_t>;

class Board {

  friend std::ostream& operator<<(std::ostream&, const Board&);

 public:
  Board(uint32_t);
  ~Board();

  /**
   * Takes a queen number and finds a place for queen on the |chessBoard|.
   * Also marks the board with all the queens potential moves.
   */
  bool placeQueens(const uint32_t);


 private:

  /**
   * Finds a spot on the heap for |Board| data members.
   */
  void allocate(uint32_t);

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

  int32_t boardSize;
  bool** chessBoard;
  char** displayChessBoard;

};

#endif // board_h
