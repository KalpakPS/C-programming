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
    int item,ch,f=0;
    printf("  BINARY SEARCH TREE");
    while(f==0)
    {
        printf("\n**********************\n");
        printf("1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
        printf("**********************\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: insertion();
                    break;
            case 2: printf("Enter the item to be deteted:");
                    scanf("%d",&item);
                    deletion(item);
                    break;
            case 3: printf("The current status is:\n");
                    display(root);
                    break;
            case 4: f=1;
                    break;
            default:printf("Invalid input!\n");
                    break;
        }
    }
}
void insertion()
{
    int item,f=0;
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter the item to be inserted:");
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
            if(ptr->data>item)
            {
                parent=ptr;
                ptr=ptr->lc;
            }
            else if(ptr->data<item)
            {
                parent=ptr;
                ptr=ptr->rc;
            }
            else
            {
                f=1;
                printf("Item already exist!\n");
            }
        }
        if(ptr==NULL)
        {
            if(item<parent->data)
                parent->lc=new;
            else if(item>parent->data)
                parent->rc=new;
        }
    }
    printf("The current status is:\n");
    display(root);
}
void deletion(int item)
{
    int f=0;
    ptr=root;
    while(ptr!=NULL&&f==0)
    {
        if(ptr->data>item)
        {
            parent=ptr;
            ptr=ptr->lc;
        }
        else if(ptr->data<item)
        {
            parent=ptr;
            ptr=ptr->rc;
        }
        else
            f=1;
    }
    if(f==0)
        printf("Item doesn't exist!");
    else
    {
        if(root->lc==NULL&&root->rc==NULL)
            root=NULL;
        else if(ptr->lc==NULL&&ptr->rc==NULL)
        {
            if(ptr==parent->lc)
                parent->lc=NULL;
            else    
                parent->rc=NULL;
        }
        else if(ptr->lc!=NULL&&ptr->rc!=NULL)
        {
            ptr1=ptr->rc;
            while(ptr1->lc!=NULL)
                ptr1=ptr1->lc;
            item=ptr1->data;
            deletion(item);
            ptr->data=item;
        }
        else
        {
            if(ptr==root)
            {
                if(ptr->lc!=NULL)
                    root=root->lc;
                else
                    root=root->rc;
            }
            else if(ptr==parent->lc)
            {
                if(ptr->lc!=NULL)
                    parent->lc=ptr->lc;
                else
                    parent->rc=ptr->rc;
            }
            else if(ptr==parent->rc)
            {
                if(ptr->lc!=NULL)
                    parent->lc=ptr->lc;
                else
                    parent->rc=ptr->rc;
            }
        }
        if(root==NULL)
            printf("The tree is empty\n");
        else
        {
            printf("The current status is:\n");
            display(root);
        }
    }
}
void display(struct node*t)
{
    if(t!=NULL)
    {
        display(t->lc);
        printf("%d\t",t->data);
        display(t->rc);
    }
}