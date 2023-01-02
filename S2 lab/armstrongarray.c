//to display armstrong numbers present in an array
#include<stdio.h>
void main()
{
    int n,n2,i,sum=0,a[10],dig=0;
    printf("Enter the limit of the array:\n");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("The armstrong numbers in the array are:\n");
    for(i=0;i<n;i++)
    {
        n2=a[i];
        sum=0;
        while(n2>0)
        {
            dig=n2%10;
            sum=sum+(dig*dig*dig);
            n2=n2/10;
        }
        if(a[i]==sum)
            printf("%d\n",sum);
    }

}