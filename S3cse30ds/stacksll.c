//stack using sll
#include<stdio.h>
#include<stdlib.h>
void PUSH();//insert at beginning
void POP();//delete from beginning
void DISPLAY();
struct node
{
	int data;
	struct node *next;
}*top,*new,*ptr,*ptr1;
void main()
{
	int ch,flag=0;
	top=(struct node*)malloc(sizeof(struct node));
	top->next=NULL;
	while(flag==0)
	{
		printf("\n***Stack using single linked list***");
		printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:PUSH();
				break;
			case 2:POP();
				break;
			case 3:DISPLAY();
				break;
			case 4:flag=1;
				printf("Exiting..");
				break;
			default:printf("Invalid choice!\n");
		}
	}
}
void PUSH()
{
	int item;
	printf("Enter the element to insert:");
	scanf("%d",&item);
	new=(struct node*)malloc(sizeof(struct node));
	new->data=item;
	new->next=NULL;
	if(top->next==NULL)
		top->next=new;
	else
	{
		ptr=top->next;
		top->next=new;
		new->next=ptr;
	}DISPLAY();
}
void POP()
{
	if(top->next==NULL)
		printf("Stack is empty\n");
	else
	{
		ptr=top->next;
		if(ptr->next==NULL)
		{
			top->next=NULL;
			free(ptr);	
		}
		else
		{
			ptr1=ptr->next;
			top->next=ptr1;
			free(ptr);
		}
		DISPLAY();		
	}
}
void DISPLAY()
{
	if(top->next==NULL)
		printf("Stack is empty\n");
	else
	{
		printf("Current status is:\n");
		ptr=top->next;
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
	}
}
