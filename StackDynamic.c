#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}NODE,*PNODE,**PPNODE;

void Push(PPNODE Head,int No)
{
    PNODE temp = *Head;
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = No;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

int Pop(PPNODE Head)
{
    int iValue = 0;
    PNODE temp = *Head;

    if(*Head == NULL)
    {
        printf("Stack is empty \n");
        return -1;
    }
    else if((*Head)->next == NULL)
    {
        iValue = (*Head)->data;
        free(*Head);
        *Head = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        iValue = temp->next->data;
        free(temp->next);
        temp->next = NULL;
    }
    return iValue;
}

void Display(PNODE Head)
{
    if(Head == NULL)
    {
        printf("Stack is empty \n");
        return;
    }

    while(Head != NULL)
    {
        printf("| %d | \n",Head->data);
        Head = Head->next;
    }
}

int Count(PNODE Head)
{
    int iCount = 0;

    while(Head != NULL)
    {
        iCount++;
        Head = Head->next;
    }
    return iCount;
}

int main()
{
    PNODE first = NULL;
    int iChoice = 0;
    int iValue = 0,iRet = 0;

    printf("---------------------------------------------------------------------------------------\n");
    printf("Dynamic Impletation of Stack \n");
    printf("---------------------------------------------------------------------------------------\n");

    while(1)
    {
        printf("-----------------------------------------------------------------------------------\n");
        printf("1 : To push element into stack\n");
        printf("2 : To Pop element from stack \n");
        printf("3 : Display element from stack \n");
        printf("4 : Count elements of the stack \n");
        printf("0 : Terminate the application \n");
        printf("-----------------------------------------------------------------------------------\n");

        printf("Enter the choice \n");
        scanf("%d",&iChoice);

        if(iChoice == 1)
        {
            printf("Enter element to push in stack \n");
            scanf("%d",&iValue);
            Push(&first,iValue);
        }
        else if(iChoice == 2)
        {
            iRet = Pop(&first);
            if(iRet != -1)
            {
                printf("Poped element from stack is : %d\n",iRet);
            }
        }
        else if(iChoice == 3)
        {
            Display(first);
        }
        else if(iChoice == 4)
        {
            iRet = Count(first);
            printf("Count of elements in stack is : %d\n",iRet);
        }
        else if(iChoice == 0)
        {
            printf("Thank you for using application \n");
            return 0;
        }
        else
        {
            printf("NOTE : Please enter valid option \n");
        }
    }

    return 0;
}