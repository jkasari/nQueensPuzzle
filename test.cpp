#include <iostream>
#include "nuttiest/nuttiest.hpp"
#include "queen.h"

using namespace std;
using namespace nuttiest;

int main() {
  section("row") {
    unit_test("Queen at a current row") {
      Queen hearts(0, 5);
      Queen spades(4, 5);
      assert_eq(0, hearts.row());
      assert_eq(4, spades.row());
    }
  }
  section("col") {
    unit_test("Queen at a current col") {
      Queen hearts(5, 0);
      Queen spades(5, 4);
      assert_eq(0, hearts.col());
      assert_eq(4, spades.col());
    }
  }

  summary();
}

