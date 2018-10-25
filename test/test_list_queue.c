#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;
//def node
typedef struct QNode{
  DataType _elem;
  struct QNode* _next;
} QNode;

//def queue
typedef struct Queue{
  QNode* _front;
  QNode* _tail;
} Queue;

void InitQueue(Queue* queue){
  //set front and tail point the same node
  queue->_tail = queue->_front = NULL;
}
//tail insert
void inQueue(Queue* queue, DataType elem){
  if(NULL == queue->_front){
    //def one node
    queue->_front = (QNode*)malloc(sizeof(QNode));
    //node assignment 
    queue->_front->_elem = elem;  
    queue->_front->_next = NULL;
    queue->_tail = queue->_front;
  } else {
    queue->_tail->_next = (QNode*)malloc(sizeof(QNode));
    queue->_tail->_next->_elem = elem;
    queue->_tail->_next->_next = NULL;
    queue->_tail = queue->_tail->_next;
  }
}
//head output
QNode* outQueue(Queue* queue){
  if(queue->_front == NULL){
    return NULL; 
  } 
  QNode* tmp = queue->_front;
  queue->_front = queue->_front->_next;
  return tmp;
}

//test
int main(){
  Queue q; 
  InitQueue(&q);
  inQueue(&q, 1);
  inQueue(&q, 2);
  inQueue(&q, 3);
  inQueue(&q, 4);
  int i = 0;
  printf("queue data: ");
  while(i < 4){
    printf("%d ", q._front->_elem);
    outQueue(&q);
    ++i;
  }
  printf("\n");
  return 0;
}
