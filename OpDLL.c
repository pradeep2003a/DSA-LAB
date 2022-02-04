#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;
NODE first = 0;
int i, choice, ch1 = 1, choice1, ch2 = 1, choice2, ch3 = 1;
NODE insert_front(NODE);
NODE insert_rear(NODE);
NODE insert_pos(NODE);
NODE delete_front(NODE);
NODE delete_end(NODE);
NODE delete_pos(NODE);
void display(NODE);

//Inserting at Front
NODE insert_front(NODE first)
{
    NODE newnode;
    newnode = (NODE)malloc(sizeof(struct node));
    newnode->llink = newnode->rlink = 0;
    printf("Enter the data to be stored: ");
    scanf("%d", &newnode->data);
    if (first == 0)
    {
        first = newnode;
        return (first);
    }
    newnode->rlink = first;
    first->llink = newnode;
    return (first);
}

//Inserting at Rear
NODE insert_rear(NODE first)
{
    NODE newnode, temp;
    newnode = (NODE)malloc(sizeof(struct node));
    newnode->rlink = newnode->llink = 0;
    printf("Enter The data to be stored: ");
    scanf("%d", &newnode->data);
    if (first == 0)
    {
        first = newnode;
        return (first);
    }
    temp = first;
    while (temp->rlink != 0)
        temp = temp->rlink;
    temp->rlink = newnode;
    newnode->llink = temp;
    return (first);
}

//Inserting at specified Position
NODE insert_pos(NODE first)
{
    NODE newnode, temp, temp1;
    int pos;
    newnode = (NODE)malloc(sizeof(struct node));
    newnode->llink = newnode->rlink = 0;
    printf("Enter the data to be stored: ");
    scanf("%d", &newnode->data);
    printf("Enter the position where node to be inserted: ");
    scanf("%d", &pos);
    temp = first;
    if ((pos == 1) && (first == 0))
    {
        first = newnode;
        return (first);
    }
    if (pos == 1)
    {
        newnode->rlink = first;
        first->llink = newnode;
        first = newnode;
        return (first);
    }
    for (i = 1; i < pos; i++)
    {
        temp1 = temp;
        temp = temp->rlink;
    }
    if (temp == 0)
    {
        printf("Invalid position!!");
        return (first);
    }
    temp1->rlink = newnode;
    newnode->llink = temp1;
    newnode->rlink = temp;
    temp->llink = newnode;
    return (first);
}

//Delete at front
NODE delete_front(NODE first)
{
    NODE temp;
    if (first == 0)
    {
        printf("NO nodes in the list.\n");
        return (first);
    }
    temp = first;
    if (temp->rlink == 0)
    {
        printf("Deleted data = %d.", temp->data);
        free(temp);
        return (first);
    }
    printf("Deleted data = %d.", temp->data);
    first = first->rlink;
    first->llink = 0;
    free(temp);
    return (first);
}

//Delete At Rear
NODE delete_end(NODE first)
{
    NODE temp, temp1;
    if (first == 0)
    {
        printf("No Nodes In The List!!\n");
        return (first);
    }
    temp = first;
    if (first->rlink == 0)
    {
        printf("Deleted Data = %d.", temp->data);
        free(temp);
        first = 0;
        return (first);
    }
    while (temp->rlink != 0)
        temp = temp->rlink;
    printf("Deleted data = %d.", temp->data);
    temp1 = temp->llink;
    free(temp);
    temp1->rlink = 0;
    return (first);
}

//Delete At Specified Position
NODE delete_pos(NODE first)
{
    NODE temp, temp1, temp2;
    int pos;
    if (first == 0)
    {
        printf("No nodes in the list\n");
        return (first);
    }
    printf("Enter the position where node to deleted\n");
    scanf("%d", &pos);
    temp = first;
    if ((pos == 1) && (first->rlink == 0))
    {
        printf("Deleted data = %d\n", temp->data);
        free(temp);
        first = 0;
        return (first);
    }
    if (pos == 1)
    {
        printf("Deleted data = %d\n", temp->data);
        first = first->rlink;
        first->llink = 0;
        free(temp);
        return (first);
    }
    for (i = 1; i < pos; i++)
        temp = temp->rlink;
    if (temp == 0)
    {
        printf("Invalid position\n");
        return (first);
    }
    temp1 = temp->llink;
    temp2 = temp->rlink;
    printf("Deleted data = %d\n", temp->data);
    temp1->rlink = temp2;
    temp2->llink = temp1;
    free(temp);
    return (first);
}

//Display Function
void display(NODE first)
{
    NODE temp;
    temp = first;
    if (first == 0)
    {
        printf("No Nodes In The List.\n");
        return (first);
    }
    else
    {
        printf("The Contents Of The List Are:\n");
        for (temp = first; temp != 0; temp = temp->rlink)
        {
            printf("%d\t", temp->data);
        }
        printf("\n");
    }
}

//Main Funtion
int main()
{
    int ch1 = 1;
    clrscr();                 /*Only For Turbo C Compiler*/
    while (ch1 == 1)
    {
        printf("Doubly Linked List Implementation:\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Insert Implementation\n");
            ch2 = 1;
            while (ch2 == 1)
            {
                printf("Select Operation\n");
                printf("1.Insert at front\n2.Insert at rear\n3.Insert at specified position\n");
                printf("Enter Your Choice: ");
                scanf("%d", &choice1);
                switch (choice1)
                {
                case 1:
                    first = insert_front(first);
                    break;
                case 2:
                    first = insert_rear(first);
                    break;
                case 3:
                    first = insert_pos(first);
                    break;
                default:
                    printf("Wrong Choice!!");
                    break;
                }
                printf("Enter 1 to Insert Again and 0 to Exit: ");
                scanf("%d", &ch2);
            }
            break;
        case 2:
            printf("Delete Implementation\n");
            ch3 = 1;
            while (ch3 == 1)
            {
                printf("Select Operation\n");
                printf("1.Delete at front\n2.Delete at rear\n3.Delete at specified position\n");
                printf("Enter your Choice: ");
                scanf("%d", &choice2);
                switch (choice2)
                {
                case 1:
                    first = delete_front(first);
                    break;
                case 2:
                    first = delete_end(first);
                    break;
                case 3:
                    first = delete_pos(first);
                    break;
                default:
                    printf("Wrong Choice!!\n");
                    break;
                }
                printf("Enter 1 to Delete Again and 0 to Exit: ");
                scanf("%d", &ch3);
            }
            break;
        case 3:
            display(first);
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong Choice. Try Again!!\n");
            break;
        }
        printf("Do You Want To Continue 1-Yes, 0-No: ");
        scanf("%d", &ch1);
    }
    return 0;
}
