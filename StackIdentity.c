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

void StackCompare(PPNODE stack1,PPNODE stack2)
{
    int No1 = 0,No2 = 0;

    while((*stack1 != NULL) && (*stack2 != NULL))
    {
        No1 = Pop(stack1);
        No2 = Pop(stack2);

        if(No1 != No2)
        {
            break;
        }
    }

    if((*stack1 == NULL) && (*stack2 == NULL))
    {
        printf("Both stacks are Identicle \n");
    }
    else
    {
        printf("Stacks are NOT identicle \n");
    }
}

int main()
{
    PNODE first1 = NULL;
    PNODE first2 = NULL;
    int n = 0,i = 0,k = 0;

    printf("enter how many elements of first stack \n");
    scanf("%d",&n);

    printf("Enter elements of first Stack \n");
    for(i = 0; i < n; i++)
    {
        printf("Enter data :\n");
        scanf("%d",&k);

        Push(&first1,k);
    }
    
    printf("enter how many elements of second stack \n");
    scanf("%d",&n);

    printf("Enter elements of second Stack \n");
    for(i = 0; i < n; i++)
    {
        printf("Enter data :\n");
        scanf("%d",&k);

        Push(&first2,k);
    }
    
    StackCompare(&first1,&first2);
    
    return 0;
}