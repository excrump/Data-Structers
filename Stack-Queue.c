#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#define size 100
#define stack_size 100
#define queue_size 100

struct node {
    int data;
    struct node *next;
};
typedef struct {
    int cnt;
    struct node *top;
}stack;
typedef struct {
    int cnt;
    struct node *rear;
    struct node *front;
}queue;
void initialize_stack(stack *stk){
    stk->cnt = 0;
    stk->top = NULL;
}
void initialize_queue(queue *q){
    q->cnt=0;
    q->rear=q->front=NULL;
}
typedef enum {false, true}boolean;
 boolean isEmpty_stack(stack *stk) {
     return(stk -> cnt == 0);
    }
    boolean isFull_stack(stack *stk) {
        return(stk -> cnt == stack_size);
    }
void push(stack *stk,int a){
    if(!isFull_stack(stk)){
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        temp->data=a;
        temp-> next=stk->top;
        stk->top =temp;
        stk->cnt++;
    }else{
        printf("Stack dolu");
    }
}
int pop(stack *stk){
    if(!isEmpty_stack(stk)){
        struct node *temp=stk->top;
        stk->top=stk->top->next;
        int x=temp->data;
        free(temp);
        stk->cnt--;
        return x;
    }
}
int isEmpty_queue(queue *q){
    return (q->cnt == 0);
}
int isFull_queue(queue *q){
    return (q->cnt == queue_size);
}
void enqueue(queue *q, int x){
    if(!isFull_queue(q)){
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        temp->next=NULL;
        temp->data=x;
        if(isEmpty_queue(q)){
            q->front=q->rear=temp;
        }else{
            q->rear=q->rear->next=temp;
        }
        q->cnt++;
    }
}
int dequeue(queue *q){
    if(!isEmpty_queue(q)){
        struct node *temp=q->front;
        int x = temp->data;
        q->front=temp->next;
        free(temp);
        q->cnt--;
        return x;
    }
}
int main(){                 // Program to Check if a Given String is Palindrome with using Stacks and queues.
      char string[size];
    queue q;
    stack s;
    int i=0;
    int miss=0;
    initialize_queue(&q);
    initialize_stack(&s);
    printf("Palindromu kontrol edilecek ifadeyi giriniz. \n");
    gets(string);
    for(i=0; i !=strlen(string); i++){
        if(isalpha(string[i])){
            enqueue(&q, tolower(string[i]));
            push(&s, tolower(string[i]));
        }
    }
    while (!isEmpty_queue(&q)){
        if(pop(&s) != dequeue(&q)){
            printf("Palindrom degildir;");
            return 0;
        }else{
    printf("Palindromdur");
    return 0;
        }
    }
    getch();
    return 0;
}
