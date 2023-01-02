#include<stdio.h>
int add(int a,int b)
{
    int s;
    s=a+b;
    return s;
}
int sub(int a,int b)
{
    int s;
    s=a-b;
    return s;
}
void main()
{
    int a,b;
    printf("Enter 2 num:\n");
    scanf("%d%d",&a,&b);
    printf("add= %d\n",add(a,b));
    printf("sub= %d\n",sub(a,b));
}