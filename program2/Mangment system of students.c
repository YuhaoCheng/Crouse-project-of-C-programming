#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#define SIZE 81
struct message1 
{ char studentid[SIZE];
  char apatment[SIZE];
  char major[SIZE];
  char name[SIZE];
  char gender[SIZE];
  char phone[SIZE];//修改过，从int改成char 
  char key[SIZE];
  char mail[SIZE];
  int  one;/*学生选的课程的编号*/
  int two;
  int three;
}; 
struct message2
{ char teacherid[SIZE];
  char apartment[SIZE];
  char name[SIZE];
  char mail[SIZE];
  char key[SIZE];
};
struct message3
{ int courseid;
  char name[SIZE];
  int credit;
  int period;
  char identify[SIZE];
  char teacher[SIZE];
  char date[SIZE];
  char site[SIZE];
  int number;
  char brief[SIZE];
  char book[SIZE];
  char apartment[SIZE];
  int kaishi;
  int jieshu;
  int suanke;
  int shengyu;
};
typedef struct message1 STUDENT;
typedef struct message2 TEACHER;
typedef struct message3 COURSE;
STUDENT student[SIZE];
TEACHER teacher[SIZE];
COURSE  course[SIZE];
COURSE  temp1;
COURSE  temp2;
COURSE  temp3;
COURSE  newcourse;
void getdatestudent(char [SIZE],struct message1 *);//提取学生信息 
void getdateteacher(char [SIZE],struct message2 *);//提取老师信息 
void getdatecourse(char [SIZE],struct message3 *); //提取课程信息 
void delstudent(char [100],int);//删除函数 
void teacherlog();//老师登录 
void studentlog();//学生登录 
void teacherfunction(char [SIZE]);// 老师功能 
void studentfunction(char [SIZE]);//学生功能 
void studentselectcourse(char [SIZE]);//学生选课系统 
void studentlookcourse(char [SIZE]);//查看选修的课程 
void search();//根据课程名称，学院查询
void paixu();//根据课余量和选课人数排序 
void studentalter(char [SIZE]);//修改学生个人的信息
void teacherlookcourse(char [SIZE]);//查看选课情况 
void teacherdel(char [SIZE]);
void delcourse(char [SIZE]);//删除课程
void del(int);//删除某个课程号的课程 
void delc(int);
void delcm(int);
void dels(char [SIZE],int);
void statistics(char [SIZE]);//统计信息
void  xiugai();//修改信息  
int teacherlookself(char [SIZE]);//查看自己开设的课程 
void teachersearchcourse();//根据课程号查询学生信息
void searchTeacher(char[SIZE]);//根据id查找教师名称及信息并排序 
void addcourse(char [SIZE]);//添加课程
//void delteachercourse();//删除课程  
void teacheralter(char [SIZE]);//修改老师个人的信息 
void back();//返回到登录界面 

int main()
{  system("mode concols=1366 lines=768");
   void logfunction(char);
  //void registerfunction(char);
  int i=0,m=0,n=0;
  char choose1,choose2;
  /*FILE *fp;
  fp=fopen("student.txt","r");
  if(fp==NULL)
  { 
    printf("\nThe file is not successful opened");
    exit(1);
  }*/ 
  printf("                                                \n");
  printf("                                                \n");
  printf("                                                \n");
  printf("                                                \n");
  printf("                                                \n");
  printf("                         欢迎进入学生选课管理系统   \n");
  printf("                                                \n");
  printf("                         请选择您需要的功能\n") ; 
  printf("                                                \n");
  printf("                           1.用户登陆\n");
  printf("                           2.退出程序\n ");
  scanf("%c",&choose1);
  getchar();
  while(choose1!=49&&choose1!=50)
  { system("cls");
    printf("                         输入有误，请再次尝试   \n");
    printf("                                              \n");
    printf("                         请选择您需要的功能     \n");
    printf("                                              \n");
    printf("                           1.用户登陆\n");
    printf("                                     \n");
    printf("                           2.离开系统  \n");
    scanf("%c",&choose1);
    getchar();
   
  }
  switch(choose1)
  { case 49:
  	 { 
	   system("cls");
  	   printf("                                                \n");
       printf("                                                \n");
       printf("                                                \n");
       printf("                                                \n");
       printf("                                                \n");
	   printf("                         请输入您的身份\n");
	   printf("                                     \n");
  	   printf("                           1.教师 \n");
  	   printf("                           2.学生 \n");
  	   printf("                           3.离开程序         ");
  	   scanf("%c",&choose2);
  	   getchar();
  	   logfunction(choose2);
  	   break;
	 }
	//case 50:
	 /*{printf("please type in you identify.\n");
	  printf("1.student\n2.teacher\n");
	  scanf("%c",&choose2);
	  getchar();
	  registerfunction(choose2); 
	  break;	
	 }*/	
	case 50:
		{ system("cls");
		printf("                                                \n");
        printf("                                                \n");
        printf("                                                \n");
        printf("                                                \n");
        printf("                                                \n"); 
		printf("                         你已经退出程序");
		  break;
		}
  	
  }
  //back(); 
  system("pause");
  return 0;
}
void logfunction(char a)
{ 
  switch(a)
  { case 49:
  	{
  	system("cls");
	teacherlog();
	break;}
  	case 50:
  	{
  	  system("cls");
	  studentlog();
	  break;
    }
  }
}


void getdatestudent(char val[SIZE],STUDENT *hh)
{   int i;
	FILE *fp;
	fp=fopen(val,"r");
	for(i=0;i<SIZE;i++)
	{
	  	fscanf(fp,"%s      %s        %s %s %s %s     %s %s %d %d %d",&hh[i].studentid,&hh[i].apatment,&hh[i].major,&hh[i].name,&hh[i].gender,&hh[i].phone,&hh[i].key,&hh[i].mail,&hh[i].one,&hh[i].two,&hh[i].three);
	}
	fclose(fp);
	
}
void getdateteacher(char val[SIZE],TEACHER *hh)
{   int i;
	FILE *fp;
	fp=fopen(val,"r");
	for(i=0;i<SIZE;i++)
	{
		fscanf(fp,"%s      %s       %s   %s     %s",&hh[i].teacherid,&hh[i].apartment,&hh[i].name,&hh[i].mail,&hh[i].key);
    }
	fclose(fp);
}
void getdatecourse(char val[SIZE],COURSE *hh)
{   int i;
	FILE *fp;
	fp=fopen(val,"r");
	for(i=0;i<SIZE;i++)
	{
	 fscanf(fp,"%d %s %d %d %s %s %s %s %d %s %s %s %d %d %d %d\n",&hh[i].courseid,&hh[i].name,&hh[i].credit,&hh[i].period,&hh[i].identify,&hh[i].teacher,&hh[i].date,&hh[i].site,&hh[i].number,&hh[i].brief,&hh[i].book,&hh[i].apartment,&hh[i].kaishi,&hh[i].jieshu,&hh[i].suanke,&hh[i].shengyu);   
	}
	fclose(fp);
	
	
}
void teacherlog()
{ int i=0,m=0;
  char a;
  char c,d;
  char messageID[SIZE];
  char messageKEY[SIZE];
  getdateteacher("teacher.txt",&teacher);
  printf("                                                \n");
  printf("                                                \n");
  printf("                                                \n");
  printf("                                                \n");
  printf("                                                \n");
  /**/printf("                         请输入你的教师工号.\n");
  while((i<(SIZE-1))&&((c=getchar())!='\n'))   
   {   messageID[i]=c;
       i++;
   }
   messageID[i]='\0';
   //puts(messageID);
   /*i=0;
   printf("Please type in your password\n");
   	while((i<(SIZE-1))&&((d=getchar())!='\n'))   
   {   messageKEY[i]=d;
       i++;
   }
   messageKEY[i]='\0';*/
   //puts(messageKEY);
   //puts(teacher[0].teacherid);
   for(m=0;m<SIZE;)
   {
   	 if(strcmp(teacher[m].teacherid,messageID))
       {   m++;
		   continue; 
	   }
     break;			     	
   }  
   //printf("%d",m);
   
   while(m==81)
   {printf("                         工号有误，请重新输入;或者你可以选择退出\n");
    printf("                                                                \n");
   	printf("                         请选择：\n");
   	printf("                                  \n");
   	printf("                         1.重新输入.\n");
   	printf("                         2.退出程序.\n");
   	scanf("%c",&a);
   	getchar();
   	switch(a)
   	{case 49:
   		{  printf("\n");
		   printf("                         输入你的工号.\n");
   		  i=0;
   		  while((i<(SIZE-1))&&((c=getchar())!='\n'))   
             {   messageID[i]=c;
                 i++;
             }
            messageID[i]='\0';
            
            for(m=0;m<SIZE;)
            {
   	              if(strcmp(teacher[m].teacherid,messageID))
                        {   m++;
		                     continue; 
	                    }
                  break;			     	
            } 
			//printf("%d",m);          
            continue;
		}
	 case 50:
	 	exit(1);
	}
   }
   printf("                                          \n");
   printf("                         系统验证工号成功~\n");
   printf("                                          \n");
   /**/i=0;
   printf("                         请输入你的密码:\n");
   	while((i<(SIZE-1))&&((d=getchar())!='\n'))   
   {   messageKEY[i]=d;
       i++;
   }
   messageKEY[i]='\0';
   
   
   
  /* */ while(strcmp(teacher[m].key,messageKEY))
   {
   	system("cls"); 
    printf("                                                \n");
    printf("                                                \n");
    printf("                                                \n");
    printf("                                                \n");
    printf("                                                \n");
   	printf("                          \n");
    printf("                         你输入的密码有误，请重新输入;或者你可以退出程序.\n");
   	printf("                                                                           \n");
   	printf("                         请选择:\n");
   	printf("                                \n");
   	printf("                         1.重新输入.\n");
   	printf("                         2.退出程序.\n");
   	scanf("%c",&a);
   	getchar();
   	switch(a)
   	{ case 49:
      { printf("                         请输入你的密码\n");
	    i=0;
   	    while((i<(SIZE-1))&&((d=getchar())!='\n'))   
        {   messageKEY[i]=d;
            i++;
        }
	    messageKEY[i]='\0';
	    //puts(messageKEY);
	    break;
	  }
     case 50:
     	exit(1);
    }
    //puts(teacher[m].key);
    continue;
    }
   printf("                         教师端登录成功\n");
   system("pause");
   system("cls"); 
   teacherfunction(messageID);
  
}

