#include <stdio.h>

int
main()
{
  unsigned char k0 [21] = {'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 't', 'h', 'e', ' ', 'k', 'e', 'y', ' ', 'h', 'i', 'd', 'e', '!'};
  
  unsigned char m1 [21] = {'H', 'e', 'l', 'l', 'o', ' ', 'M', 'y', ' ', 'n', 'a', 'm', 'e', ' ', 'i', 's', ' ', 'I', 'z', 'a', 'k'};

  unsigned char m2 [21] = {'I', 't', 's', ' ', 'n', 'i', 'c', 'e', ' ', 't', 'o', ' ', 'm', 'e', 'e', 't', ' ', 'y', 'o', 'u', '!'};

  unsigned char m3 [21] = {'C', 'a', 'n', ' ', 'i', ' ', 'h', 'a', 'v', 'e', ' ', 'y', 'o', 'u', 'r', ' ', 'd', 'i', 'g', 'i', 't'};


  unsigned char c1 [21] = {0};
  unsigned char c2 [21] = {0};
  unsigned char c3 [21] = {0};
  
  unsigned char res [21] = {0};
      
  unsigned char *msg [3] = {m1, m2, m3};
  unsigned char *cip [3] = {c1, c2, c3};


  unsigned char s[] = {'I', 't', 's'};
  int sl = 3;

  unsigned char ch;
  
  for (int i  = 0; i < 3; i++)
    {
      for (int j = 0; j < 21; j++)
	{
	  cip[i][j] = k0[j] ^ msg[i][j];
	  res[j] ^= cip[i][j];
	}
    }


  // ciphers
  for (int i = 0; i < 3; i++)
    {
      // ciphers
      for (int j = 0; j < 21; j++)
	{
	  // res
	  for (int k = 0; k < 21; k++)
	    {

	      ch = res[k] ^ 'e' ^ cip[i][j];
	      
	      if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch == ' ') )
		{
		  //if (ch == 'e')
		  printf("\033[0;31m%c\033[0m", ch);
		  //else
		  //printf("%c", ch);
		}
	      else		
		{
		  printf("%c", ' ');      
		}
	      
	    }
	  printf("\n");
	}

      printf("\n");

    }

  printf("\n");
  
  return 0;
}
