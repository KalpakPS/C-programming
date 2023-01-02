#include<stdio.h>
void main()
{
    int a[10][10],i,j,m,n;
    printf("Enter the order of matrix:\n");
    scanf("%d%d",&m,&n);
    printf("Enter the elements:\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    printf("The matrix is:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }
    printf("Transpose of the matrix is:\n");
    for(i=0;i<m;i++)
    {
        
        for(j=0;j<n;j++)
            printf("%d\t",a[j][i]);
        printf("\n");
    }
        
}