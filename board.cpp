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
      chessBoard[i][j] = true;
    }
  }
}


bool Board::placeQueens(const uint32_t col) {
  if(col == 8) {
    return true;
  } else if(!isRoomFor(col)) {
    return false;
  }
  uint32_t row = 0;
  for(int row = 0; row < boardSize; row++) {
    if(chessBoard[row][col]) {
      decreaseMoves(Square(row, col));
    }
    if(placeQueens(col + 1)) {
      return true;
    } else {
      increaseMoves(Square(row, col));
    }
  }
  return false;
}

bool Board::isRoomFor(const uint32_t col) {
  for(int row = 0; row < boardSize; row++) {
    if(chessBoard[row][col]) {
      return true;
    }
  }
  return false;
}

Square Board::moveQueen(const uint32_t moveNumber, uint32_t row, uint32_t col) {
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

void Board::decreaseMoves(const Square location) {
  uint32_t row = location.first;
  uint32_t col = location.second;
  chessBoard[row][col] = false;
  displayChessBoard[row][col] = '@';

  for(int i = 0; i < 8; i++) {
  row = moveQueen(i, row, col).first;
  col = moveQueen(i, row, col).second;
    while(isOnBoard(row, col)) {
      if(chessBoard[row][col]) {
        chessBoard[row][col] = false;
        displayChessBoard[row][col] = '*';
      }
      row = moveQueen(i, row, col).first;
      col = moveQueen(i, row, col).second;
    }
    row = location.first;
    col = location.second;
  }
}

void Board::increaseMoves(const Square location) {
  uint32_t row = location.first;
  uint32_t col = location.second;
  chessBoard[row][col] = true;
  displayChessBoard[row][col] = ' ';

  for(int i = 0; i < 8; i++) {
  row = moveQueen(i, row, col).first;
  col = moveQueen(i, row, col).second;
    while(isOnBoard(row, col)) {
      if(!chessBoard[row][col]) {
        chessBoard[row][col] = true;
        displayChessBoard[row][col] = ' ';
      }
      row = moveQueen(i, row, col).first;
      col = moveQueen(i, row, col).second;
    }
    row = location.first;
    col = location.second;
  }
}

bool Board::isOnBoard(const uint32_t row, const uint32_t col) {
  return (row >= 0 && boardSize > row && col >= 0 && boardSize > col);
}