void studentlog()
{ int i=0,m=0;
  char a;
  char c,d;
  char messageID[SIZE];
  char messageKEY[SIZE];
  getdatestudent("student.txt",&student);
      printf("                                                \n");
      printf("                                                \n");
      printf("                                                \n");
      printf("                                                \n");
      printf("                                                \n");
      printf("                         请输入你的学号.\n");
      printf("\n");
  while((i<(SIZE-1))&&((c=getchar())!='\n'))   
   {   messageID[i]=c;
       i++;
   }
   messageID[i]='\0';
   //puts(messageID);
   /*i=0;
   printf("Please type in your password\n");
   	while((i<(SIZE-1))&&((d=getchar())!='\n'))   
   {   messageKEY[i]=d;
       i++;
   }
   messageKEY[i]='\0';*/
   //puts(messageKEY);
   //puts(teacher[0].teacherid);
   for(m=0;m<SIZE;)
   {
   	 if(strcmp(student[m].studentid,messageID))
       {   m++;
		   continue; 
	   }
     break;			     	
   }  
   //printf("%d",m);
   
   while(m==81)
   {printf("                         你输入的学号有误，请重新输入;或者你可以退出程序\n");
   	printf("\n");
   	printf("                         请选择\n");
   	printf("\n");
   	printf("                         1.重新输入.\n");
   	printf("                         2.退出程序.\n");
   	printf(" \n");
   	scanf("%c",&a);
   	getchar();
   	switch(a)
   	{case 49:
   		{ printf("输入你的学号.\n");
   		  i=0;
   		  while((i<(SIZE-1))&&((c=getchar())!='\n'))   
             {   messageID[i]=c;
                 i++;
             }
            messageID[i]='\0';
            
            for(m=0;m<SIZE;)
            {
   	              if(strcmp(student[m].studentid,messageID))
                        {   m++;
		                     continue; 
	                    }
                  break;			     	
            } 
			//printf("%d",m);          
            continue;
		}
	 case 50:
	 	exit(1);
	}
   }
   printf("                         学生端学号确认成功\n");
   printf(" \n");
   /**/i=0;
   printf("                         请输入你的密码\n");
   	while((i<(SIZE-1))&&((d=getchar())!='\n'))   
   {   messageKEY[i]=d;
       i++;
   }
   messageKEY[i]='\0';
   
   
   
  /* */ while(strcmp(student[m].key,messageKEY))
   {
   	system("cls");
   	printf("                         你输入的密码有误，请重新输入；或者你可以选择退出程序\n");
   	printf("\n");
   	printf("                         请选择：\n");
   	printf("\n");
   	printf("                         1.重新输入.\n");
   	printf("                         2.退出程序.\n"); 
   	printf(" \n");
   	scanf("%c",&a);
   	getchar();
   	switch(a)
   	{ case 49:
      { printf("                         请输入你的密码\n");
	    i=0;
   	    while((i<(SIZE-1))&&((d=getchar())!='\n'))   
        {   messageKEY[i]=d;
            i++;
        }
	    messageKEY[i]='\0';
	    //puts(messageKEY);
	    break;
	  }
     case 50:
     	exit(1);
    }
    //puts(teacher[m].key);
    continue;
    }
   printf("                         学生端登录成功\n");
   system("cls");
   studentfunction(messageID);
  
}

void studentfunction(char val[SIZE])
{ char choose;
  void  studentselectcourse(char [SIZE]);//选课系统 
  void  studentinqurecourse(char [SIZE]);//查询课程 
  void  studentmanagement(char [SIZE]);//个人信息管理 
  system("cls");
  printf("                                                \n");
  printf("                                                \n");
  printf("                                                \n");
  printf("                                                \n");
  printf("                                                \n");
  printf("                         欢迎进入学生管理界面    \n");
  printf("\n"); 
  printf("                         请选择所需要的功能:    \n");
  printf("\n");
  printf("                         1.选课                 \n");
  printf("                         2.查询课程             \n");
  printf("                         3.个人信息管理         \n");
  printf("                         4.退出系统             \n");
  printf("\n                                                ");
  scanf("%c",&choose);
  switch(choose)
  { case 49:
  	  { 
  	    system("cls");
  	  	studentselectcourse(val);
  	  	back(); 
  	  	break;
  	  }
  	case 50:
  	  {
  	  	system("cls");
  	  	studentinquirecourse();
  	  	back();
  	  	break;
		
	  }
	case 51:
		{
			system("cls");
			studentmanagement(val);
			back();
			break;
		}
	case 52:
		{
		  system("cls");
		  exit(1);
		  back();
		  break;
		}
	default:
		{system("cls");
		 exit(1);
		 back();
		}
     
  }

}


