//To find area and perimeter of a circle
#include<stdio.h>
void main()
{
    int r;
    float area,peri;
    printf("Enter the radius of the circle:\n");
    scanf("%d",&r);
    area=3.14*r*r;
    peri=2*3.14*r;
    printf("The area of the circle is %.2f\nThe perimeter of the circle is %.2f\n",area,peri);
}
