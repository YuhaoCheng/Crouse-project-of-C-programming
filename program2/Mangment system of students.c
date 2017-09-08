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
  char phone[SIZE];//�޸Ĺ�����int�ĳ�char 
  char key[SIZE];
  char mail[SIZE];
  int  one;/*ѧ��ѡ�Ŀγ̵ı��*/
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
void getdatestudent(char [SIZE],struct message1 *);//��ȡѧ����Ϣ 
void getdateteacher(char [SIZE],struct message2 *);//��ȡ��ʦ��Ϣ 
void getdatecourse(char [SIZE],struct message3 *); //��ȡ�γ���Ϣ 
void delstudent(char [100],int);//ɾ������ 
void teacherlog();//��ʦ��¼ 
void studentlog();//ѧ����¼ 
void teacherfunction(char [SIZE]);// ��ʦ���� 
void studentfunction(char [SIZE]);//ѧ������ 
void studentselectcourse(char [SIZE]);//ѧ��ѡ��ϵͳ 
void studentlookcourse(char [SIZE]);//�鿴ѡ�޵Ŀγ� 
void search();//���ݿγ����ƣ�ѧԺ��ѯ
void paixu();//���ݿ�������ѡ���������� 
void studentalter(char [SIZE]);//�޸�ѧ�����˵���Ϣ
void teacherlookcourse(char [SIZE]);//�鿴ѡ����� 
void teacherdel(char [SIZE]);
void delcourse(char [SIZE]);//ɾ���γ�
void del(int);//ɾ��ĳ���γ̺ŵĿγ� 
void delc(int);
void delcm(int);
void dels(char [SIZE],int);
void statistics(char [SIZE]);//ͳ����Ϣ
void  xiugai();//�޸���Ϣ  
int teacherlookself(char [SIZE]);//�鿴�Լ�����Ŀγ� 
void teachersearchcourse();//���ݿγ̺Ų�ѯѧ����Ϣ
void searchTeacher(char[SIZE]);//����id���ҽ�ʦ���Ƽ���Ϣ������ 
void addcourse(char [SIZE]);//��ӿγ�
//void delteachercourse();//ɾ���γ�  
void teacheralter(char [SIZE]);//�޸���ʦ���˵���Ϣ 
void back();//���ص���¼���� 

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
  printf("                         ��ӭ����ѧ��ѡ�ι���ϵͳ   \n");
  printf("                                                \n");
  printf("                         ��ѡ������Ҫ�Ĺ���\n") ; 
  printf("                                                \n");
  printf("                           1.�û���½\n");
  printf("                           2.�˳�����\n ");
  scanf("%c",&choose1);
  getchar();
  while(choose1!=49&&choose1!=50)
  { system("cls");
    printf("                         �����������ٴγ���   \n");
    printf("                                              \n");
    printf("                         ��ѡ������Ҫ�Ĺ���     \n");
    printf("                                              \n");
    printf("                           1.�û���½\n");
    printf("                                     \n");
    printf("                           2.�뿪ϵͳ  \n");
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
	   printf("                         �������������\n");
	   printf("                                     \n");
  	   printf("                           1.��ʦ \n");
  	   printf("                           2.ѧ�� \n");
  	   printf("                           3.�뿪����         ");
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
		printf("                         ���Ѿ��˳�����");
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
  /**/printf("                         ��������Ľ�ʦ����.\n");
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
   {printf("                         ������������������;���������ѡ���˳�\n");
    printf("                                                                \n");
   	printf("                         ��ѡ��\n");
   	printf("                                  \n");
   	printf("                         1.��������.\n");
   	printf("                         2.�˳�����.\n");
   	scanf("%c",&a);
   	getchar();
   	switch(a)
   	{case 49:
   		{  printf("\n");
		   printf("                         ������Ĺ���.\n");
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
   printf("                         ϵͳ��֤���ųɹ�~\n");
   printf("                                          \n");
   /**/i=0;
   printf("                         �������������:\n");
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
    printf("                         �������������������������;����������˳�����.\n");
   	printf("                                                                           \n");
   	printf("                         ��ѡ��:\n");
   	printf("                                \n");
   	printf("                         1.��������.\n");
   	printf("                         2.�˳�����.\n");
   	scanf("%c",&a);
   	getchar();
   	switch(a)
   	{ case 49:
      { printf("                         �������������\n");
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
   printf("                         ��ʦ�˵�¼�ɹ�\n");
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
      printf("                         ���������ѧ��.\n");
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
   {printf("                         �������ѧ����������������;����������˳�����\n");
   	printf("\n");
   	printf("                         ��ѡ��\n");
   	printf("\n");
   	printf("                         1.��������.\n");
   	printf("                         2.�˳�����.\n");
   	printf(" \n");
   	scanf("%c",&a);
   	getchar();
   	switch(a)
   	{case 49:
   		{ printf("�������ѧ��.\n");
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
   printf("                         ѧ����ѧ��ȷ�ϳɹ�\n");
   printf(" \n");
   /**/i=0;
   printf("                         �������������\n");
   	while((i<(SIZE-1))&&((d=getchar())!='\n'))   
   {   messageKEY[i]=d;
       i++;
   }
   messageKEY[i]='\0';
   
   
   
  /* */ while(strcmp(student[m].key,messageKEY))
   {
   	system("cls");
   	printf("                         ������������������������룻���������ѡ���˳�����\n");
   	printf("\n");
   	printf("                         ��ѡ��\n");
   	printf("\n");
   	printf("                         1.��������.\n");
   	printf("                         2.�˳�����.\n"); 
   	printf(" \n");
   	scanf("%c",&a);
   	getchar();
   	switch(a)
   	{ case 49:
      { printf("                         �������������\n");
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
   printf("                         ѧ���˵�¼�ɹ�\n");
   system("cls");
   studentfunction(messageID);
  
}

void studentfunction(char val[SIZE])
{ char choose;
  void  studentselectcourse(char [SIZE]);//ѡ��ϵͳ 
  void  studentinqurecourse(char [SIZE]);//��ѯ�γ� 
  void  studentmanagement(char [SIZE]);//������Ϣ���� 
  system("cls");
  printf("                                                \n");
  printf("                                                \n");
  printf("                                                \n");
  printf("                                                \n");
  printf("                                                \n");
  printf("                         ��ӭ����ѧ���������    \n");
  printf("\n"); 
  printf("                         ��ѡ������Ҫ�Ĺ���:    \n");
  printf("\n");
  printf("                         1.ѡ��                 \n");
  printf("                         2.��ѯ�γ�             \n");
  printf("                         3.������Ϣ����         \n");
  printf("                         4.�˳�ϵͳ             \n");
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
{   printf("�ɹ�����ѡ�ι���\n");
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
    int p=1;//ָʾ����p=0ѡ��ʧ�ܣ�p=1ѡ�γɹ� 
    int k[4];
    int j[4];
    int id[SIZE];
    strcat(val,".txt");
    fp1=fopen(val,"r");
    getdatecourse("course.txt",&course);
    //system("mode concols=1366 lines=768");
    printf("�γ̱��    �γ�����   ѧ��  ѧʱ   ����   ��ʦ   �Ͽ�ʱ��   �Ͽεص�   ����   �γ̼��    �̲���Ϣ              ��ֹʱ��\n");
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
	  printf("201%d��-201%d���%dѧ�ڵ�%d��~",k[0],k[1],k[2],k[3]);
	  printf("201%d��-201%d���%dѧ�ڵ�%d��\n",j[0],j[1],j[2],k[3]);
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
    	printf("ѡ�β��ܳ�������");
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
    printf("������γ̱��.\n");//��ʾ�û�Ϊ6λ���� 
    printf("\n");
	scanf("%d",&a);
	//getchar();
	//printf("%d\n",a);
	 
	e=0;//��ѡ�γ���coursemessage�е�λ��
	while(a!=coursem[e].msid)
	{e++;}
	printf("%d\n",e);
	if(coursem[e].snumber==80||coursem[e].snumber==100)
	  {
	    printf("�γ�����.");
	    p=0;
	  }
	else
	{ 
		coursem[e].snumber=coursem[e].snumber+1;
		coursem[e].ynumber=coursem[e].ynumber-1;
    } 
    printf("%d\n%d\n",coursem[e].snumber,coursem[e].ynumber);
   /* for(m=0;m<SIZE;m++)                                         //�������ݿ��е��ļ�                            
    {
    	fprintf(fp2,"%d   %d    %d",coursem[m].msid,coursem[m].snumber,coursem[m].ynumber);
    	
	}*/
    
    
    
    
    
    
	fp3=fopen(val,"a");
	b=0;
	while(a!=course[b].courseid)//b����ѡ�γ������ݿ��е�λ�� 
	{b++;}
	//printf("%d\n",b);
	while(id[0]!=course[c].courseid)//c����ѡ�ĵ�һ�Ŀγ������ݿ��е�λ�� 
	{c++;}
	//printf("%d\n",c);
	while(id[1]!=course[d].courseid)//b����ѡ�ĵڶ����γ������ݿ��е�λ�� 
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
		printf("ѡ�γɹ�~\n");
		fprintf(fp3,"%d\n",a);  
		   for(m=0;m<SIZE;m++)                                         //�������ݿ��е��ļ�                            
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
   	   printf("ѡ��ʧ��.\n");
   	   fclose(fp2);
   	   fclose(fp3);
   	   exit(1);
     }
    
    
	
}
void studentinquirecourse(char val[SIZE])
{   char choose;

	printf("�ɹ������ѯ�γ̹���\n");
	printf("1.���ݿγ����򿪿�ѧԺ��ѯ\n.2.���ݿ����������ѡ���������пγ�.\n");
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
    
    printf("1---�γ�����\n");
    printf("2---ѧԺ����\n");
    printf("�������ѡ��");
	scanf("%d",&i);
	getchar();
	 
	if(i==1)
{
	 for(j=0;j<SIZE;j++)
    {
    fscanf(inFile, "%d %s %d %d %s %s %s %s %d %s %s %s %d %d %d %d",&course[j].courseid,course[j].name,&course[j].credit, &course[j].period,course[j].identify,course[j].teacher,course[j].date,course[j].site,&course[j].number,course[j].brief,course[j].book,course[j].apartment,&course[j].kaishi,&course[j].jieshu,&course[j].shengyu,&course[j].suanke );
    }
    
    
   
    printf("������Ҫ��ѯ�Ŀγ�����:");
  
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
    
  
    printf("������Ҫ��ѯ��ѧԺ���ƣ�");
    
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
void paixu()//���� 
{
     
    FILE *inFile;
    int i,j,k=0,n,p=0,q=0;
    //char coursename[SIZE];
    
    
	printf("1---����ѡ����������\n");
	printf("2---���տ���������\n");
	printf("����������ѡ��1 �� 2����\n");
	scanf("%d",&i); 
	 
	 
	inFile = fopen("course.txt","r");//kecheng(xuankerenshu)
    
    if(inFile == NULL)
    {
              printf("\n�򿪿γ��ļ�ʧ��.\n");
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
  //char a[SIZE];//����뷵��Ҫ���Ӻ��������¸����ַ��� 
  //char b[SIZE];
  system("cls");
  printf("                                                \n");
  printf("                                                \n");
  printf("                                                \n");
  printf("                                                \n");
  printf("                                                \n");
  printf("                         �ɹ����������Ϣ����    \n");
  printf("\n"); 
  //printf("%s\n",val);
  printf("                         ��ѡ������Ҫ�Ĺ���:    \n");
  printf("\n");
  printf("                         1.�鿴ѡ�޵Ŀγ�                \n");
  printf("                         2.ɾ���γ�             \n");
  printf("                         3.�޸ĸ�����Ϣ         \n");
  printf("                         4.�˳���Ϣ             \n");
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
	   studentlookcourse(val);//�Ѿ���Ϊ��************.txt 
  	    //strcpy(a,val);
  	    //strcat(a,".txt");
  	    puts(val);
  	    printf("��������Ҫɾ���Ŀγ̱�š�\n");
  	    //getchar();
		scanf("%d",&shanchu);
  	    //getchar();
	    delstudent(val,shanchu);
	    //printf("ɾ���γ�\n");
	    back();
		break; 
     }
  	case 51:
  	{ system("cls");
	  printf("�޸ĸ�����Ϣ\n");
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
{   printf("�ɹ�����ѧ���鿴ѡ�޿γ̽���\n");
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
	       printf("201%d��-201%d���һѧ�ڵ�%d��~",k[0],k[1],k[2]);
	       printf("201%d��-201%d���һѧ�ڵ�%d��\n",j[0],j[1],j[2]);
	       break;
		   }
		 }
	} 
        	
    	
	//}
}
void studentalter(char val[SIZE])
{   printf("�ɹ�����ѧ��������Ϣ�޸Ľ���\n");   
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
   printf("��ѡ���޸�����\n");
   printf("1.����\n");
   printf("2.�绰\n");
   printf("3.����\n");
   printf("\n"); 
   //printf("%s",student[i].studentid);
   getchar();
   scanf("%c",&choose);
   getchar();
   switch(choose)
   { case 49:
   	  { 
		printf("���������������䡣\n");
   	    gets(newmail);
   	    strcpy(student[i].mail,newmail);
   	    break;
   	  }
   	  case 50:
	  { printf("�������µ绰\n");
	    gets(newphone);
		strcpy(student[i].phone,newphone); 
		break;
	  } 
	  case 51:
	  {  printf("������������\n");
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
   	printf("�޸ĳɹ�.\n");
   	
}





void teacherfunction(char val[SIZE])
{ char choose;
  void teacherselectcourse(char [SIZE]);//ѡ�ι�������Լ� 
  void teachermanagecourse(char [SIZE]);//�γ̹�������Լ��Ŀγ� 
  void teachermanagement(char [SIZE]);// ������Ϣ�Ĺ��� 
  printf("                                                \n");
  printf("                                                \n");
  printf("                                                \n");
  printf("                                                \n");
  printf("                                                \n");
  printf("                         ��ӭ�����ʦ�������\n");
  printf("\n");
  printf("                         ��ѡ������Ҫ�Ĺ���:\n");
  printf("                            1.ѡ�ι���                    \n");
  printf("                            2.�γ̹���                    \n");
  printf("                            3.������Ϣ����                    \n");
  printf("                            4.�˳�ϵͳ                   \n");
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
  printf("�ɹ�����ѡ�ι���\n");
  printf("��ѡ����\n");
  printf("\n");
  printf("1.�鿴ѡ�����\n");
  printf("2.ɾ��ѡ��\n");
  printf("3.ͳ��ѡ����Ϣ\n");
  printf("4.�˳�����\n");
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
	printf("�ɹ�����γ̹���.\n");
	printf("\n");
	printf("1.��ӿγ�\n");
	printf("2.�޸Ŀγ���Ϣ\n");
	printf("3.ɾ���γ�\n");
	scanf("%c",&choose);
	getchar();
	switch(choose)
	{
	  case 49:
	  	{  printf("��ӿγ�");
		   addcourse(val);
		   break;
	  		
	  	}
	  case 50:
	    {
	      printf("�޸Ŀγ���Ϣ");
		  xiugai();	
		  break;
	    } 
	    case 51:
		{ printf("ɾ���γ�");
		  delcourse(val);
		  break;
		  } 
		
	}
	
}
void teacherlookcourse(char val[SIZE])//�鿴ѡ����� 
{ char choose;
  int  a;//��ʦ�Ŀ������� 
  //printf("%s\n",val);
  printf("�ɹ�����鿴ѡ��������� ");
  printf("��ѡ����.\n");
  printf("\n");
  printf("1.�鿴�Լ�����Ŀγ�\n");
  printf("2.��ѯĳ�ſε���Ϣ\n");
  scanf("%c",&choose);
  //printf("%c\n",choose);
  switch(choose)
  { case 49:
  	 { teacherlookself(val);
  	   break;
	   }
  	
  	case 50:
	  { teachersearchcourse();
	    //printf("�ɹ���ѯ");
	    break;
	   } 
  	
   } 
} 
void  xiugai()
 {                    
    FILE *inFile;
    int i,j,k=0,n=0,m;
    char coursename[SIZE];//���޸ĵĿγ����� 
    char newbook[SIZE];
    char newbrief[SIZE];
    int newnumber=0;
    
	inFile = fopen("course.txt","r");//��ȡ�ĵ����� //kecheng(xuankerenshu)
    
      if(inFile == NULL)
    {
              printf("\n�򿪿γ��ļ�ʧ��.\n");
              system("pause");
              exit(1);
    } 
    
      for(j=0;j<SIZE;j++)//���ļ����ݶ�ȡ���ṹ�� 
    {
    fscanf(inFile, "%d %s %d %d %s %s %s %s %d %s %s %s  %d %d %d %d\n",&course[j].courseid,&course[j].name,&course[j].credit, &course[j].period,&course[j].identify,&course[j].teacher,&course[j].date,&course[j].site,&course[j].number,&course[j].brief,&course[j].book,&course[j].apartment,&course[i].kaishi,&course[i].jieshu,&course[j].suanke,&course[j].shengyu);
    }
     fclose(inFile);
     
     
 
     inFile = fopen("course.txt","w");//��дģʽ���´��ĵ� kecheng(xuankerenshu)
     printf("������Ҫ�޸ĵĿγ�����:");
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
            printf("���ɸ��ĵ�ѡ���У�\n");
            printf("1---�̲���Ϣ\n");
            printf("2---�γ̼��\n");
            printf("3---��������\n");
            scanf("%d",&i);
           
            if(i==1)
            {
                printf("���еĽ̲����ƣ�%s\n",course[j].book);
                printf("�������޸ĺ�Ľ̲����ƣ�");
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
                    	printf("�޸ĳɹ���\n");
            }
			    
		
		          if(i==2)
            {
                    printf("���пγ̼�飺%s\n",course[j].brief);
                    printf("�������޸ĺ�Ŀγ̼�飺");
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
                    	printf("�޸ĳɹ�.\n");
            }
                           
                             
              if(i==3)
              {
                	printf("��ǰ����������%d\n",course[j].number);
                	printf("�������޸ĺ������������");
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
                    	printf("�޸ĳɹ�\n");
           }
				
          } 
		
 
       if(course[j].suanke != 0)
      
        {
           	printf("�ÿγ��ѱ�ѡ��ֻ�ܸ�������������\n");
            printf("��ǰ����������%d\n",course[j].number);
            printf("�������޸ĺ������������");
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
          	printf("�޸ĳɹ�\n"); 
		    
		}
		
  }
void teacherdel(char val[SIZE])//ɾ���γ� 
{//printf("%s\n",val);
  //printf("ɾ���γ�");
  delcourse(val);
}
void delcourse(char val[SIZE]) 
{   FILE *fp1;//������delcourse.txt
    FILE *fp2;//�����򿪸����ı� 
    int i;//ѭ������ 
    int temdelcourse[SIZE];
	int delcid;//��¼Ҫɾ���Ŀγ� 
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
	 printf("��������Ҫɾ���Ŀγ̱�š�\n");
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
     printf("ɾ���ɹ���1������ɾ�� 2���˳�");
     scanf("%d",&xuanze);
    }while(xuanze==1);
	/*int num;
    int xuanze;
    void del(int); 
    
    printf("������Ҫɾ���Ŀγ̱�ţ�\n");
    scanf("%d",&num);
    del(num);*/
    
	
}

void delc(int num)
{
FILE *f1;
long length;
char *f2;//���ڼ�¼Ҫ���������     
char s[100];//���ڱ���ÿ�ζ�ȡ��һ������    
 int n;//���ڴ洢���     
 f1=fopen("course.txt","r");//�Զ��ķ�ʽ���ļ�     
 fseek(f1,0,2);//�ļ�ָ���Ƶ��ļ�β    
 length=ftell(f1);//ȡ���ļ�����     
 f2=(char *)malloc(sizeof(char)*length);//��f2�����ļ����ȵĿռ�    
  *f2=0;//ʹ��f2�ַ����ĳ��ȳ�ʼΪ0        
  rewind(f1);//�ļ�ָ��ص��ļ�ͷ     
  while(ftell(f1)<length-3)
  {//���ļ�û�н���ʱ�����ζ�ȡ�ļ���ÿһ��         
  fgets(s,100,f1);//��ȡһ����Ϣ         
  n=atoi(s);//�Ӷ�ȡ����Ϣȡ�ñ��         
  if(n==num) 
  continue;//��������Ҫɾ���ı�ţ��Ͳ��ñ�����һ����Ϣ��        
   strcat(f2,s);//�����ȡ������һ����Ϣ    
    }      
    fclose(f1);//�ر��ļ�     
    f1=fopen("course.txt","w");//������д�ķ�ʽ���ļ�     
    fputs(f2,f1);
    //�ѱ������Ϣ���´洢���ļ�����     
    fclose(f1);//�ر��ļ� 
}
void delcm(int num)
{
FILE *f1;
long length;
char *f2;//���ڼ�¼Ҫ���������     
char s[100];//���ڱ���ÿ�ζ�ȡ��һ������    
 int n;//���ڴ洢���     
 f1=fopen("coursemessage.txt","r");//�Զ��ķ�ʽ���ļ�     
 fseek(f1,0,2);//�ļ�ָ���Ƶ��ļ�β    
 length=ftell(f1);//ȡ���ļ�����     
 f2=(char *)malloc(sizeof(char)*length);//��f2�����ļ����ȵĿռ�    
  *f2=0;//ʹ��f2�ַ����ĳ��ȳ�ʼΪ0        
  rewind(f1);//�ļ�ָ��ص��ļ�ͷ     
  while(ftell(f1)<length-3)
  {//���ļ�û�н���ʱ�����ζ�ȡ�ļ���ÿһ��         
  fgets(s,100,f1);//��ȡһ����Ϣ         
  n=atoi(s);//�Ӷ�ȡ����Ϣȡ�ñ��         
  if(n==num) 
  continue;//��������Ҫɾ���ı�ţ��Ͳ��ñ�����һ����Ϣ��        
   strcat(f2,s);//�����ȡ������һ����Ϣ    
    }      
    fclose(f1);//�ر��ļ�     
    f1=fopen("coursemessage.txt","w");//������д�ķ�ʽ���ļ�     
    fputs(f2,f1);
    //�ѱ������Ϣ���´洢���ļ�����     
    fclose(f1);//�ر��ļ� 
}
void dels(char val[SIZE],int num)
{
FILE *f1;
long length;
char *f2;//���ڼ�¼Ҫ���������     
char s[100];//���ڱ���ÿ�ζ�ȡ��һ������    
 int n;//���ڴ洢���     
 f1=fopen(val,"r");//�Զ��ķ�ʽ���ļ�     
 fseek(f1,0,2);//�ļ�ָ���Ƶ��ļ�β    
 length=ftell(f1);//ȡ���ļ�����     
 f2=(char *)malloc(sizeof(char)*length);//��f2�����ļ����ȵĿռ�    
  *f2=0;//ʹ��f2�ַ����ĳ��ȳ�ʼΪ0        
  rewind(f1);//�ļ�ָ��ص��ļ�ͷ     
  while(ftell(f1)<length-3)
  {//���ļ�û�н���ʱ�����ζ�ȡ�ļ���ÿһ��         
  fgets(s,100,f1);//��ȡһ����Ϣ         
  n=atoi(s);//�Ӷ�ȡ����Ϣȡ�ñ��         
  if(n==num) 
  continue;//��������Ҫɾ���ı�ţ��Ͳ��ñ�����һ����Ϣ��        
   strcat(f2,s);//�����ȡ������һ����Ϣ    
    }      
    fclose(f1);//�ر��ļ�     
    f1=fopen(val,"w");//������д�ķ�ʽ���ļ�     
    fputs(f2,f1);
    //�ѱ������Ϣ���´洢���ļ�����     
    fclose(f1);//�ر��ļ� 
} 
void teacherlookselfdel(char val[SIZE])
{
	
    int i,a,b=0;
    int m=0;
    getdatecourse("course.txt",&course);
    getdateteacher("teacher.txt",&teacher);
    FILE *fp;//������delcourse.txt 
    //printf("%s\n",val);
    //printf("%s\n",teacher[0].teacherid);
    m=0;
	for(m=0;m<SIZE;m++)
	{  if(strcmp(teacher[m].teacherid,val))
	     break;
	}        //m����ѡ�γ������ݿ��е�λ�� 
    //printf("%d\n",m); 
	//printf("%s",teacher[m].name);
	fp=fopen("delcourse.txt","w");
    printf("�ҿ���ɾ���Ŀγ̣�\n"); 
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
void statistics(char val[SIZE])//ͳ����Ϣ 
{ char choose;
  int  a;
  //printf("%s\n",val);
  printf("ͳ����Ϣ");
  printf("��ѡ����\n");
  printf("\n");
  printf("1.ͳ���Լ�����Ŀγ�����\n");
  printf("2.��ѡ�������������п�����Ŀγ�\n"); 
  scanf("%c",&choose);
  getchar();
  switch(choose)
  { case 49:
  	 { a=teacherlookself(val);
  	   printf("��ĿΪ��%d",a);
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
{   int c=1;//�жϱ��� 
    int i=0;//��¼��ʦ��λ�� 
    int m=0;//ѭ������
    int choose;//ѡ����� 
    int kaike;//����ѡ����� 
	int ident=0;//��¼ѡ�޸���
	int recordid=0;//��¼�γ̸��� �������ǽṹ����±ꡣ��1 
    char tem[SIZE];//��ʱ����val
    char temdate[SIZE][SIZE];//��ʱ����ʱ�� 
    char temident[SIZE][SIZE];//��ʱ��������
	int temk[4];//��ʱ��¼��ʼʱ�� 
	int temj[4]; 
    strcpy(tem,val);
    FILE *fp1;//������addcoursedate.txt
	FILE *fp2;//������addcourseidentify.txt 
    FILE *fp3;//������coursemessage.txt
	FILE *fp4;//������course.txt 
    getdatecourse("course.txt",&course);
    getdateteacher("teacher.txt",&teacher);
    fp1=fopen("addcoursedate.txt","w");
    //printf("%s",teacher[0].teacherid);
    for(i=0;i<SIZE;i++)//i֮���ٱ仯 
    {
   	   if(!strcmp(teacher[i].teacherid,tem))
      {
   	    //printf("\n��ʦ���ƣ�%s\n", teacher[i].name);
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
	  if(!strcmp(temident[m],"ѡ��"))
	    { ident++;}	
	}
	if(ident>=2)
	{  
	  printf("����ѧ���ѿ���2��ѡ�޿Σ��Ƿ����������޿γ�?\n");
	  printf("1.��2.��\n");
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
	printf("������Ҫ��ӵĿγ����ƣ�\n");
	scanf("%s",&newcourse.name);
	for(m=0;m<SIZE;m++)
	 {  
	    if(!strcmp(newcourse.name,course[m].name))
	     {   c=1;//m=0;
	         printf("�γ����ظ�������������\n");
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
	while(c)                               //�������ļ��У���ΪӢ����ʽ 
	{
	printf("�������Ͽ�ʱ�䣺\n");
	scanf("%s",&newcourse.date);
	for(m=0;m<SIZE;m++)
	 {  
	    if(!strcmp(newcourse.date,temdate[m]))
	     {   c=1;//m=0;
	         printf("�Ͽ�ʱ���ͻ,����������\n");
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
	
	printf("������γ�ѧ�֣�");
    scanf("%d",&newcourse.credit);
    printf("������ѧʱ��");
    scanf("%d",&newcourse.period);
    printf("�������Ͽεص㣺");
    scanf("%s",newcourse.site);
    printf("������γ̼�飺");
    scanf("%s",newcourse.brief);
    printf("������̲���Ϣ��");
    scanf("%s",newcourse.book);
    printf("�����뿪��ѧԺ��");
	scanf("%s",&newcourse.apartment); 
    /**/
	printf("�������Ͽ�ʱ�䣨�ܣ�201_��~201_���_ѧ�ڵ�_��---201_��~201_���_ѧ�ڵ�_��\n");
	printf("���������������10\n"); 
	scanf("%d%d%d%d%d%d%d%d",&temk[0],&temk[1],&temk[2],&temk[3],&temj[0],&temj[1],&temj[2],&temj[3]); 
	newcourse.kaishi=temk[0]*1000+temk[1]*100+temk[2]*10+temk[3];
	newcourse.jieshu=temj[0]*10000+temj[1]*1000+temj[2]*100+temj[3];
	printf("%d %d\n",newcourse.kaishi,newcourse.jieshu); 
	printf("��ѡ���Ͽ�����\n");
	printf("1.80��   2.100��\n");
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
	printf("���¿���Ŀγ̱��Ϊ%d",newcourse.courseid);
	fp3=fopen("coursemessage.txt","a");
	fprintf(fp3,"%d %d %d\n",newcourse.courseid,newcourse.suanke,newcourse.shengyu);
	fclose(fp3);
	fp4=fopen("course.txt","a");
	fprintf(fp4,"%d  %s %d %d %s %s %s %s %d %s %s %s %d %d %d %d\n",newcourse.courseid,newcourse.name,newcourse.credit,newcourse.period,newcourse.identify,newcourse.teacher,newcourse.date,newcourse.site,newcourse.number,newcourse.brief,newcourse.book,newcourse.apartment,newcourse.kaishi,newcourse.jieshu,newcourse.suanke,newcourse.shengyu);
	fclose(fp4);
	printf("���γɹ�\n"); 
	
}


void teachermanagement(char val[SIZE])
{
	//printf("%s\n",val);
	printf("�ɹ����������Ϣ����");
	 
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
   printf("��ѡ���޸ĵ����ݡ�\n");
   printf("\n");
   printf("1.����\n"); 
   printf("2.����\n");
   //getchar();
   scanf("%c",&choose);
   getchar();
   switch(choose)
   { case 49:
   	  { printf("������������\n");
   	    gets(newmail);
   	    strcpy(teacher[i].mail,newmail);
   	    break;
   	  }
   	  case 50:
   	  {  printf("������������\n");
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
   	printf("�޸ĳɹ�\n");
   	
}

void delstudent(char val[100],int num)
{ 
  FILE *f1;
  long length;
  char *f2;//���ڼ�¼Ҫ���������     
  char s[100];//���ڱ���ÿ�ζ�ȡ��һ������    
  int n;//���ڴ洢���     
  f1=fopen(val,"r");//�Զ��ķ�ʽ���ļ�     
  fseek(f1,0,2);//�ļ�ָ���Ƶ��ļ�β    
  length=ftell(f1);//ȡ���ļ�����     
  f2=(char *)malloc(sizeof(char)*length);//��f2�����ļ����ȵĿռ�    
  *f2=0;//ʹ��f2�ַ����ĳ��ȳ�ʼΪ0        
  rewind(f1);//�ļ�ָ��ص��ļ�ͷ     
  while(ftell(f1)<length-3)
  {//���ļ�û�н���ʱ�����ζ�ȡ�ļ���ÿһ��         
  fgets(s,100,f1);//��ȡһ����Ϣ         
  n=atoi(s);//�Ӷ�ȡ����Ϣȡ�ñ��         
  if(n==num) 
  continue;//��������Ҫɾ���ı�ţ��Ͳ��ñ�����һ����Ϣ��        
   strcat(f2,s);//�����ȡ������һ����Ϣ    
    }      
    fclose(f1);//�ر��ļ�     
    f1=fopen(val,"w");//������д�ķ�ʽ���ļ�     
    fputs(f2,f1);
    //�ѱ������Ϣ���´洢���ļ�����     
    fclose(f1);//�ر��ļ� 
    printf("�ɹ�ɾ���γ̡�"); 
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
	}        //m����ѡ�γ������ݿ��е�λ�� 

	   
    
	//printf("%d\n",m); 
	//printf("%s",teacher[m].name);
    printf("�ҿ���Ŀγ����£�\n"); 
    printf("�γ̱��      �γ�����	ѧ��	ѧʱ	�γ�����	���ν�ʦ	�Ͽ�ʱ��	�Ͽεص�   ������      �̲�      ѡ������	 \n");
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
{   int a;//��¼�γ̺� 
    int i;
    getdatestudent("student.txt",&student);
    printf("������γ̺š�\n");
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
	printf("��ѯ���\n"); 
}
void delteachercourse()
{
	int num;
    int xuanze;
        do
        {
        printf("������Ҫɾ���Ŀγ̱�ţ�\n");
        scanf("%d",&num);
        del(num);
        printf("ɾ���ɹ���1������ɾ�� 2���˳�");
        scanf("%d",&xuanze);
        }while(xuanze==1);
	
}

void del(int num)
{
FILE *f1;
long length;
char *f2;//���ڼ�¼Ҫ���������     
char s[100];//���ڱ���ÿ�ζ�ȡ��һ������    
 int n;//���ڴ洢���     
 f1=fopen("course.txt","r");//�Զ��ķ�ʽ���ļ�     
 fseek(f1,0,2);//�ļ�ָ���Ƶ��ļ�β    
 length=ftell(f1);//ȡ���ļ�����     
 f2=(char *)malloc(sizeof(char)*length);//��f2�����ļ����ȵĿռ�    
  *f2=0;//ʹ��f2�ַ����ĳ��ȳ�ʼΪ0        
  rewind(f1);//�ļ�ָ��ص��ļ�ͷ     
  while(ftell(f1)<length-3)
  {//���ļ�û�н���ʱ�����ζ�ȡ�ļ���ÿһ��         
  fgets(s,100,f1);//��ȡһ����Ϣ         
  n=atoi(s);//�Ӷ�ȡ����Ϣȡ�ñ��         
  if(n==num) 
  continue;//��������Ҫɾ���ı�ţ��Ͳ��ñ�����һ����Ϣ��        
   strcat(f2,s);//�����ȡ������һ����Ϣ    
    }      
    fclose(f1);//�ر��ļ�     
    f1=fopen("course.txt","w");//������д�ķ�ʽ���ļ�     
    fputs(f2,f1);
    //�ѱ������Ϣ���´洢���ļ�����     
    fclose(f1);//�ر��ļ� 
}
void back()
{
	char choose100;
	char choose200;
	printf("���뷵�ص�¼���滹���˳�������ѡ��\n");
	printf("1.���ص�¼����.\n");
	printf("2.�˳�����.\n");
	//printf(" \n");
	
	scanf("%c",&choose100);
	getchar();
	 switch(choose100)
  { case 49:
  	 { 
  	   system("cls");
  	   printf("������ʦ����ѧ����¼����");
  	   printf("1.��ʦ2.ѧ��"); 
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
		printf("                         ���Ѿ��˳�����");
		  break;
		}
  	
  }
	
}
void searchTeacher(char id[SIZE])
{   
    TEACHER teacher[SIZE];
	FILE *inFile,*teaFile;
	int i,j,k=0,n;
   
    teaFile = fopen("teacher.txt","r");//�򿪽�ʦ�ļ� 
	if(teaFile == NULL)
    {
              printf("\nFailed to open the file.\n");
              system("pause");
              exit(1);
    } 
    
      for(j=0;j<SIZE;j++)//��ȡ�ļ����� 
    {
    fscanf(teaFile, "%s  %s  %s  %s  %s\n",teacher[j].teacherid,teacher[j].apartment,teacher[j].name,teacher[j].mail,teacher[j].key);
    }
    
    
     
	  for(i=0;i<SIZE;i++)//i֮���ٱ仯 
    {
   	   if(!strcmp(teacher[i].teacherid,id))
      {
   	    printf("\n��ʦ���ƣ�%s\n", teacher[i].name);
           // continue;
           break;
      }				
    }
    fclose(teaFile);
    
  
    
   	inFile = fopen("course.txt","r");//��ѡ���ļ� 
    
    if(inFile == NULL)
    {
              printf("\nFailed to open the file.\n");
              system("pause");
              exit(1);
    } 
    
   
    for(j=0;j<SIZE;j++)//��ȡ�ļ����� 
    {
    fscanf(inFile, "%d %s %d %d %s %s %s %s %d %s %s %s  %d %d %d %d",&course[j].courseid,course[j].name,&course[j].credit, &course[j].period,course[j].identify,course[j].teacher,course[j].date,course[j].site,&course[j].number,course[j].brief,course[j].book,course[j].apartment,&course[j].kaishi,&course[j].jieshu,&course[j].suanke,&course[j].shengyu );
    }
    
    
    
   for(k=0; k<(SIZE-1); k++)  //����
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
    
    
    printf("\n����γ����£�����ѡ���������򣩣�\n");
  
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
    printf("�γ�������%d\n\n",n);
 
fclose(inFile);
}


 
