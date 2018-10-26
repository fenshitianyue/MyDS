#include <stdio.h>
#include <assert.h>
#define MAXSIZE 10

typedef int DataType;
typedef struct QNode{
  DataType _data[MAXSIZE];
  int _front;
  int _tail;
} Queue;

void InitQueue(Queue* queue){
  assert(queue);
  queue->_front = 0;
  queue->_tail = 0;
}

void inQueue(Queue* queue, DataType elem){
  if((queue->_tail + 1) % MAXSIZE == queue->_front){
    printf("空间已满");
    return;
  }
  queue->_data[queue->_tail % MAXSIZE] = elem;
  queue->_tail++;
}

void outQueue(Queue* queue){
  if(queue->_front == queue->_tail){
    return;
  }
  queue->_front = (queue->_front + 1) % MAXSIZE;
}


int main(){
  Queue q;
  InitQueue(&q);
  inQueue(&q, 1);
  inQueue(&q, 2);
  inQueue(&q, 3);
  inQueue(&q, 4);
  inQueue(&q, 5);
  inQueue(&q, 6);
  inQueue(&q, 7);
  inQueue(&q, 8);
  int i = 0 ;
  printf("queue data: ");
  for(; i < 8; ++i){
    printf("%d ", q._data[q._front]);
    outQueue(&q);
  }
  printf("\n");
  return 0;
}
