#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include "labels.h"

int main (int argc, char* argv[]) {

  uint64_t ux = 0x8000000000000000;
  uint64_t uy = 0x3fffffffffffffff;

  int64_t sx = 0x8000000000000000;
  int64_t sy = 0x3fffffffffffffff;

  printf("[jcc:%d] unsigned, x = %lu, y = %lu\n", __LINE__, ux, uy);
  printf("[jcc:%d] signed, x = %ld, y = %ld\n", __LINE__, sx, sy);

  DEBUG_LABEL(jcc_jae)
  if (ux > uy) {
    DEBUG_LABEL(jcc_jae_no_jump)
    printf("[jcc:%d] x >u y\n", __LINE__);
  } else {
    printf("[jcc:%d] x <=u y\n", __LINE__);
  }

  DEBUG_LABEL(jcc_jne)
  if (ux == uy) {
    printf("[jcc:%d] x == y\n", __LINE__);
  } else {
    DEBUG_LABEL(jcc_jne_jump)
    printf("[jcc:%d] x != y\n", __LINE__);
  }

  DEBUG_LABEL(jcc_jle)
  if (sx > sy) {
    printf("[jcc:%d] x >s y\n", __LINE__);
  } else {
    DEBUG_LABEL(jcc_jle_jump)
    printf("[jcc:%d] x <=s y\n", __LINE__);
  }

  return 1;

}
