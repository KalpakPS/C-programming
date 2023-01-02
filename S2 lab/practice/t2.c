#include<stdio.h>
int fact()
{
    int n,f,i;
    printf("Enter the number:\n");
    scanf("%d",&n);
    for(i=1,f=1;i<=n;i++)
    {
        f=f*i;
    }
    return f;    
}
void main()
{
    int f;
    f=fact();
    printf("Factoral is %d",f);
}
