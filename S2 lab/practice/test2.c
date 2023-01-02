#include<stdio.h>
void main()
{
    int a[20],n,count,j,i,temp=0;
    printf("Enter the limit of array:");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Elements in the list are:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\n");
    for(i=0;i<n;i++)
    {
        temp=a[i];
        count=0;
        for(j=0;j<n;j++)
            if(temp==a[j])
                count++;
        printf("%d occurs %d time(s)",temp,count);
        printf("\n");
    }
}