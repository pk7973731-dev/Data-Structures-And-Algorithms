#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define Max 10

int stk[Max]  ;
int top = -1;


bool topCheck()
{
    if(top == Max-1)
    {
        printf("Your Stack is filled \n");
        return true;
    }
    else
    {
        top++;
        return false;
    }
}

bool IsEmpty()
{
    if(top== -1)
    {
        printf("Your Stack is empty\n");
        return true;
    }
    else
    {
        return false;
    }
}
void push(int val)
{
    if(!topCheck())
    {
        stk[top] = val;
        printf("Your element is added \n");
    }
    
}

void peek()
{
    if(!IsEmpty())
    {
        printf(" %d \n", stk[top]);
    }
}

void pop()
{
    int val;
    if(!IsEmpty())
    {
        val = stk[top];
        top--;
        printf("%d\n", val);
    }
}

void display()
{
    
    if(!IsEmpty())
    {
        for ( int i = top ;i >=0;i--)
        {
            printf("[  %d  ]\n", stk[i]);
        }
    }
}

void leave()
{
    printf("\t\t\t\t=========================\n");
    printf("\t\t\t\t     THANK YOU (^_^)     \n");
    printf("\t\t\t\t=========================\n");
    exit(0);
}

int main()
{
    int ch, a;
    printf("\t\t\t\t===============================\n");
    printf("\t\t\t\t          STACKby Array        \n");
    printf("\t\t\t\t===============================\n");
    printf("\n\n");
    while(true)
    {
        printf("\t\t\t\t1. Push \n");
        printf("\t\t\t\t2. Peek \n");
        printf("\t\t\t\t3. Pop  \n");
        printf("\t\t\t\t4. Display \n");
        printf("\t\t\t\t5. Exit \n");
        printf("\t\t\t\tEnter Your Choice : ");
        scanf("%d", &ch);
        system("cls");
        switch(ch)
        {
            case 1:
            {
                printf("Enter  a value : ");
                scanf("%d", &a);
                push(a);
                break;
            }
            case 2:
            {
                peek();
                break;
            }
            case 3:
            {
                pop();
                break;
            }
            case 4:
            {
                display();
                break;
            }
            case 5:
            {
                leave();
                break;
            }
            default:
            {
                printf("invalid input \n");
                break;
            }
        }
    }
}