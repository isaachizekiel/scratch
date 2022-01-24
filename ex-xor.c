#include <stdio.h>


/*
Recall that the Luby-Rackoff theorem discussed in The Data  Encryption Standard lecture states that applying a three round Feistel network to a secure PRF gives a secure block cipher.  Let's see what goes wrong if we only use a two round Feistel.

Let F:K×{0,1}32→{0,1}32F: K \times \{0,1\}^{32} \to \{0,1\}^{32}F:K×{0,1}32→{0,1}32 be a secure PRF.

Recall that a 2-round Feistel defines the following PRP 

F2:K2×{0,1}64→{0,1}64F_2: K^2 \times \{0,1\}^{64} \to \{0,1\}^{64}F2​:K2×{0,1}64→{0,1}64:

Here R0R_0R0​ is the right 32 bits of the 64-bit input and L0L_0L0​ is the left 32 bits.

One of the following lines is the output of this PRP F2F_2F2​ using a random key, while the other three are the output of a truly random permutation f:{0,1}64→{0,1}64f:\{0,1\}^{64} \to \{0,1\}^{64}f:{0,1}64→{0,1}64. All 64-bit outputs are encoded as 16 hex characters.

Can you say which is the output of the PRP?       Note that since you are able to distinguish the output of F2F_2F2​ from random, F2F_2F2​ is not a secure block cipher, which is what we wanted to show.

Hint: First argue that there is a detectable pattern in the xor of F2(⋅, 064)F_2(\cdot,\  0^{64})F2​(⋅, 064) and F2(⋅, 132032)F_2(\cdot,\  1^{32} 0^{32})F2​(⋅, 132032).   Then try to detect this pattern in the given outputs.
 */

int
main()
{
  
  unsigned char c1_0_64_r [] = { 0x9f, 0x97, 0x0f, 0x4e };
  unsigned char c1_0_64_l [] = { 0x93, 0x23, 0x30, 0xe4 };
  unsigned char c1_1_32_0_32_r [] = { 0x60, 0x68, 0xf0, 0xb1 };
  unsigned char c1_1_32_0_32_l [] = { 0xb6, 0x45, 0xc0, 0x08 };

  
  unsigned char c2_0_64_r [] = { 0x7c, 0x28, 0x22, 0xeb };
  unsigned char c2_0_64_l [] = { 0xfd, 0xc4, 0x8b, 0xfb };
  unsigned char c2_1_32_0_32_r [] = { 0x32, 0x50, 0x32, 0xa9 };
  unsigned char c2_1_32_0_32_l [] = { 0xc5, 0xe2, 0x36, 0x4b };

  
  unsigned char c3_0_64_r [] = { 0x4a, 0xf5, 0x32, 0x67 };
  unsigned char c3_0_64_l [] = { 0x13, 0x51, 0xe2, 0xe1 };
  unsigned char c3_1_32_0_32_r [] = { 0x87, 0xa4, 0x0c, 0xfa };
  unsigned char c3_1_32_0_32_l [] = { 0x8d, 0xd3, 0x91, 0x54 };


  unsigned char c4_0_64_r [] = { 0x2d, 0x1c, 0xfa, 0x42 };
  unsigned char c4_0_64_l [] = { 0xc0, 0xb1, 0xd2, 0x66 };
  unsigned char c4_1_32_0_32_r [] = { 0xee, 0xa6, 0xe3, 0xdd };
  unsigned char c4_1_32_0_32_l [] = { 0xb2, 0x14, 0x6d, 0xd0 };



  for (int i = 0; i < 4; i++)
    {

      printf("%02x ", c1_0_64_r[i] ^ c1_1_32_0_32_r[i]);

    }


    for (int i = 0; i < 4; i++)
    {

      printf("%02x ", c1_0_64_l[i] ^ c1_1_32_0_32_r[i]);

    }

    printf("\n\n");


  for (int i = 0; i < 4; i++)
    {

      printf("%02x ", c2_0_64_r[i] ^ c2_1_32_0_32_r[i]);

    }


    for (int i = 0; i < 4; i++)
    {

      printf("%02x ", c2_0_64_l[i] ^ c2_1_32_0_32_r[i]);

    }

    printf("\n\n");

    

  for (int i = 0; i < 4; i++)
    {

      printf("%02x ", c3_0_64_r[i] ^ c3_1_32_0_32_r[i]);

    }


    for (int i = 0; i < 4; i++)
    {

      printf("%02x ", c3_0_64_l[i] ^ c3_1_32_0_32_r[i]);

    }

    printf("\n\n");

  for (int i = 0; i < 4; i++)
    {

      printf("%02x ", c4_0_64_r[i] ^ c4_1_32_0_32_r[i]);

    }


    for (int i = 0; i < 4; i++)
    {

      printf("%02x ", c4_0_64_l[i] ^ c4_1_32_0_32_r[i]);

    }

    printf("\n\n");    
    
}
