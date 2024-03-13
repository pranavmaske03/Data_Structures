#include<iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *rchild;
    struct Node *lchild;
}NODE,*PNODE;

class BST
{
    public:
        static PNODE first;

        void Insert(int);
        bool Search(int);

        void Preorder(PNODE head = first);
        void Postorder(PNODE head = first);
        void Inorder(PNODE head = first);

        int CountNodes(PNODE head = first);
        int CountLeafNodes(PNODE head = first);
        int CountParentNodes(PNODE head = first);
};

PNODE BST::first = NULL;

void BST::Insert(int no)
{
    PNODE temp = first;
    PNODE newn = new NODE;
    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        while(1)
        {
            if(temp->data == no)
            {
                cout<<"\nDuplicate element : Unable to insert \n";
                delete newn;
                break;
            }
            else if(no > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else if(no < temp->data)
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
        }
    }
}

void BST::Preorder(PNODE head)
{
    if(head != NULL)
    {
        cout<<head->data<<"\t";
        Preorder(head->lchild);
        Preorder(head->rchild);
    }
}

void BST::Postorder(PNODE head)
{
    if(head != NULL)
    {
        Postorder(head->lchild);
        Postorder(head->rchild);
        cout<<head->data<<"\t";
    }
}

void BST::Inorder(PNODE head)
{
    if(head != NULL)
    {
        Inorder(head->lchild);
        cout<<head->data<<"\t";
        Inorder(head->rchild);
    }
}

bool BST::Search(int search)
{
    PNODE temp = first;
    bool flag = false;

    if(first == NULL)
    {
        cout<<"Tree is empty \n";
        return flag;
    }
    
    while(temp != NULL)
    {
        if(temp->data == search)
        {
            flag = true;
            break;
        }
        else if(search > temp->data)
        {
            temp = temp->rchild;
        }
        else if(search < temp->data)
        {
            temp = temp->lchild;
        }
    }
    return flag;
}

int BST::CountNodes(PNODE head)
{
    static int iCnt = 0;

    if(head != NULL)
    {
        iCnt++;
        CountNodes(head->lchild);
        CountNodes(head->rchild);
    }
    return iCnt;
}

int BST::CountLeafNodes(PNODE head)
{
    static int iCnt = 0;

    if(head != NULL)
    {
        if((head->lchild == NULL) && (head->rchild == NULL))
        {
            iCnt++;
        }
        CountLeafNodes(head->lchild);
        CountLeafNodes(head->rchild);
    }
    return iCnt;
}

int BST::CountParentNodes(PNODE head)
{
    static int iCnt = 0;

    if(head != NULL)
    {
        if((head->lchild != NULL) || (head->rchild != NULL))
        {
            iCnt++;
        }
        CountParentNodes(head->lchild);
        CountParentNodes(head->rchild);
    }
    return iCnt;
}

int main()
{
    BST *obj = new BST();
    bool bRet = false;

    obj->Insert(21);
    obj->Insert(23);
    obj->Insert(15);
    obj->Insert(78);
    obj->Insert(45);
    obj->Insert(10);
    obj->Insert(90);

    cout<<"\nElements of the Preorder are : \n";
    obj->Preorder();
    cout<<"\nElements of the Postorder are : \n";
    obj->Postorder();
    cout<<"\nElements of the Inorder are : \n";
    obj->Inorder();

    bRet = obj->Search(780);
    if(bRet == true)
    {
        printf("\nElement is there in BST\n");
    }
    else
    {
        printf("\nElement is not there in BST\n");
    }

    cout<<"\nCount of the Nodes are : "<<obj->CountNodes()<<"\n";
    cout<<"\nCount of the LeafNodes are : "<<obj->CountLeafNodes()<<"\n";
    cout<<"\nCount of the ParentNodes are : "<<obj->CountParentNodes()<<"\n";

    return 0;
}