//To check whether a 3 digit number is palindrome or not
#include<stdio.h>
void main()
{
    int a;
    printf("Enter the 3 digit number:\n");
    scanf("%d",&a);
    if(a%10==a/100)
        printf("The number %d is palindrome\n",a);
    else
        printf("the number %d is not palindrome\n",a);
        
}