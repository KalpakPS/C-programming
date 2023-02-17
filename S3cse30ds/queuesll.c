//queue using sll
#include<stdio.h>
#include<stdlib.h>
void ENQUEUE();//insert at end
void DEQUEUE();//delete from beginning
void DISPLAY();
struct node
{
	int data;
	struct node *next;
}*front,*rear,*ptr,*ptr1,*new;
void main()
{
	int ch,flag=0;
	front=(struct node*)malloc(sizeof(struct node));
	rear=front;
	while(flag==0)
	{
		printf("\n***Queue using single linked list***");
		printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:ENQUEUE();
				break;
			case 2:DEQUEUE();
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
void ENQUEUE()
{
	int item;
	printf("Enter the element to insert:");
	scanf("%d",&item);
	new=(struct node*)malloc(sizeof(struct node));
	new->data=item;
	new->next=NULL;
	rear->next=new;
	rear=new;
	DISPLAY();
}
void DEQUEUE()
{
	if(front==rear)
		printf("Queue is empty\n");
	else
	{
		ptr=front->next;
		if(ptr->next==NULL)
		{
			front=rear;
			front->next=NULL;
			free(ptr);	
		}
		else
		{
			ptr1=ptr->next;
			front->next=ptr1;
			free(ptr);
		}
		DISPLAY();		
	}
}
void DISPLAY()
{
	if(front==rear)
		printf("Queue is empty\n");
	else
	{
		printf("Current status is:\n");
		ptr=front->next;
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
	}
}
