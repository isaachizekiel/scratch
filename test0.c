#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main()
{
  unsigned char *chars = (unsigned char *)malloc(50);
  memset(chars, 0, 50);

  // I thought the entire buffer can be shifted
  // I am still wondering how the multi-precision works
  chars[0] <<=  chars[0];
  return 0;
}
