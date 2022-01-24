#include <stdio.h>
#include <inttypes.h>


int main()
{
  
  unsigned char x[4] = {0xd4, 0xbf, 0x5d, 0x30};
  unsigned char y[4] = { 0x01, 0x02, 0x03, 0x01 };
  
  unsigned char a = 0x00;
  uint16_t b = 0x0000;

  for (int i = 0; i < 4; i++)
    {      

      if (y[i] == 3)
	{
	  b = (x[i] * 2) ^ x[i];
	}
      else
	{
	  b = x[i] * y[i];
	}
      
      if (b >> 8)
	{
	  b ^= 0x1b;
	}
      
      a ^= b;

    }

  printf("%04x\n", a);
  printf("\n");
  
  return 0;
  
}
