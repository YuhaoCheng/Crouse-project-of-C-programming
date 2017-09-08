#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 81

int strCount(char []); 
struct student
{  char id[SIZE];
   int score;
   int time;
};
void starttest(int *,int *);
void check(FILE *,char[]);
int main()
{ struct student date;
  FILE *fp;
  char ID[81];
  char *string;
  int  score=0,use=0;
  //int d=1;
  
  fp=fopen("record.txt","r");
  char b;
   char c='y';
     int i=0,a=0;
  printf("Please type in your ID number\n");
  gets(date.id);
  i=strCount(date.id);
  if(i>6)
    a=0;
  else
   { if('a'<=date.id[0]&&date.id[0]<='z'||'A'<=date.id[0]&&date.id[0]<='Z')
      {
        if('a'<=date.id[1]&&date.id[1]<='z'||'A'<=date.id[1]&&date.id[1]<='Z')
         { 
                 for(i=2;i<4;i++)
                  {   if('0'<=date.id[i]&&date.id[i]<='9')
                            a=1; 
                      else                 
                            a=0; 
                                        }                                           
         }
      }  
    }
    while(a==0)
  {  printf("The ID number is wrong.Please type in a new one.\n");
     printf("If you  want to contine,please type in 'Y'.\n");
     printf("If you don't want to contine,please type in 'N'.\n");
     c=getchar();
     getchar();
     if(c=='N')
      { break;}
     printf("Please type in a new one.\n");  
     gets(date.id);
     i=strCount(date.id);
     if(i>6)
         a=0;
     else
         if('a'<=date.id[0]&&date.id[0]<='z'||'A'<=date.id[0]&&date.id[0]<='Z')
            {
                  if('a'<=date.id[1]&&date.id[1]<='z'||'A'<=date.id[1]&&date.id[1]<='Z')
                        { 
                               for(i=2;i<4;i++)
                                   {   if(('0'<=date.id[i])&&(date.id[i]<='9'))
                                                a=1; 
                                       else                 
                                                a=0; 
                                                                 }                                           
         }
    }
  }
 if(fp==NULL)
  {  printf("The previous record is not exist.\n");
     printf("If you want to set a new one,please type in 'Y'.\n");
     printf("If you want to exit,plaese type in 'N'\n");
     b=getchar();
     if(b=='N')
       exit(1);
      else
       {   fp=fopen("record.txt","w"); 
           //fputs("ID--------SCORE-----TIME\n",fp);
           fclose(fp);                   }  
  }

int choice; 
loop:; 
printf("Please select the function:\n");
printf("1.Start a test\n2.Check scores\n3.Exit\n");
scanf("%d",&choice);  
switch(choice)
{ case 1:
    fp=fopen("record.txt","a");
    starttest(&score,&use);
    fprintf(fp,"%s%9d%9d\n",date.id,score,use);
    fclose(fp);
    goto loop;
    break;
  case 2:
       fp=fopen("record.txt","r");
       
       /*while((fscanf(fp,"%s",&ID)!=EOF)&&d==0)
        {   if(ID==date.id)
               d=0;
        }
        if(d==1)
          {
           printf("The ID is not exist.\n");
           //system("pause");
           //exit(1);
           goto loop;  
           }*/
            
       fp=fopen("record.txt","r");
       check(fp,date.id);
       goto loop;
       break;
  case 3:
       system("pause");     
       exit(1);       } 
 
 
     
    
 system("pause");                                     
 return 0;
}

int strCount(char str[])
{  int j;
   j=0;
   while((j<(SIZE-1))&&(str[j]!='\0'))
   {j++;}
   return j;
}

void starttest(int *saddr,int *uaddr)
{ 
   srand(time(NULL));
   int item[10][4];
   int start,end,during;                      
   int score=0; 
   
  
   int i,j;
   int answer[10];
   char ch[10];
   
   for(i=0;i<10;i++)
    {  item[i][0]=1+(int)rand()%99;
       item[i][1]=1+(int)rand()%4;
       item[i][2]=1+(int)rand()%99;
       
       while((item[i][1]==1)&&((item[i][0]+item[i][2])>99))
         {item[i][2]=1+(int)rand()%99;}
       while((item[i][1]==2)&&((item[i][0]-item[i][2])<0))
          {item[i][2]=1+(int)rand()%99;}
       while((item[i][1]==3)&&((item[i][0]*item[i][2])>99))
          {item[i][2]=1+(int)rand()%99;}
       while((item[i][1]==4)&&((item[i][0]%item[i][2])!=0))
          {item[i][2]=1+(int)rand()%99;}
      switch(item[i][1])
        { case 1:
            item[i][3]=item[i][0]+item[i][2];
            ch[i]='+';
             break;
          case 2:
            item[i][3]=item[i][0]-item[i][2];
            ch[i]='-';
            break;
          case 3:
            item[i][3]=item[i][0]*item[i][2];
            ch[i]='*';
            break;
          case 4:
            item[i][3]=item[i][0]/item[i][2];
            ch[i]='/';
            break;                
                        }  
    }
    printf("The test starts!!");
   start=time(NULL);    
   for(i=0;i<10;i++)
   { 
     printf("\n%d%c%d=",item[i][0],ch[i],item[i][2]);
     scanf("%d",&answer[i]);
   }
    end=time(NULL);
     *uaddr=end-start;   
   for(i=0;i<10;i++)
     {  if(item[i][3]==answer[i])
           *saddr=*saddr+10;
     }
   for(i=0;i<10;i++)
   { 
      printf("Prob. | Correct Answ.  |  Ur Answ\n");              
      printf("%d%c%d        %d              %d\n",item[i][0],ch[i],item[i][2],item[i][3],answer[i]);
   }
    
}
void check(FILE *fname,char date[81])
{  int score1,use1,d=1;
   char ID1[81];
   char *string;
   //string=&date;    
   printf("Your previous records are:\n");
    while(fscanf(fname,"%s%d%d",&ID1,&score1,&use1)!=EOF)
       {  if(!strcmp(ID1,date))
            {printf("%s  %d  %dseconds\n",ID1,score1,use1);
             d=0;}
          //else
            //{printf("None");}          
       }
   if(d==1)
       printf("None\n");
    fclose(fname);      
}
