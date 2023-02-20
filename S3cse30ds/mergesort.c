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
void msort(int left,int right)
{
	int mid;
	if(left>=right)
		return;
	else
	{
		mid=(left+right)/2;
		msort(left,mid);
		msort(mid+1,right);
		merge(left,mid,right);
	}
}
void merge(int left,int mid,int right)
{
	int i=left,j=mid+1,k=left,m,t;
	while(i<=mid&&j<=right)
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
	while(j<=right)
	{
		c[k]=a[j];
		k++;
		j++;
	}
	printf("\nAfter iteration %d:",q++);
	for(m=left;m<k;m++)
		a[m]=c[m];
	for(t=0;t<n;t++)
		printf("%d\t",a[t]);
}

/*
CHAT GPT-demonstrate recursion in this

Sure, let's use the following example array: [4, 7, 2, 8, 1, 9, 5]

First, the function msort is called with the indices 0 and 6 (the left and 
right indices of the array).It calculates the middle index as 3 and calls 
itself with the indices 0 and 3, and again with the indices 4and 6.

The first call to msort with the indices 0 and 3 calculates the middle 
index as 1 and calls itself with the indices 0 and 1, and again with 
the indices 2 and 3.

The first call to msort with the indices 0 and 1 calculates the middle 
index as 0 and returns, as the left index is now greater than or equal 
to the right index.

The second call to msort with the indices 2 and 3 calculates the middle 
index as 2 and returns, as the left index is now greater than or equal to 
the right index.

Now, the first call to msort with the indices 0 and 3 has returned, so 
it calls the function merge with the indices 0, 1, and 3. The function 
compares the values at indices 0 and 2 and adds the smaller value (4) to c. 
It then compares the values at indices 1 and 2 and adds the smaller value (2) 
to c. It then copies the remaining value (7) into c. The values in c are then 
copied back into the original array, which now looks like this: 
[2, 4, 7, 8, 1, 9, 5]

The second call to msort with the indices 4 and 6 calculates the middle index 
as 5 and calls itself with the indices 4 and 5, and again with the indices 6 
and 6.

The first call to msort with the indices 4 and 5 calculates the middle index 
as 4 and returns, as the left index is now greater than or equal to the 
right index.

The second call to msort with the indices 6 and 6 calculates the middle 
index as 6 and returns, as the left index is now greater than or equal 
to the right index.

Now, the second call to msort with the indices 4 and 6 has returned, so 
it calls the function merge with the indices 4, 5, and 6. The function 
compares the values at indices 4 and 5 and adds the smaller value (1) to 
c. It then copies the remaining value (9) into c. The values in c are 
then copied back into the original array, which now looks like this: 
[2, 4, 7, 1, 8, 9, 5]

Finally, the original call to msort with the indices 0 and 6 has returned,
so it calls the function merge with the indices 0, 3, and 6. The function 
compares the values at indices 0 and 4 and adds the smaller value (2) to 
c. It then compares the values at indices 1 and 4 and adds the smaller 
value (4) to c. It continues this process until all values in the left 
and right halves of the array have been compared and added to c. The 
values in c are then copied back into the original array, which is now 
fully sorted: [1, 2, 4, 5, 7, 8, 9]

This is an example of how recursion works in this code, with the 
function calling itself with different parameters until the base case 
(left index greater than or equal to right index) is reached, at which 
point it returns and the process works its way back up the chain of 
function calls.

*/