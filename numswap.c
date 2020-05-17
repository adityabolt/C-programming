#include<stdio.h>

int main()
{
    int a,b;
    printf("Enter values of a and b\na= ");
    scanf("%d",&a);
    printf ("b= ");
    scanf("%d",&b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("The new values of a and b are:\na= %d\nb= %d",a,b);
    return 0;
}
