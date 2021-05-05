#include "first.h"
// search for a number in a stack, them pop it

int extrairdapilha(Pilha *p, int x)
{
  if(is_empty_pilha(p)){
    return -1;
  }

  Celula * front;
  Celula * back;
  front = p->topo->prox;
  back = p->topo; 
  
  while(front != NULL)
  {
    if(back->dado == x)
    {
      return pop(p);
    }
    else
    {
      if(front->dado == x)
      {
        int asw = front->dado;
        Celula *tmp = front;
        back->prox = front->prox;
        free(tmp);
        p->tam--;
        return asw;
      }
    }
    front=front->prox;
    back=back->prox;
  }
  return -1; // return when not found
}

void first()
{
  int size, num, data, answer;
  Pilha stack;
  create_pilha(&stack);

  /*
  input example:
  5 3
  1
  2
  3
  4
  5
  */

  scanf("%d %d", &size, &num);
  for(int i = 0; i < size; i++)
  {
    scanf("%d", &data);
    push(&stack, data);
  }

  answer = extrairdapilha(&stack, num);

  /*
  output example:
  Removed:3
  5
  4
  2
  1
  */

  printf("Removed:%d\n", answer);
  print_pilha(&stack);
}