void studentselectcourse(char val[SIZE])
{   printf("成功进入选课功能\n");
    printf("\n");
    //system("pause");
    //printf("%s\n",val);
    struct hh
    { char sid[SIZE];
      int cid;
    };
    struct ms
    { int msid;
      int snumber;
      int ynumber;
    };
    typedef struct ms MS;
	typedef struct hh KK;
	KK scou[SIZE];
	MS coursem[SIZE];

    int i=0;
    int m=0;
    FILE *fp1,*fp2,*fp3;
    int a=0,b=0,c=0,d=0;
    int e=0;
    int p=1;//指示变量p=0选课失败，p=1选课成功 
    int k[4];
    int j[4];
    int id[SIZE];
    strcat(val,".txt");
    fp1=fopen(val,"r");
    getdatecourse("course.txt",&course);
    //system("mode concols=1366 lines=768");
    printf("课程编号    课程名称   学分  学时   性质   教师   上课时间   上课地点   人数   课程简介    教材信息              起止时间\n");
    do
	{ k[0]=(course[i].kaishi)/1000;
	  k[1]=(course[i].kaishi-k[0]*1000)/100;
	  k[2]=(course[i].kaishi-k[0]*1000-k[1]*100)/10;
	  k[3]=(course[i].kaishi-k[0]*1000-k[1]*100-k[2]*10);
	  j[0]=(course[i].jieshu)/10000;
	  j[1]=(course[i].jieshu-j[0]*10000)/1000;
	  j[2]=(course[i].jieshu-j[0]*10000-j[1]*1000)/100;
	  j[3]=(course[i].jieshu-j[0]*10000-j[1]*1000-j[2]*100)/10;
	  printf("%d  %s %d %d %s %s %s %s %d %s %s",course[i].courseid,course[i].name,course[i].credit,course[i].period,course[i].identify,course[i].teacher,course[i].date,course[i].site,course[i].number,course[i].brief,course[i].book);
	  printf("201%d年-201%d年第%d学期第%d周~",k[0],k[1],k[2],k[3]);
	  printf("201%d年-201%d年第%d学期第%d周\n",j[0],j[1],j[2],k[3]);
	  i++;
	}while(course[i].courseid!=0);
	
	for(i=0;i<SIZE;i++)
	{
		fscanf(fp1,"%d\n",&id[i]);
	}
	i=0;
    while(id[i]!=0)
    {
    	i++;
    } 
    //printf("%d",i);
    if(i>=3)
    {
    	printf("选课不能超过三门");
    	exit(1);
    }
    /**/
	fclose(fp1);
    fp2=fopen("coursemessage.txt","r");
    do
    {
    	fscanf(fp2,"%d   %d    %d\n",&coursem[m].msid,&coursem[m].snumber,&coursem[m].ynumber);
    	 m++;
    }while(coursem[m].msid==0);
    //coursem[2].snumber=56
    fclose(fp2);
	fp2=fopen("coursemessage.txt","w"); 
    printf("%d\n",coursem[0].msid);
    printf("请输入课程编号.\n");//提示用户为6位数字 
    printf("\n");
	scanf("%d",&a);
	//getchar();
	//printf("%d\n",a);
	 
	e=0;//所选课程在coursemessage中的位置
	while(a!=coursem[e].msid)
	{e++;}
	printf("%d\n",e);
	if(coursem[e].snumber==80||coursem[e].snumber==100)
	  {
	    printf("课程已满.");
	    p=0;
	  }
	else
	{ 
		coursem[e].snumber=coursem[e].snumber+1;
		coursem[e].ynumber=coursem[e].ynumber-1;
    } 
    printf("%d\n%d\n",coursem[e].snumber,coursem[e].ynumber);
   /* for(m=0;m<SIZE;m++)                                         //更新数据库中的文件                            
    {
    	fprintf(fp2,"%d   %d    %d",coursem[m].msid,coursem[m].snumber,coursem[m].ynumber);
    	
	}*/
    
    
    
    
    
    
	fp3=fopen(val,"a");
	b=0;
	while(a!=course[b].courseid)//b是所选课程在数据库中的位置 
	{b++;}
	//printf("%d\n",b);
	while(id[0]!=course[c].courseid)//c是已选的第一的课程在数据库中的位置 
	{c++;}
	//printf("%d\n",c);
	while(id[1]!=course[d].courseid)//b是已选的第二个课程在数据库中的位置 
	{d++;}
	//printf("%d\n",d);
	if((course[b].kaishi>course[c].kaishi)&&(course[b].jieshu<course[c].kaishi))
	 {
	 	//printf("successful!!!!\n");
	 }
	else
	 { if(!strcmp(course[b].date,course[c].date))
         {   //printf("fail by 1.");
               p=0;
					  } 
	   else
	    {  //printf("successfl!!!\n");
					}   	 	
	 }
	 
	 if((course[b].kaishi>course[d].kaishi)&&(course[b].jieshu<course[d].kaishi))
	 {
	 //	printf("successful!!!!\n");
	 }
	else
	 { if(!strcmp(course[b].date,course[d].date))
         {   //printf("fail by 2.\n");
             p=0;
         } 
	   else
	    {  //printf("successfl!!!\n");
					}   	 	
	 }
	if(p)
	{
		printf("选课成功~\n");
		fprintf(fp3,"%d\n",a);  
		   for(m=0;m<SIZE;m++)                                         //更新数据库中的文件                            
           { if(coursem[m].msid==NULL)
    	      {break;
			  }
    	      fprintf(fp2,"%d   %d    %d\n",coursem[m].msid,coursem[m].snumber,coursem[m].ynumber);
    	      
    	
	       }
	    fclose(fp2);
   	    fclose(fp3);   
	}
     else
     {
   	   printf("选课失败.\n");
   	   fclose(fp2);
   	   fclose(fp3);
   	   exit(1);
     }
    
    
	
}
void studentinquirecourse(char val[SIZE])
{   char choose;

	printf("成功进入查询课程功能\n");
	printf("1.根据课程名或开课学院查询\n.2.根据课余量排序或选课人数所有课程.\n");
	printf("\n");
	getchar(); 
	scanf("%c",&choose); 
	getchar();
	switch(choose)
	{case 49:{search();
	           break;
			 }
	 case 50:{paixu();
	           break;
			}
	}
	
	
}
void search()
{ 
    FILE *inFile;
    int i,j,k;
   
   
    char coursename[SIZE];
    
    inFile = fopen("course.txt","r");//kecheng(xuankerenshu)
    
    if(inFile == NULL)
    {
              printf("\nFailed to open the file.\n");
              system("pause");
              exit(1);
    } 
    
    printf("1---课程名称\n");
    printf("2---学院名称\n");
    printf("输入你的选择：");
	scanf("%d",&i);
	getchar();
	 
	if(i==1)
{
	 for(j=0;j<SIZE;j++)
    {
    fscanf(inFile, "%d %s %d %d %s %s %s %s %d %s %s %s %d %d %d %d",&course[j].courseid,course[j].name,&course[j].credit, &course[j].period,course[j].identify,course[j].teacher,course[j].date,course[j].site,&course[j].number,course[j].brief,course[j].book,course[j].apartment,&course[j].kaishi,&course[j].jieshu,&course[j].shengyu,&course[j].suanke );
    }
    
    
   
    printf("请输入要查询的课程名称:");
  
    scanf("%s",&coursename);
    
	for(j=0;j<SIZE;j++)
    {             
   	if(!strcmp(course[j].name,coursename))
    {
      printf("%d %s %d %d %s %s  %s  %s %d %s %s %s\n",course[j].courseid, course[j].name, course[j].credit, course[j].period, course[j].identify, course[j].teacher, course[j].date, course[j].site, course[j].number,course[j].brief, course[j].book,course[j].apartment);
            continue;
	}
    }
}

    if(i==2)
{
    	for(j=0;j<SIZE;j++)
    {
    fscanf(inFile, "%d %s %d %d %s %s %s %s %d %s %s %s %d %d %d %d",&course[j].courseid,course[j].name,&course[j].credit, &course[j].period,course[j].identify,course[j].teacher,course[j].date,course[j].site,&course[j].number,course[j].brief,course[j].book,course[j].apartment,&course[j].kaishi,&course[j].jieshu,&course[j].shengyu,&course[j].suanke );
    }
    
  
    printf("请输入要查询的学院名称：");
    
    scanf("%s",&coursename);
  
    for(j=0;j<SIZE;j++)
    {
   	if(!strcmp(course[j].apartment,coursename))
    {
   	 printf("%d %s %d %d %s %s  %s  %s %d %s %s %s\n",course[j].courseid, course[j].name, course[j].credit, course[j].period, course[j].identify, course[j].teacher, course[j].date, course[j].site, course[j].number,course[j].brief, course[j].book,course[j].apartment);
            continue;
    }				
    }
}
    fclose(inFile);
}
void paixu()//交换 
{
     
    FILE *inFile;
    int i,j,k=0,n,p=0,q=0;
    //char coursename[SIZE];
    
    
	printf("1---按照选课人数排序\n");
	printf("2---按照课余量排序\n");
	printf("请输入您的选择（1 或 2）：\n");
	scanf("%d",&i); 
	 
	 
	inFile = fopen("course.txt","r");//kecheng(xuankerenshu)
    
    if(inFile == NULL)
    {
              printf("\n打开课程文件失败.\n");
              system("pause");
              exit(1);
    } 

 if(i==1)
	{
	
	for(j=0;j<SIZE;j++)
    {
    fscanf(inFile, "%d %s %d %d %s %s %s %s %d %s %s %s  %d %d %d %d",&course[j].courseid,course[j].name,&course[j].credit, &course[j].period,course[j].identify,course[j].teacher,course[j].date,course[j].site,&course[j].number,course[j].brief,course[j].book,course[j].apartment,&course[j].kaishi,&course[j].jieshu,&course[j].shengyu,&course[j].suanke );
    }
    
    for(k=0; k<(SIZE-1); k++)  //change the order....
    {
        for(j=1; j<SIZE; j++)
        {
            
            if(course[j].suanke > course[j-1].suanke)
            {
               temp1 = course[j-1];
               course[j-1] = course[j];
               course[j] = temp1;
            }
        }
    }
    k=0;
    printf("\n\n\n");
   do
   {
    printf("%d%s %d %d %s %s %s %s %d %s %s %s %d\n",course[k].courseid, course[k].name, course[k].credit, course[k].period, course[k].identify, course[k].teacher, course[k].date, course[k].site, course[k].number,course[k].brief, course[k].book,course[k].apartment,course[k].suanke);
    k++;
	}while(course[k].courseid != 0);
  
	}
    
   
	
	if(i==2)
	{
	  for(j=0;j<SIZE;j++)
     {
      fscanf(inFile, "%d %s %d %d %s %s %s %s %d %s %s %s %d %d  %d %d",&course[j].courseid,course[j].name,&course[j].credit, &course[j].period,course[j].identify,course[j].teacher,course[j].date,course[j].site,&course[j].number,course[j].brief,course[j].book,course[j].apartment,&course[j].kaishi,&course[j].jieshu,&course[j].shengyu,&course[j].suanke );
     }
     
     for(k=0; k<(SIZE-1); k++)  //change the order....
     {
        for(j=1; j<SIZE; j++)
        {
            
            if(course[j].shengyu > course[j-1].shengyu)
            {
               temp2 = course[j-1];
               course[j-1] = course[j];
               course[j] = temp2;
            } 
        }
    }
    
   
    printf("\n\n");
	k=0;
    do
    {
     printf("%d%s %d %d %s %s %s %s %d %s %s %s %d\n",course[k].courseid, course[k].name, course[k].credit, course[k].period, course[k].identify, course[k].teacher, course[k].date, course[k].site, course[k].number,course[k].brief, course[k].book,course[k].apartment,course[k].shengyu);
     k++;
    }while(course[k].courseid != 0);
    } 
    
   
    fclose(inFile);
    
}
 
