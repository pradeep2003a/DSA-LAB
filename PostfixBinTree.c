#include <stdio.h>
#include <conio.h>
#include <math.h>
#include<stdlib.h>

//Structure declaration
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

//typedef
typedef struct node *NODE;
NODE root = 0;
NODE create_tree(char postfix[]);
float eval(NODE root);

//Main Function
void main()
{
    char postfix[20];
    float result;
    //clrscr();
    printf("Enter the postfix expression\n");
    scanf("%s", postfix);
    root = create_tree(postfix);
    result = eval(root);
    printf("Result = %f\n", result);
    getch();
}

//Create tree function
NODE create_tree(char postfix[])
{
    NODE temp, stack[20];
    int i = 0, j = 0;
    char symbol;
    for (i = 0; (symbol = postfix[i]) != '\0'; i++)
    {
        temp = (NODE)malloc(sizeof(struct node));
        temp->lchild = 0;
        temp->rchild = 0;
        temp->data = symbol;
        if (isalnum(symbol))
            stack[j++] = temp;
        else
        {
            temp->rchild = stack[--j];
            temp->lchild = stack[--j];
            stack[j++] = temp;
        }
    }
    return (stack[--j]);
}

//Evaluator function
float eval(NODE root)
{
    float num;
    switch (root->data)
    {
    case '+':
        return eval(root->lchild) + eval(root->rchild);
    case '-':
        return eval(root->lchild) - eval(root->rchild);
    case '/':
        return eval(root->lchild) / eval(root->rchild);
    case '*':
        return eval(root->lchild) * eval(root->rchild);
    case '^':
        return pow(eval(root->lchild), eval(root->rchild));
    default:
        if (isalpha(root->data))
        {
            printf("Enter the value of %c\n", root->data);
            scanf("%f", &num);
            return (num);
        }
        else
            return (root->data - '\0');
    }
}