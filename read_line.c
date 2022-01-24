#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int
main()
{
  int fd = open("/home/izak/test.c", O_RDONLY, S_IRUSR | S_IWUSR);

  struct stat sb;

  if (fstat(fd, &sb) == -1)
    {
      perror("Error: ");
      return -1;
    }

  printf("file size if %ld\n", sb.st_size);

  char *file_in_memory = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);


  for(int i=0; i<sb.st_size; i++)
    {

      /*
      int j = 0;

      if (file_in_memory[i] == '#')
	{

	  while(file_in_memory[i + j++] != '>')
	    {
	      printf("%c", file_in_memory[i + j]);

	    }
  
	}


      i += j;
      */
      printf("%c", file_in_memory[i]);
            
    }

  printf("\n");

  return 1;
  
}

