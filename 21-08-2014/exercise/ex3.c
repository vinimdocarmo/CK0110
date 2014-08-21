#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int getLatterDigit(int number);
int numberOfDigits(int number);

int main(int argc, char const *argv[]) {
  FILE *file;
  int number, aux, i, invertedDigits[10];

  if(argc < 2) {
    printf("Entre com um valor inteiro de até 10 dígitos: ");
    scanf("%i", &number);

    aux = number;

    for(i = 0; i < 10; i++, number /= 10) {
      invertedDigits[i] = getLatterDigit(number);
    }
  } else {  
    file = fopen(argv[1], "r");

    if(file == NULL) {
      printf("Erro ao abrir o arquivo.\n");
      return EXIT_FAILURE;
    }

    fscanf(file, "%i", &number);

    aux = number;

    for(i = 0; i < 10; i++, number /= 10) {
      invertedDigits[i] = getLatterDigit(number);
    }

    fclose(file);
  }  

  for(i = 0; i < numberOfDigits(aux); i++) {
      printf("%i", invertedDigits[i]);
  }

  printf("\n");

  return EXIT_SUCCESS;
}

int getLatterDigit(int number) {
  return number % 10; 
}

int numberOfDigits(int number) {
  int n = 0;

  while(number != 0) {
    number /= 10;
    n++;
  }

  return n;
}
