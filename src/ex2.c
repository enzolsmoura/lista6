/* 
 * Enunciado: 
 * Implemente um programa que leia o nome, a idade e o endereço de diversas
 * pessoas, armazene esses dados em um array de estruturas (Pessoa). O programa
 * deve permitir a leitura de diferentes pessoas até que o usuário decida 
 * encerrar a inserção (caractere 'n'). Em seguida, o programa deve pedir para
 * o usuário digitar um nome a ser buscado no array de Pessoas. Caso o nome
 * seja encontrado, o endereço da Pessoa buscada deve ser exibido. Caso o nome
 * não seja encontrado, o usuário deve ser informado de que a busca não foi 
 * bem sucedida. Utilize o algoritmo de busca que preferir.
 *
 * Exemplos:
 *   Nome: Rodrigo
 *   Endereço: Aqui
 *   Idade: 31
 *   Deseja adicionar outra pessoa? (s/n): s
 *   Nome: Alexandre
 *   Endereço: Ali
 *   Idade: 34
 *   Deseja adicionar outra pessoa? (s/n): n
 *   Digite um nome para ser buscado: Alexandre
 *   Endereço de Alexandre: Ali
 *
 *   Nome: Camila
 *   Endereço: Rua da Felicidade, 340
 *   Idade: 20
 *   Deseja adicionar outra pessoa? (s/n): s
 *   Nome: Diego
 *   Endereço: Rua da Miséria, 666
 *   Idade: 30
 *   Deseja adicionar outra pessoa? (s/n): n
 *   Digite um nome para ser buscado: Diego
 *   Endereço de Diego: Rua da Miséria, 666
 *
 *   Nome: Ahmad 
 *   Endereço: Avenida Brasil, 5670
 *   Idade: 19
 *   Deseja adicionar outra pessoa? (s/n): n
 *   Digite um nome para ser buscado: Alexandre
 *   'Alexandre' não foi encontrado
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

Pessoa ler_pessoa();
int busca_linear(Pessoa p[MAX], int tam_string, char *chave);

int main (int argc, char *argv[])
{
  char ans, nome[MAX];
  int a;
  Pessoa p[MAX_PESSOAS];
  for(int i = 0;i<MAX_PESSOAS;i++){
    p[i] = ler_pessoa();
    setbuf(stdin,0);
    printf("Deseja adicionar outra pessoa? (s/n): ");
    scanf("%c",&ans);
    getchar();
    if(ans=='n'){
      break;
    }
  }
  printf("Digite um nome para ser encontrado: ");
  setbuf(stdin,0);
  fgets(nome,MAX,stdin);
  if(nome[strlen(nome)-1]=='\n'){
    nome[strlen(nome)-1]='\0';
  }
  a = busca_linear(p,sizeof(p)/sizeof(p[0]),nome);
  if(a==-1){
    printf("'%s' não foi encontrado",nome);
    return 0;
  }
  printf("Endereço de %s: %s",p[a].nome,p[a].endereco);
  return 0;
}

Pessoa ler_pessoa(){
  char nome[MAX],endereco[MAX];
  Pessoa p;
  printf("Nome: ");
  fgets(nome,MAX,stdin);
  if(nome[strlen(nome)-1]=='\n'){
    nome[strlen(nome)-1]='\0';
  }
  strcpy(p.nome,nome);
  setbuf(stdin,0);
  printf("Endereço: ");
  fgets(endereco,MAX,stdin);
  if(endereco[strlen(endereco)-1]=='\n'){
    endereco[strlen(endereco)-1]='\0';
  }
  strcpy(p.endereco,endereco);
  setbuf(stdin,0);
  printf("Idade: ");
  scanf("%i",&p.idade);
  return p;
}

int busca_linear(Pessoa p[MAX], int tam_string, char *chave) {
  int i;
  for(i=0;i<tam_string-5;i++){
    if(strcmp(chave,p[i].nome)==0){
      return i;
    }
  }
  return -1;
}