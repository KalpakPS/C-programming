//sort array using quick sort
#include<stdio.h>
int a[20],c[20],n,q=1;
void quicksort(int,int);
int partition(int,int);
void main()
{
	int i;
	printf("Enter the limit:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	quicksort(0,n-1);
	printf("\nArray after sorting:\t");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}
void quicksort(int low,int high)
{
	int i,p;
	if(low<high)
	{
		p=partition(low,high);
		quicksort(low,p);
		quicksort(p+1,high);
	}
}
int partition(int low,int high)
{
	int i,piv,temp;
	piv=low;
	while(low<high)
	{
		while(a[piv]<=a[high]&&piv<high)
			high=high-1;
		if(a[piv]>a[high])
		{
			temp=a[piv];
			a[piv]=a[high];
			a[high]=temp;
			piv=high;
			low=low+1;
		}
		while(a[piv]>=a[low]&&piv>low)
			low=low+1;
		if(a[piv]<a[low])
		{	
			temp=a[piv];
			a[piv]=a[low];
			a[low]=temp;
			piv=low;
			high=high-1;
		}
		printf("\nAfter iteration %d:\t",q++);
		for(i=0;i<n;i++)
			printf("%d\t",a[i]);
		return piv;	
	}

	
}
