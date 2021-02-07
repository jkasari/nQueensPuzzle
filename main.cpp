#include <iostream>
#include "board.h"
#include "queen.h"
using namespace std;

int main () {
Board chessBoard;
Queen elizabeth(4, 2);
vector<Square> moves = chessBoard.potentialMoves(elizabeth);
vector<Queen> queens;

for(int i = 0; i < moves.size(); ++i) {
    Queen mary(moves[i].first, moves[i].second);
    queens.push_back(mary);
}

chessBoard.update(queens);
cout << chessBoard << endl;
// Create 8 queens.
// cycle through those 8 queens.
// Each queen is going to leave a mark on the board of it's current location.
// Use the chessboard to judge where best to move queen.
// The move will change the queens data memebers AND change the marking on the chess baord.



}