#include <stdio.h>
#include <string.h>



int
main()
{

  unsigned char k = 'o';

  unsigned char m1 = 'a';
  unsigned char m2 = 'b';
  unsigned char m3 = 'd';

  unsigned char c1 = k ^ m1;
  unsigned char c2 = k ^ m2;
  unsigned char c3 = k ^ m3;

  unsigned char cs = c1 ^ c2 ^ c3;
    
  unsigned char s = (cs ^ k);
  unsigned char m = c1 ^ s;

  
  printf("M: %02x %02x %02x\n", m1, m2, m3);
  printf("K: %02x %02x %02x\n", k, k, k);
  printf("C: %02x %02x %02x\n", c1, c1, c3);
					       

  printf("\nS:%02x %c\n\n", s, s);
  
  printf("D: %02x %02x %02x\n", (cs ^ c1) ^ s, (cs ^ c2) ^ s, (cs ^ c3) ^ s);
  printf("E: %02x %02x %02x\n", (cs ^ m1) ^ s, (cs ^ m2) ^ s, (cs ^ m3) ^ s);

  printf("\n");

  // c = k ^ m

  //cs ^ ? = c1 ^ k = [ASCII]


  for (unsigned char i = 0; i < 0xff; i++)
    {      
      if (i % 16 == 0) printf("\n");


      if( (i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
	{
	  printf("\033[0;31m%02x\033[0m ", i);
	}
      else if (i >= '0' && i <= '9')
	{
	  printf("\033[0;33m%02x\033[0m ", i);      
	}
      else
	{
	  printf("%02x ", i);      
	}	      
    }

  printf("%02x\n\n", 0xff);

  
  return 0;
}
