// #include <stdio.h>

// int rev(int n)
// {
//     if (n == 0)
//     {
//         return 0;
//     }
//     else
//     {
//         printf("%d", n % 10);
//         return (n % 10) + rev(n / 10);
//     }
// }

// int main()
// {
//     int n;
//     printf("enter the numbre : ");
//     scanf("%d", &n);
//     printf("\n%d", rev(n));
// }

#include <stdio.h>

void matrixinput(int a[10][10], int r, int c);
void displaymatrix(int mat[10][10], int r, int c);

int main()
{
    int mat1[10][10], mat2[10][10], mat3[10][10];
    int r, c, r2, c2;
    printf("Enter the rows and colomns of the matrix 1 : \n");
    scanf("%d%d", &r, &c);
    printf("Enter the rows and colomns of the matrix 2 : \n");
    scanf("%d%d", &r2, &c2);

    if (c != r2)
    {
        printf("Invalid size\n");
    }
    else
    {
        matrixinput(mat1, r, c);
        displaymatrix(mat1, r, c);
        matrixinput(mat2, r2, c2);
        // displaymatrix(mat2, r2, c2);
    }
}

void matrixinput(int a[10][10], int r, int c)
{
    int i, j;
    printf("Entre the elements of matrix\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", (*(a + r) + c));
        }
    }
}

void displaymatrix(int mat[10][10], int r, int c)
{
    int i, j;
    printf("The matrix\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d\t", *((*mat + r) + c));
        }
        printf("\n");
    }
}