#include "queue.h"
//========================================

Cell *new_cell(){
  Cell *tmp = (Cell*) malloc(sizeof(Cell));
  tmp->next = NULL;
  return tmp;
}
//========================================
void new_queue(Queue *q){

  Cell *news = new_cell();

  q->start = news;
  q->end = news;
  q->size = 0;
}
//========================================
void enqueue(Queue *q, int data){

  Cell *news = new_cell();
  news->data = data;

  q->end->next = news;
  q->end = news;
  q->size++;
}
//========================================
void print_queue(Queue *q){

  Cell *tmp = q->start->next;

  while(tmp != NULL){
    printf("\n%d",tmp->data);
    tmp = tmp->next;
  }
}
//========================================
int size_queue(Queue *q){
  return q->size;
}
//========================================
int dequeue(Queue *q){

  if(q->size == 0){
    return -1;
  }

  Cell *tmp = q->start;
  q->start = q->start->next;  
  free(tmp);
  q->size--;

  return q->start->data;
}