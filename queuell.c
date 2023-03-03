#include <stdio.h>
#include <malloc.h>
#define max 20
int queue[20];
int choice,i,item;

struct node
{
    int data;
    struct node *next;
}*header,*front,*rear,*new;

void push()
{
    printf("Enter the data => ");
    scanf("%d",&item);
    new = malloc(sizeof(struct node));
    new->data = item;
    new->next = NULL;
    if(front == NULL){
        front = new;
    }
    else{
        rear->next = new;
    }
    rear = new;
}

void pop ()
{
    
}

void main()
{
    front = NULL;
    rear = NULL;
    printf("Enter the chioce => ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        push();
        break;
    // case 2:
    //     pop();
    //     break;
    // case 3:
    //     display();
    //     break;
    default:
        break;
    }
}