void studentmanagement(char val[SIZE])
{ char choose;
  int shanchu;
  int m=0;
  //char a[SIZE];//如果想返需要在子函数中重新复制字符串 
  //char b[SIZE];
  system("cls");
  printf("                                                \n");
  printf("                                                \n");
  printf("                                                \n");
  printf("                                                \n");
  printf("                                                \n");
  printf("                         成功进入个人信息管理    \n");
  printf("\n"); 
  //printf("%s\n",val);
  printf("                         请选择所需要的功能:    \n");
  printf("\n");
  printf("                         1.查看选修的课程                \n");
  printf("                         2.删除课程             \n");
  printf("                         3.修改个人信息         \n");
  printf("                         4.退出信息             \n");
  printf("\n");
  getchar();
  scanf("%c",&choose);
  //printf("%c",choose);
  printf("%s\n",val);
  switch(choose)
  { case 49:
  	 { system("cls");
	   studentlookcourse(val);
	   back(); 
  	   break;
	 }
  	case 50:
  	 { system("cls"); 
	   studentlookcourse(val);//已经变为了************.txt 
  	    //strcpy(a,val);
  	    //strcat(a,".txt");
  	    puts(val);
  	    printf("请输入想要删除的课程编号。\n");
  	    //getchar();
		scanf("%d",&shanchu);
  	    //getchar();
	    delstudent(val,shanchu);
	    //printf("删除课程\n");
	    back();
		break; 
     }
  	case 51:
  	{ system("cls");
	  printf("修改个人信息\n");
  	  puts(val);
  	  studentalter(val);
  	  back();
  	  break;
  	}
	case 52:
		{exit(1);
		 break;}
    //default:
    	//{exit(1);}
	
  	
  }
}
void studentlookcourse(char val[SIZE])
{   printf("成功进入学生查看选修课程界面\n");
    //printf("%s",val);
    /**/FILE *fp1;
    int i=0,m=0;
    int k[3];
    int j[3];
    getdatecourse("course.txt",&course);
    strcat(val,".txt");
    fp1=fopen(val,"r");
    int c[3];
    for(i=0;i<SIZE;i++)
    {fscanf(fp1,"%d\n",&c[i]);}
    //if(c[2]==0)
    //{printf("hh1");
	//}
	//printf("%d\n",c[2]);
    for(i=0;i<3;i++)
    {   for(m=0;m<SIZE;m++)
         {
		   if(c[i]==course[m].courseid)
           {
		   k[0]=(course[m].kaishi)/100;
	       k[1]=(course[m].kaishi-k[0]*100)/10;
	       k[2]=(course[m].kaishi-k[0]*100-k[1]*10);
	       j[0]=(course[m].jieshu)/1000;
	       j[1]=(course[m].jieshu-j[0]*1000)/100;
	       j[2]=(course[m].jieshu-j[0]*1000-j[1]*100);
	       printf("%d  %s %d %d %s %s %s %s %d %s %s",course[m].courseid,course[m].name,course[m].credit,course[m].period,course[m].identify,course[m].teacher,course[m].date,course[m].site,course[m].number,course[m].brief,course[m].book);
	       printf("201%d年-201%d年第一学期第%d周~",k[0],k[1],k[2]);
	       printf("201%d年-201%d年第一学期第%d周\n",j[0],j[1],j[2]);
	       break;
		   }
		 }
	} 
        	
    	
	//}
}
void studentalter(char val[SIZE])
{   printf("成功进入学生个人信息修改界面\n");   
    getdatestudent("student.txt",&student);
    int m;
    int i;
    char choose;
	char newmail[SIZE];
	char newkey[SIZE];
	char newphone[SIZE];
	FILE *fp;
   	for(i=0;i<SIZE;)
   {
   	 if(strcmp(student[i].studentid,val))
       {   i++;
		   continue; 
	   }
     break;			     	
   }
   //printf("%d",i); 
   printf("请选择修改内容\n");
   printf("1.邮箱\n");
   printf("2.电话\n");
   printf("3.密码\n");
   printf("\n"); 
   //printf("%s",student[i].studentid);
   getchar();
   scanf("%c",&choose);
   getchar();
   switch(choose)
   { case 49:
   	  { 
		printf("请输入邮箱新邮箱。\n");
   	    gets(newmail);
   	    strcpy(student[i].mail,newmail);
   	    break;
   	  }
   	  case 50:
	  { printf("请输入新电话\n");
	    gets(newphone);
		strcpy(student[i].phone,newphone); 
		break;
	  } 
	  case 51:
	  {  printf("请输入新密码\n");
	     gets(newkey);
	     strcpy(student[i].key,newkey);
	     break;
	  }  	
   	}
   	fp=fopen("student.txt","w");
   	for(m=0;m<SIZE;m++)
   	{ if(student[m].studentid==NULL)
   	  {
        break;		 }
      fprintf(fp,"%s %s %s %s %s %s %s %s %d %d %d\n",student[m].studentid,student[m].apatment,student[m].major,student[m].name,student[m].gender,student[m].phone,student[m].key,student[m].mail,student[m].one,student[m].two,student[m].three);     
   	}
   	fclose(fp);
   	printf("修改成功.\n");
   	
}





