#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<string.h>

int menu();
int checkacc();
int delacc();
int updateacc();
int menuchoice();

int choice,age;
char username[20],password[10],usr[20],pass[10],name[20],line[140],lineread[140];
unsigned long long phoneno;unsigned long money;

struct date{
  int dd,mm,yy;
}dob;

int menuchoice(){
  printf("\n\nEnter 1 to go back to the main menu or enter 0 to exit: ");
  scanf("%d",&choice);
  if(choice==1){
    menu();
    return 0;
  }
  else if(choice==0){
    system("cls");
    printf("\n\n\n\n\tThis C Project is developed by Aditya!");
    return 0;
  }
  else{
    printf("\nInvalid Choice,try again");
    menuchoice();
    return 0;
  }
}

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

int changedetails(){
  printf("\n\tEnter 1 for yes or 0 for no: ");
  scanf("%d",&choice);
  if(choice==1){
    printf("Change it to: ");
    return 1;
  }
  else if(choice==0)
    return 0;
  else{
    printf("\nInvalid Input,try again!");
    changedetails();
  }
}

int updateacc(){
  checkacc();
  FILE *ptr=fopen("userrecord.dat","r");
  FILE *tempptr=fopen("newfile.dat","w");
  printf("\n\n\t\tSet a new Password? ");
  if(changedetails()) scanf("%s",password);
  printf("\n\n\t\tChange name? ");
  if(changedetails()) scanf("%s",name);
  printf("\n\n\t\tChange age? ");
  if(changedetails()) scanf("%d",&age);
  printf("\n\n\t\tChange phone no? ");
  if(changedetails()) scanf("%llu",&phoneno);
  sprintf(line,"%s %s %s %lu %d %d/%d/%d %llu\n",username,password,name,money,age,dob.dd,dob.mm,dob.yy,phoneno);
  while(fgets(lineread,140,ptr)) {
    sscanf(lineread,"%s",usr);
    if(strcmp(usr,username)==0)
      fputs(line,tempptr);
    else
      fputs(lineread,tempptr);
  }
  fclose(ptr);fclose(tempptr);
  remove("userrecord.dat");
  rename("newfile.dat","userrecord.dat");
}

int delacc(){
  FILE *ptr=fopen("userrecord.dat","r");
  FILE *tempptr=fopen("newfile.dat","w");
  printf("\t\t\t\aAre you sure you want to close this bank account?\a");
  printf("\n\nEnter 1 to delete this account permanently or enter anything else to return to main menu: ");
  scanf("%d",&choice);
  if(choice==1){
  while(fgets(lineread,140,ptr)) {
    sscanf(lineread,"%s",usr);
    if(strcmp(usr,username)==0)
      continue;
    else
      fputs(lineread,tempptr);
  }
    fclose(ptr);fclose(tempptr);
    remove("userrecord.dat");
    rename("newfile.dat","userrecord.dat");
}
  else{
    menu();
    return 0;
  }
}
int checkacc(){
  sscanf(line,"%s %s %s %lu %d %d/%d/%d %llu",username,password,name,&money,&age,&dob.dd,&dob.mm,&dob.yy,&phoneno);
  return 0;
}

int transact(){
  unsigned long newamt;
  FILE *ptr=fopen("userrecord.dat","r");
  FILE *tempptr=fopen("newfile.dat","w");
  Transact_page:
  system("cls");
  printf("\n\t\t------------------Transaction Page------------------");
  printf("\n\t\tDo you want to\n\t\t1.Deposit\n\t\t2.Withdraw\n\nEnter your choice: ");
  scanf("%d",&choice);
  if(choice==1){
    printf("\n\t\tEnter the amount you want to deposit:$ ");
    scanf("%lu",&newamt);
    money+=newamt;
  }
  else if(choice==2){
    printf("\n\t\tEnter the amount you want to withdraw:$ ");
    scanf("%lu",&newamt);
    if(newamt>money){
      printf("\nAccount doesn't have sufficient balance");
      fclose(ptr);fclose(tempptr);
      menuchoice();
      return 0;
    }
    else
      money-=newamt;
  }
  else{
    printf("\nWrong Choice,Please try again");
    fordelay(100000000);
    goto Transact_page;
  }
  sprintf(line,"%s %s %s %lu %d %d/%d/%d %llu\n",username,password,name,money,age,dob.dd,dob.mm,dob.yy,phoneno);
  while(fgets(lineread,140,ptr)) {
    sscanf(lineread,"%s",usr);
    if(strcmp(usr,username)==0)
      fputs(line,tempptr);
    else
      fputs(lineread,tempptr);
  }
    fclose(ptr);fclose(tempptr);
    remove("userrecord.dat");
    rename("newfile.dat","userrecord.dat");
}

