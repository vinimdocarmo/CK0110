#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  FILE *arq;
  int k;

  if(argc < 2) {
    printf("Falta argumentos.\n");
    return EXIT_FAILURE;
  }

  printf("O nome do arquivo passado foi: %s.\n", argv[1]);

  arq = fopen(argv[1], "r");

  if(arq == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return EXIT_FAILURE;
  }

  fscanf(arq, "%i", &k);

  printf("O inteiro contido no arquivo é: %i\n", k);

  return EXIT_SUCCESS;
}