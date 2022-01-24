#include <stdio.h>


unsigned char gmul(unsigned char a, unsigned char b) {
	unsigned char p = 0;
	while (a && b) {
            if (b & 1)
                p ^= a;

            if (a & 0x80) 
                a = (a << 1) ^ 0x11b;
            else
                a <<= 1; /* equivalent to a*2 */
            b >>= 1; /* equivalent to b // 2 */
	}
	return p;
}


// Bitwise ("peasant") multiplication, using galois addition



int
main()
{

  unsigned char a = 0xd4;
  unsigned char s = 0x00;
    

  unsigned char f[4] = {0x2, 0x3, 0x1, 0x1};
  //unsigned char f[4] = {0x2, 0x3, 0x1, 0x3};  
  
  for (int i = 0; i < 4; i++)
    {
      s ^= gmul(a, f[i]);
      printf("%02x * %02x = %02x \n", a, f[i], s);

      
    }

  
  printf("%02x\n", s);
  //printf("%06x %02x\n", (((0xff * 0xff) & 0xff00) >> 8) & 0xff, 283);
  
  return 0;
}
