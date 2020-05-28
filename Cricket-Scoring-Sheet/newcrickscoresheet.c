char filename[20],format[8],venue[20],team1[20],team2[20],c;
int toss,tosschoice;
FILE *ptr;
struct date{
  int mm,dd,yy;
}dom;

struct batsmen{
  char name[20];
  int runs,balls;
  float strikerate;
}team1bat[11],team2bat[11];

struct bowler{
  char name[20];
  int runs,overs,wickets;
  float runrate;
}team1bowl[8],team2bowl[8];

int createnewscoresheet(){
  Create_Filename:
  system("cls");
  printf("\n\tEnter new File name: ");
  scanf("%s",filename);
  char check[5];
  check[0]=filename[strlen(filename)-4];check[1]=filename[strlen(filename)-3];check[2]=filename[strlen(filename)-2];check[3]=filename[strlen(filename)-1];check[4]='\0';
  if(strcmp(check,".txt")!=0){
  strcat(filename,".txt");
  }
  if((ptr=fopen(filename,"r"))){
    printf("\a\n\tFile Name already exists,please try again!");
    Sleep(2);
    goto Create_Filename;
  }
  else
    ptr=fopen(filename,"w");
}

int scoresheetinput(){
  int i,n;
  printf("\n=================================================================");
  printf("\nCompetiton Format: ");scanf("%s",format);
  printf("Venue: ");scanf("%s",venue);
  printf("Date(dd/mm/yyyy): ");scanf("%2d/%2d/%4d",&dom.dd,&dom.mm,&dom.yy);
  printf("Team 1: ");scanf("%s",team1);
  printf("Team 2: ");scanf("%s",team2);
  Toss:
  printf("Toss won by \n1.)%s\n2.)%s\nEnter 1 or 2: ",team1,team2);c=getch();
  if(c!='1'&& c!='2'){
    printf("\nInvalid input try again");
    Sleep(2);
    goto Toss;
  }
  else
    toss=c-'0';
  Toss_Choice:
  printf("\nThey chose to \n1.)Bat\n2.)Bowl\nEnter 1 or 2: ");c=getch();
  if(c!='1'&& c!='2'){
    printf("\nInvalid input try again");
    Sleep(2);
    goto Toss_Choice;
  }
  else
    tosschoice=c-'0';
  fprintf(ptr,"%s %s %d/%d/%d %s %s %d %d\n",format,venue,dom.dd,dom.mm,dom.yy,team1,team2,toss,tosschoice);
  printf("\nEnter the number of batsmen who played for %s: ",team1);scanf("%d",&n);
  printf("\nEnter the Scorecard Below(seperated by spaces)");
  printf("\n%s\n\t\tBatsmen Name  Runs Scored  Balls Faced\n",team1);
  fprintf(ptr,"Batting\n");
  for(i=0;i<n;i++){
    printf("Batsmen %d: ",i+1);
    scanf("%s %d %d",team1bat[i].name,&team1bat[i].runs,&team1bat[i].balls);
    team1bat[i].strikerate=(team1bat[i].runs/(float)team1bat[i].balls)*100;
    fprintf(ptr,"%s %d %d %3.2f\n",team1bat[i].name,team1bat[i].runs,team1bat[i].balls,team1bat[i].strikerate);
  }
  printf("\nEnter the number of bowlers who bowled for %s: ",team1);scanf("%d",&n);
  printf("\nEnter the Scorecard Below(seperated by spaces)");
  printf("\n%s\n\tBowler Name  Runs conceded  Overs Bowled  Wickets Taken\n",team1);
  fprintf(ptr,"Bowling\n");
  for(i=0;i<n;i++){
    printf("Bowler %d: ",i+1);
    scanf("%s %d %d %d",team1bowl[i].name,&team1bowl[i].runs,&team1bowl[i].overs,&team1bowl[i].wickets);
    team1bowl[i].runrate=team1bowl[i].runs/(float)team1bowl[i].overs;
    fprintf(ptr,"%s %d %d %d %2.1f\n",team1bowl[i].name,team1bowl[i].runs,team1bowl[i].overs,team1bowl[i].wickets,team1bowl[i].runrate);
  }
//Now for team2
  fprintf(ptr,"Batting 2\n");
  printf("\nEnter the number of batsmen who played for %s: ",team2);scanf("%d",&n);
  printf("\nEnter the Scorecard Below(seperated by spaces)");
  printf("\n%s\n\tBatsmen Name  Runs Scored  Balls Faced\n",team2);
  for(i=0;i<n;i++){
    printf("Batsmen %d: ",i+1);
    scanf("%s %d %d",team2bat[i].name,&team2bat[i].runs,&team2bat[i].balls);
    team2bat[i].strikerate=(team2bat[i].runs/(float)team2bat[i].balls)*100;
    fprintf(ptr,"%s %d %d %3.2f\n",team2bat[i].name,team2bat[i].runs,team2bat[i].balls,team2bat[i].strikerate);
  }
  printf("\nEnter the number of bowlers who bowled for %s: ",team2);scanf("%d",&n);
  printf("\nEnter the Scorecard Below(seperated by spaces)");
  printf("\n%s\n\tBowler Name  Runs conceded  Overs Bowled  Wickets Taken\n",team2);
  fprintf(ptr,"Bowling 2\n");
  for(i=0;i<n;i++){
    printf("Bowler %d: ",i+1);
    scanf("%s %d %d %d",team2bowl[i].name,&team2bowl[i].runs,&team2bowl[i].overs,&team2bowl[i].wickets);
    team2bowl[i].runrate=team2bowl[i].runs/(float)team2bowl[i].overs;
    fprintf(ptr,"%s %d %d %d %2.1f\n",team2bowl[i].name,team2bowl[i].runs,team2bowl[i].overs,team2bowl[i].wickets,team2bowl[i].runrate);
  }
  fclose(ptr);
}
