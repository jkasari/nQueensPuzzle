#include "board.h"
#include <iomanip>
#include <iostream>

std::ostream& operator<<(std::ostream& stream, const Board& displayChessBoard) {
  stream << "+---+---+---+---+---+---+---+---+" << std::endl;
  for (int i = 0; i < Board::boardSize; i++) {
    stream << "| ";
    for (int j = 0; j < Board::boardSize; j++) {
      //    stream << std::setfill('0') << std::setw(2);
      stream << static_cast<char>(displayChessBoard.displayChessBoard[i][j]) << " | ";
    }
    if (i < Board::boardSize - 1) {
      stream << std::endl << "|---|---|---|---|---|---|---|---|" << std::endl;
    }
  }
  stream << std::endl << "+---+---+---+---+---+---+---+---+" << std::endl;
  return stream;
}

Board::Board() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      displayChessBoard[i][j] = ' ';
      chessBoard[1][j] = true;
    }
  }
}

void Board::displayBoard(void) {
  uint32_t row = 0;
  uint32_t col = 0;
  while(isOnBoard(row, col)) {
    while(isOnboard(row, col)) {
      if(chessBoard[row][col]) {
        displayChessBoard[row][col] = '@';
      }
      col += 1;
    }
    col = 0;
    row += 1;
  }
  std::cout << displayChessBoard << std::endl;
}

void placeQueen(uint32_t row) {
  uint32_t col = 0;
  while(isOnBoard[row][col]) {
    if(chessBoard[row][col]) {
      decreaseMoves(row, col);
      return;
    }
    col += 1;
  }
}

Square moveQueen(uint32_t moveNumber, Square location) {
  uint32_t row = location.first;
  uint32_t col = location.second;
 switch(moveNumber) {
  case 0:
   return(Square(row + 1, co));
  case 1:
   return(Square(row, col + 1));
  case 2:
   return(Square(row, co));
  case 3:
   return(Square(row, co));
  case 4:
   return(Square(row, co));
  case 5:
   return(Square(row, co));
  case 6:
   return(Square(row, co));
  case 7:
   return(Square(row, co));
 }
}
