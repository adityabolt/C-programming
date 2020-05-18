#include <stdio.h>
int lcm(int n,int m,int k);
int main()
{
  int n,m,answer;
  printf("Enter two numbers ");
  scanf("%d%d",&n,&m);
  answer=(n>m)?lcm(n,m,n):lcm(n,m,m);
  printf("The lcm of %d and %d is %d",n,m,answer);
}
int lcm(int n,int m,int k)
{
  if(k%n==0 && k%m==0)
    return k;
  else
    return lcm(n,m,k+1);
}
