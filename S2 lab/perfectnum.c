//to check a number is perfect or not
#include<stdio.h>
void main()
{
    int n,i,sum=0;
    printf("Enter the number:\n");
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        if(n%i==0)
            sum=sum+i;
    }
    if(n==sum)
        printf("The number %d is a perfect number\n",n);
    else
        printf("The number %d is not a perfect number\n",n);
}