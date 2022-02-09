#include <stdio.h>
#include <conio.h>
void main()
{
    int n, a[20], a1[20], a2[20], i, result;
    // clrscr();
    printf("Enter the size of hash table : ");
    scanf("%d", &n);
    printf("Enter the elements : \n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
    {
        result = a[i] % 10;
        a1[result] = a[i];
        a2[i] = a1[result];
        printf("Location = a[%d], Value = %d\n", result, a1[result]);
        result = 0;
    }
    printf("Hash table is : \n");
    for (i = 0; i < n; i++)
        printf("%d\t", a2[i]);
    getch();
}