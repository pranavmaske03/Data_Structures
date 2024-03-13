#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}NODE,*PNODE,**PPNODE;

void Enqueue(PPNODE Head,int iNo)
{
    PNODE newn = NULL;
    PNODE temp = *Head;
    newn = (PNODE)malloc(sizeof(NODE));
    
    newn->next = NULL;
    newn->data = iNo;

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

int Dequeue(PPNODE Head)
{
    int iValue = 0;
    PNODE temp = *Head;

    if(*Head == NULL)
    {
        printf("Queue is empty \n");
        return -1;
    }

    if((*Head)->next == NULL)
    {
        iValue = (*Head)->data;
        free(*Head);
        *Head = NULL;
    }
    else
    {
        iValue = (*Head)->data;
        *Head = (*Head)->next;
        free(temp);
    }
    return iValue;
}

void Display(PNODE Head)
{
    if(Head != NULL)
    {
        printf("Elements of the queue are \n");

        while(Head != NULL)
        {
            printf("|%d|->",Head->data);
            Head = Head->next;
        }
        printf("\n");
    }
    else
    {
        printf("Queue is empty \n");
        return;
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
    int iRet = 0;

    iRet = Dequeue(&first);
    if(iRet != -1)
    {
        printf("Dequeue element is : \n",iRet);
    }

    Enqueue(&first,11);
    Enqueue(&first,21);
    Enqueue(&first,31);
    Enqueue(&first,41);
    Enqueue(&first,51);

    Display(first);

    iRet = Dequeue(&first);
    if(iRet != -1)
    {
        printf("Dequeue element is : %d\n",iRet);
    }

    return 0;
}