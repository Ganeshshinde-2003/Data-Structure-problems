#include <stdio.h>
#include <stdlib.h>


struct node* create(struct node* head);
struct node* insert(struct node*head,float c,int e);
struct node* polyadd(struct node*head1,struct node*head2);
void display(struct node*head);


struct  node
{
    float co;
    int ex;
    struct node* link;
};

struct node* create(struct node* head)
{

    int n,i;
    float co;
    int e;

    printf("Enter the lenght of the expresion : ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter the coefficient for term %d : ",i+1);
        scanf("%f",&co);
        printf("Enter the exponent for the term %d : ",i+1);
        scanf("%d",&e);

        head = insert(head,co,e);
    }

    return head;

}

struct node* insert(struct node*head,float c,int e)
{

    struct node*temp;
    struct node*new = malloc(sizeof(struct node));
    new->co = c;
    new->ex = e;
    new->link = NULL;

    if(head == NULL || e > head->ex)
    {
        new->link = head;
        head = new;
    }
    else{
        temp = head;
        while (temp->link != NULL && temp->link->ex>e)
        {
            temp = temp->link;
        }
        new->link = temp->link;
        temp->link = new;
    }
    return head;
}

struct node* polyadd(struct node*head1,struct node*head2)
{
    struct node*p1 = head1;
    struct node*p2 = head2;
    struct node*head3 = NULL;
    while (p1!=NULL && p2!=NULL)
    {
        if(p1->ex == p2->ex)
        {
            head3 = insert(head3,p1->co+p2->co,p1->ex);
            p1 = p1->link;
            p2 = p2->link;
        }
        else if(p1->ex > p2->ex){
            head3 = insert(head3,p1->co,p1->ex);
            p1 = p1->link;
        }
        else if(p1->ex < p2->ex){
            head3 = insert(head3,p2->co,p2->ex);
            p2 = p2->link;
        }
    }
    while(p1!=NULL){
        head3 = insert(head3,p1->co,p1->ex);
        p1 = p1->link;
    }
    while(p2!=NULL){
        head3 = insert(head3,p2->co,p2->ex);
        p2 = p2->link;
    }
    // printf("Added polynomial is : ");
    // display(head3);
    return head3;
}

void display(struct node*head)
{
    if(head == NULL)
        printf("NO POLYNOMIAL...");
    else {
        struct node* temp = head;
        while (temp != NULL)
        {
            printf("(%.1f x ^ %d)",temp->co,temp->ex);
            temp = temp ->link;
            if(temp != NULL)
                printf(" + ");
            else
                printf("\n");
        }   
    }
}
int main()
{
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    struct node* head3 = NULL;
    printf("Enter the first polynomial \n");
    head1 = create(head1);
    printf("Enter the second polynomial \n");
    head2 = create(head2);
    display(head1);
    display(head2);
    printf("The added polynomial is =>");
    head3 = polyadd(head1,head2);
    display(head3);
}