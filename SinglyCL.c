#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}NODE,*PNODE,**PPNODE;

void InsertFirst(PPNODE Head,PPNODE Tail,int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->next = NULL;
    newn->data = iNo;

    if(*Head == NULL && *Tail == NULL)
    {
        *Head = newn;
        *Tail = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
    (*Tail)->next = newn;
}

void InsertLast(PPNODE Head,PPNODE Tail,int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->next = NULL;
    newn->data = iNo;

    if(*Head == NULL && *Tail == NULL)
    {
        *Head = newn;
        *Tail = newn;
    }
    else
    {
        (*Tail)->next = newn;
        *Tail = newn;
    }
    (*Tail)->next = *Head;
}

void Display(PNODE Head,PNODE Tail)
{
    printf("Elements of the linklist are : \n");

    if((Head != NULL) && (Tail != NULL))
    {
        do
        {
            printf("|%d|-> ",Head->data);
            Head = Head->next;
        }while(Head != Tail->next);
    }
    else
    {
        printf("Linklist is empty \n");
    }
    printf("\n");
}

int Count(PNODE Head,PNODE Tail)
{
    int iCount = 0;

    if((Head != NULL) && (Tail != NULL))
    {
        do
        {
            iCount++;
            Head = Head->next;
        }while(Head != Tail->next);

        return iCount;
    }
    else
    {
        return 0;
    }
}

void DeleteFirst(PPNODE Head,PPNODE Tail)
{
    if((*Head == NULL) && (*Tail == NULL))
    {
        printf("LInklist is empty \n");
        return;
    }

    if(*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        *Head = (*Head)->next;
        free((*Tail)->next);

        (*Tail)->next = *Head;
    }
}

void DeleteLast(PPNODE Head,PPNODE Tail)
{
    PNODE temp = *Head;

    if((*Head == NULL) && (*Tail == NULL))
    {
        printf("LInklist is empty \n");
        return;
    }

    if(*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        while(temp->next != *Tail)
        {
            temp = temp->next;
        }
        free(temp->next);
        *Tail = temp;
        (*Tail)->next = *Head;
    }
}

void InsertAtPos(PPNODE Head,PPNODE Tail,int iPos,int iNo)
{
    int iLength = 0;
    int iCnt = 0;
    PNODE newn = NULL;
    PNODE temp = *Head;
    
    iLength = Count(*Head,*Tail);

    if((iPos < 1) || (iPos > iLength+1))
    {
        printf("Invalid Position \n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(Head,Tail,iNo);
    }
    else if(iPos == iLength+1)
    {
        InsertLast(Head,Tail,iNo);
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

void DeleteAtPos(PPNODE Head,PPNODE Tail,int iPos)
{
    int iLength = 0;
    int iCnt = 0;
    PNODE temp = *Head,tempX = NULL;
    
    iLength = Count(*Head,*Tail);

    if((iPos < 1) || (iPos > iLength))
    {
        printf("Invalid Position \n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(Head,Tail);
    }
    else if(iPos == iLength)
    {
        DeleteLast(Head,Tail);
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
    PNODE first = NULL;
    PNODE last = NULL;

    InsertFirst(&first,&last,41);
    InsertFirst(&first,&last,21);
    InsertFirst(&first,&last,31);
    InsertFirst(&first,&last,11);

    InsertLast(&first,&last,101);
    InsertLast(&first,&last,121);
    InsertLast(&first,&last,131);

    InsertAtPos(&first,&last,5,51);    
    Display(first,last);

    DeleteAtPos(&first,&last,5);
    Display(first,last);

    DeleteFirst(&first,&last);
    DeleteLast(&first,&last);
    Display(first,last);
}