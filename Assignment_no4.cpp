#include <stdio.h> 
#include<stdlib.h> 

struct Node {
  int value; 
  Node *next; 
} *head, *tail, *head2,*tail2;

Node *createNode(int value) {
  Node *temp = (Node*)malloc(sizeof(Node));
  temp->value = value;
  temp->next = NULL; 
  return temp;
}
void pushTail(int value) {
  Node *temp = createNode(value);

  if(!head) { 
    head = tail = temp;
  } else { 
    tail->next = temp; 
    tail = temp; 
  }
}

void printLinkedList() {
  Node *curr = head; 
                                          
  while(curr) { 
    printf("%d", curr->value); 
    printf("->");
    curr = curr->next; 
  }
  printf("NULL\n");
}

void del(){
    Node *curr = head;
    Node *temp;
    while(curr) { 
    if(curr->value==curr->next->value){
        temp=curr->next->next;
        curr->next=NULL;
        free(curr->next);
        curr->next=temp;
    }
    curr = curr->next; 
  }
}

int main(){
    pushTail(1);
    pushTail(2);
    pushTail(3);
    pushTail(3);
    pushTail(4);
    pushTail(5);
    pushTail(5);
    del();
    printLinkedList();
    return 0;
}