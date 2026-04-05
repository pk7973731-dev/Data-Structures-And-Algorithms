#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define Max 40

//Global:
int arr[Max];
int n =-1;

bool IsEmpty()
{
    if(n == Max-1)
    {
        printf("Your List is full\n");
        return true;
    }
    else 
    {
        n++;
        return false;
    }
}
//IsEmpty^

bool MinArray()
{
    if(n==-1)
    {
        printf("Your List is Empty\n");
        return true;
    }
    else
    {
        return false;
    }
}
//MinArray^

void MakeList()
{
    int ending;
    f1:
    printf("Enter the ending value: \n");
    scanf("%d",&ending);
    if(ending <= Max-1)
    {
        n= ending-1;
        printf("Enter %d numbers : \n", ending);
        for(int i = 0;i<=n;i++)
        {
            scanf("%d", &arr[i]);
        }
        printf("Your elements are added \n");
    }
    else
    {
        printf("Your value is more than the maximum \n ");
        goto f1;
    }
}
//MakeList^

void AddElement(int val)
{
    if(!IsEmpty())
    {
        arr[n]= val;
        printf("Your Element is added in our list ADT \n");
    }

}
//AddElement^

void AddMiddle(int pos, int val)
{
    if(!IsEmpty() && pos<=n)
    {
        for(int i = n;i>pos;i--)
        {
            arr[i] = arr[i-1];
        }
        arr[pos] = val;
    }
}
//AddMiddle^

void AddBigin(int val)
{
    if(!IsEmpty())
    {
        for( int j = n;j>0;j--)
        {
            arr[j] = arr[j-1];
        }
        arr[0] = val;
    }
}
//AddBigin^

void DeleteEnd()
{
    if(!MinArray())
    {
        n--;
        printf("The Last Element is Deleted frm the List ADT\n");
    }
}
//DeleteEnd^

void DeleteBigin()
{
    if(!MinArray())
    {
        n--;
        for(int k = 0;k<=n;k++)
        {
            arr[k] = arr[k+1];
        }
        printf("Your Last Element of the list ADT is removed\n");
    }
}
//DeleteBigin^

void DeleteMiddle(int pos)
{
    if(!MinArray() && pos<=n)
    {
        n--;
        for(int p = pos;p<=n;p++)
        {
            arr[p] = arr[p+1];
        }
        printf("Your Element is removed form the list ADT \n");
    }
}
//DeleteMiddle^

int Search(int refv ) // int val
{
    bool flag = false;
    int pos;
    if(!MinArray())
    {
        for(int q = 0;q <= n;q++)
        {
            if(arr[q] == refv)
            {
                flag = true;
                pos = q;
                //arr[q] = val;
                break;
            }
        }
    }
    if(flag == true) 
    {
        printf("Your Element is Found at Index %d \n", pos);
        return pos;
    }
    else
    {
        printf("we can't able to find your Element \n");
        return Max-1;
    }
}
//Search^

void Display()
{
    if(!MinArray())
    {
        printf("Your Array is \n ");
        printf("[ ");
        for(int i = 0;i<= n;i++)
        {
            printf("%d ", arr[i]);
        }
        printf("] \n\n");
    }
}
//Display^

void Leave()
{
    printf("================================\n");
    printf("          THANK YOU (^_^)       \n  ");
    printf("================================\n");
    getchar();
    exit(0);
}
//Leave^

// The OG

int main()
{
    int ch, pos, rev,val;
    printf("\t\t\t\t====================================\n");
    printf("\t\t\t\t           LIST ADT                 \n");
    printf("\t\t\t\t====================================\n");
    printf("\n\n\n");
    MakeList();
    while(true)
    {
        printf("\n\n");
        printf("\t\t========================================================\n");
        printf("\t\t1.  to add element at end \n");
        printf("\t\t2.  to add element at bigin \n");
        printf("\t\t3.  to add element at middle \n");
        printf("\t\t4.  to search an element \n");
        printf("\t\t5.  to delete at end\n");
        printf("\t\t6.  to delete at bigin \n");
        printf("\t\t7.  to delete at middel \n");
        printf("\t\t8.  to search for an element and update \n");
        printf("\t\t9.  to search for an element and  delete that \n ");
        printf("\t\t10. to Display the elements \n ");
        printf("\t\t11. to exit from the code \n ");
        printf("\n\n\t\tEnter Your Input : ");
        scanf("%d", & ch);
        system("cls");
        switch(ch)
        {
            case 1:{
                printf("Enter a value : \n");
                scanf("%d",&val);
                AddElement(val);
                break;
            }
            case 2:{
                printf("Enter a value : \n");
                scanf("%d",&val);
                AddBigin(val);
                break;
            }
            case 3:{
               printf("Enter the position: \n");
               scanf("%d", &pos);
               printf("Enter a value : \n");
               scanf("%d", &val);
               AddMiddle(pos,val);
               break;
            }
            case 4:{
                printf("Enter the element : \n");
                scanf("%d",rev);
                Search(rev);
                break;
            }
            case 5:{
                DeleteEnd();
                break;
            }
            case 6:{
                DeleteBigin();
                break;
            }
            case 7:{
                printf("Enter the Position : \n");
                scanf("%d", &pos);
                DeleteMiddle(pos);
                break;
            }
            case 8:{
                printf("Enter the value : \n");
                scanf("%d", &rev);
                printf("Enter the new val : \n");
                scanf("%d", & val);
                AddMiddle(Search(rev),val);
                break;
            }
            case 9:{
                printf("Enter the value : \n");
                scanf("%d", &rev);
                DeleteMiddle(Search(rev));
                break;
            }
            case 10:{
                Display();
                break;
            }
            case 11:{
                Leave();
                break;
            }
            default:{
                printf("Invalid User Inputs : Try Again!..\n");
                break;
            }
        }//switch^
    }//while^
}//main^