#include <stdio.h>
int stack[10], top = -1;

void isempty()
{
    if (top == -1)
        printf("STACK UNDERFLOW");
}

void isfull()
{
    if (top == 9)
        printf("STACK OVERFLOW");
}

void push()
{
    if (top == 9)
        isfull();
    else
    {
        printf("\nEnter the element to be pushed:");
        scanf("%d", &stack[++top]);
    }
}

void pop()
{
    if (top == -1)
        isempty();
    else
    {
        printf("\nThe element popped is: %d", stack[top--]);
    }
}

void peek()
{
    if (top == -1)
        printf("\n STACK is EMPTY");
    else
        printf("\nElement at the TOP:%d", stack[top]);
}

void display()
{
    if (top == -1)
        printf("\n STACK is EMPTY");
    printf("\nElements of the stack:");
    for (int i = 0; i <= top; i++)
        printf("%d\t", stack[i]);
}

int main()
{
    int ch = 1;

    while (ch)
    {
        printf("\n1>PUSH\t2>POP\n3>PEEK\t4>DISPLAY\n0>EXIT\nEnter Choice:");
        scanf("%d", &ch);
        if (ch == 1)
            push();
        else if (ch == 2)
            pop();
        else if (ch == 3)
            peek();
        else if (ch == 4)
            display();
    }
    return 0;
}
