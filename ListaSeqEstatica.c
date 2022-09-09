#include <stdio.h>
#include <stdlib.h>

//struct da lista
struct ListaSeq{
 int num;
 struct ListaSeq *prox;
};
typedef struct ListaSeq Elem;
int tam;

void cria(Elem *LISTA);
int menu(void);
void opcao(Elem *LISTA, int op);
Elem *criaNo();
void insereInicio(Elem *LISTA);
void exibe(Elem *LISTA);
void libera(Elem *LISTA);
void insere (Elem *LISTA);
Elem *retiraInicio(Elem *LISTA);
Elem *retira(Elem *LISTA);


int main()
{
 Elem *LISTA = (Elem *) malloc(sizeof(Elem));
 if(!LISTA){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
 cria(LISTA);
 int opt;

 do{
  opt=menu();
  opcao(LISTA,opt);
 }while(opt);

 free(LISTA);
 return 0;
 }
}

void cria(Elem *LISTA)
{
 LISTA->prox = NULL;
 tam=0;
}

//menu interface do usuario
int menu(void)
{
 int opt;

 printf("\n-Escolha uma opcao:\n\n");
 printf("0- Sair\n");
 printf("1- Zerar lista\n");
 printf("2- Mostrar lista\n");
 printf("3- Inserir elemento no inicio\n");
 printf("4- Escolher onde inserir\n");
 printf("5- Retirar elemento do inicio\n");
 printf("6- Escolher de onde retirar\n");
 printf("\nOpcao: "); scanf("%d", &opt);

 return opt;
}

//switch case para escolha do usuario
void opcao(Elem *LISTA, int op)
{
 Elem *tmp;
 switch(op){
  case 0:
   libera(LISTA);
   break;

  case 1:
   libera(LISTA);
   cria(LISTA);
   break;

  case 2:
   exibe(LISTA);
   break;

  case 3:
   insereInicio(LISTA);
   break;

  case 4:
   insere(LISTA);
   break;

  case 5:
   tmp= retiraInicio(LISTA);
   printf("Retirado: %3d\n\n", tmp->num);
   break;

  case 6:
   tmp= retira(LISTA);
   printf("Retirado: %3d\n\n", tmp->num);
   break;

  default:
   printf("Comando invalido\n\n");
 }
}

int vazia(Elem *LISTA)
{
 if(LISTA->prox == NULL)
  return 1;
 else
  return 0;
}

Elem *aloca()
{
 Elem *novo=(Elem *) malloc(sizeof(Elem));
 if(!novo){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
  printf("Novo elemento: "); scanf("%d", &novo->num);
  return novo;
 }
}

//inserir elemento no inicio da lista
void insereInicio(Elem *LISTA)
{
 Elem *novo=aloca();
 Elem *oldHead = LISTA->prox;

 LISTA->prox = novo;
 novo->prox = oldHead;

 tam++;
}

//mostrar a lista
void exibe(Elem *LISTA)
{
 system("cls");
 if(vazia(LISTA)){
  printf("\n\nLista vazia!\n\n");
  return ;
 }

 Elem *tmp;
 tmp = LISTA->prox;
 printf("Lista:");
 while( tmp != NULL){
  printf("%5d", tmp->num);
  tmp = tmp->prox;
 }
 printf("\n        ");
 int count;
 for(count=0 ; count < tam ; count++)
  printf("  ^  ");
 printf("\nOrdem:");
 for(count=0 ; count < tam ; count++)
  printf("%5d", count+1);

 printf("\n\n");
}

void libera(Elem *LISTA)
{
 if(!vazia(LISTA)){
  Elem *proxNode, *atual;

  atual = LISTA->prox;
  while(atual != NULL){
   proxNode = atual->prox;
   free(atual);
   atual = proxNode;
  }
 }
}

//insere elemento em posicao N escolhida pelo usuario
void insere(Elem *LISTA)
{
 int pos,
  count;
 printf("Em que posicao, [de 1 ate %d] voce quer inserir: ", tam);
 scanf("%d", &pos);

 if(pos>0 && pos <= tam){
  if(pos==1)
   insereInicio(LISTA);
  else{
   Elem *atual = LISTA->prox,
     *anterior=LISTA;
   Elem *novo=aloca();

   for(count=1 ; count < pos ; count++){
     anterior=atual;
     atual=atual->prox;
   }
   anterior->prox=novo;
   novo->prox = atual;
   tam++;
  }

 }else
  printf("Elemento invalido\n\n");
}

//retira elemento inicial da lista
Elem *retiraInicio(Elem *LISTA)
{
 if(LISTA->prox == NULL){
  printf("Lista ja esta vazia\n");
  return NULL;
 }else{
  Elem *tmp = LISTA->prox;
  LISTA->prox = tmp->prox;
  tam--;
  return tmp;
 }

}

//retira elemento em posicao N da lista, escolhido pelo usuario
Elem *retira(Elem *LISTA)
{
 int pos, count;
 printf("Que posicao, [de 1 ate %d] voce deseja retirar: ", tam);
 scanf("%d", &pos);

 if(pos>0 && pos <= tam){
  if(pos==1)
   return retiraInicio(LISTA);
  else{
   Elem *atual = LISTA->prox,
     *anterior=LISTA;

   for(count=1 ; count < pos ; count++){
    anterior=atual;
    atual=atual->prox;
   }

  anterior->prox=atual->prox;
  tam--;
  return atual;
  }

 }else{
  printf("Elemento invalido\n\n");
  return NULL;
 }
}
