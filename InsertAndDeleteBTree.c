#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#define TRUE 1
#define FALSE 0

//Structure Declaration
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

//typedef 
typedef struct node *NODE;
void insert(NODE *, int);
void node_delete(NODE *);
void search(NODE *, int, NODE *, NODE *, int *);
void inorder(NODE);

//Main function
void main()
{
    NODE root = 0;
    int i = 1, num, req;
    // clrscr();
    printf("Enter the num of nodes:  ");
    scanf("%d", &req);
    while (i++ <= req)
    {
        printf("Enter the data\n");
        scanf("%d", &num);
        insert(&root, num);
    }
    printf("Nodes before deletion\n");
    inorder(root);
    printf("Nodes after deletion\n");
    node_delete(&root);
    inorder(root);
    getch();
}

//Nodes Insert Function
void insert(NODE *(root1), int num)
{
    if ((*root1) == 0)
    {
        (*root1) = (NODE)malloc(sizeof(struct node));
        (*root1)->lchild = (*root1)->rchild = 0;
        (*root1)->data = num;
    }
    else
    {
        if (num < ((*root1)->data))
            insert(&((*root1)->lchild), num);
        else
            insert(&((*root1)->rchild), num);
    }
    return;
}

//In-Order Funtion
void inorder(NODE root4)
{
    if (root4 != 0)
    {
        inorder(root4->lchild);
        printf("%d=>", root4->data);
        inorder(root4->rchild);
    }
}

//Search Function
void search(NODE *root3, int num2, NODE *par, NODE *x, int *found)
{
    NODE q;
    q = *root3;
    *found = FALSE;
    *par = 0;
    while (q != 0)
    {
        if (num2 == q->data)
        {
            *found = TRUE;
            *x = q;
            return;
        }
        *par = q;
        if (num2 < q->data)
            q = q->lchild;
        else
            q = q->rchild;
    }
    return;
}

//Delete Function
void node_delete(NODE *root2)
{
    int num1, found;
    NODE parent, x, xsucc;
    parent = 0;
    x = 0;
    if (*root2 == 0)
    {
        printf("\nTree is empty\n");
        return;
    }
    printf("\nEnter data to be deleted: ");
    scanf("%d", &num1);
    search(&(*root2), num1, &parent, &x, &found);
    if (found == FALSE)
    {
        printf("Data to be deleted is not found \n", num1);
        return;
    }
    printf("Data to be deleted is found \n", num1);
    if (x->lchild != 0 && x->rchild != 0)
    {
        parent = x;
        xsucc = x->lchild;
        while (xsucc->lchild != 0)
        {
            parent = xsucc;
            xsucc = xsucc->lchild;
        }
        x->data = xsucc->data;
        x = xsucc;
    }
    if (x->lchild != 0 && x->rchild == 0)
    {
        if (parent->lchild == x)
            parent->lchild = x->lchild;
        else
            parent->rchild = x->lchild;
        free(x);
        return;
    }
    if (x->rchild != 0 && x->lchild == 0)
    {
        if (parent->lchild == x)
            parent->lchild = x->rchild;
        else
            parent->rchild = x->rchild;
        free(x);
        return;
    }
    if (x->lchild == 0 && x->rchild == 0)
    {
        if (parent->rchild == x)
            parent->rchild = 0;
        else
            parent->lchild = 0;
        free(x);
        return;
    }
}