/* the purpose of this program is to help me understand how i can search and replace strings in a large project
   i.e godot scons files. */


#include <regex.h>
#include <stdio.h>
#include <fcntl.h> // open
#include <string.h>
// #define __USE_GNU // fix for mremap
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h> // close


#define BUFFER_LEN 8

int
main(int argc, char **argv)
{
  if (argc < 4)
    {
      printf("Useage : %s [filepath] [search] [insert] \n", argv[0]);
      return 0;
    }

  
  int fd, new_file_size;
  char *map;
  const size_t map_size = 4096;
  struct stat sb;  

  const char *filepath = argv[1];
  const char *search = argv[2];
  const char *insert = argv[3];

  char buffer[BUFFER_LEN];
  
  fd = open(filepath, O_RDWR, S_IRUSR | S_IWUSR);
  
  if (fstat(fd, &sb) == -1)
    {
      printf("Could not open file %s\n", filepath);
      return 0;
    }

  char tmp [sb.st_size];

  map = mmap(NULL, map_size, PROT_READ | PROT_WRITE | PROT_GROWSDOWN | PROT_GROWSDOWN, MAP_FILE | MAP_SHARED, fd, 0);


  int i = 0, s_len = 0, i_len = 0, t_len = 0;
  while (search[i] != 0x00) /* check for null for some reason NULLL has warning */
    {
      s_len++; i++; /* count the search string */
    }

  i = 0;
  while (insert[i] != 0x00)
    {
      i_len++; i++; /* count the insertion string */
    }


  for (i = 0; i < sb.st_size; i++)
    {
      
      int j = 0, k = 0, l = 0, m = 0; unsigned char b = 0x00;
      while (j < sb.st_size)
	{
	  tmp[j] = 0x00; /* clean the tmp, this is where we place the characters that appear after thee search key word */
	  j++;
	}

      j = 0;
      while (j < BUFFER_LEN)
	{
	  buffer[j] = 0x00; /* clean the buffer, it is where we place the search pattern */
	  j++;
	}

      j = 0; k = i;
      while (j < s_len)
	{
	  buffer[j] = map[k]; /* initialize the buffer with the range of charafters to be searched */
	  j++; k++;	  
	}

      j = 0; b = 0; 
      while (j < s_len)
	{
	  if (buffer[j] != search[j])
	    {
	      b = 0;
	      break;
	    }	
	  b = 1;
	  j++;
	}
            
      if (b == 1)
	{
	  j = 0; k = i + s_len, b = 0;
	  while (k < sb.st_size)
	    {
	      tmp[j] = map[k]; /* move characters past to the search keyword */
	      map[k] = 0x00;  /* cleaning */
	      j++; k++; t_len++;
	    }
	  
	  j = 0; k = i;
	  while (j < i_len)
	    {
	      map[k + s_len] = insert[j];
	      j++; k++;
	    }

	  j = 0; k = i;
	  while(j < t_len)
	    {
	      map[k + s_len + i_len] = tmp[j];
	      j++; k++;
	    }
	  
	  printf("bingo !! %s at %d, len is %d t_len is %d and tmp is `%s` the new map is `%s`\n",
		 buffer, i, s_len, t_len, tmp, map); /* we find it mayor */

	}
      
    }

  munmap(map, map_size);  
  close(fd);  
}
