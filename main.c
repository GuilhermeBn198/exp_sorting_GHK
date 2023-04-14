#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

struct timeval t1, t2;
double elapsedTime;
/*para o calculo do tempo*/
unsigned long time_diff(struct timeval a, struct timeval b){
	struct timeval res;
	timersub(&a, &b, &res);
	return res.tv_sec * 1000000 + res.tv_usec;
}

void bubble_sort(int arr[], int n) {
	int i, j;
	for (i = 0; i < n-1; i++) {
		for (j = 0; j < n-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main(int argc, char **argv) {
  FILE *fp;
  int num, count = 0;
  int *lista = NULL;

  if (argc != 2) {
    printf("Uso: %s <arquivo>\n", argv[0]);
    exit(0);
  }
  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Não foi possível abrir o arquivo.\n");
    exit(1);
  }

  while (fscanf(fp, "%d", &num) == 1) {
    count++;
    lista = realloc(lista, count * sizeof(int));
    lista[count - 1] = num;
  }

  fclose(fp);
  int size = sizeof(&lista) / sizeof(lista[0]);
  gettimeofday(&t1, NULL);
  // EXECUCAO - apenas o algoritmo de ordenacao deve executar aqui
  bubble_sort(lista, count);
  gettimeofday(&t2, NULL);
  // OUTPUT
  // for (int i = 0; i < count; i++) {
  //   printf("%d\n", lista[i]);
  // }
	//imprimi o tempo em milisegundos								
	printf("\n Tempo de Execucao: ---> %lf \n",time_diff(t2, t1)/100000.0);

  free(lista);
  return 0;
}
