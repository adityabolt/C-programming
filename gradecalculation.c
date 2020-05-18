#include <stdio.h>
int main()
{
  int marks;
  printf("Enter marks\n");
  scanf("%d",&marks);
  if(marks>84)
    printf("Grade A");
  else if(marks>69)
    printf("Grade B");
  else if(marks>54)
    printf("Grade C");
  else if(marks>39)
    printf("Grade D");
  else
    printf("Grade F");
}
