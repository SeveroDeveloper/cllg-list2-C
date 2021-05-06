#include "third.h"

Answer * parentheses(Expression* expressions, int *size, Answer *answer)
{
  Pilha stack;
  create_pilha(&stack);

  for(int i=0; i<*size; i++)
  {
    for(int j=0;j<strlen(expressions[i].data);j++)
    {
      if(expressions[i].data[j] == '(')
      {
        push(&stack, 1);
      }
      if(expressions[i].data[j] == ')')
      {
        if(stack.tam != 0 && stack.topo->dado == 1)
        {
          pop(&stack);
        }
        else{
          push(&stack, 2);
        }
      }
    }
    if(is_empty_pilha(&stack))
    {
      strcpy(answer[i].data, "correct");
    }
    else{
      strcpy(answer[i].data, "incorrect");
      for(int k=0; k<stack.tam;k++){pop(&stack);} // cleanig
    }
  }

  

  return 0;
}

void third()
{
  int size;

  scanf("%d", &size);
  Expression *expressions = (Expression*)malloc(size*sizeof(Expression));
  Answer *answer = (Answer*)malloc(size*sizeof(Answer));

  for(int i = 0; i < size; i++)
  {
    scanf("%s", expressions[i].data);
  }

  parentheses(expressions, &size, answer);
  
  for(int i = 0; i < size; i++)
  {
    printf("%s\n", answer[i].data);
  }

  free(expressions);
  free(answer);
}
