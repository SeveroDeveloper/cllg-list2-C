#include "stack.h"
//======================================
Celula *create_celula(int dado, Celula *prox){
  Celula *tmp = (Celula*)malloc(sizeof(Celula));
  tmp->dado = dado;
  tmp->prox = prox;
  return tmp;
}
//======================================
void create_pilha(Pilha *p){
  p->topo = NULL;
  p->tam = 0;
}

//======================================
void push(Pilha *p, int dado){
  Celula *tmp = create_celula(dado, p->topo);
  p->topo = tmp;
  p->tam++;
}
//======================================
int pop(Pilha *p){
  if(is_empty_pilha(p)){
    return -1;
  }

  int res = p->topo->dado;
  Celula *tmp = p->topo;
  p->topo = p->topo->prox;
  free(tmp);

  p->tam--;
  return res;
}

//======================================
int size_pilha(Pilha *p){
  return p->tam;
}

//======================================
bool is_empty_pilha(Pilha *p){
  return p->topo == NULL;
}

//======================================
void print_pilha(Pilha *p){

  //printf("Tamanho da Pilha: %d\n\n", size_pilha(p));

  for(Celula *i = p->topo; i!=NULL; i = i->prox){
    printf("%d\n", i->dado);
  }
}

//======================================