#include "queen.h"

Queen::Queen(int32_t currentRow, uint32_t currentCol) {
    this->currentRow = currentRow;
    this->currentCol = currentCol;
}

void Queen::moveTo(int32_t newRow, uint32_t newCol) {
    currentRow = newRow;
    currentCol = newCol;
}

int32_t Queen::row() {return currentRow;}

int32_t Queen::col() {return currentCol;}
