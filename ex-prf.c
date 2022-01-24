#include <stdio.h>

int
main()
{

  int k[] = {1, 0, 0, 1};
  
  int t = 0x00;

  int x[] = {0x06, 0x05, 0x0e, 0xd};
  


  for (unsigned char i = 0; i <= 0x0f; i++)
    {
      for (int j = 0; j < 4; j++)
	{
	  t = x[j] ^ i;

	  if (t == 0x03 || t == 0x0a || t == 0x0e)
	    {

		
	      printf("\033[0;31m%02x\033[0m ", t);
	    

	    }
	  else
	    {
	      printf("%02x ", 0x00);
	    }
	    
	}

      printf("\n");
    }

  printf("\n");
  printf("\n");

  for (unsigned char i = 0; i < 0x0a; i++)
    {
      for (unsigned char j = 0; j < 0x0a; j++)
	{
	  t = i ^ j;
	  if (t == 0x0a)
	    {
	      //intf("%02x %02x ", i , j);
	      printf("\033[0;31m%02x\033[0m %02x %02x ", t, i , j);
	    }
	  else
	    {
	      printf("%c ", ' ');
	    }

	}

      printf("\n");
    }

  printf("\n");
  printf("\n");



  unsigned char k0 = 0x11;
  unsigned char k1 = 0xf0;
  unsigned char k2 = 0x0a;
  unsigned char k3 = 0xd1;
  unsigned char k4 = 0x03;


  printf("%02x\n", k0 ^ k2 ^ k3);

  printf("%02x\n", k0 ^ k1 ^ k2 ^ k3);

  printf("%02x\n", k0 ^ k1 ^ k2 ^ k3 ^ k0 ^ k2 ^ k3);

  
    
  
  return 0;
  
}
