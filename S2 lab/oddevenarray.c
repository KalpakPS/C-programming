//to seperate odd and even numbers present in an array into seperate arrays
#include<stdio.h>
void main()
{
    int a[10],n,o[10],e[10],i,j=0,k=0;
    printf("Enter the limit of the array:\n");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        if(a[i]%2==0)
        {    
            e[j]=a[i];
            j++;
        }
        else
        {
            o[k]=a[i];
            k++;
        }
    }
    printf("Inputted elements:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\n");
    printf("The even numbers in the array are:\n");
    for(i=0;i<j;i++)
        printf("%d\t",e[i]);
    printf("\n");
    printf("The odd numbers in the array are:\n");
    for(i=0;i<k;i++)
        printf("%d\t",o[i]);
}