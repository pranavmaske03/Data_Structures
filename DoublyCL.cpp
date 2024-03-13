#include<iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}NODE,*PNODE;

class linklist
{
    public:
        PNODE first;
        PNODE last;
        int iCount;

        virtual void InsertFirst(int) = 0;
        virtual void InsertLast(int) = 0;
        virtual void InsertAtPos(int,int) = 0;

        virtual void DeleteFirst() = 0;
        virtual void DeleteLast() = 0;
        virtual void DeleteAtPos(int) = 0;

        void Display()
        {
            if(first != NULL)
            {
                cout<<"Elements of the linklist are \n";
                PNODE temp = first;

                do 
                {
                    cout<<"|"<<temp->data<<"|->";
                    temp = temp->next;
                }while(temp != last->next);
            }
            else 
            {
                cout<<"Linklist is empty \n";
            }
            cout<<"\n";
        }

        int Count()
        {
            return iCount;
        }
};

class DoublyCL : public linklist
{   
    public:

        DoublyCL();
        ~DoublyCL();
        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};

DoublyCL::DoublyCL()
{
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

DoublyCL::~DoublyCL()
{
    cout<<"INside Destructor \n";

    PNODE temp = first;

    while(first->next != last)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
    delete last;
}

void DoublyCL::InsertFirst(int no)
{
    PNODE newn = new NODE;
    newn->next = NULL;
    newn->prev = NULL;
    newn->data = no;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    first->prev = last;
    last->next = first;
    iCount++;
}

void DoublyCL::InsertLast(int no)
{

    PNODE newn = new NODE;
    newn->next = NULL;
    newn->prev = NULL;
    newn->data = no;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->prev = last;
        last->next = newn;
        last = newn;
    }
    first->prev = last;
    last->next = first;
    iCount++;
}

void DoublyCL::DeleteFirst()
{
    if((first == NULL) && (last == NULL))
    {
        cout<<"Linklist is empty \n";
        return;
    }

    if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        last->next = NULL;
    }
    first->prev = last;
    last->next = first;
    iCount--;
}

void DoublyCL::DeleteLast()
{
    if((first == NULL) && (last == NULL))
    {
        cout<<"Linklist is empty \n";
        return;
    }

    if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;
        delete last->next;
        last->next = NULL;
    }
    first->prev = last;
    last->next = first;
    iCount--;
}

void DoublyCL::InsertAtPos(int iPos,int no)
{
    int count = Count();

    if((iPos < 1) || (iPos > count+1))
    {
        cout<<"Invalid Position \n";
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

void DoublyCL::DeleteAtPos(int iPos)
{
    int count = Count();

    if((iPos < 1) || (iPos > count+1))
    {
        cout<<"Invalid Position \n";
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
    DoublyCL obj;

    obj.InsertFirst(31);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();
    cout<<"Count of the elements is : "<<obj.Count()<<"\n";

    obj.InsertLast(111);
    obj.InsertLast(111);
    obj.InsertLast(111);
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