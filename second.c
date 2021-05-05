#include "second.h"
// search for a number in a queue, them dequeue it

int extrairdafila(Queue *q, int x)
{
  Cell *back = q->start;
  Cell *front = q->start->next;
  while(front != NULL)
  {
    if(back->data == x)
    {
      return dequeue(q);
    }
    else
    {
      if(front->data == x) // dequeue the number
      {
        int asw = front->data;
        Cell *tmp = front;
        back->next = front->next;

        if(front->next == NULL)
        {
          q->end = back;
        }

        free(tmp);
        q->size--;
        return asw;
      }
    }
    back = back->next;
    front = front->next;
  }
  return -1; // return when not found
}

void second()
{
  int size, num, data, answer;
  Queue queue;
  new_queue(&queue);

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
    enqueue(&queue, data);
  }

  answer = extrairdafila(&queue, num);

  /*
  output example:
  Removed:3
  5
  4
  2
  1
  */

  printf("Removed:%d", answer);
  print_queue(&queue);
}

