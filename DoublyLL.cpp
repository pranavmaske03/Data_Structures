#include<iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}NODE, *PNODE;

class DoublyLL
{
    public:
        int iCount;
        PNODE first;

        DoublyLL();
        ~DoublyLL();

        void InsertFirst(int); 
        void InsertLast(int);      
        void Display();
        int Count();
        void InsertAtPos(int,int);
        void DeleteFirst();       
        void DeleteLast();
        void DeleteAtPos(int);
};


DoublyLL::DoublyLL()
{
    this->iCount = 0;
    this->first = NULL;
}

DoublyLL::~DoublyLL()
{
    PNODE temp = first;
    cout<<"Inside Destructor \n";

    while(first != NULL)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
}

void DoublyLL::InsertFirst(int no)
{
    PNODE newn = new NODE;
    newn->next = NULL;
    newn->prev = NULL;
    newn->data = no;

    if((first == NULL))
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    iCount++;
}

void DoublyLL::InsertLast(int no)
{
    PNODE newn = new NODE;
    newn->next = NULL;
    newn->prev = NULL;
    newn->data = no;

    if((first == NULL))
    {
        first = newn;
    }
    else
    {
        PNODE temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

void DoublyLL::Display()
{
    if(first != NULL)
    {   
        PNODE temp = first;

        while(temp != NULL)
        {
            cout<<"|"<<temp->data<<"|->";
            temp = temp->next;
        }
    }
    cout<<"\n";
}

int DoublyLL::Count()
{
    return iCount;
}

void DoublyLL::DeleteFirst()
{
    if(first == NULL)
    {
        cout<<"Linklist is empty \n";
        return;
    }

    if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;
        first->prev = NULL;
    }
    iCount--;
}

void DoublyLL::DeleteLast()
{
    if(first == NULL)
    {
        cout<<"Linklist is empty \n";
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

void DoublyLL::InsertAtPos(int iPos,int no)
{
    int count = Count();

    if((iPos < 1) || (iPos > count+1))
    {
        cout<<"Invalid position \n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == count+1)
    {
        InsertLast(no);
    }
    else
    {
        PNODE temp = first;
        PNODE newn = new NODE;
        newn->next = NULL;
        newn->prev = NULL;
        newn->data = no;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        iCount++;
    }
}
void DoublyLL::DeleteAtPos(int iPos)
{
    int count = Count();

    if((iPos < 1) || (iPos > count))
    {
        cout<<"Invalid position \n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == count)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = first;
       
        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        iCount--;
    }
}

int main()
{
    DoublyLL obj;

    obj.InsertFirst(31);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();
    cout<<"Count of the elements is : "<<obj.Count()<<"\n";

    obj.InsertLast(111);
    obj.InsertLast(121);
    obj.InsertLast(131);
    obj.Display();
    cout<<"Count of the elements is : "<<obj.Count()<<"\n";

    obj.InsertAtPos(4,51);
    obj.Display();

    obj.DeleteAtPos(4);
    obj.Display();
    cout<<"Count of the elements is : "<<obj.Count()<<"\n";

    obj.DeleteFirst();
    obj.DeleteLast();
    obj.Display();
    cout<<"Count of the elements is : "<<obj.Count()<<"\n";

    return 0;
}