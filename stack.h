#ifndef  STACK_H
#define  STACK_H
//======================================
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//======================================
typedef struct Celula{
  int dado;
  struct Celula *prox;
}Celula;
//======================================
Celula *create_celula(int dado, Celula *prox);
//======================================
typedef struct Pilha{
  Celula *topo;
  int tam;
}Pilha;
//======================================
void create_pilha(Pilha *p);
void push(Pilha *p, int dado);
int pop(Pilha *p);
int size_pilha(Pilha *p);
bool is_empty_pilha(Pilha *p);
void print_pilha(Pilha *p);
//======================================
#endif 