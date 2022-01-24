#include <stdio.h>

static void
any_sub(unsigned char *in, unsigned char size)
{
  
  for (unsigned char i = 0; i < size; i++ )
    {
      
      printf("%p ", in);
      
    }

  printf("\n");
  
}


int
main()
{

  unsigned char a[4] = {0x54, 0x67, 0x43, 0x55};

  any_sub(&a, 4);
    
  return 0;
  
}
