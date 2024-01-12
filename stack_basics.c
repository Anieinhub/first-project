#include<stdio.h>
#include<stdlib.h>
int item;
int stack[10];
int top=-1;
int maxsize=10;
 
void push()
{
    if(top==maxsize-1)
      printf("Stack overflow!\n");
    else
    {
        printf("Enter the item to be pushed\n");
        scanf("%d",&item);
        top=top+1;
        stack[top]=item;
    }
}
void pop()
{
    if(top==-1)
      printf("Stack underflow!\n");
    else
    {
        item=stack[top];
        top=top-1;
        printf("The popped element is %d\n",item);
    }
}
void display()
{
    if(top==-1)
      printf("Stack is empty\n");
    else
    {
        printf("The stack is as follows\n");
        for(int i=top;i>=0;i--)
           printf("%d\n",stack[i]);
    }
}
void main()
{
    int ch;
    while(1)
    {
        printf("Menu:\n1.Push \t 2.Pop\t3.Display\t4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
             case 4:
                exit(0);
            default:
                printf("Invalid input\n");
                break;
        }                
    }    
}