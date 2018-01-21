#include "stdlib.h"
#include "stdio.h"
typedef struct _node{
    void *data;
    struct _node *next;
}Node;
typedef struct _linkedList{
    Node* head;
    Node* tail;
    Node* current;
}LinkedList;

void initializeList(LinkedList* list)
{
   list->head=NULL;
  list->tail=NULL;
  list->current=NULL;
}
void addHead(LinkedList *list,void* data)
{
    Node *node=(Node*)malloc(sizeof(Node));
    node->data=data;
    if(list->head==NULL){
        node->next=NULL;
        list->tail=node;
    }else{
        node->next=list->head;
    }
    list->head=node;
}
void addTail(LinkedList* list,void* data){
   Node* node=(Node*)malloc(sizeof(Node));
   node->data;
   node->next=NULL;
   if(list->head==NULL){
       list->head=node;
   }else{
       list->tail->next=node;
   }
   list->tail=node;
}
void delete(LinkedList *list,Node *node){
    if(node==list->head){
        if(list->head->next==NULL){
            list->head=NULL;
            list->tail=NULL;
        }
        else{
            list->head=list->head->next; 
        }
    }else{
        Node* temp=list->head;
        Node *temp_1=list->head;
        while(temp!=node){
            temp=temp_1;
            temp_1=temp_1->next;
        }
        temp->next=temp_1->next;
    }
    free(node);
}
typedef struct _employee{
    char name[32];
    unsigned char age;
}Employee;

































