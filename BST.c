#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
    int data;
    struct Node *rchild;
    struct Node *lchild;
}NODE,*PNODE,**PPNODE;

void Insert(PPNODE Head,int no)
{
    PNODE temp = *Head;
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->rchild = NULL;
    newn->lchild = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while(1)
        {
            if(temp->data == no)
            {
                printf("Duplicate element : Unable to insert \n");
                free(newn);
                break;
            }
            else if(temp->data > no)
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
            else if(temp->data < no)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
        }
    }
}

void Preorder(PNODE Head)
{
    if(Head != NULL)
    {
        printf("%d\t",Head->data);
        Preorder(Head->lchild);
        Preorder(Head->rchild);
    }
}

void Postorder(PNODE Head)
{
    if(Head != NULL)
    {
        Preorder(Head->lchild);
        Preorder(Head->rchild);
        printf("%d\t",Head->data);
    }
}

void Inorder(PNODE Head)
{
    if(Head != NULL)
    {
        Inorder(Head->lchild);
        printf("%d\t",Head->data);
        Inorder(Head->rchild);
    }
}

bool Search(PNODE Head,int iSearch)
{
    bool flag = false;

    if(Head == NULL)
    {
        printf("Tree is empty : \n");
        return flag;
    }

    while(Head != NULL)
    {
        if(Head->data == iSearch)
        {
            flag = true;
            break;
        }
        else if(Head->data > iSearch)
        {
            Head = Head->lchild;
        }
        else if(Head->data < iSearch)
        {
            Head = Head->rchild;
        }
    }
}

int CountNodes(PNODE Head)
{
    static int iCount = 0;

    if(Head != NULL)
    {
        iCount++;
        CountNodes(Head->lchild);
        CountNodes(Head->rchild);
    }
    return iCount;
}

int CountLeafNodes(PNODE Head)
{
    static int iCount = 0;

    if(Head != NULL)
    {
        if((Head->rchild == NULL) && (Head->lchild == NULL))
        {
            iCount++;
        }
        CountLeafNodes(Head->lchild);
        CountLeafNodes(Head->rchild);
    }
    return iCount;
}

int CountParentNodes(PNODE Head)
{
    static int iCount = 0;

    if(Head != NULL)
    {
        if((Head->lchild != NULL) || (Head->rchild != NULL))
        {
            iCount++;
        }
        CountParentNodes(Head->lchild);
        CountParentNodes(Head->rchild);
    }
    return iCount;
}

int main()
{
    PNODE first = NULL;
    bool bRet = false;

    Insert(&first,21);
    Insert(&first,23);
    Insert(&first,15);
    Insert(&first,78);
    Insert(&first,45);
    Insert(&first,10);
    Insert(&first,90);

    printf("\nElements in preorder are :\n");
    Preorder(first);

    printf("\nElements in Postorder are : \n");
    Postorder(first);

    printf("\nElements in Inorder are : \n");
    Inorder(first);

    bRet = Search(first,78);
    if(bRet == true)
    {
        printf("\nElement is there in BST\n");
    }
    else
    {
        printf("\nElement is not there in BST\n");
    }

    printf("\nCount of the Nodes are : %d\n",CountNodes(first));
    printf("\nCount of the Leaf Nodes are : %d\n",CountLeafNodes(first));
    printf("\nCount of the Parent Nodes are : %d\n",CountParentNodes(first));

    return 0;
}