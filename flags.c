#include <stdint.h>
#include <stdio.h>
#include "labels.h"

int main() {

  int32_t x = 2050000000;
  int32_t y = 2100000000;

  printf("[flags:%d] x = %i, y = %i\n", __LINE__, x, y);

  DEBUG_LABEL(sub_x_y)
  int32_t sub = x - y;

  printf("[flags:%d] x - y = %i (signed), %u (unsigned)\n", __LINE__, sub, sub);

  DEBUG_LABEL(add_x_y)
  int32_t add = x + y;

  printf("[flags:%d] x + y = %i (signed), %u (unsigned)\n", __LINE__, add, add);
}
