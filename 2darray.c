// gcc t2array.c -o t2array
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct a {
  char *name;
  int age;
};

int main(int argc, const char **argv)  {

  if (argc < 2) return 0;

  unsigned int num = atoi(argv[1]), r;;

  r *= num;

  srand(time(NULL));
  printf("%d\n", rand() % r);

  for (int i = 1; i <= r; i++) {
    printf("%02d %c", i-1, i % num == 0 ? '\n' : ' ');
  }

  printf("%d", 'A'&'B');

  return 0;
}
