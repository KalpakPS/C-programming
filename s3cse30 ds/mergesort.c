//sort array using merge sort
#include<stdio.h>
int a[20],c[20],n,q=1;
void msort(int,int);
void merge(int,int,int);
void main()
{
	int i;
	printf("Enter the limit:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	msort(0,n-1);
	printf("\nArray after sorting: ");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}
void msort(int l,int r)
{
	int mid;
	//mid=(l+r)/2;	
	if(l>=r)
		return;
	else
	{
		mid=(l+r)/2;
		msort(l,mid);
		msort(mid+1,r);
		merge(l,mid,r);
	}
}
void merge(int l,int mid,int r)
{
	int i=l,j=mid+1,k=l,m,t;
	while(i<=mid&&j<=r)
	{
		if(a[i]<a[j])
		{
			c[k]=a[i];
			k++;
			i++;
		}
		else
		{
			c[k]=a[j];
			k++;
			j++;
		}
	}
	while(i<=mid)
	{
		c[k]=a[i];
		k++;
		i++;
	}
	while(j<=r)
	{
		c[k]=a[j];
		k++;
		j++;
	}
	printf("\nAfter iteration %d:\n",q++);
	for(m=l;m<k;m++)
		a[m]=c[m];
	for(t=0;t<n;t++)
		printf("%d\t",a[t]);
}
