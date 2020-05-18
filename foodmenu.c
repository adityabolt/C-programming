#include <stdio.h>
int main()
{
  int choice;
  printf("Enter a number\n");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:printf("Food item - Sandwich\nPrice - Rs149\n");break;
    case 2:printf("Food item - French Fries\nPrice - Rs99\n");break;
    case 3:printf("Food item - Burger\nPrice - Rs129\n");break;
    case 4:printf("Food item - Pizza\nPrice - Rs239\n");break;
    case 5:printf("Food item - Pasta\nPrice - Rs179\n");break;
    default:printf("Invalid Input");
  }
}
