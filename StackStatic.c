#include<stdio.h>
#include<stdbool.h>


#define MAXSIZE 5

int Arr[MAXSIZE];
int top = -1;

void Push(int No)
{
    if(isFull() == 1)
    {
        printf("Stack is Full \n");
        return;
    }

    top++;
    Arr[top] = No;
}


int Pop()
{
    int No = 0;

    if(isEmpty() == 1)
    {
        printf("Stack is Empty \n");
        return -1;
    }

    No = Arr[top];
    top--;

    return No;
}

int isEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if(top == MAXSIZE-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Peek()
{
    int No = 0;

    No = Arr[top];
    printf("Top most element is : %d\n",No);

}

void Display()
{
    int iCnt = 0;

    for(iCnt = top; iCnt >= 0; iCnt--)
    {
        printf("| %d |\n",Arr[iCnt]);
    }
}

int main()
{
    int iChoice = 0;
    int iValue = 0;
    int iRet = 0;

    printf("---------------------------------------------------------------------------------------\n");
    printf("Static Impletation of Stack \n");
    printf("---------------------------------------------------------------------------------------\n");

    while(1)
    {
        printf("-----------------------------------------------------------------------------------\n");
        printf("1 : To push element into stack\n");
        printf("2 : To Pop element from stack \n");
        printf("3 : Display element from stack \n");
        printf("4 : To Check top most element is the stack \n");
        printf("0 : Terminate the application \n");
        printf("-----------------------------------------------------------------------------------\n");

        printf("Enter your choice \n");
        scanf("%d",&iChoice);

        if(iChoice == 1)
        {
            printf("Enter number to push in the stack \n");
            scanf("%d",&iValue);
            Push(iValue);
        }
        else if(iChoice == 2)
        {
            iRet = Pop();
            if(iRet != -1)
            {
                printf("Poped element from stack is : %d\n",iRet);
            }
        }
        else if(iChoice == 3)
        {
            Display();
        }
        else if(iChoice == 4)
        {
            Peek();
        }
        else if(iChoice == 0)
        {
            printf("***********************************************************\n");
            printf("Thank you for using application \n");
            printf("***********************************************************\n");
            return 0;
        }
        else
        {
            printf("NOTE : Enter valid choice \n");
        }
    }


    return 0;
}

