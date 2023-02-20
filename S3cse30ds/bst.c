//Binary search tree
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *lc,*rc;
}*root=NULL,*ptr,*ptr1,*parent,*new;
void insertion();
void deletion(int);
void display(struct node*);
void main()
{
	int ch,item,f=0;
	while(f==0)
	{
		printf("\n*************\n");
		printf("1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
		printf("*************\nEnter your choice:");
		scanf("%d",&ch);
	    switch(ch)
		{
			case 1:insertion();
				break;
			case 2:printf("Enter the item to be deleted\n");
				scanf("%d",&item);
			   	deletion(item);
			  	break;
			case 3:printf("The current status is\n");
			   	display(root);
			   	break;
			case 4:	f=1;
				break;
			default:printf("Invalid choice\n");
		}
	}
}
void insertion()
{
	int item,f=0;
	new=(struct node *)malloc(sizeof(struct node));
	printf("Enter a value ");
	scanf("%d",&item);
	new->data=item;
	new->lc=NULL;
	new->rc=NULL;
	ptr=root;
	if(ptr==NULL)
		root=new;
	else
	{
		while(ptr!=NULL&&f==0)
		{
			if(item<ptr->data)
			{
				parent=ptr;
				ptr=ptr->lc;
			}
			else if(item>ptr->data)
			{
				parent=ptr;
				ptr=ptr->rc;
			}
			else if(item==ptr->data)
			{
				f=1;
				printf("Item is already exist\n");
			}
		}
		if(ptr==NULL)
		{
			if(parent->data<item)
				parent->rc=new;
			else if(parent->data>item)
				parent->lc=new;
		}
	}
    printf("The current status is:\n");
    display(root);
}
void deletion(int item)
{
	int  f=0;
	ptr=root;
	while(ptr!=NULL&&f==0)
  	{
		if(item<ptr->data)
		{
			parent=ptr;
			ptr=ptr->lc;
		}
		else if(item>ptr->data)
		{
			parent=ptr;
			ptr=ptr->rc;
		}
		else if(item==ptr->data)
			f=1;
   	}
  	if(f==0)
    		printf("Item does not exist\n");
  	else
    	{

      		if(root->lc==NULL&&root->rc==NULL)
             		root=NULL;
      		else if(ptr->lc==NULL&&ptr->rc==NULL)
        	{
            	if(parent->lc==ptr)
        			parent->lc=NULL;
            	else if(parent->rc==ptr)
        			parent->rc=NULL;
    		}
      		else if(ptr->lc!=NULL&&ptr->rc!=NULL)
        	{
            		ptr1=ptr->rc;
            		if(ptr1!=NULL)
              		{
						while(ptr1->lc!=NULL)
							ptr1=ptr1->lc;
              		}
            		item=ptr1->data;
            		deletion(item);
            		ptr->data=item;
    		}
      		else
        	{
				if(ptr==root)
				{
					if(root->lc==NULL)
						root=root->rc;
					else if(root->rc==NULL)
						root=root->lc;
				}
        		else if(parent->lc==ptr)
				{
					if(ptr->lc==NULL)
							parent->lc=ptr->rc;
					else
						parent->lc=ptr->lc;
				}
				else if(parent->rc==ptr)
				{
					if(ptr->lc==NULL)
							parent->rc=ptr->rc;
					else
							parent->rc=ptr->lc;
				}

    		}
	}
 	if(root==NULL)
      		printf("Tree is empty\n");
 	else
    	{
      		printf("The current status is\n");
      		display(root);
     	}
}
void display(struct node *bst)
{
	if(bst!=NULL)
        {
        	display(bst->lc);
        	printf("%d\t",bst->data);
        	display(bst->rc);
        }
}
