//stack
#include<stdio.h>
#define SIZE 5
void POP();
void PUSH();
void DISPLAY();
int stack[SIZE],top=-1,i;
void main()
{
	int ch;
	char opt;
	do
	{
		printf("****************\n");
		printf("Choices\n1.PUSH\n2.POP\n3.DISPLAY\n");
		printf("****************\n");
		printf("Enter the choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:PUSH();
				break;
			case 2:POP();
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
void PUSH()
{
	int n;
	if(top==(SIZE-1))
		printf("Stack is full\n");
	else
	{
		printf("Enter the element:");
		scanf("%d",&n);	
		top++;
		stack[top]=n;
		printf("%d is inserted\n",n);
		DISPLAY();	
	}
}
void POP()
{
	if(top==-1)
		printf("The stack is empty\n");
	else
	{
		printf("Element %d is poped\n",stack[top]);
		top--;
		DISPLAY();	
	}
}
void DISPLAY()
{
	if(top==-1)
		printf("The stack is empty");
	else
	{
		printf("The stack is:\n");
		for(i=top;i>=0;i--)
			printf("%d\t",stack[i]);	
		printf("\n");
	}
}
