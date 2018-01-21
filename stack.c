#include "stdio.h"
#include "string.h"
#include "stdlib.h"
typedef struct _node{
    void *data;
    struct _node *next;
}Node;
typedef struct _stack{
    Node* current;
    Node* head;
    Node* tail;
}Stack;
void initializeStack(Stack* stack){
    stack->head=NULL;
    stack->tail=NULL;
    stack->current=NULL;
}
void push(Stack* stack,void *data){
    Node* node=(Node*)malloc(sizeof(Node));
    node->data=data;
    if(stack->head==NULL){
        stack->tail=node;
    }else{
        node->next=stack->head;
    }
    stack->head=node;
}
void* pop(Stack* stack){
    Node* node=stack->head;
    if(node==NULL)
        return(NULL);
    else if(node==stack->tail){
        stack->head=stack->tail=NULL;
        void* data=node->data;
        free(node);
        return(data);
    }else
    {
        stack->head=node->next;
       void* data=node->data;
      free(node) ;
      return(data);
    }
}

typedef struct _employee{
    char name[32];
    unsigned char age;
}Employee;
void main(){
    Employee* Susan=(Employee*)malloc(sizeof(Employee));
    Employee* Sally=(Employee*)malloc(sizeof(Employee));
    Employee* Samuel=(Employee*)malloc(sizeof(Employee));
    strcpy(Susan->name,"Susan");
    strcpy(Sally->name,"Sally");
    strcpy(Samuel->name,"Samuel");
    Samuel->age=1;
    Sally->age=2;
    Samuel->age=3;
    Stack stack;
    initializeStack(&stack);
    push(&stack,Susan);
    push(&stack,Sally);
    push(&stack,Samuel);
    Employee *employee;
    for(int i=0;i<4;i++){
        employee=(Employee*)pop(&stack);
        printf("Popped %s\n",employee->name);
    }
}



























