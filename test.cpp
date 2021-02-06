#include <iostream>
#include "nuttiest/nuttiest.hpp"
#include "queen.h"

using namespace std;
using namespace nuttiest;

int main() {
  section("row") {
    unit_test("A queen on row 4") {
      queen hearts(4, 5);
      assert_eq(4, hearts.row());
    }
  }

  summary();
}

