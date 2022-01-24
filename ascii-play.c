#include <stdio.h>

int main()
{
  /*
  for (int i = 0; i < 256; i++)
    {
      if (i == 0x00 || i == 0x20 || i == 0x40 || i == 0x60 || i == 0x80 ||
	  i == 0xa0 || i == 0xc0 || i == 0xe0)
	{
	  printf("\n");
	}
      printf("%c ", i);
    }
  printf("\n\n");
  */

  
  
  for (int i = 0; i < 256; i++)
    {
      if (i == 0x00 ||
	  //i == 0x10 ||
	  i == 0x20 ||
	  //i == 0x30 ||
	  i == 0x40 ||
	  //i == 0x50 ||
	  i == 0x60 ||
	  //i == 0x70 ||
	  i == 0x80 ||
	  //i == 0x90 ||
	  i == 0xA0 ||
	  //i == 0xB0 ||
	  i == 0xC0 ||
	  //i == 0xD0 ||
	  i == 0xE0 )
	  // i == 0xF0 )
	  
	{
	  printf("\n");
	}
      printf("%02x ", i);

    }

  printf("\n\n");
  
}
