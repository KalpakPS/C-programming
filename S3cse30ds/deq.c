//double ended queue
#include<stdio.h>
#define SIZE 3
void ENQUEUE();
void DEQUEUE();
void DISPLAY();
void INJECT();
void EJECT();
int front=-1,rear=-1,deq[SIZE],i,n;
void main()
{
	int ch;
	char opt;
	do
	{
		printf("****************\n");
		printf("Choices\n1.ENQUEUE\n2.DEQUEUE\n3.INJECT\n4.EJECT\n5.DISPLAY\n");
		printf("****************\n");
		printf("Enter the choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:ENQUEUE();
				break;
			case 2:DEQUEUE();
				break;
			case 3:INJECT();
				break;
			case 4:EJECT();
				break;
			case 5:DISPLAY();
				break;
			default:printf("Invalid input!\n");
				break;
		}	
		printf("Do you want to continue(y/n)?\n");
		scanf("%s",&opt);
	}while(opt=='y');
}
void ENQUEUE()
{
	if(rear==(SIZE-1))
		printf("Queue overflow\n");
	else
	{	
		printf("Enter the element:");
		scanf("%d",&n);
		rear++;
		deq[rear]=n;
		if(front==-1)
			front=0;
		printf("%d is inserted\n",n);
		DISPLAY();
	}
}
void DEQUEUE()
{
	if(front==-1&&rear==-1)
		printf("Queue is empty\n");
	else
	{
		printf("\nElement %d is deleted\n",deq[front]);
		if(front==rear)
		{
			front=-1;rear=-1;
		}		
		else
			front++;
		DISPLAY();			
	}
}
void INJECT()
{
	if(front<=0)
		printf("Injection not possible!\n");
	else
	{
		printf("Enter the element:");
		scanf("%d",&n);
		front--;
		deq[front]=n;
		DISPLAY();
	}
}
void EJECT()
{
	if(front==-1&&rear==-1)
		printf("The queue is empty\n");
	else
	{
		printf("the element %d is deleted\n",deq[rear]);
		if(front==rear)
		{
			front=-1;rear=-1;
		}
		else
			rear--;
		DISPLAY();
	}
}
void DISPLAY()
{
	
	if(front==-1&&rear==-1)
		printf("The queue is empty\n");
	else
	{
		printf("The queue is:\n");
		for(i=front;i<=rear;i++)
			printf("%d\t",deq[i]);	
		printf("\n");
	}
}
