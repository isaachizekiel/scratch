#include <stdio.h>

int
main()
{
  unsigned char m[14] =  {'a','t','t','a','c','k',' ','a','t',' ','d','a','w','n'};

  unsigned char m2[14] =  {'a','t','t','a','c','k',' ','a','t',' ','d','u','s','k'};

  //unsigned char c[14] = {0x6c,0x73,0xd5,0x24,0x0a,0x94,0x8c,0x86,0x98,0x1b,0xc2,0x94,0x81,0x4d};

  unsigned char c[14] = {0x09, 0xe1, 0xc5, 0xf7, 0x0a, 0x65, 0xac, 0x51, 0x94, 0x58, 0xe7, 0xe5, 0x3f, 0x36};

  unsigned char k[14];


  // xoring to 
  for (int i = 0; i < 14; i++)
    {
      k[i] = m[i] ^ c[i];      
    }
 
  // 
  for (int j = 0; j < 14; j++)
    {
      printf("%02x", k[j] ^ m2[j]);
    }

  printf("\n");


  //k1' = k1 + k;
  //k2' = k2 + k;

  //k = k1' ^ k1;
  //k = k2' ^ k2;


  unsigned char key = k[0], key1 = k[1], key2 = k[2];

  unsigned char k1prime = key ^ key1, k2prime = key ^ key2;

  printf("k:%02x - k1:%02x - k2:%02x - k1p:%02x - k2p:%02x\n", key, key1, key2, k1prime, k2prime);

  printf("%02x == %02x\n", key1 ^ k1prime, key);

  printf("%02x == %02x\n", key2 ^ k2prime, key);


  printf("%02x == %02x\n", (k1prime ^ k2prime),  key1 ^ key2);
  
  printf("-- \n");
  
  printf("%02x == %02x\n", (key1 ^ key2) ^ k2prime, key);

  printf("%02x == %02x\n", (key1 ^ key2) , key);

  
  
  
  return 0;
}


  

  
