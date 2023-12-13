#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int a[MAX],front=0,rear=0;
int isEmpty(){
        if(front == rear){
                return 1;
        }
        return 0;
}
int isFull(){
        if(rear==MAX-1){
                return 1;
        }
        return 0;
}
void enqueue(int data){
        if(isFull()){
                printf("queue is full\n");
                exit(1);
        }
        a[rear++]=data;
}
int dequeue(){
        if(isEmpty()){
                printf("queue is empty\n");
                exit(1);
        }
        return a[front++];
}
void peek(){
        printf("%d\n",a[front]);
}
void display(){
        if(isEmpty()){
                printf("queue is empty\n");
                exit(1);
        }
        for(int i=front;i<rear;i++){
                printf("%d ",a[i]);
        }printf("\n");
}
int main(){
        int choice,element;
        while(1){
                printf("Enter corresponding no for choice:\n  -->enqueue(1)\n  -->dequeue(2)\n  -->peek(3)\n  -->display(4)\n  -->quit(5) : ");
                scanf("%d",&choice);
                switch(choice){
                        case 1:
                                printf("enter element : ");
                                scanf("%d",&element);
                                enqueue(element);
                             break;
                        case 2:
                                printf("removed element : %d\n",dequeue());
                                break;
                        case 3:
                                peek();
                                break;
                        case 4:
                                display();
                                break;
                        case 5:
                                exit(1);
                        default:
                                printf("wrong choice\n");
                }
        }
}