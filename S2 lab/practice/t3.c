#include<stdio.h>

void search()
{
    int i,key,n,a[15],flag=0;
    printf("Enter the limit:\n");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the element to search:\n");
    scanf("%d",&key);
    for(i=0;i<n;i++)
        if(a[i]==key)
        {
            flag=1;
            break;
        }
    if(flag==1)
        printf("%d is at pos:%d\n",key,i+1);
    else
        printf("%d dosent exist in array\n",key);
}
void main()
{
    search();
}