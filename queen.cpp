#include "queen.h"

Queen::Queen(uint32_t currentRow, uint32_t currentCol) {
    this->currentRow = currentRow;
    this->currentCol = currentCol;
}

void Queen::moveTo(uint32_t newRow, uint32_t newCol) {
    currentRow = newRow;
    currentCol = newCol;
}

uint32_t Queen::row() {return currentRow;}

uint32_t Queen::col() {return currentCol;}
