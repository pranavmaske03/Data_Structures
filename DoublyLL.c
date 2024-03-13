#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}NODE, *PNODE,**PPNODE;

void InsertFirst(PPNODE Head,int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->next = NULL;
    newn->prev = NULL;
    newn->data = No;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {   
        (*Head)->prev = newn;
        newn->next = *Head;
        *Head = newn;
    }
}

void InsertLast(PPNODE Head,int No)
{
    PNODE temp = *Head;
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->prev = NULL;
    newn->next = NULL;
    newn->data = No;

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
        newn->prev = temp;
    }
}

void Display(PNODE Head)
{
    while(Head != NULL)
    {
        printf("| %d | <=>",Head->data);
        Head = Head->next;
    }

    printf("\n");
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

void DeleteFirst(PPNODE Head)
{
    if(*Head == NULL)
    {
        return;
    }
    else if((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        *Head = (*Head)->next;
        free((*Head)->prev);
        (*Head)->prev = NULL;
    }
}

void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;

    if(*Head == NULL)
    {
        return;
    }
    else if((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void InsertAtPos(PPNODE Head,int No,int iPos)
{
    int iCnt = 0,iLength = 0;
    PNODE newn = NULL;
    PNODE temp = *Head;

    iLength = Count(*Head);

    if((iPos < 1) || (iPos > iLength+1))
    {
        printf("Invalid position \n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(Head,No);
    }
    else if(iPos = iLength+1)
    {
        InsertLast(Head,No);
    }
    else
    {
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn = (PNODE)malloc(sizeof(NODE));
        newn->next = NULL;
        newn->prev = NULL;
        newn->data = No;

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
    }
}

void DeleteAtPos(PPNODE Head,int iPos)
{
    int iCnt = 0,iLength = 0;
    PNODE temp = *Head;

    iLength = Count(*Head);

    if((iPos < 1) || (iPos > iLength))
    {
        printf("Invalid position \n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(Head);
    }
    else if(iPos = iLength)
    {
        DeleteLast(Head);
    }
    else
    {
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }
}

int main()
{
      PNODE First = NULL;
    int iRet = 0;

    InsertFirst(&First, 51);
    InsertFirst(&First, 21);
    InsertFirst(&First, 11);
    Display(First);
    iRet = Count(First);
    printf("Number of elements are : %d\n", iRet);

    InsertLast(&First, 101);
    InsertLast(&First, 111);
    InsertLast(&First,121);
    Display(First);
    iRet = Count(First);
    printf("Number of elements are : %d\n", iRet);

    InsertAtPos(&First, 81, 4);
    Display(First);
    iRet = Count(First);
    printf("Number of elements are : %d\n", iRet);

    DeleteAtPos(&First, 4);
    Display(First);
    iRet = Count(First);
    printf("Number of elements are : %d\n", iRet);

    DeleteFirst(&First);
    DeleteLast(&First);
    Display(First);
    iRet = Count(First);
    printf("Number of elements are : %d\n", iRet);


    return 0;
}