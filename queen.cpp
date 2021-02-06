#include "queen.h"

Queen::Queen(uint32_t currentRow, uint32_t currentCol) {
    this->currentRow = currentRow;
    this->currentCol = currentCol;
}


uint32_t Queen::row() {return currentRow;}

uint32_t Queen::col() {return currentCol;}
