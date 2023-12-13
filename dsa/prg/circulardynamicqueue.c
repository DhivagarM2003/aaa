#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1,max=1;
void enqueue(int* a,int data){
        if(front==-1 && rear==-1){
                front=rear=0;
                a[rear]=data;
        }
        else if((rear+1)%max==front){
                max++;
                a= realloc(a,sizeof(int)*max);
                a[++rear] = data;
        }
        else{
                rear=(rear+1)%max;
                a[rear]=data;
        }
}
void dequeue(int* a){
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
                front=(front+1)%max;
        }
}
void display(int* a){
        if(front==-1 && rear==-1){
                printf("queue is empty");
                exit(1);
        }
        int i=front;
        while(i!=rear){
                printf("%d ",a[i]);
                i=(i+1)%max;
        }
        printf("%d\n",a[i]);
}
void peek(int* a){
        if(front==-1 && rear==-1){
                printf("queue is empty");
                exit(1);
        }
        printf("%d\n",a[front]);
}
int main(){
        int* a = (int *)malloc(sizeof(int));
        int choice,element;
        while(1){
                printf("Enter Your choice:\n  -->enqueue(1)\n  -->dequeue(2)\n  -->peek(3)\n  -->display(4)\n  -->quit(5) : ");
                scanf("%d",&choice);
                switch(choice){
                        case 1:
                                printf("enter element : ");
                                scanf("%d",&element);
                                enqueue(a,element);
                                break;
                        case 2:
                                dequeue(a);
                                break;
                        case 3:
                                peek(a);
                                break;
                        case 4:
                                display(a);
                                break;
                        case 5:
                                exit(1);
                        default:
                                printf("wrong choice\n");
                }
        }
}