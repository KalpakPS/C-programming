//priority queue
#include<stdio.h>
#define SIZE 3
void PDEQUEUE();
void PENQUEUE();
void DISPLAY();
int front=-1,rear=-1,i,j;
struct pqueue
{
	int pr,val;
}PQ[SIZE];
void main()
{
	int choice;
	char opt;
	do{	
		printf("----------------\n");
		printf("Choices:\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n");
		printf("----------------\n");
		printf("Enter the choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:PENQUEUE();
				break;
			case 2:PDEQUEUE();
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
void PENQUEUE()
{
	int p,v;
	if(rear==(SIZE-1))
		printf("The pqueue is full\n");
	else
	{
		printf("Enter the value and priority:\n");
		scanf("%d%d",&v,&p);
		if(front==-1&&rear==-1)
		{
			front=0;rear=0;
			PQ[0].val=v;
			PQ[0].pr=p;
		}
		else
		{
			for(i=front;i<=rear;i++)
				if(p<=PQ[i].pr)
				{
					for(j=rear+1;j>i;j--)
						PQ[j]=PQ[j-1];
					break;
				}
			PQ[i].val=v;
			PQ[i].pr=p;
			rear++;
		}
	}
	DISPLAY();
}
void PDEQUEUE()
{
	if(front==-1&&rear==-1)
		printf("The pqueue is empty\n");
	else
	{
		printf("\nElement %d is deleted\n",PQ[front].val);
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
		printf("The pqueue is empty\n");
	else
	{
		printf("The pqueue is:\n");
		for(i=front;i<=rear;i++)
			printf("%d(%d)\t",PQ[i].val,PQ[i].pr);	
		printf("\n");
	}
}
