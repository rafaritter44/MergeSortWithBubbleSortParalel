#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SMALL 1000

double array[SIZE], temp[SIZE];

void bubble_sort(double v[], int n);
void merge_sort(double v[], int n, double temp[]);
void merge(double v[], int n, int half, double temp[]);

void bubble_sort(double v[], int n) {
  int c =0, d, troca, trocou =1;

  while (c < (n-1) && trocou ) {
        trocou = 0;
        for (d = 0 ; d < n - c - 1; d++) {
            if (v[d] > v[d+1]) {
                troca  = v[d];
                v[d]   = v[d+1];
                v[d+1] = troca;
                trocou = 1;
            }
        }
        c++;
  }
}

void merge_sort(double v[], int n, double temp[]) {
  if (n < SMALL)
     bubble_sort(v, n);
  else {
     int half = n/2;
     merge_sort(v, half, temp);
     merge_sort(v+half, n-half, temp);
     merge(v, n, half, temp);
  }
}

void merge(double v[], int n, int half, double temp[]) {
  int p1 = 0, p2 = half, t = 0;

  while (p1 < half && p2 < n) {
        if (v[p1] < v[p2])
           temp[t++] = v[p1++];
        else
           temp[t++] = v[p2++];
  }
  while (p1 < half)
        temp[t++] = v[p1++];
  while (p2 < n)
        temp[t++] = v[p2++];
  for (t = 0; t < n; ++t)
      v[t] = temp[t];
}

int main() {
  double elapsed_time;
  int i;

  // INICIALIZA O ARRAY A SER ORDENADO (COM O PIOR CASO)
  for (i=0 ; i<SIZE; i++)
      array[i] = (double)SIZE-i;

  elapsed_time = -omp_get_wtime();
  merge_sort(array, SIZE, temp);    // ORDENA
  elapsed_time += omp_get_wtime();

  // VERIFICA SE A ORDENAÇÃO FUNCIONOU
  for (i=0 ; i<SIZE-1; i++)
      if (array[i] > array[i+1])
         return 1;

  printf("%lf",elapsed_time);
  return 0;
}