#include <stdio.h> 
#include<stdlib.h> 

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
}

void printLinkedList() {
  Node *curr = head; 
                                          
  while(curr) { 
    printf("%d -> ", curr->value); 
    curr = curr->next; 
  }
  printf("NULL\n");
}

void cycle(){
    Node *curr;
    int flag=0; 
    while(curr) { 
        if(curr==head){
            printf("CYCLE");
            flag=1;
        }
        curr = curr->next;
    }
    if(flag==0){
        printf("NOT CYCLE\n");
    }
}


int main(){
    pushTail(1);
    pushTail(2);
    pushTail(3);
    pushTail(4);
    pushTail(5);
    printLinkedList();
    cycle();
    return 0;
}