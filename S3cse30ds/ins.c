//sorting using insertin sort
#include<stdio.h>
void main()
{
	int i,n,temp,a[20],j,k;
	printf("Enter the limit:\n");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Entered elements are:\t");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
	for(i=1;i<n;i++)
	{
		temp=a[i];
		j=i-1;
		while(j>=0&&a[j]>temp)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=temp;
		printf("\narray after iteration %d:\t",i);
		for(k=0;k<n;k++)
			printf("%d\t",a[k]);
		
	}
	printf("\n");
}
