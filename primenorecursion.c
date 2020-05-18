#include <stdio.h>
int isPrime(int n,int k);
int main()
{
  int n;
  printf("Enter a number ");
  scanf("%d",&n);
  if(isPrime(n,2)==1)
    printf("%d is a prime number",n);
  else
    printf("%d is not a prime number",n);
}
int isPrime(int n,int k)
{
  if(n==k)
    return 1;
  else if(n%k==0)
    return 0;
  return isPrime(n,k+1);
}
