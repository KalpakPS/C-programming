//to check whether a number is armstrong or not
#include<stdio.h>
void main()
{
    int n,temp,dig,sum=0;
    printf("Enter the number:\n");
    scanf("%d",&n);
    temp=n;
    while (n>0)
    {
        dig=n%10;
        sum=sum+(dig*dig*dig);
        n=n/10;
    }
    if(sum==temp)
        printf("The number %d is Armstrong\n",temp);
    else
        printf("The number %d is not armstrong\n",temp);
}