void teacherfunction(char val[SIZE])
{ char choose;
  void teacherselectcourse(char [SIZE]);//选课管理，针对自己 
  void teachermanagecourse(char [SIZE]);//课程管理，针对自己的课程 
  void teachermanagement(char [SIZE]);// 个人信息的管理 
  printf("                                                \n");
  printf("                                                \n");
  printf("                                                \n");
  printf("                                                \n");
  printf("                                                \n");
  printf("                         欢迎进入教师管理界面\n");
  printf("\n");
  printf("                         请选择所需要的功能:\n");
  printf("                            1.选课管理                    \n");
  printf("                            2.课程管理                    \n");
  printf("                            3.个人信息管理                    \n");
  printf("                            4.退出系统                   \n");
  scanf("%c",&choose);
  getchar();
  switch(choose)
  { case 49:
  	{ system("cls");
	  teacherselectcourse(val);
	  back();
  	  break;
  	}
  	case 50:
  	{
  	  system("cls");
	  teachermanagecourse(val);
	  back();
	  break;
	}
  	case 51:
  	{
  	  system("cls");
  	  teachermanagement(val);
  	  back();
	  break;	
	}
	case 52:
		{
		  system("cls");
		  exit(1);
		  back();
		  break;
		}
	
   }
}
void teacherselectcourse(char val[SIZE])
{ printf("%s\n",val);
  char choose;
  printf("成功进入选课管理\n");
  printf("请选择功能\n");
  printf("\n");
  printf("1.查看选课情况\n");
  printf("2.删除选课\n");
  printf("3.统计选课信息\n");
  printf("4.退出程序\n");
	//getchar();
	scanf("%c",&choose);
	getchar();
	switch(choose)
	{ case 49:
		{system("cls");
		 teacherlookcourse(val);
		 break;
		}
	  case 50:
	  	{ system("cls");
		  teacherdel(val);
	  	  break;
		}
	  case 51:
	  	{ system("cls");
		  statistics(val);
		  break;}
	  case 52:
	  	{ system("cls");
		  exit(1);
		  }
	 
    }
}
void teachermanagecourse(char val[SIZE])
{   char choose;
	//printf("%s\n",val);
	printf("成功进入课程管理.\n");
	printf("\n");
	printf("1.添加课程\n");
	printf("2.修改课程信息\n");
	printf("3.删除课程\n");
	scanf("%c",&choose);
	getchar();
	switch(choose)
	{
	  case 49:
	  	{  printf("添加课程");
		   addcourse(val);
		   break;
	  		
	  	}
	  case 50:
	    {
	      printf("修改课程信息");
		  xiugai();	
		  break;
	    } 
	    case 51:
		{ printf("删除课程");
		  delcourse(val);
		  break;
		  } 
		
	}
	
}
void teacherlookcourse(char val[SIZE])//查看选课情况 
{ char choose;
  int  a;//老师的开课门数 
  //printf("%s\n",val);
  printf("成功进入查看选课情况界面 ");
  printf("请选择功能.\n");
  printf("\n");
  printf("1.查看自己开设的课程\n");
  printf("2.查询某门课的信息\n");
  scanf("%c",&choose);
  //printf("%c\n",choose);
  switch(choose)
  { case 49:
  	 { teacherlookself(val);
  	   break;
	   }
  	
  	case 50:
	  { teachersearchcourse();
	    //printf("成功查询");
	    break;
	   } 
  	
   } 
} 
void  xiugai()
 {                    
    FILE *inFile;
    int i,j,k=0,n=0,m;
    char coursename[SIZE];//想修改的课程名称 
    char newbook[SIZE];
    char newbrief[SIZE];
    int newnumber=0;
    
	inFile = fopen("course.txt","r");//读取文档内容 //kecheng(xuankerenshu)
    
      if(inFile == NULL)
    {
              printf("\n打开课程文件失败.\n");
              system("pause");
              exit(1);
    } 
    
      for(j=0;j<SIZE;j++)//将文件内容读取到结构里 
    {
    fscanf(inFile, "%d %s %d %d %s %s %s %s %d %s %s %s  %d %d %d %d\n",&course[j].courseid,&course[j].name,&course[j].credit, &course[j].period,&course[j].identify,&course[j].teacher,&course[j].date,&course[j].site,&course[j].number,&course[j].brief,&course[j].book,&course[j].apartment,&course[i].kaishi,&course[i].jieshu,&course[j].suanke,&course[j].shengyu);
    }
     fclose(inFile);
     
     
 
     inFile = fopen("course.txt","w");//用写模式重新打开文档 kecheng(xuankerenshu)
     printf("请输入要修改的课程名称:");
     printf("\n"); 
    
      gets(coursename);
    
   for(j=0;j<SIZE;j++)
   {   
      if(!strcmp(course[j].name,coursename))
     {
        printf("%d %s %d %d %s %s %s %s %d %s %s %s %d\n",course[j].courseid, course[j].name, course[j].credit, course[j].period, course[j].identify, course[j].teacher, course[j].date, course[j].site, course[j].number,course[j].brief, course[j].book,course[j].apartment,course[j].suanke);
       
        break;
	 }
   }
   
   
        if(course[j].suanke == 0)
        {     
            printf("您可更改的选项有：\n");
            printf("1---教材信息\n");
            printf("2---课程简介\n");
            printf("3---限制人数\n");
            scanf("%d",&i);
           
            if(i==1)
            {
                printf("现有的教材名称：%s\n",course[j].book);
                printf("请输入修改后的教材名称：");
			    scanf("%s",newbook);
			    strcpy(course[j].book,newbook);
			  
			      for(m=0;m<SIZE;m++)
   	             { 
                                 if(course[m].courseid==NULL)
   	                         {
                             break;		 
                             }
                   	        fprintf(inFile, "%d %s %d %d %s %s %s %s %d %s %s %s  %d  %d\n",course[m].courseid,course[m].name,course[m].credit, course[m].period,course[m].identify,course[m].teacher,course[m].date,course[m].site,course[m].number,course[m].brief,course[m].book ,course[m].apartment,course[m].shengyu,course[m].suanke );
			      }
   	                    fclose(inFile);
                    	printf("修改成功。\n");
            }
			    
		
		          if(i==2)
            {
                    printf("现有课程简介：%s\n",course[j].brief);
                    printf("请输入修改后的课程简介：");
					scanf("%s",newbrief);
					strcpy(course[j].brief,newbrief);
					
					for(m=0;m<SIZE;m++)
   	             { 
                     if(course[m].courseid==NULL)
   	                         {
                             break;		 
                             }
                   	        fprintf(inFile, "%d %s %d %d %s %s %s %s %d %s %s %s %d %d\n",course[m].courseid,course[m].name,course[m].credit, course[m].period,course[m].identify,course[m].teacher,course[m].date,course[m].site,course[m].number,course[m].brief,course[m].book,course[m].apartment,course[m].shengyu,course[m].suanke );
			      }
   	                    fclose(inFile);
                    	printf("修改成功.\n");
            }
                           
                             
              if(i==3)
              {
                	printf("当前限制人数：%d\n",course[j].number);
                	printf("请输入修改后的限制人数：");
					scanf("%d",&newnumber);
					course[j].number = newnumber;
					
				    for(m=0;m<SIZE;m++)
   	               { 
                     if(course[m].courseid==NULL)
   	                         {
                             break;		 
                             }
                   	        fprintf(inFile, "%d %s %d %d %s %s %s %s %d %s %s %s %d %d\n",course[m].courseid,course[m].name,course[m].credit, course[m].period,course[m].identify,course[m].teacher,course[m].date,course[m].site,course[m].number,course[m].brief,course[m].book ,course[m].apartment,course[m].shengyu,course[m].suanke );
			        }
   	                    fclose(inFile);
                    	printf("修改成功\n");
           }
				
          } 
		
 
       if(course[j].suanke != 0)
      
        {
           	printf("该课程已被选择，只能更改限制人数。\n");
            printf("当前限制人数：%d\n",course[j].number);
            printf("请输入修改后的限制人数：");
            scanf("%d",&newnumber);
            course[j].number = newnumber;
					
		    for(m=0;m<SIZE;m++)
           { 
             if(course[m].courseid==NULL)
             {
               break;		 
             }
    	        fprintf(inFile, "%d %s %d %d %s %s %s %s %d %s %s %s %d %d\n",course[m].courseid,course[m].name,course[m].credit, course[m].period,course[m].identify,course[m].teacher,course[m].date,course[m].site,course[m].number,course[m].brief,course[m].book ,course[m].apartment,course[m].shengyu,course[m].suanke );
           }
            fclose(inFile);   
          	printf("修改成功\n"); 
		    
		}
		
  }
