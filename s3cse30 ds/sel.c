//Kalpak P S, Rollno:30, 11-10-22
//sort elements using selection sort
#include<stdio.h>
void main()
{
	int n,i,j,temp=0,a[20],k;
	printf("Enter the limit:\n");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;			
			}
		}
		printf("\n");
		printf("Array after iteration %d:\t",i+1);
		for(k=0;k<n;k++)
			printf("%d\t",a[k]);
	}
	printf("\nArray after sorting:");
	for(k=0;k<n;k++)
		printf("%d\t",a[k]);
}
