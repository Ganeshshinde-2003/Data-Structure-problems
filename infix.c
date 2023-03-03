#include <stdio.h>
#include <ctype.h>
#define MAX 15
char stack[MAX], top = -1;

void isempty()
{
    if (top == -1)
        printf("STACK UNDERFLOW");
}

void isfull()
{
    if (top == MAX)
        printf("STACK OVERFLOW");
}

void push(char x)
{
    if (top == MAX)
        isfull();
    else
        stack[++top] = x;
}

char pop()
{
    if (top == -1)
        isempty();
    else
        return stack[top--];
}

int priority(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
}

int main()
{
    char X[MAX];
    char *e, x;
    int ch = 1;

    while (ch)
    {
        printf("\nEnter INFIX Expression:");
        scanf("%s", X);
        e = X;

        printf("\nThe POSTFIX Expression:");
        while (*e != '\0')
        {
            if (isalnum(*e))
                printf("%c", *e);
            else if (*e == '(')
                push(*e);
            else if (*e == ')')
            {
                while ((x = pop() != '('))
                    printf("%c", x);
            }
            else
            {
                while (priority(stack[top]) >= priority(*e))
                    printf("%c", pop());
                push(*e);
            }
            e++;
        }
        while (top != -1)
            printf("%c", pop());
    }
    return 0;
}
// #include <stdio.h>
// #define max 15
// char stack[max],top = -1;

// void push(char x)
// {
//     if (top == max)
//         printf("stack overflow");
//     else
//         stack[++top] = x;
// }

// char pop()
// {
//     if (top == -1)
//         printf("stack underfow");
//     else
//         return stack[top--];
// }

// int priority(char x)
// {
//     if (x == '(')
//         return 0;
//     if (x == '+' || x == '-')
//         return 1;
//     if (x == '*' || x == '/')
//         return 2;
//     if (x == '^')
//         return 3;
// }

// int main()
// {
//     char X[max];
//     char x,*e;
//     int ch= 1;

//     printf("Enter the infix expression : \n");
//     scanf("%s",X);
//     e = X;

//     printf("The postfix expression is : \n");

//     while(*e != '\0')
//     {
//         if (isalnum(*e))
//             printf("%c",*e);
//         else if (*e == '(')
//             push(*e);
//         else if (*e == ')')
//         {
//             while((x=pop() != '('))
//                 printf("%c",x);
//         }
//         else
//         {
//             while(priority(stack[top])>=priority(*e))
//             {
//                 printf("%c",pop());
//             }
//             push(*e);
//         }
//         e++;

//         while (top!=0)
//         {
//             printf("%c",pop());
//         }
//     }
// }
