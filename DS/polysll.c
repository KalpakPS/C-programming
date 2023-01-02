#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coeff,exp;
	struct node*next;
}*phead,*qhead,*rhead,*pptr,*qptr,*rptr,*new,*ptr;
void display(struct node*);
void read();
void add();

void main()
{
	
	phead=(struct node*)malloc(sizeof(struct node));
	phead->next=NULL;
	qhead=(struct node*)malloc(sizeof(struct node));
	qhead->next=NULL;
	rhead=(struct node*)malloc(sizeof(struct node));
	rhead->next=NULL;
	read();
	add();
}
void read()
{
	int coef,exp;
	char ch='y';
	
	pptr=phead;
	
	
	
	while((ch=='y')||(ch=='Y'))
	{
		new=(struct node *)malloc(sizeof(struct node));
		printf("\nenter the coefficent and exponent of  term1\n");
		scanf("%d%d",&coef,&exp);
		new->coeff=coef;
		new->exp=exp;
		new->next=NULL;
		pptr->next=new;
		pptr=new;
		printf("\ndo u want to add more terms?(Y/N)\t");	
		scanf("%s1",&ch);
	
	}
		
	
	qptr=qhead;
	ch='y';
	while((ch=='y')||(ch=='Y'))
	{
		new=(struct node *)malloc(sizeof(struct node));
		new->next=NULL;
		printf("\nenter the coefficent and exponent of  term2\n");
		scanf("%d%d",&coef,&exp);
		new->coeff=coef;
		new->exp=exp;
		new->next=NULL;
		qptr->next=new;
		qptr=new;
		printf("\ndo u want to add more terms?(Y/N)\t");	
		scanf("%s1",&ch);
	
	}
	printf("\nenter 1 st polinomial\n");
	display(phead);
	printf("\nenter 2nd polinomial\n");
	display(qhead);	
}
void add()
{
	pptr=phead->next;
	qptr=qhead->next;
	rptr=rhead;
	//new=(struct node*)malloc(sizeof(struct node));
	
	
	while(pptr!=NULL&&qptr!=NULL)
	{
		new=(struct node *)malloc(sizeof(struct node));
		new->next=NULL;
		if((pptr->exp)>(qptr->exp))
		{
			new->coeff=pptr->coeff;
			new->exp=pptr->exp;
			pptr=pptr->next;
		}
		else if((pptr->exp)<(qptr->exp))
		{
			new->coeff=qptr->coeff;
			new->exp=qptr->exp;
			qptr=qptr->next;
		}
		else
		{
			new->coeff=pptr->coeff+qptr->coeff;
			new->exp=pptr->exp;
			pptr=pptr->next;
			qptr=qptr->next;
		}
	rptr->next=new;
	rptr=new;
	}
	
	while(pptr!=NULL)
	{
		new=(struct node *)malloc(sizeof(struct node));
		new->coeff=pptr->coeff;
		new->exp=pptr->exp;
		pptr=pptr->next;
		rptr->next=new;
		rptr=new;
	}
	while(qptr!=NULL)
	{
		new=(struct node *)malloc(sizeof(struct node));
		new->coeff=qptr->coeff;
		new->exp=qptr->exp;
		qptr=qptr->next;
		rptr->next=new;
		rptr=new;
	}printf("\nenter resultant polinomial\n");
	display(rhead);
	
display(rhead);
}	
void display(struct node *head)
{    
	ptr=head->next;
	while(ptr!=NULL)
	{	
		if(ptr==head->next)
		{
			printf("%dx^%d",ptr->coeff,ptr->exp);
		}
		else if(ptr->exp!=0&&ptr->coeff!=0)
			printf("%+dx^%d",ptr->coeff,ptr->exp);
		else if((ptr->exp)==0)
			printf("%+d",ptr->coeff);
		ptr=ptr->next;
	}
}
		


