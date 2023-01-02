//To check whether a number is positive or not
#include<stdio.h>
void main()
{
    int a;
    printf("Enter the number to be checked{\n");
    scanf("%d",&a);
    if(a>0)
        printf("The number %d is positive\n",a);
    else
        printf("The number %d is not positive\n",a);

}