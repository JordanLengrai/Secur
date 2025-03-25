#include <stdio.h>
#include "labels.h"

long __attribute__ ((noinline)) mult2(long a, long b){
  long s = a * b;
  DEBUG_LABEL(mult2_ret)
  return s;
}

void __attribute__ ((noinline)) multstore(long x, long y, long *dest){
  long t = mult2(x, y);
  DEBUG_LABEL(multstore_call)
  *dest = t;
  DEBUG_LABEL(multstore_ret)
}

int main(){
  long dst;
  multstore(52, 78, &dst);

  return dst;
}
