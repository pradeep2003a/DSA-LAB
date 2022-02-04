#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node *NODE;
NODE insert_front(NODE);
NODE insert_rear(NODE);
NODE delete_front(NODE);
NODE delete_rear(NODE);
void display(NODE);
void main()
{
    int ch = 1, choice, choice1, p = 1, q = 1;
    NODE first = 0;
    while (ch == 1)
    {
        printf("Double Ended Queue Operation\n");
        printf("1.Input Restricted Queue\n2.Output Restricted Dequeue\n3.Display\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            p = 1;
            while (p == 1)
            {
                printf("Input restricted Dequeue\n");
                printf("1.Insert From Rear\n2.Delete From Rear\n3.Delete From Front\n");
                printf("Enter Your Choice: ");
                scanf("%d", &choice1);
                switch (choice1)
                {
                case 1:
                    first = insert_rear(first);
                    break;
                case 2:
                    first = delete_rear(first);
                    break;
                case 3:
                    first = delete_front(first);
                    break;
                default:
                    printf("Invalid Choice!!\n");
                    break;
                }
                printf("Press 1 To Continue\n");
                scanf("%d", &p);
            }
            break;
        case 2:
            q = 1;
            while (q == 1)
            {
                printf("Output Restricted Queue\n");
                printf("1.Insert From Rear\n2.Insert From Front\n3.Delete From Front\n");
                printf("Enter Your Choice: ");
                scanf("%d", &choice1);
                switch (choice1)
                {
                case 1:
                    first = insert_rear(first);
                    break;
                case 2:
                    first = insert_front(first);
                    break;
                case 3:
                    first = delete_front(first);
                    break;
                default:
                    printf("Invalid Choice!!!\n");
                    break;
                }
                printf("Press 1 To Continue\n");
                scanf("%d", &q);
            }
            break;
        case 3:
            display(first);
            break;
        default:
            printf("Invalid Choice!!!");
            break;
        }
        printf("\nDo You Want To Continue 1-Yes or 0-No\n");
        scanf("%d", &ch);
    }
    
}

NODE insert_front(NODE first)
{
    NODE newnode;
    newnode = (NODE)malloc(sizeof(struct node));
    newnode->link = 0;
    printf("Enter The Data To Be Stored\n");
    scanf("%d", &newnode->data);
    if (first == 0)
    {
        first = newnode;
        return (first);
    }
    else
    {
        newnode->link = first;
        first = newnode;
        return (first);
    }
}
NODE delete_front(NODE first)
{
    NODE temp;
    if (first == 0)
    {
        printf("No Nodes Present In The List\n");
        return (first);
    }
    else
    {
        printf("Node To Be Deleted = %d\n", first->data);
        temp = first;
        if (first->link == 0)
        {
            free(first);
            first = 0;
            return (first);
        }
        else
        {
            first = first->link;
            free(temp);
            return (first);
        }
    }
}
NODE insert_rear(NODE first)
{
    NODE newnode, temp;
    newnode = (NODE)malloc(sizeof(struct node));
    newnode->link = 0;
    printf("Enter the data to be stored\n");
    scanf("%d", &newnode->data);
    if (first == 0)
    {
        first = newnode;
        return (first);
    }
    else
    {
        temp = first;
        while (temp->link != 0)
            temp = temp->link;
        temp->link = newnode;
        return (first);
    }
}
NODE delete_rear(NODE first)
{
    NODE temp, temp1;
    if (first == 0)
    {
        printf("No Nodes Present In The List\n");
        return (first);
    }
    else
    {
        temp = first;
        if (temp->link == 0)
        {
            printf("Node To Be Deleted = %d\n", temp->data);
            free(temp);
            first=0;
            return (first);
        }
        while (temp->link != 0)
        {
            temp1 = temp;
            temp = temp->link;
        }
        printf("Node To Deleted = %d\n", temp->data);
        free(temp);
        temp1->link=0;
        return (first);
    }
}
void display(NODE first)
{
    NODE temp;
    if (first == 0)
    {
        printf("No Nodes Are Present In List\n");
    }
    else
    {
        printf("The Contents Of The List Are\n");
        for ( temp = first; temp != 0; temp=temp->link)
        {
            printf("%d\t", temp->data);
        }
        printf("\n");
    }
}
