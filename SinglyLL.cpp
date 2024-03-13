#include<iostream>
using namespace std;

typedef struct Node 
{   
    int data;
    struct Node *next;
}NODE,*PNODE;

class SinglyLL
{
    private:
        PNODE first;
        int iCount;

    public:
        SinglyLL();
        ~SinglyLL();

        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

SinglyLL::SinglyLL()
{
    first = NULL;
    iCount = 0;
}

SinglyLL::~SinglyLL()
{
    PNODE temp = NULL;
    while(first != NULL)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
}

void SinglyLL::InsertFirst(int no)
{
    PNODE newn = NULL;
    newn = new NODE;

    newn->next = NULL;
    newn->data = no;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    iCount++;
}

void SinglyLL::InsertLast(int no)
{
    PNODE temp = first;
    PNODE newn = NULL;
    newn = new NODE;

    newn->next = NULL;
    newn->data = no;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

void SinglyLL::Display()
{
    cout<<"Elements of the linklist are \n";
    
    PNODE temp = first;

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"\n";
}

int SinglyLL::Count()
{
    return iCount;
}

void SinglyLL::DeleteFirst()
{

    if(first == NULL)
    {
        cout<<"linklist is empty \n";
        return;
    }

    if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else 
    {
        PNODE temp = first;
        first = first->next;
        delete temp;
    }
    iCount--;
}

void SinglyLL::DeleteLast()
{
    if(first == NULL)
    {
        cout<<"linklist is empty \n";
        return;
    }

    if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else 
    {
        PNODE temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

void SinglyLL::InsertAtPos(int no,int iPos)
{
    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Ivalid position \n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        PNODE newn = NULL;
        PNODE temp = first;
        newn = new NODE;

        newn->next = NULL;
        newn->data = no;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

void SinglyLL::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Ivalid position \n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = first;
        PNODE tempx = NULL;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        tempx = temp->next;
        temp->next = temp->next->next;
        delete tempx;

        iCount--;
    }
}

int main()
{
    int iRet = 0;

    SinglyLL obj1;

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
    obj1.InsertLast(101);
    obj1.InsertLast(111);

    obj1.InsertAtPos(55,4);
    obj1.Display();

    obj1.DeleteAtPos(4);

    obj1.Display();
    iRet = obj1.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

   obj1.DeleteFirst();
   obj1.DeleteLast();

    obj1.Display();
    iRet = obj1.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";


    return 0;
}