#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int a[MAX],front=-1,rear=-1;
void enqueue(int data){
        if(front==-1 && rear==-1){
                front=rear=0;
                a[rear]=data;
        }
        else if((rear+1)%MAX==front){
                printf("queue is full");
                exit(1);
        }
        else{
                rear=(rear+1)%MAX;
                a[rear]=data;
        }
}
void dequeue(){
        if(front==-1 && rear==-1){
                printf("queue is empty");
                exit(1);
        }
        else if(front==rear){
                printf("removed element : %d\n",a[front]);
                front=rear=-1;
        }
        else{
                printf("removed element : %d\n",a[front]);
                front=(front+1)%MAX;
        }
}
void display(){
        if(front==-1 && rear==-1){
                printf("queue is empty");
                exit(1);
        }
        int i=front;
        while(i!=rear){
                printf("%d ",a[i]);
                i=(i+1)%MAX;
        }printf("%d\n",a[i]);
}
void peek(){
        if(front==-1 && rear==-1){
                printf("queue is empty");
                exit(1);
        }
        printf("%d\n",a[front]);
}
int main(){
        int choice,element;
        while(1){
                printf("enter 1 for enqueue 2 for dequeue 3 for peek 4 for display 5 to quit : ");
                scanf("%d",&choice);
                switch(choice){
                        case 1:
                                printf("enter element : ");
                                scanf("%d",&element);
                                enqueue(element);
                                break;
                        case 2:
                                dequeue();
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