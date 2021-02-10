#include "board.h"
#include "queen.h"
#include <iomanip>

std::ostream& operator<<(std::ostream& stream, const Board& chessBoard) {
  stream << "+---+---+---+---+---+---+---+---+" << std::endl;
  for (int i = 0; i < Board::boardSize; i++) {
    stream << "| ";
    for (int j = 0; j < Board::boardSize; j++) {
      //    stream << std::setfill('0') << std::setw(2);
      stream << static_cast<char>(chessBoard.chessBoard[i][j]) << " | ";
    }
    if (i < Board::boardSize - 1) {
      stream << std::endl << "|---|---|---|---|---|---|---|---|" << std::endl;
    }
  }
  stream << std::endl << "+---+---+---+---+---+---+---+---+" << std::endl;
  return stream;
}

char Board::testBoard(int32_t row, uint32_t col) {
  return chessBoard[row][col];
}

Board::Board() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      chessBoard[i][j] = ' ';
    }
  }
}


int32_t Board::findSmallestIndex(std::vector<int32_t> vec) {
    int32_t tempVal = vec[0];
    int32_t index = 0;
    for(int i = 0; i < vec.size(); ++i) {
        if(tempVal > vec[i]) {
            tempVal = vec[i];
            index = i;
        }
    }
    return index;
}

void Board::update(std::vector<Queen> queens) {
  cleanBoard();
  for (int q = 0; q < queens.size(); ++q) {
    for (int i = 0; i < boardSize; ++i) {
      if (queens[q].row() == i) {
        for (int j = 0; j < boardSize; ++j) {
          if (queens[q].col() == j) {
            markBoard(queens[q]);
          }
        }
      }
    }
  }
}

void Board::markBoard(Square location) {
    chessBoard[location.first][location.second] = '*';
}


void Board::cleanBoard() {
  for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        chessBoard[i][j] = ' ';
      }
    }
}

void Board::markBoard(Queen elizabeth) {
  chessBoard[elizabeth.row()][elizabeth.col()] = '@';
}

bool Board::isOnBoard(int32_t row, uint32_t col) {
    if(row < boardSize && 0 <= row && col < boardSize && 0 <= col) {
        return true;
    } else {
        return false;
    }
}



std::vector<Square> Board::potentialMoves(Queen elizabeth) {
  int32_t row = elizabeth.row();
  int32_t col = elizabeth.col();
  std::vector<Square> newMoves;

  for(int i = 0; i < 8; ++i) {
    row = queensMoves(i, row, col).first;
    col = queensMoves(i, row, col).second;
    while(isOnBoard(row, col) && chessBoard[row][col] != '@') {
      newMoves.push_back(Square(row, col));
    row = queensMoves(i, row, col).first;
    col = queensMoves(i, row, col).second;
    }
    row = elizabeth.row();
    col = elizabeth.col();
  }
  return newMoves;
}


int32_t Board::underAttackBy(Square location) {
  int32_t row = location.first;
  int32_t col = location.second;
  int32_t numberOfAttackers = 0;

  for(int i = 0; i < 8; i++) {
    while(isOnBoard(row, col)) {
      row = queensMoves(i, row, col).first;
      col = queensMoves(i, row, col).second;
      if(chessBoard[row][col] == '@') {
        numberOfAttackers += 1;
        break;
      }
    }
    row = location.first;
    col = location.second;
  }
  return numberOfAttackers;
}

//takes a square and a number. The number is 1 - 8 on moves the queen can make.
//returns an incremented Square of the original moves.
//so (8, 0, 0) should return Square(1, 1) as 8 iincreases both rows and coloms.
Square Board::queensMoves(int32_t moveNumber, int32_t row, int32_t col) {
 switch(moveNumber) {
 case 0:
  return(Square(row - 1, col));
 case 1:
  return(Square(row + 1, col));
 case 2:
  return(Square(row, col - 1));
 case 3:
  return(Square(row, col + 1));
 case 4:
  return(Square(row - 1, col + 1));
 case 5:
  return(Square(row - 1 , col - 1));
 case 6:
  return(Square(row + 1 , col - 1));
 case 7:
  return(Square(row + 1, col + 1));
 }
 //If the number is not 1 - 8 this returns a 0, 0 location.
 return(Square(0, 0));
}





bool Board::keepTrying(std::vector<Queen> queens) {
    for(int i = 0; i < queens.size(); ++i) {
        if(0 != underAttackBy(Square(queens[i].row(), queens[i].col()))) {
            return true;
        }
    }
    return false;
}


Square Board::findBestMove(Queen elizabeth) {
    std::vector<Square> moves(potentialMoves(elizabeth));
    std::vector<int32_t> moveValues;

    for(int i = 0; i < moves.size(); ++i) {
        moveValues.push_back(underAttackBy(moves[i]));
    }
    return moves[findSmallestIndex(moveValues)];
}


int32_t Board::queenToMove(std::vector<Queen> queens) {
  std::vector<int32_t> moveValues;
  for(int i = 0; i < queens.size(); ++i) {
    moveValues.push_back(underAttackBy(findBestMove(queens[i])));
  }
  return findSmallestIndex(moveValues);
}