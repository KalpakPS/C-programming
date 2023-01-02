#include<stdio.h>
void main()
{
    int a[20],i,key,flag=0,n;
    printf("Enter the limit:\n");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the element to search:\n");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(key==a[i])
        {
            printf("The number %d is at position %d\n",key,i+1);
            flag=1;
        }
    }
    if(flag==0)
    {
        a[n]=key;
        printf("The number %d dosen't present in array and is been added to position %d\n",key,n+1);
        printf("The elements are:\n");
        for(i=0;i<=n;i++)
            printf("%d\t",a[i]);
    }    
    
}