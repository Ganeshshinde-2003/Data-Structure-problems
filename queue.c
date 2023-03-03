// #include <stdio.h>
// int queue[10];
// int rear = -1;
// int front = -1;

// void enqueue()
// {
//     if (rear == 9)
//     {
//         printf("the queue is full\n");
//     }
//     else
//     {
//         printf("\nEnter the data : ");
//         scanf("%d", &queue[++rear]);
//     }
// }
// void dequeue()
// {
//     if (front == rear + 1)
//     {
//         printf("The queue is empty\n");
//     }
//     else
//     {
//         front = front + 1;
//         printf("\nThe poped element is %d\n", queue[front]);
        
//     }
// }
// void display()
// {
//     printf("\nThe elements of queue\n");
//     for (int i = front; i <= rear; i++)
//     {
//         printf("%d\n", queue[i]);
//     }
//     printf("\n");
// }
// int main()
// {
//     int i = 1;
//     int ch;
//     while (i != 0)
//     {
//         printf("0 to exit \n1 to push\n2 to pop\n3 to desplay\nEnter >= ");
//         scanf("%d", &ch);
//         if (ch == 1)
//         {
//             enqueue();
//         }
//         else if (ch == 2)
//         {
//             dequeue();
//         }
//         else if (ch == 3)
//         {
//             display();
//         }
//         else
//         {
//             break;
//         }
//     }
// }

#include <stdio.h>
 
#define MAX 50
 
void insert();
void delete();
void display();
int queue_array[MAX];
int rear = - 1;
int front = - 1;
main()
{
    int choice;
    while (1)
    {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(1);
            default:
            printf("Wrong choice \n");
        } 
    } 
} 
 
void insert()
{
    int add_item;
    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
            front = 0;
        printf("Inset the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
} 
 
void delete()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else if(front<rear){
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
    else {
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front = -1;
        rear =-1;
    }

    
} 
 
void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
} 