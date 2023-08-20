#include <stdio.h>
#include <stdlib.h>
#define N 10
int f = -1, r = -1;

struct queue{
    int data;
    struct queue * next;
};
struct queue *front, *rear;
int isFull(){
    if(r==N-1)
    return 1;
    else 
    return 0;
}

int isEmpty(){
    if (f==-1 && r==-1)
    return 1;
    else 
    return 0;
}

void enqueue(int data){
    struct queue *newitem = (struct queue *)malloc(sizeof(struct queue));
    newitem->data = data;
    newitem->next = NULL;

    if(isFull())
    printf("\nQueue is Full!");
    else if(isEmpty()){
        f=r=0;
        front = newitem;
        rear = newitem;
        printf("\n%d is added in the queue!",newitem->data);
    }
    else{
        rear->next=newitem;
        rear=newitem;
        printf("\n%d is added in the queue!",newitem->data);
        r++;
    }
}

void dequeue(){
    if(isEmpty()){
        printf("\nQueue is Empty!");
    }
    else if(f==r){
        f=r=-1;
        struct queue *delitem;
        delitem=front;
        front=front->next;
        printf("\n%d is dequeued",delitem->data);
        free(delitem);
    }
    else{
        struct queue *delitem;
        delitem=front;
        front=front->next;
        f++;
        printf("\n%d is dequeued",delitem->data);
        free(delitem);
    }
}

void Display(){
    if(isEmpty()){
        printf("\nQueue is Empty!");
    }
    else{
        struct queue *temp;
        temp=front;
        printf("\n");
        while(temp!=NULL){
            printf("%d -- ",temp->data);
            temp=temp->next;
        }
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    enqueue(70);
    Display();
    return 0;
}
