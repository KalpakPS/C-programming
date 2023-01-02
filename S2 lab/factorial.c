//to find the factorial of the number
#include<stdio.h>
void main()
{
    int n,i;
    long int f;
    printf("Enter the number:\n");
    scanf("%d",&n);
    for(i=1,f=1;i<n;i++)
        f=f*i;
    printf("The factorial of the number %d = %ld\n",n,f);
}