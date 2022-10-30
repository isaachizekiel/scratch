#include <stdio.h>

int main() {

  unsigned char c; // 0 0 0 0 0 0 0 0

  // 0 0 0 0 0 x 0 0 
  c ^= 0x4; // set or unset the third bit
  printf("%02x\n", c);

  // 0 0 0 0 0 0 x 0 
  c ^= 0x2; // set or unset the second bit
  printf("%02x\n", c);

  // 0 0 0 0 0 0 0 x 
  c ^= 0x1; // set or unset the first bit
  printf("%02x\n", c);
  
  return 42;
}    
