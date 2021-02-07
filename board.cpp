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
        if(i < vec[i]) {
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

    // Move up.
    for(int i = 0; i < boardSize; ++i) {
        row++;
        if(isOnBoard(row, col) && chessBoard[row][col] == ' ') {
          newMoves.push_back(Square(row, col));
        }
    }
    row = elizabeth.row();
    col = elizabeth.col();

    // Move down.
    for(int i = 0; i < boardSize; ++i) {
        row--;
        if(isOnBoard(row, col) && chessBoard[row][col] == ' ') {
          newMoves.push_back(Square(row, col));
        }
    }
    row = elizabeth.row();
    col = elizabeth.col();

    // Move left.
    for(int i = 0; i < boardSize; ++i) {
        col--;
        if(isOnBoard(row, col) && chessBoard[row][col] == ' ') {
          newMoves.push_back(Square(row, col));
        }
    }
    row = elizabeth.row();
    col = elizabeth.col();

    // Move right.
    for(int i = 0; i < boardSize; ++i) {
        col++;
        if(isOnBoard(row, col) && chessBoard[row][col] == ' ') {
          newMoves.push_back(Square(row, col));
        }
    }
    row = elizabeth.row();
    col = elizabeth.col();

    // Move diagonally up and left.
    for(int i = 0; i < boardSize; ++i) {
        row--;
        col--;
        if(isOnBoard(row, col) && chessBoard[row][col] == ' ') {
          newMoves.push_back(Square(row, col));
        }
    }
    row = elizabeth.row();
    col = elizabeth.col();

    // Move diagonally up and right.
    for(int i = 0; i < boardSize; ++i) {
        row--;
        col++;
        if(isOnBoard(row, col) && chessBoard[row][col] == ' ') {
          newMoves.push_back(Square(row, col));
        }
    }
    row = elizabeth.row();
    col = elizabeth.col();

    // Move diagonally down and left.
    for(int i = 0; i < boardSize; ++i) {
        row++;
        col--;
        if(isOnBoard(row, col) && chessBoard[row][col] == ' ') {
          newMoves.push_back(Square(row, col));
        }
    }
    row = elizabeth.row();
    col = elizabeth.col();

    // Move diagonally down and right.
    for(int i = 0; i < boardSize; ++i) {
        row++;
        col++;
        if(isOnBoard(row, col) && chessBoard[row][col] == ' ') {
          newMoves.push_back(Square(row, col));
        }
    }
    return newMoves;
}


int32_t Board::underAttackBy(Square location) {
    int32_t row = location.first;
    int32_t col = location.second;
    int32_t numberOfAttackers = 0;

    // Move up.
    while(isOnBoard(row, col)) {
       row--;
       if(chessBoard[row][col] == '@') {
         numberOfAttackers++;
         row = -1;
       }
    }
    row = location.first;
    col = location.second;

    // Move down.
    while(isOnBoard(row, col)) {
       row++;
       if(chessBoard[row][col] == '@') {
         numberOfAttackers++;
         row = -1;
       }
    }
    row = location.first;
    col = location.second;

    // Move left.
    while(isOnBoard(row, col)) {
       col--;
       if(chessBoard[row][col] == '@') {
         numberOfAttackers++;
         row = -1;
       }
    }
    row = location.first;
    col = location.second;

    // Move right.
    while(isOnBoard(row, col)) {
       col++;
       if(chessBoard[row][col] == '@') {
         numberOfAttackers++;
         row = -1;
       }
    }
    row = location.first;
    col = location.second;

    // Move diagonally up and left.
    while(isOnBoard(row, col)) {
       row--;
       col--;
       if(chessBoard[row][col] == '@') {
         numberOfAttackers++;
         row = -1;
       }
    }
    row = location.first;
    col = location.second;

    // Move diagonally up and right.
    while(isOnBoard(row, col)) {
       row++;
       col--;
       if(chessBoard[row][col] == '@') {
         numberOfAttackers++;
         row = -1;
       }
    }
    row = location.first;
    col = location.second;

    // Move diagonally down and left.
    while(isOnBoard(row, col)) {
       row--;
       col++;
       if(chessBoard[row][col] == '@') {
         numberOfAttackers++;
         row = -1;
       }
    }
    row = location.first;
    col = location.second;

    // Move diagonally down and right.
    while(isOnBoard(row, col)) {
       row++;
       col++;
       if(chessBoard[row][col] == '@') {
         numberOfAttackers++;
         row = -1;
       }
    }
    if(numberOfAttackers == 1) {
      numberOfAttackers = 2;
    }
    return numberOfAttackers;
}

bool Board::keepTrying(std::vector<Queen> queens) {
    return true;
    for(int i = 0; i < queens.size(); ++i) {
        if(0 != underAttackBy(Square(queens[i].row(), queens[i].col()))) {
            return true;
        } else {
            return false;
        }
    }
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
  return moveValues[findSmallestIndex(moveValues)];
}