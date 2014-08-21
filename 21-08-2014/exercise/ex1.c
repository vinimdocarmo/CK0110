#include <stdlib.h>
#include <stdio.h>

int isPrime(int number);

int main(int argc, char const *argv[]) {  
  int n, i = 2;

  printf("Entre com um valor inteiro positivo: ");
  scanf("%i", &n);

  printf("\nOs %i primeiros números primos são: ", n);

  do {
    if(isPrime(i)) {
      printf("%i ", i);
      n--;
    }
    i++;
  } while(n != 0);

  printf("\n\n");

  return EXIT_SUCCESS;
}

/*
* Return 1 if the number is prime, return 0 otherwise.
*/
int isPrime(int number) {
  int i;

  for (i = 2; (i * i) <= number; ++i) {
    if(number % i == 0 && i != number)
      return 0;
  }

  return 1;
}
