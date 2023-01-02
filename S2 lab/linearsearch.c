//Kalpak P S, Rollno:30, 11-10-22
//to search an element in an array
#include<stdio.h>
void main()
{
    int a[10],n,i,key,flag=0;
    printf("Enter the limit:\n");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the element to be searched:\n");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            flag=1;
                break;
        }
    }
    if(flag==1)
        printf("The element %d is in position %d\n",key,i+1);
    else
        printf("The element %d do not present in the array\n",key);
}