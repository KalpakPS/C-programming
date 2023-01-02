#include<stdio.h>
struct product
{
    char name[20];
    int price,qnt,total;
}p;
void read()
{ 
    printf("Enter the below details:\n");
    printf("Name:");
    gets(p.name);
    printf("Price:");
    scanf("%d",&p.price);
    printf("Quantity:");
    scanf("%d",&p.qnt);
}
void print()
{
    printf("Data:\n");
    printf("Name:%s\nPrice:%d\nQuantity:%d\n",p.name,p.price,p.qnt);
}
void main()
{
    read();
    print();
}