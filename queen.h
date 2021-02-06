#include <vector>
#ifndef queen_h
#define queen_h

using Position = std::array<uint32_t, 2>;


class queen {

 public:
  queen(uint32_t, uint32_t);

  /**
   * Returns a value that represents how many other |queen|s are
   * a |queen| from any given location.
   */
  uint32_t underAttackFrom(uint32_t, uint32_t);

  /**
   * Returns the |row| of a |queen|.
   */
  uint32_t row();

  /**
   * Returns the |col| of a |queen|.
   */
  uint32_t col();

 private:

  uint32_t currentRow;
  uint32_t currentCol;
};

#endif // queen_h
