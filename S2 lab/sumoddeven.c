//Sum of odd and even numbers upto n
#include<stdio.h>
void main()
{
    int i=1,n,sum1=0,sum2=0;
    printf("Enter the number:\n");
    scanf("%d",&n);
    while (i<n)
    {
        if(i%2==0)
            sum1=sum1+i;
        else
            sum2=sum2+i;
        i++;
    }
    printf("The sum of even numbers is %d\n",sum1);
    printf("The sum of odd numbers is %d\n",sum2);
    
}