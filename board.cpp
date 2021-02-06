#include "board.h"
#include "queen.h"
#include <iomanip>

std::ostream& operator<<(std::ostream& stream, const Board& chessBoard) {
    stream << "+---+---+---+---+---+---+---+---+" << std::endl;
    for(int i = 0; i < Board::boardSize; i++) {
        stream << "| ";
        for(int j = 0; j < Board::boardSize; j++) {
        //    stream << std::setfill('0') << std::setw(2);
            stream << static_cast<char>(chessBoard.chessBoard[i][j]) << " | ";
        }
        if(i < Board::boardSize - 1) {
          stream << std::endl << "|---|---|---|---|---|---|---|---|" << std::endl;
        }
    }
    stream << std::endl << "+---+---+---+---+---+---+---+---+" << std::endl;
    return stream;
}


Board::Board() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            chessBoard[i][j] = ' ';
        }
    }
}