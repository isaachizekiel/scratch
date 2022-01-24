#include <stdio.h>


int
lengthOfLongestSubstring(char *s)
{
  int i, j, k;

  for (i = 0; s[i] != 0x00; i++)
    {
      for (j = 0; j <= i; j++)
	{
	  for (k = j; k < i; k++)
	    {
	      printf("%c", s[k]);
	    }
	  printf("\t");
	}      
      printf("\n");
    }
  

  printf("\n\n%s %d\n", s, i);
}

int
main()
{

  //char *input = "abcabcbb";
  char *input = "abcdefgh";
  // char *input = "pwwkew";

  int length = lengthOfLongestSubstring(input);
}

