#include <stdio.h>




int
main()
{
  char a = 0x2e;

  char b = 0x67;

  // 11111111
  // 00001111 = 0x0f
  // 11110000 = 0xf0

  
  printf("%02x \n", a & 0x0f);
  printf("%02x \n", (a & 0xf0) >> 4);





  /*
  for (int i = 0, j = 0; i < 16; i++)
    {
      if (i % 4 == 0)
	{
	  j = i >> 2;
	}
      
      key[i % 4][j] = k[i];      
      printf("(%d, %d)  ", i % 4, j);
    }
  */
  
  
  return 0;
}


