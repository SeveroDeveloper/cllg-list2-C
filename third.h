#ifndef THIRD_H
#define THIRD_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"

typedef struct Expression{
  char data[1000];
}Expression;

typedef struct Answer{
  char data[10];
}Answer;

void third();
Answer * parentheses(Expression* expressions, int *size, Answer *answer);

#endif