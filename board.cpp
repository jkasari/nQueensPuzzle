#include "board.h"
#include <iomanip>
#include <iostream>

std::ostream& operator<<(std::ostream& stream, const Board& displayChessBoard) {
  for(int i = 0; i < displayChessBoard.boardSize; ++i) {
    stream << "+---";
  }
  stream << "+" << std::endl;
  for (int i = 0; i < displayChessBoard.boardSize; i++) {
    stream << "| ";
    for (int j = 0; j < displayChessBoard.boardSize; j++) {
      //    stream << std::setfill('0') << std::setw(2);
      stream << static_cast<char>(displayChessBoard.displayChessBoard[i][j]) << " | ";
    }
    if (i < displayChessBoard.boardSize - 1) {
      stream << std::endl;
      for(int i = 0; i < displayChessBoard.boardSize; ++i) {
        stream << "|---";
      }
      stream << "|" << std::endl;
    }
  }
  stream << std::endl;
  for(int i = 0; i < displayChessBoard.boardSize; ++i) {
    stream << "+---";
  }
  stream << "+" << std::endl;
  return stream;
}

Board::Board(uint32_t sizeOfBoard) {
  boardSize = sizeOfBoard;
  allocate(boardSize);
  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < boardSize; j++) {
      displayChessBoard[i][j] = ' ';
      chessBoard[i][j] = true;
    }
  }
}

void Board::allocate(uint32_t sizeOfBoard) {
  chessBoard = new bool*[sizeOfBoard];
  for(int i = 0; i < sizeOfBoard; ++i) {
    chessBoard[i] = new bool[sizeOfBoard];
  }
  displayChessBoard = new char*[sizeOfBoard];
  for(int i = 0; i < sizeOfBoard; ++i) {
    displayChessBoard[i] = new char[sizeOfBoard];
  }
}

Board::~Board() {
  if(chessBoard) {
    for(int i = 0; i < boardSize; ++i) {
      delete[] chessBoard[i];
      chessBoard[i] = nullptr;
    }
    for(int i = 0; i < boardSize; ++i) {
      delete[] displayChessBoard[i];
      displayChessBoard[i] = nullptr;
    }
    delete[] chessBoard;
    delete[] displayChessBoard;
    chessBoard = nullptr;
    displayChessBoard = nullptr;
  }
}

bool Board::placeQueens(const uint32_t col) {
  if(col == boardSize) {
    return true;
  } else if(!isRoomFor(col)) {
    return false;
  }
  uint32_t row = 0;
  for(int row = 0; row < boardSize; row++) {
    if(chessBoard[row][col]) {
      std::vector<Square> moves = potentialMoves(Square(row, col));
      decreaseMoves(moves);
      if(placeQueens(col + 1)) {
        return true;
      }   else {
        increaseMoves(moves);
      }
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

const std::vector<Square> Board::potentialMoves(Square location) {
  uint32_t row = location.first;
  uint32_t col = location.second;
  std::vector<Square> newLocations;
  newLocations.push_back(Square(row, col));
  for(int i = 0; i < 8; i++) {
  row = moveQueen(i, row, col).first;
  col = moveQueen(i, row, col).second;
    while(isOnBoard(row, col)) {
      if(chessBoard[row][col]) {
        newLocations.push_back(Square(row, col));
      }
      row = moveQueen(i, row, col).first;
      col = moveQueen(i, row, col).second;
    }
    row = location.first;
    col = location.second;
  }
  return newLocations;
}


void Board::decreaseMoves(const std::vector<Square> locations) {
  uint32_t row = locations[0].first;
  uint32_t col = locations[0].second;
  chessBoard[row][col] = false;
  displayChessBoard[row][col] = '@';
  for(int i = 1; i < locations.size(); ++i) {
    row = locations[i].first;
    col = locations[i].second;
    chessBoard[row][col] = false;
  //  If you want to display the potential paths the queens can take un comment this.
  //  displayChessBoard[row][col] = '-';
  }
}

void Board::increaseMoves(const std::vector<Square> locations) {
  for(int i = 0; i < locations.size(); ++i) {
    uint32_t row = locations[i].first;
    uint32_t col = locations[i].second;
    chessBoard[row][col] = true;
    displayChessBoard[row][col] = ' ';
  }
}

bool Board::isOnBoard(const uint32_t row, const uint32_t col) {
  return (row >= 0 && boardSize > row && col >= 0 && boardSize > col);
}
