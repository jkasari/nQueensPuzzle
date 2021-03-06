#include <iostream>
#include <unistd.h>
#include <string>
#include "board.h"
using namespace std;


int main(int argc, char** argv) {
  if(argc != 2) {
    cout << endl;
    cout << "Just give the size of the board you want to calculate, nothing more, nothing less.";
    cout << endl << endl;
    return 0;
  }
  uint32_t sizeOfBoard = stoul(argv[1]);
  if(sizeOfBoard < 4) {
    cout << endl;
    cout << "Sorry partner, anything less then a 4 X 4 just don't work";
    cout << endl << endl;
    return 0;
  } else if( sizeOfBoard > 42) {
    cout << endl;
    cout << "Calm youself!! This isn't a super computer! You try solving with a board bigger then 42!";
    cout << endl << endl;
    return 0;
  }
  Board chessBoard(sizeOfBoard);
  chessBoard.placeQueens(0);
  cout << endl << chessBoard << endl;
  cout << "If apsolute power corrupts apsolutely, does absolute powerlessness make you pure?";
  cout << endl << endl;
  return 0;
}