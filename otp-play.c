#include <stdio.h>

#define MAX_2D_ARRAY 11
#define MAX_MSG_SIZE 32

int main()
{
  unsigned char k0[32] = {'6', 'P', 'T', 'B', 'y', 'Y', 'V', 'l', 'n', 't', 'Z', 'x', '9', '6', '0', 'x', 'W', '7', 'N', 'd', '9', 'b', 'S', 'x', 'S', 'K', 'B', 'u', 'l', 'E', 'h', 'U'};
  
  unsigned char m0[32] = {'F', 'f', 'b', 'w', 'g', 'Z', 'a', 'U', 'm', '2', 'p', 'O', 'h', 'V', 'p', 'h', 'B', 'G', '0', '0', 'E', '5', 'C', 'W', '1', 'G', 'u', 'n', '3', 'p', 'k', 'I'};
  unsigned char m1[32] = {'6', '1', 's', 'f', 'X', 'w', 'd', 'x', 'B', 'A', 'h', 'D', 'L', 'Q', 'n', 'E', 'V', 'H', 'z', 'J', '1', 'v', 'z', 'e', 'C', 'g', 'g', 'M', 'O', 'k', 'a', 'm'};
  unsigned char m2[32] = {'J', 'v', 'b', 'A', '0', '4', 'L', 'f', '7', 'N', 'O', 'J', 'R', 'Q', 'E', 'h', 'T', '4', '8', 'v', 'z', 'h', 'B', 'Q', 'r', 'V', 'c', 'D', '8', 'S', 'J', 's'};
  unsigned char m3[32] = {'m', 'B', '9', 'K', 'Q', 'O', 'z', 'P', '5', 'j', '3', 'r', '9', 'j', 'J', 'n', 'M', '1', 'D', 'A', 's', 'f', 'j', '6', 'A', 'D', 'Y', '7', 'Y', 'd', 'g', 'g'};
  unsigned char m4[32] = {'x', 'g', 'T', 'Z', 'K', 'Q', 'P', 'O', 'h', '9', 'T', 'W', '0', 'I', 'R', 'v', 'a', 'M', 'v', 'd', 'm', 'f', 'P', '9', 'K', 'Q', 'M', '6', 'e', 'I', 'a', 'P'};
  unsigned char m5[32] = {'h', 'f', 'G', 'C', 'F', 'V', 'k', 'x', 'e', 'T', 'O', '0', '1', 'T', 'Y', '5', '3', 'D', '1', 'F', 'u', 'c', 'v', 'm', 'L', 'N', 'y', 'X', 'g', 'w', 'x', 'S'};
  unsigned char m6[32] = {'K', 'W', 'j', 'T', 'Z', '3', 's', 't', 't', 'g', '4', 'e', 'I', 'u', 'P', 'r', 'R', 'H', 'E', 'E', 'x', 'X', 'a', 'L', 'l', 'b', 'q', 'E', 'R', 'V', 'P', '3'};
  unsigned char m7[32] = {'P', 'X', 'D', 'a', '4', '9', '0', 'r', 'x', 'p', 'k', 'g', 'g', 'h', 'u', '9', 'V', 'u', 'J', 'D', 'd', '5', 'V', 'T', 'G', '6', 's', 'q', 'A', '1', 'b', 'K'};
  unsigned char m8[32] = {'o', 'G', '3', 'K', 'P', 'f', 'u', 'J', '6', 'A', 'D', 'n', 'g', '0', 'n', '9', 'q', '7', '3', 'L', 'z', 'b', 'y', 'z', '7', '1', 'e', 's', 'Y', 'Y', 'n', 'i'};
  unsigned char m9[32] = {'g', 'r', 'W', 'f', '6', '0', 'i', '5', 'P', 'F', 'g', 'o', 'a', 'c', 'V', 'F', 'W', 'j', 'j', 'i', 'x', 'D', 'I', 'C', 'N', 'q', '8', 'f', 'J', 'l', 'u', 'e'};
  unsigned char mt[32] = {'V', '8', '1', 'G', 'V', 'T', 'S', 'N', '2', 'Z', 'c', '2', 'o', 'H', 'Q', 't', 'C', 'g', 'h', 'M', 'x', 'L', 'p', 'L', 'S', 'l', 'n', '1', 'U', 'U', 'R', '4'};

  unsigned char *msgs[11] = {m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, mt};


  unsigned char c0[32] = {0};
  unsigned char c1[32] = {0};
  unsigned char c2[32] = {0};
  unsigned char c3[32] = {0};
  unsigned char c4[32] = {0};
  unsigned char c5[32] = {0};
  unsigned char c6[32] = {0};
  unsigned char c7[32] = {0};
  unsigned char c8[32] = {0};
  unsigned char c9[32] = {0};  
  unsigned char ct[32] = {0};
  
  unsigned char *cips[11] = {c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, ct};

  
  unsigned char res[32] = {0};
  unsigned char con[32] = {0};
  unsigned char key[32] = {0};
  

  for(int i = 0; i < 11; i++)
    {
      int j;
      
      for (j = 0; j < MAX_MSG_SIZE; j++)
	{
	  cips[i][j] = k0[j] ^ msgs[i][j];
	  res[j] ^= cips[i][j];
	  con[j] = k0[j] ^ res[j];
	  key[j] = con[j] ^ res[j];	  
	}

      
      // from this onward i have all the necessary values
      // to play with the cipher

      printf("\n\nk0\n");
      for(j = 0; j < MAX_MSG_SIZE; j++)
	{
	  printf("%02x ", k0[j]);
	}
      
      printf("\n\nmessage\n");
      for(j = 0; j < MAX_MSG_SIZE; j++)
	{
	  printf("%02x ", msgs[i][j]);
	}

      printf("\n\ncipher [OTP] stream cipher\n");
      for(j = 0; j < MAX_MSG_SIZE; j++)
	{
	  printf("%02x ", cips[i][j]);
	}

      printf("\n\nres xored ciphers c0 ^ c1 ..  = m0 ^ m1 ..  \n");
      for(j = 0; j < MAX_MSG_SIZE; j++)
	{
	  printf("%02x ", res[j]);
	}
      
      printf("\n\nconst k0 ^ res  \n");
      for(j = 0; j < MAX_MSG_SIZE; j++)
	{
	  printf("%02x ", con[j]);
	}

      printf("\n\nmake the key --> con[j] ^ ct  = key = k0 \n");
      for(j = 0; j < MAX_MSG_SIZE; j++)
	{
	  printf("%02x ", key[j]);
	}      

      printf("\n\nthe deciphered message \n");
      for(j = 0; j < MAX_MSG_SIZE; j++)
	{
	  printf("%02x ", key[j] ^ cips[i][j]);
	}      
      
      printf("\n\n\n\n\n");
      
    }

  
  return 0;
}
