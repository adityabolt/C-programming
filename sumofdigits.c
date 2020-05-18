#include <stdio.h>
int sumofdigits(int n);
int main()
{
  int n,sum;
  printf("Enter a number ");
  scanf("%d",&n);
  sum=sumofdigits(n);
  printf("The sum of the digits is %d",sum);
}
int sumofdigits(int n)
{
  if(n==0)
    return n;
  else
    return (n%10)+sumofdigits(n/10);
}
