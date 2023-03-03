#include <stdio.h>
int main()
{
    int a[100], n, i, search, flag = 0;

    printf("enter the limit of the array : ");
    scanf("%d", &n);

    printf("\n enter the array elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("enter the number you wanna search :");
    scanf("%d", &search);

    for (i = 0; i < n; i++)
    {
        if (a[i] == search)
        {
            printf("the number %d is found at index %d", search, i + 1);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("element not found");
    }
}