void teacherdel(char val[SIZE])//删除课程 
{//printf("%s\n",val);
  //printf("删除课程");
  delcourse(val);
}
void delcourse(char val[SIZE]) 
{   FILE *fp1;//用来打开delcourse.txt
    FILE *fp2;//用来打开个人文本 
    int i;//循环变量 
    int temdelcourse[SIZE];
	int delcid;//记录要删除的课程 
	int xuanze;
	char temsid[SIZE];
	getdatestudent("student.txt",&student);
    do
    {
	 teacherlookselfdel(val);
	 fp1=fopen("delcourse.txt","r");
	 for(i=0;i<SIZE;i++)
	 {
	   fscanf(fp1,"%d",&temdelcourse[i]); 	
     }
     fclose(fp1);
	 printf("请输入想要删除的课程编号。\n");
     scanf("%d",&delcid);
     //delc(delcid);
     //delcm(delcid);
     for(i=0;i<SIZE;i++)
     {  
        if((delcid==student[i].one)||(delcid==student[i].two)||(delcid==student[i].three))
          {  strcpy(temsid,student[i].studentid);
             strcat(temsid,".txt");
             //printf("%s",temsid);
             dels(temsid,delcid); 
		  }
	}     
     printf("删除成功！1：继续删除 2：退出");
     scanf("%d",&xuanze);
    }while(xuanze==1);
	/*int num;
    int xuanze;
    void del(int); 
    
    printf("请输入要删除的课程编号：\n");
    scanf("%d",&num);
    del(num);*/
    
	
}

void delc(int num)
{
FILE *f1;
long length;
char *f2;//用于记录要保存的内容     
char s[100];//用于保存每次读取的一行内容    
 int n;//用于存储编号     
 f1=fopen("course.txt","r");//以读的方式打开文件     
 fseek(f1,0,2);//文件指针移到文件尾    
 length=ftell(f1);//取得文件长度     
 f2=(char *)malloc(sizeof(char)*length);//给f2分配文件长度的空间    
  *f2=0;//使得f2字符串的长度初始为0        
  rewind(f1);//文件指针回到文件头     
  while(ftell(f1)<length-3)
  {//当文件没有结束时就依次读取文件的每一行         
  fgets(s,100,f1);//读取一行信息         
  n=atoi(s);//从读取的信息取得编号         
  if(n==num) 
  continue;//如果编号是要删除的编号，就不用保存这一行信息了        
   strcat(f2,s);//保存读取到的这一行信息    
    }      
    fclose(f1);//关闭文件     
    f1=fopen("course.txt","w");//重新以写的方式打开文件     
    fputs(f2,f1);
    //把保存的信息重新存储到文件当中     
    fclose(f1);//关闭文件 
}
void delcm(int num)
{
FILE *f1;
long length;
char *f2;//用于记录要保存的内容     
char s[100];//用于保存每次读取的一行内容    
 int n;//用于存储编号     
 f1=fopen("coursemessage.txt","r");//以读的方式打开文件     
 fseek(f1,0,2);//文件指针移到文件尾    
 length=ftell(f1);//取得文件长度     
 f2=(char *)malloc(sizeof(char)*length);//给f2分配文件长度的空间    
  *f2=0;//使得f2字符串的长度初始为0        
  rewind(f1);//文件指针回到文件头     
  while(ftell(f1)<length-3)
  {//当文件没有结束时就依次读取文件的每一行         
  fgets(s,100,f1);//读取一行信息         
  n=atoi(s);//从读取的信息取得编号         
  if(n==num) 
  continue;//如果编号是要删除的编号，就不用保存这一行信息了        
   strcat(f2,s);//保存读取到的这一行信息    
    }      
    fclose(f1);//关闭文件     
    f1=fopen("coursemessage.txt","w");//重新以写的方式打开文件     
    fputs(f2,f1);
    //把保存的信息重新存储到文件当中     
    fclose(f1);//关闭文件 
}
void dels(char val[SIZE],int num)
{
FILE *f1;
long length;
char *f2;//用于记录要保存的内容     
char s[100];//用于保存每次读取的一行内容    
 int n;//用于存储编号     
 f1=fopen(val,"r");//以读的方式打开文件     
 fseek(f1,0,2);//文件指针移到文件尾    
 length=ftell(f1);//取得文件长度     
 f2=(char *)malloc(sizeof(char)*length);//给f2分配文件长度的空间    
  *f2=0;//使得f2字符串的长度初始为0        
  rewind(f1);//文件指针回到文件头     
  while(ftell(f1)<length-3)
  {//当文件没有结束时就依次读取文件的每一行         
  fgets(s,100,f1);//读取一行信息         
  n=atoi(s);//从读取的信息取得编号         
  if(n==num) 
  continue;//如果编号是要删除的编号，就不用保存这一行信息了        
   strcat(f2,s);//保存读取到的这一行信息    
    }      
    fclose(f1);//关闭文件     
    f1=fopen(val,"w");//重新以写的方式打开文件     
    fputs(f2,f1);
    //把保存的信息重新存储到文件当中     
    fclose(f1);//关闭文件 
} 
void teacherlookselfdel(char val[SIZE])
{
	
    int i,a,b=0;
    int m=0;
    getdatecourse("course.txt",&course);
    getdateteacher("teacher.txt",&teacher);
    FILE *fp;//用来打开delcourse.txt 
    //printf("%s\n",val);
    //printf("%s\n",teacher[0].teacherid);
    m=0;
	for(m=0;m<SIZE;m++)
	{  if(strcmp(teacher[m].teacherid,val))
	     break;
	}        //m是所选课程在数据库中的位置 
    //printf("%d\n",m); 
	//printf("%s",teacher[m].name);
	fp=fopen("delcourse.txt","w");
    printf("我可以删除的课程：\n"); 
    for(i=0;i<SIZE;i++)
    {  a=strcmp(course[i].teacher,teacher[m].name);
       if(a==0&&(course[i].suanke<30))          
          {
		   printf("%d  %s %d %d %s %s %s %s %d %s %s %d\n",course[i].courseid,course[i].name,course[i].credit,course[i].period,course[i].identify,course[i].teacher,course[i].date,course[i].site,course[i].number,course[i].brief,course[i].book,course[i].suanke);
		   fprintf(fp,"%d\n",course[i].courseid);    
          }
    }
	fclose(fp);
	
	
}
void statistics(char val[SIZE])//统计信息 
{ char choose;
  int  a;
  //printf("%s\n",val);
  printf("统计信息");
  printf("请选择功能\n");
  printf("\n");
  printf("1.统计自己开设的课程总数\n");
  printf("2.按选课人数排序所有开设过的课程\n"); 
  scanf("%c",&choose);
  getchar();
  switch(choose)
  { case 49:
  	 { a=teacherlookself(val);
  	   printf("数目为：%d",a);
  	   break;
	 }
	 case 50:
	{ 
		searchTeacher(val);
		break;
		
	}
  	 
  	
  }
  
}


