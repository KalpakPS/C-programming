#include<stdio.h>
void main()
{
    int n,num,f,l,sum=0;
    printf("Enter the number:\n");
    scanf("%d",&num);
    l=num%10;
    n=num;
    while(n>=10)
    {
        n=n/10;
    }
    f=n;
    printf("%d\t%d\n",f,l);
    sum=f+l;
    printf("The sum of first and last digit of %d= %d",num,sum);
}