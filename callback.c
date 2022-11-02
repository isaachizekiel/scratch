#include <stdio.h>
#include <stdlib.h>

struct some_stract {
  int value;
  void (*func_cb)(int v);
};


void func_one(int v) {
  printf("%d\n", v * 2);
}

void func_two(int v) {
  printf("%d\n", v * 3);
}

int main() {

  struct some_stract * s = malloc(sizeof(struct some_stract));
  
  s->value = 5;
  s->func_cb = func_two;
  s->func_cb(s->value);

  s->value = 6;
  s->func_cb = func_two;
  s->func_cb(s->value);
  
}
