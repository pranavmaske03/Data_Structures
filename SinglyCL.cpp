#include<iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
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

class SinglyCL : public linklist
{
    public:
        SinglyCL();
        ~SinglyCL();

        void InsertFirst(int); 
        void InsertLast(int);      
        void InsertAtPos(int,int);
        void DeleteFirst();       
        void DeleteLast();
        void DeleteAtPos(int);
        
};

SinglyCL::SinglyCL()
{
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

SinglyCL::~SinglyCL()
{
    cout<<"Inside Destructor \n";
    PNODE temp = first;

    while(first->next != last)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
    delete last;
}

void SinglyCL::InsertFirst(int no)
{
    PNODE newn = new NODE;
    newn->next = NULL;
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
    last->next = first;
    iCount++;
}

void SinglyCL::InsertLast(int no)
{
    PNODE newn = new NODE;
    newn->next = NULL;
    newn->data = no;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        last = newn;
    }
    last->next = first;
    iCount++;
}

void SinglyCL::DeleteFirst()
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
        last->next = first;
    }
    iCount--;
}

void SinglyCL::DeleteLast()
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
        PNODE temp = first;

        while(temp->next != last)
        {
            temp = temp->next;
        }
        delete temp->next;
        last = temp;
        last->next = first;
    }
    iCount--;
}

void SinglyCL::InsertAtPos(int iPos,int no)
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
void SinglyCL::DeleteAtPos(int iPos)
{
    int count = Count();

    if((iPos < 1) || (iPos > count))
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
    SinglyCL obj;

    obj.InsertFirst(31);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();

    obj.InsertLast(111);
    obj.InsertLast(121);
    obj.InsertLast(131);
    obj.Display();

    obj.DeleteFirst();
    obj.DeleteLast();
    obj.Display();

    obj.InsertAtPos(4,51);
    obj.Display();

    obj.DeleteAtPos(4);
    obj.Display();

    return 0;
}