#include<stdio.h>
int a[15],b[15],n;
void createheap();
void heapsort();
void main()
{
	  int item,i,j,k;
	  printf("enter aarray size\n");
	  scanf("%d",&n);
	  printf("Enter array elements\n");
	  for(i=1;i<=n;i++)
	  	scanf("%d",&a[i]);
	  createheap();
	  heapsort();	
	printf("\nSorted heap array\t");
	  	for(i=1;i<=n;i++)
	  	printf("%d\t",b[i]);				  
 
 }
 
 void createheap()
 {
 	int i=1,x,j,temp;
 	while(i<=n)
 		{
 			x=a[i];
 			b[i]=x;
 			j=i;
 			while(j>1)
 				{
 					if(b[j]>b[j/2])
 						{
 							temp=b[j];
 							b[j]=b[j/2];
 							b[j/2]=temp;
 							j=j/2;
 						}
 					else
 						j=1;
 				}
 			i++;
 		}
 		
 		printf("\nCreated heap array\t");
	  	for(i=1;i<=n;i++)
	  	printf("%d\t",b[i]);				
 }	
 
 void heapsort()
 {
 	int i=n,j,lc,rc,temp,p;
 	while(i>1)
 		{
 			temp=b[1];
 			b[1]=b[i];
 			b[i]=temp;
 			i--;
 			j=1;
 			printf("\nafter swapping\t");
	  				for(p=1;p<=n;p++)
	  					printf("%d\t",b[p]);
 			while(j<=i)
 				{
 					lc=2*j;
 					rc=2*j+1;
 					if(rc>i)
 						break;
 					else
 					{
	 					if(b[j]<b[lc] && b[lc]>b[rc])
	 						{
	 							
					 			temp=b[j];
					 			b[j]=b[lc];
					 			b[lc]=temp;
					 			j=lc;
					 		}
					 	else if(b[j]<b[rc] && b[lc]<b[rc])
	 						{
	 							
					 			temp=b[j];
					 			b[j]=b[rc];
					 			b[rc]=temp;
					 			j=rc;
					 		}
				 			
				 			
				 		else
							break;
					}
				 	printf("\n\ti=%d\n",i);				  
				 }
				 	printf("\nSorted heap array\t");
	  				for(p=1;p<=n;p++)
	  					printf("%d\t",b[p]);				  
 
		}
}