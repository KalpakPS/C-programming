//Queue
#include<stdio.h>
#define SIZE 5
void ENQUEUE();
void DEQUEUE();
void DISPLAY();
int front=-1,rear=-1,queue[SIZE],i;
void main()
{
	int ch;
	char opt;
	do
	{
		printf("****************\n");
		printf("Choices\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n");
		printf("****************\n");
		printf("Enter the choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:ENQUEUE();
				break;
			case 2:DEQUEUE();
				break;
			case 3:DISPLAY();
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
	int n;
	if(rear==(SIZE-1))
		printf("Queue overflow\n");
	else
	{	
		printf("Enter the element:");
		scanf("%d",&n);
		rear++;
		queue[rear]=n;
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
		printf("\nElement %d is deleted\n",queue[front]);
		if(front==rear)
		{
			front=-1;rear=-1;
		}		
		else
			front++;
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
			printf("%d\t",queue[i]);	
		printf("\n");
	}
}
