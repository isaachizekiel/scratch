// gcc egl_program.c -lGL  -o egl_program 

#include <GLES3/gl3.h>
#include <stdio.h>

int main() {
  // this is returning zero because there is no egl context
  if ( 0 == glCreateProgram()) {
    printf("No egl program\n");
  }
  return 0;
}
