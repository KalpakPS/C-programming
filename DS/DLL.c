//doubly LL
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
  struct node *next,*prev;
}*head,*ptr,*new,*ptr1,*ptr2;
void main()
{
  int ch;
  head=(struct node*)malloc(sizeof(struct node)); 
  head->next=NULL;
  head->prev=NULL;
  while(1)
  {
    printf("\nDoubly linked list");
    printf("\n1.insert\n2.delete\n3.search\n4.display\n5.exit\n");
    printf("enter the choice:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:insert();
        break;
      case 2:delete();
        break;
      case 3:search();
        break;
      case 4: display();
        break;
      case 5:exit(0);
      default:printf("invalid statement\n");
    }
  }
}
void insert()
{
  int ch,item;
  new=(struct node*)malloc(sizeof(struct node));
  printf("enter the element:");
  scanf("%d",&item);
  printf("insert at which location");
  printf("\n1.at front\n2.at end\n3.at any location\n");
  printf("enter the choice:");
  scanf("%d",&ch);
  switch(ch)
    {
      case 1:insert_begin(item);
        break;
      case 2:insert_end(item);
        break;
      case 3:insert_any(item);
        break;
      default:printf("invalid statement");
    }
}
void delete()
{
  int ch;
  printf("delete from which location");
  printf("\n1.from front\n2.from end\n3.from any location\n");
  printf("enter the choice:");
  scanf("%d",&ch);
  switch(ch)
    {
      case 1:delete_begin();
        break;
      case 2:delete_end();
        break;
      case 3:delete_any();
        break;
      default:printf("invalid statement");
    }
}
void insert_begin(int item)
{
  new->data=item;
  new->next=NULL;
  new->prev=NULL;
  if(head->next==NULL)
  {
    head->next=new;
    new->prev=head;
  }
  else
  {
    ptr=head->next;
    head->next=new;  
    new->prev=head;
    new->next=ptr;
    ptr->prev=new;
  }display();
}
void insert_end(int item)
{
  new->data=item;
  new->next=NULL;
  new->prev=NULL;
  if(head->next==NULL)
  {
    head->next=new;
    new->prev=head;
  }
  else
  {
    ptr=head->next;
    while(ptr->next!=NULL)
      ptr=ptr->next;
    ptr->next=new;
    new->prev=ptr;
  }display();
}
void insert_any(int item)
{
  int key;
  new->data=item;
  new->next=NULL;
  new->prev=NULL;
  if(head->next==NULL)
  {
    head->next=new;
    new->prev=head;
  }
  else
  {
    printf("enter the key:");
    scanf("%d",&key);
    ptr=head->next;
    while(ptr->data!=key&&ptr->next!=NULL)
      ptr=ptr->next;
    if(ptr->data==key)
    {
      ptr1=ptr->prev;
      ptr1->next=new;
      new->prev=ptr1;
      new->next=ptr;
      ptr->prev=new;
    }
    else
      printf("key not found!");
  }display();
}
void delete_begin()
{
    if(head->next==NULL)
       printf("dll is empty");
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
            ptr1->prev=head;
            free(ptr);
        }
  }display();
}
void delete_end()
{
  if(head->next==NULL)
     printf("dll is empty");
  else
  {
    ptr=head->next;
    while(ptr->next!=NULL)
      ptr=ptr->next;
    ptr1=ptr->prev;
    ptr1->next=NULL;
    free(ptr);
  }display();
}
void delete_any()
{
  int key,flag=0;
   if(head->next==NULL)
     printf("dll is empty");
  else
  {
    printf("enter the key:");
    scanf("%d",&key);
    ptr=head->next;
    while(ptr->data!=key&&ptr->next!=NULL)
    {
      ptr=ptr->next;
      flag=1;
    }
    if(ptr->data==key&&flag==1)
    {
      if(ptr->next!=NULL){
        ptr1=ptr->next;
        ptr2=ptr->prev;
        ptr2->next=ptr1;
        ptr1->prev=ptr2;
        free(ptr);
      }
      else{
        ptr1=ptr->prev;
        ptr1->next=NULL;
        ptr->prev=NULL;
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
            ptr1->prev=head;
            free(ptr);
        }
    }
    else
    {
      printf("key not found!");
    }
  }display();

}
void display()
{
  if(head->next==NULL)
    printf("dll is empty");
  else
  {
    printf("Current status is:\n");
    ptr=head->next;
    while(ptr!=NULL)
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
  if(head->next==NULL)
    printf("dll is empty");
  else
  {
    printf("enter the key:");
    scanf("%d",&key);
    ptr=head->next;
    while(ptr->data!=key&&ptr!=NULL)
    {
      ptr=ptr->next;
    }
    if(ptr->data==key)
      {
       printf("\nkey found");
      printf("%d\n",ptr->data);
      }
    else 
      printf("\nkey not found");
  }display();
}   