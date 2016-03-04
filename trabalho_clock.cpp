/*
 * Universidade Federal do Rio Grande do Norte
 * Instituto Metropole Digital
 *
 * copyright: Ivanovitch Silva
 * e-mail: ivan@imd.ufrn.br
 * alterado por: João Santana e Patrícia Cruz
 * Tópico: manipulação de tempo em c++
 * Programa: calcular o tempo de execução dos algoritmos
 */
 
#include <cstdlib>
#include <time.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;
 
 
//Vetores usados pelos metodos de ordenacao
int *vetorQuickSort;
int *vetorBubbleSort;
int *vetorShellSort;
int tamanho;
 
//Funcao usada pelo qsort para comparar dois numeros
int compare_ints( const void* a, const void* b ) {
     int* arg1 = (int*) a;
     int* arg2 = (int*) b;
     if( *arg1 < *arg2 ) return -1;
     else if( *arg1 == *arg2 ) return 0;
     else return 1;
}
 
//Algoritmos de ordenacao bubble sort
void bubbleSort(int *vetor, int tamanho){
  int aux;
  for (int i = 0; i < tamanho-1; i++) {
     for (int j = 0; j < tamanho-1; j++) {
        if (vetor[j] > vetor[j+1]) {
          aux = vetor[j];
      vetor[j] = vetor[j+1];
      vetor[j+1] = aux;
        }
     }
  }
}

void shellSort(int *vetor, int tamanho){
    int i, j, value;
    int gap = 1;
    while(gap < tamanho){
        gap = 3*gap+1;
    }
    while( gap > 1){
      gap /= 3;
      for(i = gap; i < tamanho; i++) {
          value = vetor[i];
          j = i - gap;
          while (j >= 0 && value < vetor[j]) {
            vetor [j + gap] = vetor[j];
            j -= gap;
          }
          vetor[j + gap] = value;
      }
    }
}
 
//Observe que os numeros sao gerados aleatorios baseados
//em uma semente. Se for passado a mesma semente, os
//numeros aleatarios serao os mesmos
void criarVetor(int tamanhoVetor, int semente){
  srand (semente);
  vetorQuickSort = new int[tamanhoVetor];
  vetorBubbleSort = new int[tamanhoVetor];
  vetorShellSort = new int[tamanhoVetor];
  for (int i=0;i<tamanhoVetor;i++){
    vetorQuickSort[i] =  rand()%100000;
    vetorBubbleSort[i] = rand()%100000;
    vetorShellSort[i] = rand()%100000;
  }
}

void geraSaida(double sum[10]){
  double media=0, desvio=0;
  for(int i=0; i<10; i++){
    media+=sum[i];
  }
  media /= 10;
  
  for(int i=0; i<10; i++){
    desvio+=pow(sum[i]-media,2);
  }
  desvio /= 10;
  desvio = sqrt(desvio);
  cout << media-desvio << " " << media << " " << media+desvio << endl;
}
 
 
int main(int argc, char *argv[])
{
  //Tamanho do vetor
  if(argc!=3){
    cout << "Parametros errados, execute novamente de forma correta" << endl;
    cout << "Execute o programa passando:\n";
    cout << "1 - Tamanho do vetor\n2 - Semente Rand\n";
    cout << "3 - Algoritmo de ordenação (1: BS, 2: QS, 3: SS)\n";
    return argc;
  }
  else{
    clock_t clock_1, clock_2;
    int n = atoi(argv[1]);
    double sum[10];
    //Criar vetor com elementos aleatorios[0,100000]
    //Seed iguais causam vetores iguais.
    for(int i=0; i<10; i++){
      criarVetor(n, i+1);
      switch(atoi(argv[2])){
        //Ordenar utilizando quickSort
        case 1:
          clock_1 = clock();
          bubbleSort(vetorBubbleSort,n);
          clock_2 = clock();
          break;
        //Ordenar utilizando bubleSort
        case 2:
          clock_1 = clock();
          qsort (vetorQuickSort, n, sizeof(int), compare_ints);
          clock_2 = clock();
          break;
        //Ordenar utilizando ShellSort
        case 3:
          clock_1 = clock();
          shellSort(vetorShellSort, n);
          clock_2 = clock();
          break;
        default:
          cout << "Entrada invalida, apenas 1, 2 ou 3\n";
          break;
        }
      sum[i] = (double)(clock_2-clock_1)/(double)(CLOCKS_PER_SEC);
    }
    geraSaida(sum);
  }

  return 0;
}