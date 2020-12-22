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

void printNth(int nth) {
  Node *curr = head; 
   int urutan=0; 
   int maju=0;                                      
  while(curr){
    urutan++;
    curr = curr->next; 
  }
  int terakhir=urutan-nth;
  curr=head;
  while(curr){
    if(terakhir==maju){
        printf("Urutan ke %d terakhir adalah %d\n",nth,curr->value);
    }
    maju++;
    curr = curr->next; 
  }
}

int main(){
    int nth;
    scanf("%d",&nth);
    pushTail(1);
    pushTail(2);
    pushTail(3);
    pushTail(4);
    pushTail(5);
    printNth(nth);
    return 0;
}