/* the purpose of this program is to help me understand how i can search and replace strings in a large project i.e godot scons files.
 * this program is not 100% complete but we can say it is 95% completed. */

#include <regex.h>
#include <stdio.h>
#include <fcntl.h> // open
#include <string.h>
#define __USE_GNU // fix for mremap
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h> // close

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

  char buffer[8];
  
  fd = open(filepath, O_RDWR, S_IRUSR | S_IWUSR);
  
  if (fstat(fd, &sb) == -1)
    {
      printf("Could not open file %s\n", filepath);
      return 0;
    }


  char tmp [sb.st_size];

  int i = 0;
  while(i < sb.st_size)
    {
      tmp[i] = 0x00; /* initial the the tmp buffer */
      i++;
    }

  map = mmap(NULL, map_size, PROT_READ | PROT_WRITE | PROT_GROWSDOWN | PROT_GROWSDOWN, MAP_FILE | MAP_SHARED, fd, 0);


  i = 0; int s_len = 0;
  while (search[i] != 0x00) /* check for null for some reason NULLL has warning*/
    {
      s_len++; i++;
    }
  
  
  for (i = 0; i < sb.st_size; i++)
    {
      int j = 0, k = 0, l = 0;
      while (j < 8) 
	{
	  buffer[j] = 0x00; /* clean the buffer */
	  j++;
	}

      j = 0;
      while (j < sb.st_size )
	{
	  tmp[j] = 0x00; /* clean tmp */
	  j++;
	}
      
      
      j = 0; k = i;
      while (j < s_len) 
	{
	  buffer[j] = map[k]; /* copy the search string to buffer */
	  j++; k++;
	}


      j = 0;
      while(j < s_len) /* */
	{
	  printf("%02x ", buffer[j]); /* display the what we are traversing */
	  j++;
	  if (j == s_len) printf("%c", 0x0a); /* new line */
	}
      
      j = 0;
      while (j < s_len) 
	{	  
	  if (buffer[j] != search[j]) /* check if index are different */
	    {
	      l = 0;
	      break;
	    }
	  
	  l = 1;
	  j++;
	}
      
      if (l == 1)
	{
	  j = i, l = 0;
	  while (map[j] != 0x00)
	    {
	      tmp[l] = map[j + s_len];    /* move the remaining characters to tmp buffer */
	      map[j + s_len] = 0x00;      /* clean the buffer */
	      l++; j++;
	    }
	  
	  j = i, l = 0; int c = 0;
	  while(insert[l] != 0x00)
	    {
	      map[j + s_len] = insert[l]; /* remplace the characters next to the searched chars with insert chars */
	      j++; l++; c++;              /* c++ tracks the length of the insertion */
	    }
	  
	  j = i; l = 0; 
	  while(tmp[l] != 0x00)
	    {
	      // map[j + c] = tmp[l]; /* restore after insertion */
	      j++; l++;
	    }

	  printf("bingo !! %s at %d and tmp is `%s`\n", buffer, i, tmp); /* we find it mayor */
	}
    }
    
  printf("search term is: `%s` insert term is: `%s`\n", search, insert);
  
  printf("map: %s\n", map);

  munmap(map, map_size);  
  close(fd);  
}
