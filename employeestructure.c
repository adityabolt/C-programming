#include <stdio.h>
#define MAXSIZE 20

typedef struct employee{
  int empno;
  int age;
  int salary;
  char empname[30];
  char deptname[30];
}EMPLOYEE;

int main()
{
  int i;
  EMPLOYEE a[MAXSIZE];//Maxsize can be changed according to the needs.
  for(i=0;i<MAXSIZE;i++){
    printf("Enter details of the Employee %d\n",i+1);
    printf("Enter name: ");
    scanf("%s",a[i].empname);
    printf("Enter deptname: ");
    scanf("%s",a[i].deptname);
    printf("Enter age: ");
    scanf("%d",&a[i].age);
    printf("Enter number: ");
    scanf("%d",&a[i].empno);
    printf("Enter salary: ");
    scanf("%d",&a[i].salary);
  }
  printf("Name\tAge\tPhone Number\tSalary\n");
  for(i=0;i<MAXSIZE;i++){
    printf("%s",a[i].empname);
    printf("\t%d",a[i].age);
    printf("\t%d",a[i].empno);
    printf("\t%d\n",a[i].salary);
}
}
