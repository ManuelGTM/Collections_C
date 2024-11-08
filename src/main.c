// #include "../lib/Stack/Stack.h"
#include <stdio.h>
#include <stdlib.h>

int value(int *a) { return *a + 2; }

int main(int argc, char *argv[]) {

  int a = 15;
  int *p = &a;
  *p = 2;

  value(p);
  printf("Variable: %d\n", a);
  printf("Direccion de A: %p", p);
  printf("\nValor puntero de A: %d", *p);
  printf("\n%p", &a);

  return EXIT_SUCCESS;
}
