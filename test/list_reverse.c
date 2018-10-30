#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct Node{
  DataType _elem;
  struct Node* _link;
}Node, *PNode;


void Init(PNode* head){
  assert(head);
  *head = NULL;
}

void Insert(PNode* head, DataType elem){
  assert(head);
  if(NULL == *head){
    *head = (PNode)malloc(sizeof(Node));
    (*head)->_elem = elem;
    (*head)->_link = NULL;
  } else {
    PNode tmp = (PNode)malloc(sizeof(Node));
    tmp->_elem = elem;
    tmp->_link = *head;
    *head = tmp;
  }
}

void Print(PNode head){
  assert(head);
  PNode tmp = head;
  while(tmp){
    printf("%d ", tmp->_elem);
    tmp = tmp->_link;
  }
  printf("\n");
}

void ListReverse(PNode* head){
  assert(head);
  PNode ptr = *head;
  PNode ptr_pre = NULL;
  PNode ptr_next = NULL;
  while(ptr){
    ptr_next = ptr->_link;
    ptr->_link = ptr_pre;
    ptr_pre = ptr;
    ptr = ptr_next;
  }
  *head = ptr_pre;
}

//test
int main(){
  PNode head;
  Init(&head);
  Insert(&head, 5);
  Insert(&head, 4);
  Insert(&head, 3);
  Insert(&head, 2);
  Insert(&head, 1);
  Print(head);
  ListReverse(&head);
  Print(head);
  return 0;
}
