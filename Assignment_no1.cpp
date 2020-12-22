#include <stdio.h> //i/o
#include<stdlib.h> // dynamic emory allocation

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
void pushTail2(int value) {
  Node *temp = createNode(value);

  if(!head2) { 
    head2 = tail2 = temp;
  } else { 
    tail2->next = temp; 
    tail2 = temp; 
  }
}
void mergeList() {
  Node *curr = head2;                     
  while(curr) { 
      //Perlu buat dua ling list, pushtail nilai dari link list ke 2 ke yang pertama,
      // terseah mau di free ato gk
    pushTail(curr->value);
    curr = curr->next;
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

int main(){
    pushTail(1);
    pushTail2(10);
    pushTail(2);
    pushTail2(20);
    pushTail(3);
    pushTail2(30);
    pushTail(4);
    pushTail2(40);
    pushTail(5);
    pushTail2(50);
    mergeList();
    printLinkedList();
    return 0;
}