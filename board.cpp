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
  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < boardSize; j++) {
      displayChessBoard[i][j] = ' ';
      chessBoard[1][j] = true;
    }
  }
}

void Board::displayBoard(void) {
  uint32_t row = 0;
  uint32_t col = 0;
  while(isOnBoard(row, col)) {
    while(isOnBoard(row, col)) {
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

void Board::placeQueen(uint32_t row) {
  uint32_t col = 0;
  while(isOnBoard(row, col)) {
    if(chessBoard[row][col]) {
      decreaseMoves(Square(row, col));
      return;
    }
    col += 1;
  }
}

Square Board::moveQueen(uint32_t moveNumber, Square location) {
  uint32_t row = location.first;
  uint32_t col = location.second;
 switch(moveNumber) {
  case 0:
   return(Square(row + 1, col));
  case 1:
   return(Square(row, col + 1));
  case 2:
   return(Square(row - 1, col));
  case 3:
   return(Square(row, col - 1));
  case 4:
   return(Square(row + 1, col + 1));
  case 5:
   return(Square(row + 1, col - 1));
  case 6:
   return(Square(row - 1, col + 1));
  case 7:
   return(Square(row - 1, col - 1));
 }
 return Square(0, 0);
}

void Board::decreaseMoves(Square location) {
  uint32_t row = location.first;
  uint32_t col = location.second;

  for(int i = 0; i < 8; i++) {
    while(isOnBoard(row, col)) {
      chessBoard[row][col] = false;
      row = moveQueen(i, location).first;
      col = moveQueen(i, location).second;
    }
    row = location.first;
    col = location.second;
  }
}

bool Board::isOnBoard(uint32_t row, uint32_t col) {
  return (row >= 0 && boardSize > row && col >= 0 && boardSize > col);
}
