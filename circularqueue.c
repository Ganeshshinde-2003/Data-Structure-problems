#include<stdio.h>
# define MAX 5
int cque[MAX];
int front = -1;
int rear = -1;

void insert(int item)
{
    if((front == 0 && rear == MAX-1) || (front == rear+1))
    {
        printf("Queue Overflow\n");
        return;
    }
    if(front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        if(rear == MAX-1)   
           rear = 0;
        else
            rear = rear+1;
    }
    cque[rear] = item ;
}
void deletion()
{
    if(front == -1)
    {
        printf("Queue Underflow");
        return ;
    }
    printf("Element deleted from queue is : %d\n",cque[front]);
    if(front == rear)
    {
        front = -1;
        rear=-1;
    }
    else
    {
        if(front == MAX-1)
            front = 0;
        else
            front = front+1;
    }
}
void display()
{
    int front_pos = front,rear_pos = rear;
    if(front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("\nQueue elements :");
    if( front_pos <= rear_pos )
        while(front_pos <= rear_pos)
        {
            printf("%d ",cque[front_pos]);
            front_pos++;
        }
    else
    {
        while(front_pos <= MAX-1)
        {
            printf("%d ",cque[front_pos]);
            front_pos++;
        }
        front_pos = 0;
        while(front_pos <= rear_pos)
        {
            printf("%d ",cque[front_pos]);
            front_pos++;
        }
    }
    printf("\n");
}
int main()
{
    int choice,item;
    do
    {
        printf("\n1.Insert");
        printf("\t2.Delete");
        printf("\n3.Display");
        printf("\t4.Quit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
                    printf("Input the element for insertion in queue : ");
                    scanf("%d", &item);
                    insert(item);
                    break;
            case 2 :
                    deletion();
                    break;
            case 3:
                    display();
                    break;
            case 4:
                    break;
            default:
                   printf("Wrong choice");
        }
    }while(choice!=4);

    return 0;
}
