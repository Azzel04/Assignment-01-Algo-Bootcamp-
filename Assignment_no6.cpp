#include <stdio.h> 
#include<stdlib.h> 

int counter=0;

struct Node {
  int value; 
  Node *next; 
} *head, *tail;

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
  counter++;
}

void Revrs(){
    Node *curr = head;
    Node *prev=NULL;
    Node *next;

    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head = prev; 
  }
void printLinkedList() {
  Node *curr = head; 
                                          
  while(curr) { 
    printf("%d -> ", curr->value); 
    curr = curr->next; 
  }
  printf("NULL\n");
}
int main(){
    pushTail(1);
    pushTail(2);
    pushTail(3);
    pushTail(4);
    pushTail(5);
    Revrs();
    printLinkedList();
    return 0;
}