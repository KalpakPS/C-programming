//find element using binary search
#include<stdio.h>
void main()
{
	int i,n,key,a[20],low,high,mid;
	printf("Enter the limit:\n");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the element to search:");
	scanf("%d",&key);
	low=0;
	high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(key==a[mid])
		{
			printf("The element %d found at position %d\n",key,mid+1);
			break;
		}
		else if(key<a[mid])
			high=mid-1;
		else
			low=mid+1;	
	}
	if(key!=a[mid])
		printf("Element not found!\n");
}
