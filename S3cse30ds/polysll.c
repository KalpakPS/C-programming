//polynomial addition using sll
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct poly
{
	int coef,exp;
	struct poly *next;
}*phead,*qhead,*rhead,*pptr,*qptr,*rptr,*new;
void main()
{ 
	char ch='y';
	int i=1,c,e;
	phead=(struct poly*)malloc(sizeof(struct poly));
	pptr=phead;
	//read poly 1
	printf("Enter the elements of polynomial 1:\n");
	while(ch=='y'||ch=='Y')
	{
		printf("Enter the coef and exp of %d: ",i);
		i++;
		scanf("%d%d",&c,&e);
		new=(struct poly*)malloc(sizeof(struct poly));
		new->coef=c;
		new->exp=e;
		new->next=NULL;
		pptr->next=new;
		pptr=pptr->next;
		printf("Do you want to add more terms(y/n):");
		scanf("%s",&ch);
	}
	//read poly 2
	qhead=(struct poly*)malloc(sizeof(struct poly));
	qptr=qhead;
	ch='y';
	i=1;
	printf("Enter the elements of polynomial 2:\n");
	while(ch=='y'||ch=='Y')
	{
		printf("Enter the coef and exp of %d: ",i);
		i++;
		scanf("%d%d",&c,&e);
		new=(struct poly*)malloc(sizeof(struct poly));
		new->coef=c;
		new->exp=e;
		new->next=NULL;
		qptr->next=new;
		qptr=qptr->next;
		printf("Do you want to add more terms(y/n):");
		scanf("%s",&ch);
	}
	//display poly 1
	printf("polynomial 1 is: ");
	pptr=phead->next;
	while(pptr->next!=NULL)
	{
		printf("%dx^%d+",pptr->coef,pptr->exp);
		pptr=pptr->next;	
	}
	if(pptr->next==NULL)
	{
		if(pptr->exp!=0)
			printf("%dx^%d\n",pptr->coef,pptr->exp);
		else
			printf("%d\n",pptr->coef);		
	}
	//display poly 2
	printf("polynomial 2 is: ");
	qptr=qhead->next;
	while(qptr->next!=NULL)
	{
		printf("%dx^%d+",qptr->coef,qptr->exp);
		qptr=qptr->next;	
	}
	if(qptr->next==NULL)
	{
		if(qptr->exp!=0)
			printf("%dx^%d\n",qptr->coef,qptr->exp);
		else
			printf("%d\n",qptr->coef);		
	}
	//addition
	pptr=phead->next;
	qptr=qhead->next;
	rhead=(struct poly*)malloc(sizeof(struct poly));
	rhead->next=NULL;
	rptr=rhead;
	while(pptr!=NULL&&qptr!=NULL)
	{
		new=(struct poly*)malloc(sizeof(struct poly));
		new->next=NULL;
		if((pptr->exp)<(qptr->exp))
		{
			new->coef=qptr->coef;
			new->exp=qptr->exp;
			qptr=qptr->next;
		}
		else if((pptr->exp)>(qptr->exp))
		{
			new->coef=pptr->coef;
			new->exp=pptr->exp;
			pptr=pptr->next;
		}
		else
		{
			new->coef=(pptr->coef)+(qptr->coef);
			new->exp=pptr->exp;
			pptr=pptr->next;
			qptr=qptr->next;
		}
		rptr->next=new;
		rptr=new;
	}
	while(pptr!=NULL)
	{
		new->coef=pptr->coef;
		new->exp=pptr->exp;
		pptr=pptr->next;
		rptr->next=new;
		rptr=new;	
	}
	while(qptr!=NULL)
	{
		new->coef=qptr->coef;
		new->exp=qptr->exp;
		qptr=qptr->next;
		rptr->next=new;
		rptr=new;
	}
	//display added poly
	printf("Added polynomial is: ");
	rptr=rhead->next;
	while(rptr->next!=NULL)
	{
		printf("%dx^%d+",rptr->coef,rptr->exp);
		rptr=rptr->next;	
	}
	if(rptr->next==NULL)
	{
		if(rptr->exp!=0)
			printf("%dx^%d\n",rptr->coef,rptr->exp);
		else
			printf("%d\n",rptr->coef);		
	}
}
