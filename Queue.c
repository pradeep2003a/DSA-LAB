#include<stdio.h>
#include<conio.h>
#define SIZE 5
#include<stdlib.h>

int rear=-1, front=-1, queue[10];

int qinsert()
{
    int num;
    if (rear == (SIZE-1))
    {
        printf("Queue is full.\n");
        return 0;
    }
    printf("Enter the element to insert\n");
    scanf("%d", &num);
    queue[++rear] = num;
    if (front == -1)
    {
        front++;
        return 0;
    }
}
int qdelete()
{
    if (front ==-1)
    {
        printf("Queue is empty.\n");
        return 0;
    }
    if (front == rear)
    {
        printf("Deleted Element = %d\n", queue[front]);
        front = -1; rear=-1;
        return 0;
    }
    printf("Deleted Element = %d\n", queue[front]);
    front++;
    return 0;
}
int qdisplay()
{
    int i;
    if (front ==-1)
    {
        printf("Queue is empty.\n");
        return 0;
    }
    else
    {
        printf("Status Of Queue is\n");
        for ( i = front; i <= rear; i++)
        {
            printf("%d\t", queue[i]);
        }
        printf("\n");
        return 0;
    }
}

void main()
{
    int ch=1, option;
    while (ch ==1)
    {
        printf("Queue operations\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter Your choice: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            qinsert();
            break;
        case 2:
            qdelete();
            break;
        case 3:
            qdisplay();
            break;
        case 4:
            exit(0);
        default:
            printf("Oops! Wrong Choice Buddy...!!!Try Again.");
        }
        printf("Do You Want To Continue 1-Yes, 0-No\n");
        scanf("%d", &ch);
    }
    getch();
}
