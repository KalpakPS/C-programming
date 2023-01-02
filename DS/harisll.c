#include<stdio.h>
#include<stdlib.h>
void insert();
void delete();
void display();
void search();//added
void insert_beginning(int);
void insert_end(int);
void insert_anywhere(int);
void delete_beginning();
void delete_end();
void delete_anywhere();

struct node
{
    int data;
    struct node*next;
}*head,*new,*ptr,*ptr1,*prt2;

void main()
{
    int ch;
    head=(struct node*)malloc(sizeof(struct node));
    head->next=NULL;//new
    while(1)//changed
    {
        printf("\n1.insert\n2.delete\n3.display\n4.search\n5.exit\n");
        printf("enter the choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();
                break;
            case 2:delete();
                break;
            case 3:display();
                break;
            case 4:search();//added
                break;
            case 5:exit(0);
                break;
            default:printf("Invalid input!");//new
        }
    }
}

void insert()
{
    int ch,item;
    new=(struct node*)malloc(sizeof(struct node));
    printf("enter the element\n");
    scanf("%d",&item);
    printf("\n1.insert at beginning\n2.insert at end\n3.insert at anywhere\n");
    printf("enter the choice");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:insert_beginning(item);
            break;
        case 2:insert_end(item);
            break;
        case 3:insert_anywhere(item);
            break;
        default :printf("invlaid input");
    }

}

void insert_beginning(int item)
{
    new->data=item;
    new->next=NULL;
    if(head->next==NULL)
        head->next=new;
    else//changed
    {
        ptr=head->next;
        head->next=new;
        new->next=ptr;
    }display();//new
}

void insert_end(int item)
{
    new->data=item;
    new->next=NULL;
    if(head->next==NULL)
    {
        head->next=new;
    }
    else
    {
        ptr=head->next;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=new; 
    }display();
}

void insert_anywhere(int item)
{
    int key;
    head->next=new;
    new->next=NULL;
    if(head->next==NULL)
    {
        head->next=new;
    }
    else
    {
        printf("enter the key\n");
        scanf("%d",&key);
        ptr=head->next;
        while (ptr->data==key&&ptr->next==NULL)
        {
            ptr1=ptr;
            ptr=ptr->next;
        }
        if(ptr->data==key)
        {
            ptr->next=new;
            new->next=ptr;
        }
        else
        {
            printf("ket is not found\n");
        }
    }display();
}

void delete()
{
    int ch;
    printf("\n1.delete from beginng\n2.delete from end\n3.delete from anywhere\n");
    printf("enter the choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:delete_beginning();
        break;
    case 2:delete_end();
        break;
    case 3:delete_anywhere();
        break;
    default : printf("invalid input\n");
    }

}

void delete_beginning()
{
    if(head->next==NULL)
    {
        printf("link list is empty");
    }
    else
    {
        ptr=head->next;
        ptr1=ptr->next;
        head->next=ptr1;
        free(ptr);
    }display();
}

void delete_anywhere()
{
    int key;
    if(head->next==NULL)
    {
        printf("link list is empty\n");
    }
    else
    {
        ptr=head->next;
        printf("enter the key element\n");
        scanf("%d",&key);
        while(ptr->data!=key&&ptr->next!=NULL)
        {
            ptr1=ptr;
            ptr=ptr->next;
        }
        if(ptr==head->next&&ptr->next==NULL)
        {
            free(ptr);
        }
        else
        {
            prt2=ptr->next;
            ptr1->next=prt2;
            free(ptr);
        }
    }display();
}

void delete_end()
{
    if(head->next==NULL)
    {
        printf("link list is empty\n");
    }
    else 
    {
        ptr=head->next;
        while(ptr->next!=NULL)
        {
            ptr1=ptr;
            ptr=ptr->next;
        }
        ptr1->next=NULL;
        free(ptr);
    }display();
}

void display()
{
    if(head->next==NULL)//changed
        printf("link list is empty\n");
    else
    {
        printf("Current status is:");//new
        ptr=head->next;
        while(ptr!=NULL)//changed
        {
            printf("%d\t",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
}

void search()
{
    int key;
    printf("enter the key element\n");
    scanf("%d",&key);
    if(head->next==NULL)
    {
        printf("link list is empty\n");
    }
    else
    {
        ptr=head->next;
        while(ptr->data!=key)
        {
            ptr=ptr->next;
        }
        if(ptr->data==key)
        {
            printf("key found\n");
            printf("%d\n",ptr->data);
        }
        else
        {
            printf("key is not present in link list\n");
        }
    }
}