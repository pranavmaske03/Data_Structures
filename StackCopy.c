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

void StackCopy(PPNODE stack1,PPNODE stack2)
{
    int No = 0;

    if(*stack1 != NULL)
    {
        No = Pop(stack1);
        StackCopy(stack1,stack2);
        Push(stack2,No);
        Push(stack1,No);
    }
}

int main()
{
    PNODE first1 = NULL;
    PNODE first2 = NULL;
    
    Push(&first1,11);
    Push(&first1,22);
    Push(&first1,33);
    Push(&first1,44);
    Push(&first1,55);

    Display(first1);
    Display(first2);

    StackCopy(&first1,&first2);
    Display(first2);
    Display(first1);
    
    return 0;
}