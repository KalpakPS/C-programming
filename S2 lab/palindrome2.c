//palindrome checking
#include<stdio.h>
void main()
{
    int n,temp,dig,rev=0;
    printf("Enter a number:\n");
    scanf("%d",&n);
    temp=n;
    //for understanding the working
    printf("dig\trev\tn\n");
    while (n>0)
    {
        dig=n%10;
        rev=(rev*10)+dig;
        n=n/10;
        //for understanding the working
        printf("%d\t%d\t%d\n",dig,rev,n);
    }
    if(temp==rev)
        printf("The number %d is palindrome",temp);
    else  
        printf("The number %d is not palindrome",temp);
    
}