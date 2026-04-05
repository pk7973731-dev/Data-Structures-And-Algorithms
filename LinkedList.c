#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

 struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;


bool headCheck()
{
    if(head == NULL)
    {
        printf("Your List is empty\n");
        return true;
    }
    else
    {
        return false;
    }
}
void Create ( int val)
{
    struct node* nn;
    struct node* temp;
    nn = (struct node*)malloc(sizeof(struct node));
    nn->data = val;
    nn->next = NULL;
    if(head == NULL)
    {
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
    }
    printf("Your data is added in out list\n");
}

//Create^

void AddBig(int val)
{
    struct node* nn;
    nn = (struct node*)malloc(sizeof(struct node));
    nn->data = val;
    nn->next = NULL;
    nn->next = head;
    head = nn;
    printf("Your element is added in the list\n");
}

//AddBig^

void AddMid(int refv, int val)
{
    if(!headCheck())
    {
        bool flag = false;
    struct node* nn;
    struct node* temp = head;
    nn = (struct node*)malloc(sizeof(struct node));
    nn->data=val;
    nn->next = NULL;
    while(temp!= NULL )
    {
        if(temp->data == refv)
        {
            nn->next  = temp->next;
            temp->next = nn;
            flag = true;
            break;
        }
    }
    if(flag)
    {
        printf("Your element is found and it new element is added \n");
        return ;
    }
    else
    {
        printf("We can't able to find there element \n");
        return ;
    }

    }
}

void DeleteEnd()
{
    struct node* temp;
    if(!headCheck())
    {
        temp = head;
        while(temp->next->next!= NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
    }
}

void DeleteBig()
{
    if(!headCheck())
    {
        head = head->next;
    }
    
}

void DeleteMid(int refv)
{
    if(!headCheck())
    {
        bool flag = false;
    struct node* temp;
    if(!headCheck())
    {
        temp = head;
        while(temp!=NULL)
        {
            if(temp->next->data == refv)
            {
                temp->next = temp->next->next;
                flag = true;
                break;
            }
        }
    }
    if(flag)
    {
        printf("Your element is found and deleted \n");
        return;
    }
    else
    {
        printf("Your element is not found \n");
        return;
    }
    }
}

void SearchUp(int refv, int val )
{
    if(!headCheck())
    {
        bool flag = false;
    struct node* temp;
    temp = head;
    while(temp!= NULL)
    {
        if(temp->data == refv)
        {
            temp->data = val;
            flag = true;
            break;
        }

    }
    if(flag)
    {
        printf("Your element is found and updated\n");
        return;
    }
    else
    {
        printf("We can't able to find your element\n");
        return;
    }
    }
}

void Display()
{
    struct node* temp ;
    if(!headCheck())
    {
        temp = head;
        printf("Your list is \n [ ");
        while(temp!=NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        //printf("%d ", temp->data);
        printf("] \n");
    }
}

void Leave()
{
    printf("\t\t\t\t============================\n");
    printf("\t\t\t\t      THANK YOU (^_^)       \n");
    printf("\t\t\t\t============================\n");
    getchar();
    exit(0);
}

/*
void Create ( int val)
AddBig(int val)
AddMid(int revf, int val)
DeleteEnd()
DeleteBig()
DeleteMid(int refv)
SearchUp(int refv, int val )
Display()
Leave()
*/

int main()
{
    int ch, a, b;
    printf("\t\t\t\t===================================================\n");
    printf("\t\t\t\t          LINKED LIST IMPLEMENTATION               \n");
    printf("\t\t\t\t===================================================\n\n\n");
    while(true)
    {
        printf("\n\n");
        printf("\t\t\t\t1. Add element \n");
        printf("\t\t\t\t2. Add at Bigin \n");
        printf("\t\t\t\t3. Add at middle \n");
        printf("\t\t\t\t4. Delete at end \n");
        printf("\t\t\t\t5. Delete at Bigin\n");
        printf("\t\t\t\t6. Delete at middle\n");
        printf("\t\t\t\t7. Search and Update\n");
        printf("\t\t\t\t8. Display all elements\n");
        printf("\t\t\t\t9. Exit\n");
        printf("\t\t\t\tEnter Your Choice : ");
        scanf("%d", &ch);
        system("cls");
        switch(ch)
        {
            case 1:{
                printf("Enter a value: \n");
                scanf("%d", &a);
                Create (a);
                break;
            }
            case 2:{
                printf("Enter a value: \n");
                scanf("%d",&a);
                AddBig(a);
                break;
            }
            case 3:{
                printf("Enter a reference value: \n");
                scanf("%d", &a);
                printf("Enter a new value: \n");
                scanf("%d", &b);
                AddMid(a,b);
                break;
            }
            case 4:{
                DeleteEnd();
                break;
            }
            case 5:{
                DeleteBig();
                break;
            }
            case 6:{
                printf("Enter the reference value: \n");
                scanf("%d", &a);
                DeleteMid(a);
                break;
            }
            case 7:{
                printf("Enter the reference value: \n");
                scanf("%d", &a);
                printf("Enter the new value: \n");
                scanf("%d", &b);
                SearchUp(a,b);
                break;
            }
            case 8:{
                Display();
                break;
            }
            case 9:{
                Leave();
                break;
            }
            default: {
                printf("Invalid user input, Try Again!..\n");
                break;
            }
        }
    }
}