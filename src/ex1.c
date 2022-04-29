/* 
 * Enunciado: 
 * Implemente um programa que leia o nome, a idade e o endereço de uma pessoa 
 * e armazene esses dados em uma estrutura. Em seguida, imprima na tela os 
 * dados da estrutura lida. Para armazenar os dados, escolha os tipos de dados 
 * mais adequados para cada informação. Utilize, obrigatoriamente, uma função 
 * para realizar a leitura da estrutura e outra função para realizar sua 
 * exibição. Outras funções auxiliares podem ser utilizadas.
 *
 * Exemplos:
 *
 *  Nome: Rodrigo Nicola
 *  Endereço: Praça Mauá, 1
 *  Idade: 31
 *  Pessoa{'Rodrigo Nicola',31,'Praça Mauá, 1'}
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct{
  char nome[MAX];
  char endereco[MAX];
  int idade;
} Pessoa;

void ler_string(char s[MAX]);
Pessoa ler_pessoa();
void exibe_pessoa(Pessoa p);

int main (int argc, char *argv[])
{
  Pessoa p1;
  p1 = ler_pessoa();
  exibe_pessoa(p1);
  return 0;
}

Pessoa ler_pessoa(){
  char nome[MAX],endereco[MAX];
  Pessoa p1;
  printf("Nome: ");
  fgets(nome,MAX,stdin);
  if(nome[strlen(nome)-1]=='\n'){
    nome[strlen(nome)-1]='\0';
  }
  strcpy(p1.nome,nome);
  setbuf(stdin,0);
  printf("Endereço: ");
  fgets(endereco,MAX,stdin);
  if(endereco[strlen(endereco)-1]=='\n'){
    endereco[strlen(endereco)-1]='\0';
  }
  strcpy(p1.endereco,endereco);
  setbuf(stdin,0);
  printf("Idade: ");
  scanf("%i",&p1.idade);
  return p1;
}


void exibe_pessoa(Pessoa p){
  printf("Pessoa{'%s',%i,'%s'}",p.nome,p.idade,p.endereco);
}  
  
  

