#ifndef QUEUE_H
#define QUEUE_H
//========================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//========================================
typedef struct Cell{
  int data;
  struct Cell *next;
}Cell;
//========================================
typedef struct Queue{
  Cell *start;
  Cell *end;
  int size;
}Queue;
//========================================
Cell *new_cell();
//========================================
void new_queue(Queue *q);
//========================================
void enqueue(Queue *q, int data);
//========================================
void print_queue(Queue *q);
//========================================
int size_queue(Queue *q);
//========================================
int dequeue(Queue *q);
//========================================
#endif