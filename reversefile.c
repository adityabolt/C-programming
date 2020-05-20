#include <stdio.h>
#include <conio.h>
#include <string.h>
int main()
{
  FILE *f1;
  char str[100];
  int i=0;
  f1=fopen("readthisfile.txt","r");//Your file should be in the same directory
  fscanf(f1, "%[^\n]", str);
  fclose(f1);
  FILE *f2=fopen("output.txt","w+");
  for(i=strlen(str);i>=0;i--){
    fputc((int)str[i],f2);
  }
  fclose(f2);
  return 0;
}
