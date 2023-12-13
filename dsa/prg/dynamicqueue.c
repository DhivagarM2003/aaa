#include<stdio.h>
#include<stdlib.h>
struct queue{
        int * p;
        int front;
        int rear;
        int capacity;
};
void create(struct queue * b){
        b->p=(int *)malloc(sizeof(int));
        b->front=0;
        b->rear=-1;
        b->capacity=0;
}
void isFull(struct queue * b){
        if(b->rear==b->capacity-1){
                b->capacity++;
                b->p=(int *)realloc(b->p,b->capacity*sizeof(int));
        }
}
void enqueue(struct queue * b,int data){
        isFull(b);
        b->rear++;
        b->p[b->rear]=data;
}
int dequeue(struct queue * b){
        if(b->front>b->rear){
                printf("queue underflow");
                exit(1);
        }
        int element=b->p[b->front];
        (b->front)++;
        return element;
}
void peek(struct queue * b){
        printf("top element : %d\n",b->p[b->front]);
}
void display(struct queue * b){
        if(b->front==b->rear){
                printf("queue underflow");
                exit(1);
        }
        int i;
        for(i=b->front;i<=b->rear;i++)
                printf("%d ",b->p[i]);
        printf("\n");
}
int main(){
        struct queue a ,*b;
        b=&a;
        int choice,element;
        create(b);
        while(1){
                printf("Enter corresponding no for choice:\n  -->enqueue(1)\n  -->dequeue(2)\n  -->peek(3)\n  -->display(4)\n  -->quit(5) : ");
                scanf("%d",&choice);
                switch(choice){
                        case 1:
                                printf("enter element: ");
                                scanf("%d",&element);
                                enqueue(b,element);
                                break;
                        case 2:
                                printf("removed element :%d\n",dequeue(b));
                                break;
                        case 3:
                                peek(b);
                                break;
                        case 4:
                                display(b);
                                break;
                        case 5:
                                exit(1);
                        default:
                                printf("wrong choice\n");
                }
        }
}