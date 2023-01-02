//to check whether a number is prime or not
#include<stdio.h>
void main()
{
    int n,i,flag=0;
    printf("Enter the number:\n");
    scanf("%d",&n);
    for(i=2;i<n;i++)
    {
        if(n%i==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
        printf("%d is not prime\n",n);
    else
        printf("%d is prime\n",n);
    
}