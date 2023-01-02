//To check whether a number os odd or even
#include<stdio.h>
void main()
{
    int a;
    printf("Enter the number to be checked:\n");
    scanf("%d",&a);
    if(a%2==0)
        printf("The number %d is even\n",a);
    else
        printf("The number %d is odd\n",a);
}