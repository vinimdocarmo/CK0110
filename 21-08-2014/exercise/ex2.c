#include <stdlib.h>
#include <stdio.h>

int fibonacci(int number);

int main(int argc, char const *argv[]) {
  int n, res = 0, i = 0;

  printf("Entre com um valor inteiro postivo: ");
  scanf("%i", &n);

  printf("\nSua sequência fibonacci: ");  

  while(res < n) {
    printf("%i ", res);
    res = fibonacci(i);
    i++;
  }

  printf("\n");

  return EXIT_SUCCESS;
}

int fibonacci(int number) {
  if(number < 2) {
    return number;
  } else {
    return fibonacci(number - 1) + fibonacci(number - 2);
  }
}
