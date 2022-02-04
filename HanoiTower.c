#include<stdio.h>
#include<conio.h>
void tower();
int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    tower(n, 's','d','t');
    getch();
    return 0;
}

void tower(int n, char source,char dest, char temp)
{
    if (n > 0)
    {
    tower(n, source, temp, dest);
    printf("Move disk %d from %c to %c\n", n, source, dest);
    tower(n, temp, dest, source); 
    }
}  
