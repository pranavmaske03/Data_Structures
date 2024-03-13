#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}NODE,*PNODE,**PPNODE;

void InsertFirst(PPNODE Head,int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
}

void InsertLast(PPNODE Head,int iNo)
{
    PNODE temp = *Head;
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
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

void Display(PNODE Head)
{
    printf("Elements of the linked List are : \n");
    
    while(Head != NULL)
    {
        printf("| %d |->",Head->data);
        Head = Head->next;
    }
    printf("NULL\n");
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
        *Head = (*Head)->next;
        free(temp);
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

void InsertAtPos(PPNODE Head,int iNo,int iPos)
{
    int iLength = 0;
    int iCnt = 0;
    PNODE temp = *Head;
    PNODE newn = NULL;

    iLength = Count(*Head);

    if((iPos < 1) || (iPos > iLength+1))
    {
        printf("Invalid position \n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(Head,iNo);
    }
    else if(iPos == iLength+1)
    {
        InsertLast(Head,iNo);
    }
    else
    {
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn = (PNODE)malloc(sizeof(NODE));
        newn->next = NULL;
        newn->data = iNo;

        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteAtpos(PPNODE Head,int iPos)
{
    int iLength = 0;
    int iCnt = 0;
    PNODE temp = *Head;
    PNODE tempX = NULL;

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
    else if(iPos == iLength)
    {
        DeleteLast(Head);
    }
    else
    {
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        tempX = temp->next;
        temp->next = temp->next->next;
        free(tempX);
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
    InsertLast(&First, 121);
    Display(First);
    iRet = Count(First);
    printf("Number of elements are : %d\n", iRet);

    InsertAtPos(&First, 41, 3);
    Display(First);
    iRet = Count(First);
    printf("Number of elements are : %d\n", iRet);

    DeleteAtpos(&First, 3);
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