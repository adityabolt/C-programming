#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#include"newcrickscoresheet.h"
#include"readscoresheet.h"

void main()
{
    printf("\n\n\t\t\t\t\tMENU:\n");
    printf("\n\n\n\t\t\t\t1.New scoresheet:\n");
    printf("\t\t\t\t2.View scoresheet:\n");
    printf("\t\t\t\t3.Exit:\n\t\t");
    printf("\n\tEnter you choice: ");
    char ch=getch();
    while(ch!='1' && ch!='2' && ch!='3'){
      printf("\a");
      ch=getch();
    }
    switch(ch)
    {
        case '1':createnewscoresheet();scoresheetinput();break;
        case '2':openscoresheet();break;
        case '3':
        system ("cls");
        exit(0);
    }
}
