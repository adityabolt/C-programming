char filename[20],format[8],venue[20],team1[20],team2[20],c;
int toss,tosschoice;
FILE *ptr;
struct date2{
  int mm,dd,yy;
}dom2;

struct batsmen2{
  char name[20];
  int runs,balls;
  float strikerate;
}team1bat1[11],team2bat1[11];

struct bowler2{
  char name[20];
  int runs,overs,wickets;
  float runrate;
}team1bowl1[8],team2bowl2[8];

int readsheet();
int openscoresheet(){
  Open_Filename:
  system("cls");
  printf("\n\tEnter File name: ");
  scanf("%s",filename);
  char check[5];
  check[0]=filename[strlen(filename)-4];check[1]=filename[strlen(filename)-3];check[2]=filename[strlen(filename)-2];check[3]=filename[strlen(filename)-1];check[4]='\0';
  if(strcmp(check,".txt")!=0){
  strcat(filename,".txt");
  }
  if((ptr=fopen(filename,"r"))){
    readsheet();
  }
  else{
    printf("\a\n\tFile Name doesn't exist,please try again!");
    Sleep(2);
    goto Open_Filename;
  }
}

int readsheet(){
  int i=0,n=0,m=0,score1=0,score2=0;
  system("color 3");
  system("cls");
  char line[100];
  fgets(line,sizeof(line),ptr);
  sscanf(line,"%s %s %d/%d/%d %s %s %d %d",format,venue,&dom2.dd,&dom2.mm,&dom2.yy,team1,team2,&toss,&tosschoice);
  printf("====================================================================================================");
  printf("\n\tFormat: %s\tDate: %d/%d/%d",format,dom2.dd,dom2.mm,dom2.yy);
  printf("\n\t\tVenue: %s\t",venue);
  printf("\n\t%s vs %s",team1,team2);
  if(toss==1)
    printf("\t%s has won the toss and has elected to %s first.",team1,(tosschoice==1)?"bat":"field");
  else
    printf("\t%s has won the toss and has elected to %s first.",team2,(tosschoice==1)?"bat":"field");
  printf("\n====================================================================================================");
  fgets(line,sizeof(line),ptr);fgets(line,sizeof(line),ptr);
  printf("\n\t\t\t\t\t%s\n",team1);
  while(strcmp(line,"Bowling\n")!=0){
    sscanf(line,"%s %d %d %f",team1bat1[i].name,&team1bat1[i].runs,&team1bat1[i].balls,&team1bat1[i].strikerate);
    fgets(line,sizeof(line),ptr);
    score1+=team1bat1[i].runs;
    i++;n++;
  }
  i=0;fgets(line,sizeof(line),ptr);
  while(strcmp(line,"Batting 2\n")!=0){
    sscanf(line,"%s %d %d %d %f",team1bowl1[i].name,&team1bowl1[i].runs,&team1bowl1[i].overs,&team1bowl1[i].wickets,&team2bowl2[i].runrate);
    fgets(line,sizeof(line),ptr);
    i++;m++;
  }
  printf("\t\tBatting\t\t\t  \t\t\t\tBowling\t\t\n");
  printf("Name\t\tRuns\tBalls Faced\tStrike Rate\tName\t\tRuns Conceded\tOvers Bowled\tWickets Taken\tRun rate");
  i=0;
  while(i<=11){
    if(i<n)
    printf("\n%10s\t%d\t%d\t\t%3.2f",team1bat1[i].name,team1bat1[i].runs,team1bat1[i].balls,team1bat1[i].strikerate);
    if(i<m)
    printf("\t\t%s\t%d\t\t%d\t\t%d\t\t%2.1f",team1bowl1[i].name,team1bowl1[i].runs,team1bowl1[i].overs,team1bowl1[i].wickets,team2bowl2[i].runrate);
    i++;
  }
  printf("\n====================================================================================================");
  //team2
  n=0;m=0;i=0;fgets(line,sizeof(line),ptr);
  printf("\n\t\t\t\t\t%s\n",team2);
  while(strcmp(line,"Bowling 2\n")!=0){
    sscanf(line,"%s %d %d %f",team2bat1[i].name,&team2bat1[i].runs,&team2bat1[i].balls,&team2bat1[i].strikerate);
    fgets(line,sizeof(line),ptr);
    score2+=team2bat1[i].runs;
    i++;n++;
  }
  i=0;
  while(fgets(line,sizeof(line),ptr)){
    sscanf(line,"%s %d %d %d %f",team2bowl2[i].name,&team2bowl2[i].runs,&team2bowl2[i].overs,&team2bowl2[i].wickets,&team2bowl2[i].runrate);
    i++;m++;
  }
  printf("\t\tBatting\t\t\t  \t\t\t\tBowling\t\t\n");
  printf("Name\t\tRuns\tBalls Faced\tStrike Rate\tName\t\tRuns Conceded\tOvers Bowled\tWickets Taken\tRun rate");
  i=0;
  while(i<=11){
    if(i<n)
    printf("\n%10s\t%d\t%d\t\t%3.2f",team2bat1[i].name,team2bat1[i].runs,team2bat1[i].balls,team2bat1[i].strikerate);
    if(i<m)
    printf("\t\t%s\t%d\t\t%d\t\t%d\t\t%2.1f",team2bowl2[i].name,team2bowl2[i].runs,team2bowl2[i].overs,team2bowl2[i].wickets,team2bowl2[i].runrate);
    i++;
  }
  printf("\n====================================================================================================");
  if(score1>score2) printf("\n\t\t%s beats %s by %d runs.",team1,team2,(score1-score2));
  else if(score1==score2) printf("\n\t\tScores are level,Match is tied.");
  else printf("\n\t\t%s beats %s by %d runs.",team2,team1,(score2-score1));
  fclose(ptr);
}
