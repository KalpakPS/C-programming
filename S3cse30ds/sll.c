//Single linked list
#include<stdio.h>
#include<stdlib.h>
void insert();
void delete();
void search();
void display();
void insert_begin(int);
void insert_end(int);
void insert_any(int);
void delete_begin();
void delete_end();
void delete_any();
struct node
{
	int data;
	struct node *next;
}*head,*new,*ptr,*ptr1,*ptr2;
void main()
{
	int ch,flag=0;
	head=(struct node*)malloc(sizeof(struct node));
	head->next=NULL;
	while(flag==0)
	{
		printf("\n***Single linked list***");
		printf("\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert();
				break;
			case 2:delete();
				break;
			case 3:search();
				break;
			case 4:display();
				break;
			case 5:flag=1;
				printf("Exiting..");
				break;
			default:printf("Invalid input!\n");
		}
	}
}
void insert()
{
	int ch,item;
	new=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element to insert:");
	scanf("%d",&item);
	printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert at any location\n");
	printf("Enter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:insert_begin(item);
			break;
		case 2:insert_end(item);
			break;
		case 3:insert_any(item);
			break;
		default:printf("Invalid input!");
	}
}
void insert_begin(int item)
{
	new->data=item;
	new->next=NULL;
	if(head->next==NULL)
		head->next=new;
	else
	{
		ptr=head->next;
		head->next=new;
		new->next=ptr;
	}display();
}
void insert_end(int item)
{
	new->data=item;
	new->next=NULL;
	if(head->next==NULL)
		head->next=new;
	else
	{
		ptr=head->next;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=new;
	}display();
}
void insert_any(int item)
{
	int key,flag=0;
	new->data=item;
	new->next=NULL;
	if(head->next==NULL)
		head->next=new;
	else
	{
		printf("Enter the key:");
		scanf("%d",&key);
		ptr=head->next;		
		while(ptr->data!=key&&ptr->next!=NULL)
		{		
			ptr1=ptr;			
			ptr=ptr->next;
			flag=1;
		}		
		if(ptr->data==key&&flag==1)
		{
			ptr1->next=new;
			new->next=ptr;
		}
		else if(ptr->data==key&&flag==0)
		{
			ptr=head->next;
			head->next=new;
			new->next=ptr;
		}
		else
			printf("Key not found!\n");
	}display();
}
void delete()
{
	int ch;
	printf("\n1.Delete from beginning\n2.Delete from end\n3.Delete from any location\n");
	printf("Enter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:delete_begin();
			break;
		case 2:delete_end();
			break;
		case 3:delete_any();
			break;
		default:printf("Invalid input!");
	}	
}
void delete_begin()
{
	if(head->next==NULL)
		printf("SLL is empty\n");
	else
	{
		ptr=head->next;
		if(ptr->next==NULL)
		{
			head->next=NULL;
			free(ptr);	
		}
		else
		{
			ptr1=ptr->next;
			head->next=ptr1;
			free(ptr);
		}		
	}display();
}
void delete_end()
{
	if(head->next==NULL)
		printf("SLL is empty\n");
	else
	{
		ptr=head->next;
		if(ptr->next==NULL)
		{
			head->next=NULL;
			free(ptr);	
		}
		else
		{
			while(ptr->next!=NULL)
			{
				ptr1=ptr;
				ptr=ptr->next;
			}
			ptr1->next=NULL;
			free(ptr);
		}
	}display();
}
void delete_any()
{
	int key,flag=0;	
	if(head->next==NULL)
		printf("SLL is empty\n");
	else
	{
		printf("Enter the key:");
		scanf("%d",&key);
		ptr=head->next;		
		while(ptr->data!=key&&ptr->next!=NULL)
		{
			ptr1=ptr;
			ptr=ptr->next;
			flag=1;
		}
		if(ptr->data==key&&flag==1)
		{
			if(ptr->next==NULL)
			{
				ptr1->next=NULL;
				free(ptr);
			}
			else
			{
				ptr2=ptr->next;
				ptr1->next=ptr2;
				free(ptr);
			}
		}
		else if(ptr->data==key&&flag==0)
		{
			if(ptr->next==NULL)
			{
				head->next=NULL;
				free(ptr);
			}
			else
			{
				ptr1=ptr->next;
				head->next=ptr1;
				free(ptr);
			}
		}
		else
			printf("Key not found");		
	}display();
}
void search()
{
	int key;
	if(head->next==NULL)
		printf("SLL is empty\n");
	else
	{
		printf("Enter the key:");
		scanf("%d",&key);
		ptr=head->next;
		while(ptr->data!=key&&ptr->next!=NULL)
			ptr=ptr->next;
		if(ptr->data==key)
		{
			printf("Key(%d) found\n",ptr->data);
		}
		else
			printf("Key not found");
	}
}
void display()
{
	if(head->next==NULL)
		printf("SLL is empty\n");
	else
	{
		printf("Current status is:\n");
		ptr=head->next;
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
	}
}