void addcourse(char val[SIZE])
{   int c=1;//判断变量 
    int i=0;//记录老师的位置 
    int m=0;//循环变量
    int choose;//选择变量 
    int kaike;//开课选择变量 
	int ident=0;//记录选修个数
	int recordid=0;//记录课程个数 ，并不是结构体的下标。—1 
    char tem[SIZE];//临时储存val
    char temdate[SIZE][SIZE];//临时储存时间 
    char temident[SIZE][SIZE];//临时储存性质
	int temk[4];//临时记录开始时间 
	int temj[4]; 
    strcpy(tem,val);
    FILE *fp1;//用来打开addcoursedate.txt
	FILE *fp2;//用来打开addcourseidentify.txt 
    FILE *fp3;//用来打开coursemessage.txt
	FILE *fp4;//用来打开course.txt 
    getdatecourse("course.txt",&course);
    getdateteacher("teacher.txt",&teacher);
    fp1=fopen("addcoursedate.txt","w");
    //printf("%s",teacher[0].teacherid);
    for(i=0;i<SIZE;i++)//i之后不再变化 
    {
   	   if(!strcmp(teacher[i].teacherid,tem))
      {
   	    //printf("\n教师名称：%s\n", teacher[i].name);
           // continue;
           break;
      }				
    }
    for(m=0;m<SIZE;m++)
    {  if(strcmp(course[m].teacher,teacher[i].name))
       { 
         continue;
	   }
	   fprintf(fp1,"%s\n",course[m].date);
    }
	fclose(fp1);
	fp1=fopen("addcoursedate.txt","r");
	for(m=0;m<SIZE;m++)
	{ 
	  fscanf(fp1,"%s\n",&temdate[m]);	
	}
	fclose(fp1);
	//printf("%s\n",temdate[3]);
	fp2=fopen("addcourseidentify.txt","w");
	for(m=0;m<SIZE;m++)
    {  if(strcmp(course[m].teacher,teacher[i].name))
       { 
         continue;
	   }
	   fprintf(fp2,"%s\n",course[m].identify);
    }
    fclose(fp2);
    fp2=fopen("addcourseidentify.txt","r");
    for(m=0;m<SIZE;m++)
	{ 
	  fscanf(fp2,"%s\n",&temident[m]);	
	} 
	for(m=0;m<SIZE;m++)
	{  
	  if(!strcmp(temident[m],"选修"))
	    { ident++;}	
	}
	if(ident>=2)
	{  
	  printf("您本学期已开满2门选修课，是否继续开设必修课程?\n");
	  printf("1.是2.否\n");
	  scanf("%d",&kaike);
	  if(kaike==2)
	  { exit(1);
		  }	
		
	}
	//printf("%d",ident);
	for(m=0;m<SIZE;m++)
	{
		if(course[m].courseid!=NULL)
		   {recordid++;}
	}
	//printf("%d",recordid);
	while(c)
	{
	printf("请输入要添加的课程名称：\n");
	scanf("%s",&newcourse.name);
	for(m=0;m<SIZE;m++)
	 {  
	    if(!strcmp(newcourse.name,course[m].name))
	     {   c=1;//m=0;
	         printf("课程名重复，请重新输入\n");
	         //scanf("%s",&newcourse.name);
	         break;
		 }
		else
		{c=0;}
	 }
	 continue;
	}
	printf("%s",newcourse.name);
	c=1;
	while(c)                               //将所有文件中：改为英文形式 
	{
	printf("请输入上课时间：\n");
	scanf("%s",&newcourse.date);
	for(m=0;m<SIZE;m++)
	 {  
	    if(!strcmp(newcourse.date,temdate[m]))
	     {   c=1;//m=0;
	         printf("上课时间冲突,请重新输入\n");
	         //printf("%s",temdate); 
	         //scanf("%s",&newcourse.name);
	         break;
		 }
		else
		{c=0;}
	 }
	 continue;
	}
	printf("%s",newcourse.date);
	
	printf("请输入课程学分：");
    scanf("%d",&newcourse.credit);
    printf("请输入学时：");
    scanf("%d",&newcourse.period);
    printf("请输入上课地点：");
    scanf("%s",newcourse.site);
    printf("请输入课程简介：");
    scanf("%s",newcourse.brief);
    printf("请输入教材信息：");
    scanf("%s",newcourse.book);
    printf("请输入开课学院：");
	scanf("%s",&newcourse.apartment); 
    /**/
	printf("请输入上课时间（周）201_年~201_年第_学期第_周---201_年~201_年第_学期第_周\n");
	printf("结束周数必须大于10\n"); 
	scanf("%d%d%d%d%d%d%d%d",&temk[0],&temk[1],&temk[2],&temk[3],&temj[0],&temj[1],&temj[2],&temj[3]); 
	newcourse.kaishi=temk[0]*1000+temk[1]*100+temk[2]*10+temk[3];
	newcourse.jieshu=temj[0]*10000+temj[1]*1000+temj[2]*100+temj[3];
	printf("%d %d\n",newcourse.kaishi,newcourse.jieshu); 
	printf("请选择上课人数\n");
	printf("1.80人   2.100人\n");
	scanf("%d",&choose);
	switch(choose)
	{ case 1:
		{newcourse.number=80;
		 newcourse.shengyu=80;
		 newcourse.suanke=0;
		 break;
		}
	  case 2:
	  	{ newcourse.number=100;
	  	  newcourse.shengyu=100;
	  	  newcourse.suanke=0;
	  	  break;
	  	}
	}
	newcourse.courseid=course[(recordid-1)].courseid+1;
	printf("您新开设的课程编号为%d",newcourse.courseid);
	fp3=fopen("coursemessage.txt","a");
	fprintf(fp3,"%d %d %d\n",newcourse.courseid,newcourse.suanke,newcourse.shengyu);
	fclose(fp3);
	fp4=fopen("course.txt","a");
	fprintf(fp4,"%d  %s %d %d %s %s %s %s %d %s %s %s %d %d %d %d\n",newcourse.courseid,newcourse.name,newcourse.credit,newcourse.period,newcourse.identify,newcourse.teacher,newcourse.date,newcourse.site,newcourse.number,newcourse.brief,newcourse.book,newcourse.apartment,newcourse.kaishi,newcourse.jieshu,newcourse.suanke,newcourse.shengyu);
	fclose(fp4);
	printf("开课成功\n"); 
	
}


void teachermanagement(char val[SIZE])
{
	//printf("%s\n",val);
	printf("成功进入个人信息管理");
	 
	teacheralter(val);
	back();
	
}
void teacheralter(char val[SIZE])
{  int choose;
   int i=0,m=0;
   FILE *fp;
   char newmail[SIZE];
   char newkey[SIZE];
   getdateteacher("teacher.txt",&teacher);
   for(i=0;i<SIZE;)
   {
   	 if(strcmp(teacher[i].teacherid,val))
       {   i++;
		   continue; 
	   }
     break;			     	
   }
   printf("请选择修改的内容。\n");
   printf("\n");
   printf("1.邮箱\n"); 
   printf("2.密码\n");
   //getchar();
   scanf("%c",&choose);
   getchar();
   switch(choose)
   { case 49:
   	  { printf("请输入新邮箱\n");
   	    gets(newmail);
   	    strcpy(teacher[i].mail,newmail);
   	    break;
   	  }
   	  case 50:
   	  {  printf("请输入新密码\n");
	     gets(newkey);
	     strcpy(teacher[i].key,newkey);
	     break;
   	  }
   	}
   	
   	fp=fopen("teacher.txt","w");
   	for(m=0;m<SIZE;m++)
   	{ if(teacher[m].teacherid==NULL)
   	  {
        break;		 }
      fprintf(fp,"%s %s %s %s %s\n",teacher[m].teacherid,teacher[m].apartment,teacher[m].name,teacher[m].mail,teacher[m].key);     
   	}
   	fclose(fp);
   	printf("修改成功\n");
   	
}

