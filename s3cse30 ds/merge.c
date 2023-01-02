//merging of 2 arrays
#include<stdio.h>
void main()
{
	int a[20],b[20],c[40],n,m,i,j,k,p;
	printf("Enter the limit of array 1:");
	scanf("%d",&n);
	printf("Enter the elements of array 1:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the limit of array 2:");
	scanf("%d",&m);
	printf("Enter the elements of array 2:\n");
	for(j=0;j<m;j++)
		scanf("%d",&b[j]);
	printf("Array 1:\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
	printf("Array 2:\n");	
	for(j=0;j<m;j++)
		printf("%d\t",b[j]);
	printf("\n");
	i=0,j=0,k=0;
	while(i<n&&j<m)
	{
		if(a[i]<b[j])
		{
			c[k]=a[i];
			k++;i++;
		}
		else if(a[i]>b[j])
		{
			c[k]=b[j];
			k++;j++;
		}
		else
		{
			c[k]=a[i];
			k++;i++;
		}
	}
	while(i<n)
	{
		c[k]=a[i];
		k++;i++;
	}
	while(j<m)
	{
		c[k]=b[j];
		k++;j++;
	}
	p=k;
	printf("Merged Array:\n");
	for(k=0;k<p;k++)
		printf("%d\t",c[k]);
	printf("\n");
}
