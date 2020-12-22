#include<stdio.h>  
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
void printMiddle(struct Node *head){  
    struct Node *slow_ptr = head;  
    struct Node *fast_ptr = head;  
  
    if (head!=NULL)  
    {  
        while (fast_ptr != NULL && fast_ptr->next != NULL)  
        {  
            fast_ptr = fast_ptr->next->next;  
            slow_ptr = slow_ptr->next;  
        }  
        printf("The middle element is [%d]\n\n", slow_ptr->value);  
    }  
}  

int main(){
    pushTail(1);
    pushTail(2);
    pushTail(3);
    pushTail(4);
    pushTail(5);
    printLinkedList();
    printMiddle(head);
    return 0;
}