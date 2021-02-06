#include <iostream>
#include "nuttiest/nuttiest.hpp"
#include "queen.h"
#include "board.h"

using namespace std;
using namespace nuttiest;

int main() {
  section("Queen.moveTo") {
    unit_test("Move a queen around") {
      Queen elizabeth(0, 0);
      elizabeth.moveTo(4,0);
      assert_eq(4, elizabeth.row());
      assert_eq(0, elizabeth.col());

      elizabeth.moveTo(4, 7);
      assert_eq(4, elizabeth.row());
      assert_eq(7, elizabeth.col());
    }
  }
  section("Queen.row") {
    unit_test("Queen at a current row") {
      Queen elizabeth(0, 5);
      Queen spades(4, 5);
      assert_eq(0, elizabeth.row());
      assert_eq(4, spades.row());
    }
  }
  section("Queen.col") {
    unit_test("Queen at a current col") {
      Queen elizabeth(5, 0);
      Queen spades(5, 4);
      assert_eq(0, elizabeth.col());
      assert_eq(4, spades.col());
    }
  }
  section("Board.update()") {
    unit_test("Update the board!") {
      Board chessBoard;
      char location1 = chessBoard.testBoard(0, 0);
      char location2 = chessBoard.testBoard(5, 2);
      assert_eq(' ', location1);
      assert_eq(' ', location2);
      std::vector<Queen> queens {
        Queen(0, 0),
        Queen(5, 2),
      };
      chessBoard.update(queens);
      location1 = chessBoard.testBoard(0, 0);
      location2 = chessBoard.testBoard(5, 2);
      assert_eq('@', location1);
      assert_eq('@', location2);
      queens[0].moveTo(1, 0);
      queens[1].moveTo(1, 3);
      chessBoard.update(queens);
      location1 = chessBoard.testBoard(0, 0);
      location2 = chessBoard.testBoard(5, 2);
      assert_eq(' ', location1);
      assert_eq(' ', location2);


    }
  }

  summary();
}

