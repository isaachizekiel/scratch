#include <stdio.h>
#include <sys/mman.h> /* mmap */
#include <sys/stat.h> /* stat constants */
#include <fcntl.h> /* open */
#include <string.h> /* memset */

unsigned char *
aes_expand_key(unsigned char *seed, unsigned char *key)
{

  
  return key;
}


void
aes_subs_byte()
{
  
}


void
aes_shift_row()
{
  
}



void
aes_mix_columns()
{


}


void aes_encrypt(unsigned char *plain_text, unsigned char *cipher_text)
{
  
  for (int i = 0; i < 10; i++)
    {
      aes_subs_byte();
      
      aes_shift_row();
      
      aes_mix_columns();
      
    }
}

void aes_decrypt(unsigned char *cipher_text, unsigned char *plain_text)
{
  
  for (int i = 0; i < 10; i++)
    {
      aes_subs_byte();
      
      aes_shift_row();
      
      aes_mix_columns();
      
    }
}



void
read_file(unsigned char *file_name, unsigned char **file_content, int *size)
{
  int fd = open(file_name, O_RDONLY, S_IRUSR | S_IWUSR);
  struct stat sb;
  if (fstat(fd, &sb) == -1)
    {
      return;
    }
  *file_content = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  *size = sb.st_size;
}


void
aes_create_block(unsigned char *plain_text, unsigned char blocks[52][4][4], int char_read)  
{
  int size = 0, index = 0;
  size = char_read / 16;

  for (int i = 0; i < size; i++)
    {
      index = i * 16;      
      for (int j = 0; j < 4; j++)
	{
	  for (int k = 0; k < 4; k++)
	    {
	      blocks[i][j][k] = plain_text[index++];
	    }
	}
    }
}


#define IN_FILE "/home/izak/plain-text.txt"

int
main()
{

  // aes block size 128 bits = 16-byte

  // 4 x 4 = 16-byte -+
  // xor with key0    |
  // (byte subs)      |round 1
  // (shift row)      |
  // (mix column)-----+


  unsigned char *plain_text;
  int char_read = 0;


  read_file(IN_FILE, &plain_text, &char_read);

  if (char_read == 0)
    {
      printf("error reading the file, exiting...\n");
      return 0;
    }
  
  
  unsigned char blocks[52][4][4];
  memset(blocks, 0, char_read*sizeof(unsigned char));
  aes_create_block(plain_text, blocks, char_read);

 
  aes_encrypt(NULL, NULL);

  

    
  return 0;
}
