#include<stdio.h>
#include<stdlib.h>
#define capacity 5
int arr[capacity];
int top = -1;
int isFull()
{
  if(top == capacity-1)
  {
    printf("Stack is full");
   return 1;
  }
  return 0;
}
int isEmpty()
{
  if (top == -1)
  {
    printf("Stack is Empty");
    return 1;
  }
  return 0;
}
int push(int x)
{
  if(isFull())
  {
    exit(0);
  }
  top++;
  arr[top] = x;
  return x;
}
int pop()
{
  if(isEmpty())
  {
  exit(0);
  }
  top--;
  printf("The deleted element is %d",arr[top+1]);
  return arr[top+1];
}
int peek()
{
  if(isEmpty())
  {
    exit(0);
  }
  printf("The peek element is %d",arr[top]);
  return arr[top];
}
void display()
{
  if(isEmpty())
  {
    return;
  }
  printf("The element in the stack are : ");
  for(int i=0;i<=top;i++)
  {
    printf("%d ",arr[i]);
  }
}
void main()
{
  int i=1,x,choice;
  while(i=1){
 printf("\n1). Push\n2). Pop\n3). peek\n4). Display\n");
 printf("Enter your choice : ");
 scanf("%d",&choice);
 if(choice == 1)
 {
  printf("Enter the element to push : ");
  scanf("%d",&x);
  push(x);
 }
 else if(choice == 2)
 {
  pop();
 }
 else if(choice == 3)
 {
  peek();
 }
 else if(choice == 4)
 {
display();
 }
 else
 {
  printf("Enter the valid choice.....!!!");
 }
}
}
