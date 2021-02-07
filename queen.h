#include <vector>
#ifndef queen_h
#define queen_h



class Queen {

 public:
  Queen(int32_t, uint32_t);

  /**
   * Takes a new location and moves the queen there.
   */
  void moveTo(int32_t, uint32_t);

  /**
   * Returns the |row| of a |queen|.
   */
  int32_t row();

  /**
   * Returns the |col| of a |queen|.
   */
  int32_t col();

 private:

  int32_t currentRow;
  int32_t currentCol;
};

#endif // queen_h
