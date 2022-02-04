#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//Structure Declaration
struct node
{
    int data;
    int *lchild;
    int *rchild;
};
typedef struct node *NODE;
NODE root = 0;

//Function Declarations 
void create(NODE *);
void inorder(NODE);
void preorder(NODE);
void postorder(NODE);
int is_lchild(NODE *);
int is_rchild(NODE *);

//Create Function
void create(NODE *root1)
{
    NODE temp, temp1;
    if (is_lchild (&(*root1)))
    {
        (*root1)->lchild = (NODE)malloc(sizeof(struct node));
        temp = (*root1)->lchild;
        printf("Enter the data for the leftt child: ");
        scanf("%d", &temp->data);
        create(&temp);
    }
    else
        (*root1)->lchild=0;
    
    if (is_rchild(&(*root1)))
    {
        (*root1)->rchild = (NODE)malloc(sizeof(struct node));
        temp1 = (*root1)->rchild;
        printf("Enter the data for the right child: ");
        scanf("%d", &temp1->data);
        create(&temp1);
    }
    else
        (*root1)->rchild = 0;

    return;
}

//Left Child Operational Function
int is_lchild(NODE *root2)
{
    int ch;
    printf("Do You Want To Create Left Child of %d 1-Yes / 0-No: ", (*root2)->data);
    scanf("%d", &ch);
    if (ch == 1)
        return (1);
    else
        return (0);
    
}

//Right Child Operational Function
int is_rchild(NODE *root2)
{
    int ch1;
    printf("Do You Want To Create Right Child Of %d 1-Yes / 0-No: ", (*root2)->data);
    scanf("%d", &ch1);
    if (ch1==1)
        return (1);
    else
        return (0);
}

//Pre-Order Function
void preorder(NODE root4)
{
    if (root4 != 0)
    {
        printf("%d->", root4->data);               /*Pre-Order = Placing root before left and right child*/
        preorder(root4->lchild);
        preorder(root4->rchild);
    }
}

//In-Order Function
void inorder(NODE root5)
{
    if (root5 != 0)
    {
        inorder(root5->lchild);
        printf("%d->", root5->data);           /*In-Order = Placing root in between left and right child*/
        inorder(root5->rchild);
    }
}

//Post-Order Function
void postorder(NODE root6)
{
    if (root6 != 0 )
    {
        postorder(root6->lchild);
        postorder(root6->rchild);          /*Post-Order = Placing root after left and right child*/
        printf("%d->", root6->data);
    }
    
}

//Main Function
void main()
{
    //clrscr();
    printf("Creation Of Tree\n");
    root = (NODE)malloc(sizeof(struct node));
    printf("Enter the data for the root node :  ");
    scanf("%d", &root->data);
    create(&root);
    printf("Tree Traversal\n");
    printf("\nPre-Order Traversal:\n");
    preorder(root);
    printf("\nInorder Traversal:\n");
    inorder(root);
    printf("\nPost-Orrder Traversal:\n");
    postorder(root);
    getch();
}
