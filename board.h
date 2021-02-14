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
  void placeQueen(uint32_t);


 private:
  /**
   * Takes a move number and increments the queen 1 place in that
   * direction.
   */
  Square moveQueen(uint32_t, uint32_t, uint32_t);
  /**
   * Takes a location and marks all the potenial moves for that queen.
   * This leaves marks in |chessBoard|.
   */
  void decreaseMoves(Square);

  /**
   * Returns true if the move is on the board.
   */
  bool isOnBoard(uint32_t, uint32_t);

  static const int32_t boardSize = 8;
  bool chessBoard[boardSize][boardSize];
  char displayChessBoard[boardSize][boardSize];

};

#endif // board_h
