#include<stdio.h>
int sum();
void main()
{
    int s;
    s=sum();
    printf("Sum = %d\n",s);
}
int sum()
{
    int a,b,sum;
    printf("Enter 2 numbers to add:\n");
    scanf("%d%d",&a,&b);
    sum=a+b;
    return sum;
}
