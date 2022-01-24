#include <stdio.h>
#include <stdbool.h>


int
main(){

  bool a = false;
  bool b = false;

  if (a || b)
    {
      // boolean algebra does not work here
      printf("this should execute! \n");
    } 
  
}