int registration(){
  FILE *ptr=fopen("userrecord.dat","r");
  FILE *changes=fopen("userrecord.dat","a+");
  system("cls");
  printf("\n\t\t------------------Registration Page------------------");
  printf("\n\n\t\tEnter the Username:");
  scanf("%s",username);
  while(fgets(lineread,140,ptr)) {
    sscanf(lineread,"%s",usr);
    if(strcmp(usr,username)==0){
      printf("\n\t\tUsername already exists,Please enter another one");
      fordelay(1000000000);
      registration();
      return 0;
    }
}
  printf("\n\n\t\tSet a Password:");
  scanf("%s",password);
  printf("\n\n\t\tEnter a name:");
  scanf("%s",name);
  printf("\n\n\t\tEnter initial deposit amount:$ ");
  scanf("%lu",&money);
  printf("\n\n\t\tEnter a age:");
  scanf("%d",&age);
  printf("\n\n\t\tEnter dob in dd/mm/yyyy:");
  scanf("%2d/%2d/%4d",&dob.dd,&dob.mm,&dob.yy);
  printf("\n\n\t\tEnter phone no:");
  scanf("%llu",&phoneno);
  sprintf(line,"%s %s %s %lu %d %d/%d/%d %llu\n",username,password,name,money,age,dob.dd,dob.mm,dob.yy,phoneno);
  fputs(line,changes);
  fclose(ptr);fclose(changes);
  printf("\nThank you! for registering, your changes will be active on your next login.\n");
}

int login(){
  FILE *ptr=fopen("userrecord.dat","r");
  system("cls");
  printf("\n\t\t------------------Login Page------------------");
  printf("\n\n\t\tEnter the Username:");
  scanf("%s",username);
  int check=0;
  while(fgets(lineread,140,ptr)) {
    sscanf(lineread,"%s %s",usr,pass);
    if(strcmp(usr,username)==0){
      strcpy(line,lineread);
      check=1;break;
    }
  }
  fclose(ptr);
  if(check==0){
    printf("\n\n\tUsername not found in the database! Please try again");
    fordelay(1000000000);
    login();
    return 0;
  }
  printf("\n\n\t\tEnter the password:");
  int i=0;
  do
  {
  password[i]=getch();
  if (password[i]!=13&&password[i]!=8)
      {
          printf("*");
          i++;
          continue;
      }
  else if(password[i]==8){
    if(i>0){
    printf("\b \b");
    i--;}
  }
}while (password[i]!=13);
  password[i]='\0';
  if (strcmp(pass,password)==0){
      printf("\n\nPassword Match!\nLOADING");
      for(i=0;i<=6;i++)
      {
          fordelay(100000000);
          printf(".");
      }
          system("cls");
          menu();
      }
  else
      {   printf("\n\nWrong password!!\a\a\a");
          login_try:
          printf("\nEnter 1 to try again or enter 0 to exit:");
          scanf("%d",&choice);
          if (choice==1)
                  {
                      system("cls");
                      login();
                      return 0;
                  }
          else if (choice==0)
                  {
                  system("cls");
                  printf("\n\n\n\nThis C Project is developed by Aditya!");}
          else
                  {printf("\nInvalid!");
                  fordelay(1000000000);
                  system("cls");
                  goto login_try;}
      }
      return 0;
}

int menu(){
      Choice_Screen2:
      system("cls");
      system("color 9");
      printf("\n\n\t\t\t\tABC BANKING SYSTEM");
      printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
      printf("\n\n\t\t1.Carry out a transaction\n\t\t2.Update information of existing account\n\t\t3.Check Account Details\n\t\t4.Delete Account\n\t\t5.Exit\n\n\n\n\n\t\t Enter your choice:");
      scanf("%d",&choice);
      system("cls");
      checkacc();
      switch(choice)
      {
          case 1:transact();menuchoice();break;
          case 2:updateacc();menuchoice();break;
          case 3:checkacc();
          printf("Username:%s\nName:%s\nAge:%d\nDOB: %d/%d/%d\nPhone no:%llu\nAccount Balance:$ %lu",username,name,age,dob.dd,dob.mm,dob.yy,phoneno,money);
          menuchoice();break;
          case 4:delacc();break;
          case 5:printf("\n\n\n\nThis C Project is developed by Aditya!");break;
          default:printf("\n\t\t\tInvalid Input,try again!");
          fordelay(1000000000);
          goto Choice_Screen2;
      }
  }

int main()
{
    int i=0;
    Choice_Screen:
    printf("\n\n\t\t\tWelcome to ABC Bank");
    printf("\n\n\t\t1)Create a new account");
    printf("\n\n\t\t2)Login using an existing account");
    printf("\nEnter 1 or 2 to choose your selected preference: ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
              registration();break;
      case 2:
              login();break;
      default:
              printf("Wrong choice Please try again");
              system("cls");
              goto Choice_Screen;
    }
        return 0;
}
