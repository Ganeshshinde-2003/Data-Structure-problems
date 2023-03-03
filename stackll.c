#include<stdio.h> 
#include<conio.h>
#include<malloc.h> 
#include<stdlib.h>
int push(); 
int pop(); 
int display(); 
int choice,i,item;
struct node {
int data;
struct node *next;
}*top,*new,*ptr;
int main() 
{ 
top=NULL;
printf("\n***Select Menu***\n");
while(1) {
printf("\n1.Push \n2.Pop \n3.Display \n4.Exit\n5.Count");
printf("\n\nEnter ur choice: ");
scanf("%d",&choice);
switch(choice) {
case 1: push(); break;
case 2: pop(); break;
case 3: display(); break;
case 4: exit(0);
case 5: count(); break;
default: printf("\nWrong choice");
}/* end of switch */
}/* end of while */
}/* end of main */
int push()
{
new=malloc(sizeof(struct node));
printf("\nEnter the item: ");
scanf("%d",&item);
new->data=item;
if(top == NULL)
{
new->next=NULL;
}
else
{
new->next=top;
}
top=new;
}/* end of insertion */
int pop()
{
if(top == NULL)
{
printf("\n\nStack is empty");
}//if
else
{
printf("\n\nThe deleted element is : %d ",top->data);
top=top->next;
}
}/* end of pop() */
int display()
{
ptr=top;
if(top == NULL)
{
printf("\nThe list is empty");
}
 printf("\nThe elements in the stact are: ");
while(ptr!=NULL)
{
printf("\n %d",ptr->data);
ptr=ptr->next;
}/* end of while */
}/* end of display() */
int count()
{
int count=1;
ptr=top;
if(top == NULL)
{
printf("\nThe list is empty");
}
while(ptr->next!=NULL)
{
++count;
ptr=ptr->next;
}
printf("\n\nThe number of elements in the stack are: %d",count);
}/* end of count */