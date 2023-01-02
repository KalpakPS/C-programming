//sorting numbers in array
#include<stdio.h>
void main()
{
    int a[10],i,j,temp=0,n;
    printf("Enter the limit:\n");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<(n-1);i++)
        for(j=0;j<(n-i-1);j++)
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;         
            }
    printf("The sorted array:\n");
    for(j=0;j<n;j++)
        printf("%d\n",a[j]);
            
}