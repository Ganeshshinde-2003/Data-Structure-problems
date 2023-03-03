#include <stdio.h>

int max = 20;
int stack[20],top=-1;

int evalpost(char emp[])
{
    char *e;
    e = emp;
    int num,tn;
    int n1,n2;

    while (*e != '\0')
    {
        if(isdigit(*e)){
            printf("%d",*e);
            push(*e-48);
        }
        else
        {
            n1=pop();
            n2=pop();
            switch (*e)
            {
            case '+':
                tn = n1+n2;
                break;
            case '-':
                tn = n1-n2;
                break;
            case '*':
                tn = n1*n2;
                break;
            case '/':
                tn = n1/n2;
                break;
            default:
                break;
            }
            push(tn);
        }
        e++;
    }
    return pop();
}

void push(int num)
{
    if(top==max)
        printf("The stack is full");
    else
        stack[++top]=num;
}

int pop()
{
    if(top == -1)
        printf("The stack is empty");
    else
        return stack[top--];

}


void main()
{
    char emp[max];

    printf("Enter the expression => ");
    scanf("%s",emp);

    printf("\nThe solution of the expression %s is => %d",emp,(evalpost(emp)));
}
