#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;

};

struct node* head = NULL;


void Create(int val)
{
    struct node* nn;
    struct node* temp;
    nn = (struct node*)malloc(sizeof(struct node));
    nn->data = val;
    if(head == NULL)
    {
        nn->prev = NULL;
        nn->next = NULL;
        head = nn;
    }
    else
    {
        temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
        nn->next = NULL;

    }
    printf("Your element is appended in our list \n");

}//Create

void InsertBig(int val)
{
    struct node* nn;
    nn = (struct node* )malloc(sizeof(struct node));
    nn->data = val;
    nn->prev = NULL;
    nn->next = head;
    head = nn;
    printf("Your element is inserted in the beginnig\n");
}//InsertBig

void InsetMid(int refv,int val)
{
    int flag = 0;
    struct node* nn;
    struct node* temp = head;
    nn = (struct node*)malloc(sizeof(struct node));
    nn->data = val;
    while(temp!=NULL)
    {
        if(temp->data == refv)
        {
            nn->prev = temp;
            nn->next = temp->next;
            temp->next->prev = nn;
            temp->next = nn;
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if(flag == 1)
    {
        printf("Your element is inserted \n");
        return ;
    }
    else
    {
        printf("We can't find the element specified\n");
        return ;
    }
}//InsetMid

void DeleteEnd()
{
    struct node* temp = head;
    while(temp->next->next!= NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    printf("Your last element is deleted \n");
    return ;
}//DeleteEnd

void DeleteBig()
{
    head->next->prev = NULL;
    head = head->next;
    printf("Your first element is deleted\n");
    return ;
}//DeleteBig

void DeleteMid(int refv)
{
    int flag=0;
    struct node* temp = head;
    struct node* pos;
    if(head->data == refv)
    {
        DeleteBig();
    }
    while(temp->next!=NULL)
    {
        if(temp->next->data == refv)
        {
            flag = 1;
            pos = temp->next->next;
            temp->next = pos;
            pos->prev = temp;
            break;
        }
        temp = temp->next;
    }
    if(temp->data == refv)
    {
        DeleteEnd();
    }
    if(flag == 1)
    {
        printf("Your element is deleted\n");
        return ;
    }
    else
    {
        printf("we can't able find your element\n");
        return ;
    }
}//DeleteMid

void SearchUp(int refv,int val)
{
    int flag = 0;
    struct node* temp = head;
    while(temp!=NULL)
    {
        if(temp->data == refv)
        {
            flag = 1;
            temp->data = val;
            break;
        }
        temp = temp->next;
    }

    if(flag == 1)
    {
        printf("your element is updated\n");
        return ;
    }
    else
    {
        printf("we can't find your element\n");
        return ;
    }
}//SearchUp

void Display()
{
    struct node* temp;
    temp = head;
    if(head == NULL)
    {
        printf("Your list is empty \n");
        return ;
    }

    printf("Your list is: \n");
    printf("[ ");
    while(temp!= NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("]\n\n");
    return ;
}//Display

int main()
{
    int a,b,ch;
    printf("\t\t\t\t=================================================================\n");
    printf("\t\t\t\t            DOUBLY LINKED LIST IMPLEMENTATION\n");
    printf("\t\t\t\t=================================================================\n\n\n");
    while(1)
    {
        printf("\t\t\t\t1.Create a element\n");
        printf("\t\t\t\t2.Display the list\n");
        printf("\t\t\t\t3.Insert at Beginning\n");
        printf("\t\t\t\t4.Insert at Middle\n");
        printf("\t\t\t\t5.Delete at End\n");
        printf("\t\t\t\t6.Delete at Beginning\n");
        printf("\t\t\t\t7.Delete at reference\n");
        printf("\t\t\t\t8.Search and Update\n");
        printf("\t\t\t\t9.Exit the Program\n");
        printf("\t\t\t\tEnter Your choice: ");
        scanf("%d",&ch);
        system("cls");
        switch(ch)
        {
            case 1:
            {
                printf("Enter a Element to add : \n");
                scanf("%d",&a);
                Create(a);
                break;
            }
            case 2:
            {
                Display();
                break;
            }
            case 3:
            {
                printf("Enter a Element to add at Beginnig : \n");
                scanf("%d",&a);
                InsertBig(a);
                break;
            }
            case 4:
            {
                if(head == NULL)
                {
                    printf("Your list is empty\n");
                    break;
                }
                printf("Enter a reference variable and : \n");
                scanf("%d",&a);
                printf("Enter a new element to insert : \n");
                scanf("%d",&b);
                InsetMid(a,b);
                break;
            }
            case 5:
            {
                if(head == NULL)
                {
                    printf("Your list is already empty\n");
                    break;
                }
                DeleteEnd();
                break;
            }
            case 6:
            {
                if(head == NULL)
                {
                    printf("Your list is already empty\n");
                    break;
                }
                DeleteBig();
                break;
            }
            case 7:
            {
                if(head == NULL)
                {
                    printf("Your list is already empty\n");
                    break;
                }
                printf("Enter the element to be deleted : \n");
                scanf("%d",&a);
                DeleteMid(a);
                break;
            }
            case 8:
            {
                if(head == NULL)
                {
                    printf("Your list is already empty\n");
                    break;
                }
                printf("Enter the element to be changed : \n");
                scanf("%d",&a);
                printf("Enter the new element to overwrite : \n");
                scanf("%d",&b);
                SearchUp(a,b);
                break;
            }
            case 9:
            {
                printf("\t\t\t\t=====================================\n");
                printf("\t\t\t\t          THANK YOUR(^_^)            \n");
                printf("\t\t\t\t=====================================\n");
                return 0;
            }
            default:
            {
                printf("Invalid user input , Please try again!..\n");
                break;
            }
        }
    }
    return 0;
}// main()


// Error Page: 
/*
    struct ;
    DeleteEnd;
    enter Your choice ; and
    DeleteMid()
*/