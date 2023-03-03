#include <stdio.h>
int main()
{
    int a[100], n, i, j, temp, search, low, high, mid, flag = 0;

    printf("limit");
    scanf("%d", &n);

    printf("enter elements");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("search");
    scanf("%d", &search);

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = ((low + high) / 2);

        if (a[mid] == search)
        {
            printf("found at %d", mid + 1);
            break;
        }
        else if (a[mid] > search)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
}