#include<stdio.h>
void main()
{
    int i,n,f,sum=0,dig,num;
    printf("Enter the number:\n");
    scanf("%d",&n);
    num=n;
    do
    {
        dig=n%10;
        for(f=1,i=1;i<=dig;i++)
        {
            f=f*i;
        }
        sum=sum+f;
        n=n/10;
        //for checking if correct
        printf("dig %d\t sum%d\n",dig,sum);
    }while(n>0);
    if(sum==num)
        printf("it is a strong number\n");
    else
        printf("it is not a strong number\n");
}