void delstudent(char val[100],int num)
{ 
  FILE *f1;
  long length;
  char *f2;//用于记录要保存的内容     
  char s[100];//用于保存每次读取的一行内容    
  int n;//用于存储编号     
  f1=fopen(val,"r");//以读的方式打开文件     
  fseek(f1,0,2);//文件指针移到文件尾    
  length=ftell(f1);//取得文件长度     
  f2=(char *)malloc(sizeof(char)*length);//给f2分配文件长度的空间    
  *f2=0;//使得f2字符串的长度初始为0        
  rewind(f1);//文件指针回到文件头     
  while(ftell(f1)<length-3)
  {//当文件没有结束时就依次读取文件的每一行         
  fgets(s,100,f1);//读取一行信息         
  n=atoi(s);//从读取的信息取得编号         
  if(n==num) 
  continue;//如果编号是要删除的编号，就不用保存这一行信息了        
   strcat(f2,s);//保存读取到的这一行信息    
    }      
    fclose(f1);//关闭文件     
    f1=fopen(val,"w");//重新以写的方式打开文件     
    fputs(f2,f1);
    //把保存的信息重新存储到文件当中     
    fclose(f1);//关闭文件 
    printf("成功删除课程。"); 
    }

int teacherlookself(char val[SIZE])
{
	
    int i,a,b=0;
    int m=0;
    getdatecourse("course.txt",&course);
    getdateteacher("teacher.txt",&teacher);
   
    //printf("%s\n",val);
    //printf("%s\n",teacher[0].teacherid);
   
     
	m=0;
	for(m=0;m<SIZE;m++)
	{  if(strcmp(teacher[m].teacherid,val))
	     break;
	}        //m是所选课程在数据库中的位置 

	   
    
	//printf("%d\n",m); 
	//printf("%s",teacher[m].name);
    printf("我开设的课程如下：\n"); 
    printf("课程编号      课程名称	学分	学时	课程性质	开课教师	上课时间	上课地点   课容量      教材      选课人数	 \n");
  for(i=0;i<SIZE;i++)
  {  
          a=strcmp(course[i].teacher,teacher[m].name);
          if(a==0)          
          {
		  printf("%d      %s	%d	%d	%s	%s %s %-6s %d  %-4s %d\n",course[i].courseid,course[i].name,course[i].credit,course[i].period,course[i].identify,   
                                                                       course[i].teacher,course[i].date,course[i].site,course[i].number,course[i].book,course[i].suanke);    
           b++;}
  }
	
	return b;
	
}

void teachersearchcourse()
{   int a;//记录课程号 
    int i;
    getdatestudent("student.txt",&student);
    printf("请输入课程号。\n");
	scanf("%d",&a);
	//getchar();
	//printf("%d",a);
	//printf("%s",student[0].phone);
	//printf("%d",student[0].one); 
	for(i=0;i<SIZE;i++)
	{  
	   if((student[i].one==a||student[i].two==a||student[i].three==a)&&student[i].studentid!=NULL)
	   {
	   	printf("%s %s %s %s %s %s %s\n",student[i].studentid,student[i].name,student[i].gender,student[i].apatment,student[i].major,student[i].phone,student[i].mail);
	   }
	   else
	   {continue;
	   }
	}
	printf("查询完成\n"); 
}
void delteachercourse()
{
	int num;
    int xuanze;
        do
        {
        printf("请输入要删除的课程编号：\n");
        scanf("%d",&num);
        del(num);
        printf("删除成功！1：继续删除 2：退出");
        scanf("%d",&xuanze);
        }while(xuanze==1);
	
}

void del(int num)
{
FILE *f1;
long length;
char *f2;//用于记录要保存的内容     
char s[100];//用于保存每次读取的一行内容    
 int n;//用于存储编号     
 f1=fopen("course.txt","r");//以读的方式打开文件     
 fseek(f1,0,2);//文件指针移到文件尾    
 length=ftell(f1);//取得文件长度     
 f2=(char *)malloc(sizeof(char)*length);//给f2分配文件长度的空间    
  *f2=0;//使得f2字符串的长度初始为0        
  rewind(f1);//文件指针回到文件头     
  while(ftell(f1)<length-3)
  {//当文件没有结束时就依次读取文件的每一行         
  fgets(s,100,f1);//读取一行信息         
  n=atoi(s);//从读取的信息取得编号         
  if(n==num) 
  continue;//如果编号是要删除的编号，就不用保存这一行信息了        
   strcat(f2,s);//保存读取到的这一行信息    
    }      
    fclose(f1);//关闭文件     
    f1=fopen("course.txt","w");//重新以写的方式打开文件     
    fputs(f2,f1);
    //把保存的信息重新存储到文件当中     
    fclose(f1);//关闭文件 
}
void back()
{
	char choose100;
	char choose200;
	printf("您想返回登录界面还是退出程序？请选择：\n");
	printf("1.返回登录界面.\n");
	printf("2.退出程序.\n");
	//printf(" \n");
	
	scanf("%c",&choose100);
	getchar();
	 switch(choose100)
  { case 49:
  	 { 
  	   system("cls");
  	   printf("返回老师还是学生登录界面");
  	   printf("1.老师2.学生"); 
  	   scanf("%c",&choose200);
  	   getchar();
  	   switch(choose200)
  	   { case 49:{logfunction(choose200);break;}
  	   	 case 50:{logfunction(choose200);break;}  
	   }
  	    
  	   break;
	 }
	case 50:
		{system("cls");
		printf("                                                \n");
        printf("                                                \n");
        printf("                                                \n");
        printf("                                                \n");
        printf("                                                \n"); 
		printf("                         你已经退出程序");
		  break;
		}
  	
  }
	
}
void searchTeacher(char id[SIZE])
{   
    TEACHER teacher[SIZE];
	FILE *inFile,*teaFile;
	int i,j,k=0,n;
   
    teaFile = fopen("teacher.txt","r");//打开教师文件 
	if(teaFile == NULL)
    {
              printf("\nFailed to open the file.\n");
              system("pause");
              exit(1);
    } 
    
      for(j=0;j<SIZE;j++)//读取文件内容 
    {
    fscanf(teaFile, "%s  %s  %s  %s  %s\n",teacher[j].teacherid,teacher[j].apartment,teacher[j].name,teacher[j].mail,teacher[j].key);
    }
    
    
     
	  for(i=0;i<SIZE;i++)//i之后不再变化 
    {
   	   if(!strcmp(teacher[i].teacherid,id))
      {
   	    printf("\n教师名称：%s\n", teacher[i].name);
           // continue;
           break;
      }				
    }
    fclose(teaFile);
    
  
    
   	inFile = fopen("course.txt","r");//打开选课文件 
    
    if(inFile == NULL)
    {
              printf("\nFailed to open the file.\n");
              system("pause");
              exit(1);
    } 
    
   
    for(j=0;j<SIZE;j++)//读取文件内容 
    {
    fscanf(inFile, "%d %s %d %d %s %s %s %s %d %s %s %s  %d %d %d %d",&course[j].courseid,course[j].name,&course[j].credit, &course[j].period,course[j].identify,course[j].teacher,course[j].date,course[j].site,&course[j].number,course[j].brief,course[j].book,course[j].apartment,&course[j].kaishi,&course[j].jieshu,&course[j].suanke,&course[j].shengyu );
    }
    
    
    
   for(k=0; k<(SIZE-1); k++)  //排序
    {
        for(j=1; j<SIZE; j++)
        {
            
            if(course[j].suanke > course[j-1].suanke)
            {
               temp3 = course[j-1];
               course[j-1] = course[j];
               course[j] = temp3;
            }
        }
        
    }
    
    
    printf("\n开设课程如下（按照选课人数排序）：\n");
  
    n=0;
    for(k=0;k<SIZE;k++)
    {
   	if(!strcmp(course[k].teacher,teacher[i].name))
       {
   	        printf("%d%s %d %d %s %s %s %s %d %s %s %s %d\n",course[k].courseid, course[k].name, course[k].credit, course[k].period, course[k].identify, course[k].teacher, course[k].date, course[k].site, course[k].number,course[k].brief, course[k].book,course[k].apartment,course[k].suanke);
            n++;
			continue;
       }				
    }
    printf("课程总数：%d\n\n",n);
 
fclose(inFile);
}


 
