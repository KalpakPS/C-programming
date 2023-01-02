//to display fibonacci series upto n
#include<stdio.h>
void main()
{
    int a=0,b=1,c,n,i;
    printf("Enter the number:\n");
    scanf("%d",&n);
    c=a+b;
    printf("The fibonacci series is:\n");
    printf("%d\t%d\t",a,b);
    do
    {
        printf("%d\t",c);
        a=b;
        b=c;
        c=a+b;
    }while(c<n);
}