#include <stdint.h>
#include <stdio.h>
#include "labels.h"

void  __attribute__ ((noinline)) swap(int64_t *x, int64_t *y) {
  int64_t t = *x;
  DEBUG_LABEL(swap2)
  *x = *y;
  DEBUG_LABEL(swap3)
  *y = t;
}

void main(){
  int64_t a = 0xDEADBEEFDECAFBAD;
  int64_t b = 0x8BADF00DFEEDF00D;

  printf("[swap:%d] a = 0x%lx; b = 0x%lx\n", __LINE__, a, b);

  swap(&a, &b);

  printf("[swap:%d] a = 0x%lx; b = 0x%lx\n", __LINE__, a, b);

}
