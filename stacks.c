// stacks using queues
#include<stdio.h>
#include<stdlib.h>
#define N 5
int arr[N];
int top = -1;

int isFull(){
    if(top==(N-1))
    return 1;
    else
    return 0;
}

int isEmpty(){
    if(top==-1)
    return 1;
    else
    return 0;
}

void push(int data){
    if(isFull())
    printf("\nOverflow!");
    else{
        top++;
        arr[top] = data;
        printf("\n%d is pushed in the stack",arr[top]);
    }
}

void pop(){
    if(isEmpty())
    printf("\nUnderflow!");
    else{
        printf("\n%d is popped from the stack",arr[top]);
        top--;
    }
}

void TopElement(){
    if(isEmpty()){
        printf("\nStack is empty!");
    }
        else{
            printf("\n%d is the top of the Stack!",arr[top]);
        }
    }

void Display(){
    for(int i=0;i<top;i++){
        printf("\n%d",arr[i]);
        printf("\n--");
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    Display();
    TopElement();
    pop();
    TopElement();
    return 0;
}
