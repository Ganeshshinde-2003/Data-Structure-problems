#include <stdio.h>
#include <malloc.h>
void insertion();
void deletion();
void display();
// void search();
int choice, i, pos, item;
struct node
{
    char rollno[20] ;
    char name[20];
    char section[20];
    struct node *next;
} * header, *tmp, *new, *ptr,*prev,*tmp2;
int main()
{
    header = NULL;
    ptr = header;
    printf("****Menu****\n");
    printf("\n 1.Insertion\n 2.Deletion\n 3.Traverse\n 4.Search\n 5.Exit\n");
    while (1)
    {
        printf("\nEnter your choice => ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertion();
            break;
        case 2:
            deletion();
            break;
        case 3:
            display();
            break;
        // case 4:
        //     search();
        //     break;
        case 5:
            exit(0);
        default:
            printf("\nwrong choice\n");
        } 
    }     
}

void insertion()
{
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the rollno of student : ");
    scanf("%s", new->rollno);
    printf("Enter the name of student : ");
    scanf("%s", new->name);
    printf("Enter the section of student : ");
    scanf("%s", new->section);
    if (header == NULL)
    {
        new->next = NULL;
        header = new;
    }
    else
    {
        printf("Where you wanna insert the data \n1 for start\n2 for middle\n3 for last\nEnter => ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            new->next = header;
            header = new;
        }
        if (choice == 2)
        {
            tmp = header;
            printf("Enter the position you wanna insert : ");
            scanf("%d", &pos);
            for (i = 1; i < pos - 1; i++)
            {
                tmp = tmp->next;
            }
            new->next = tmp->next;
            tmp->next = new;
        }
        if(choice == 3)
        {
            tmp = header;
            while (tmp->next!='\0')
            {
                tmp = tmp->next;
            }
            tmp->next = new;
            new->next = NULL;
            
        }
    }
}
void deletion() 
{
    if(header == NULL){
        printf("\nThe List is empty\n");
    }
    else{
        tmp = prev = header;
        printf("Where you wanna delete the data \n1 for start\n2 for middle\n3 for last\nEnter => ");
        scanf("%d", &choice);
        if(choice == 1)
        {
            tmp2 = tmp;
            tmp = tmp->next;
            header = tmp;
            printf("Name : %s\nRollno : %s\nSection : %s",tmp2->name,tmp2->rollno,tmp2->section);
            free(tmp);
        }
        if(choice == 2)
        {

            printf("Enter the position you wanna delete : ");
            scanf("%d", &pos);
            for (int i=0;i<pos;i++)
            {
                tmp = tmp->next;
            }
            new= tmp->next;
            printf("Name : %s\nRollno : %s\nSection : %s",new->name,new->rollno,new->section);
            tmp->next = new->next;
            free(new);
        }
        if(choice == 3)
        {
            tmp=prev=header;
            while(tmp->next != '\0')
            {
                prev = tmp;
                tmp = tmp->next;
            }
            printf("Name : %s\nRollno : %s\nSection : %s",tmp->name,tmp->rollno,tmp->section);
            prev->next = 0;
            free(tmp);
        }
    }
}
void display()
{
    if(header == NULL){
        printf("The list is empty\n");
    }
    else{
        tmp=header;
        printf("elements of stack from top to bottom are:");
        while(tmp!=NULL)
        {
            printf("\nStudent:%s \nRoll No:%s \nsec:%s \n",tmp->name, tmp->rollno,tmp->section);
            tmp=tmp->next;
        }
    }
}