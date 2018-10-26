#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int DataType;
typedef struct Stack{
  DataType _elem;
  struct Stack* _next;
} Stack;

void Push(Stack** stack, DataType elem){
  assert(stack);
  Stack* tmp = (Stack*)malloc(sizeof(Stack));
  tmp->_elem = elem;
  tmp->_next = *stack;
  *stack = tmp;
}

void Pop(Stack** stack){
  assert(stack);
  if(NULL == *stack){
    return;
  }
  Stack *tmp = *stack;
  *stack = (*stack)->_next;
  free(tmp);
}

Stack* Top(Stack* stack){
  return stack;
}

int main(){
  Stack* s = NULL;
  Push(&s, 1);
  Push(&s, 2);
  Push(&s, 3);
  Push(&s, 4);
  int i = 0;
  for(; i < 4; ++i){
    Stack* tmp = NULL;
    tmp = Top(s);
    printf("%d ", tmp->_elem);
    Pop(&s);
  }
  printf("\n");
  return 0;
}
