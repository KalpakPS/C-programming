//To find the largest number amongst 3
#include<stdio.h>
void main()
{
    int a,b,c;
    printf("Enter 3 numbers\n");
    scanf("%d%d%d",&a,&b,&c);
    if(a>b)
    {
        if(a>c)
            printf("%d is the largest",a);
        else
            printf("%d is the largest",c);
    }
    else
    {
        if(b>c)
            printf("%d is the largest",b);
        else
            printf("%d is the largest",c);
    }
}