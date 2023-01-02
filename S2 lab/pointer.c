//Testing out pointer
#include<stdio.h>
void main()
{
    int a,*p1,**p2;
    p1=&a;
    p2=&p1;
    printf("Enter 2 numbers:\n");
    scanf("%d",p1);
    printf("output:%d\t%d",*p1,**p2);
}