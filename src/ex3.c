/* 
 * Enunciado: 
 * Implemente um programa que leia o nome, a idade e o endereço de diversas
 * pessoas, armazene esses dados em um array de estruturas (Pessoa). O programa
 * deve permitir a leitura de diferentes pessoas até que o usuário decida 
 * encerrar a inserção (caractere 'n'). Em seguida, o programa deve exibir o
 * array de Pessoas digitadas em ordem alfabética (nome). Utilize o algoritmo
 * de ordenação que preferir.
 * 
 * Exemplos: 
 *
 *   Nome: Diego
 *   Endereço: Rua da Miséria, 666
 *   Idade: 30
 *   Deseja adicionar outra pessoa? (s/n): s
 *   Nome: Tawfik
 *   Endereço: Praça da Mesquita, 17
 *   Idade: 18
 *   Deseja adicionar outra pessoa? (s/n): s
 *   Nome: Alexandre
 *   Endereço: Praça Mauá, 1
 *   Idade: 34
 *   Deseja adicionar outra pessoa? (s/n): n
 *   [Pessoa{'Alexandre',34,'Praça Mauá, 1'},Pessoa{'Diego',30,'Rua da Miséria, 666'},Pessoa{'Tawfik',18,'Praça da Mesquita, 17'}]
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAX_PESSOAS 100

typedef struct {
  char nome[MAX],endereco[MAX];
  int idade;
} Pessoa;

int main (int argc, char *argv[])
{
  return 0;
}

void quicksort(int vetor[MAX], int tam_vetor, int comeco, int fim) {
  int j;
  printf(">> Quicksort(começo = %i, fim = %i). Vetor = ",comeco,fim);
  exibe_vetor(vetor,tam_vetor);
  printf("\n");
  if(comeco<fim){
    
    j = particiona(vetor,comeco,fim);

    quicksort(vetor,tam_vetor,comeco,j-1);
    quicksort(vetor,tam_vetor,j+1,fim);
  }
  printf("** Quicksort(começo = %i, fim = %i). Vetor = ",comeco,fim);
  exibe_vetor(vetor,tam_vetor);
  printf("\n");
  
}

int particiona(int vetor[MAX], int comeco, int fim) {
  int pivo,i,j;
  pivo = (comeco+fim)/2;
  troca_elementos(vetor,pivo,fim);
  j = comeco;
  for(i=comeco;i<fim;i++){
    if(strcmp(vetor[i],vetor[fim])<=0){
      troca_elementos(vetor,i,j);
      j++;
    }
  }
  troca_elementos(vetor,j,fim);
  return j;
}

void troca_elementos(int vetor[MAX], int i, int j) {
  int aux;
  aux = vetor[i];
  vetor[i] = vetor[j];
  vetor[j] = aux;
}