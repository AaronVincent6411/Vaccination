#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<graphics.h>
#include<process.h>

  int i,j,k;
  
 struct Details 
  {
  	char ID[5];
  	char Name[20];
  	char Address[30];
  	char DT1[3],DT2[3];
  	int dd,mm,yy;
  }D[10];
   
 void Write()
  {
    FILE *ptr;
    int num;
    ptr=fopen("vaccine_details.bin","wb+");
    printf("Enter the number of vaccinators :");
    scanf("%d",&num);
    for(i=0;i<num;i++)
     {
       printf("Enter the ID number :");
       scanf("%s",D[i].ID);
       printf("Enter the name :");
       scanf("%*c%[^\n]",D[i].Name);
       printf("Enter the Place :");
       scanf("%*c%[^\n]",D[i].Address);
       printf("Enter the Birth Of Date (DD MM YYYY) :");
       scanf("%d%d%d",&D[i].dd,&D[i].mm,&D[i].yy);
       printf("Have taken the first dose(Y/N) :");
       scanf("%s",D[i].DT1);
       printf("Have taken the second dose(Y/N) :");
       scanf("%s",D[i].DT2);
       fwrite(&D[i],sizeof(D[i]),1,ptr);
     }
    fclose(ptr);
  }
 
 void Read()
  {
	  char ch3;
    FILE *ptr;
    ptr=fopen("vaccine_details.bin","rb+");
    i=0;
    
    printf("ID\t Name\t");
    printf(" \t   Place");
    printf("\t  DOB\t   First Dose\t  Second Dose\n");
    while(feof(ptr)==0)
     {
   	   fread(&D[i],sizeof(D[i]),1,ptr);
       gotoxy(1,6+i);
       printf("%s",D[i].ID);
       gotoxy(10,6+i);
       printf("%s",D[i].Name);
       gotoxy(25,6+i);
       printf("%s",D[i].Address);
       gotoxy(40,6+i);
       printf("%02d/%02d/%04d",D[i].dd,D[i].mm,D[i].yy);
       gotoxy(55,6+i);
       printf("%s",D[i].DT1);
       gotoxy(70,6+i);
       printf("%s",D[i].DT2);
       i++;
     }  
    fclose(ptr);
    printf("\nPress Any key\n");
	  scanf("%s",&ch3);
  }
  
 void Append()
  {
    FILE *ptr;
    int i=0;
    char ch;
    ptr=fopen("vaccine_details.bin","ab");
    fseek(ptr,0,SEEK_END);
    i=ftell(ptr);
    do
     {
       cleardevice();
       printf("Enter the ID number :");
       scanf("%s",D[i].ID);
       printf("Enter the name :");
       scanf("%*c%[^\n]",D[i].Name);
       printf("Enter the Place :");
       scanf("%*c%[^\n]",D[i].Address);
       printf("Enter the Birth Of Date (DD MM YYYY) :");
       scanf("%d%d%d",&D[i].dd,&D[i].mm,&D[i].yy);
       printf("Have taken the first dose(Y/N) :");
       scanf("%s",D[i].DT1);
       printf("Have taken the second dose(Y/N) :");
       scanf("%s",D[i].DT2);
       fwrite(&D[i],sizeof(D[i]),1,ptr);
       i++;
       printf("Do you want to continue adding vaccinators (Y/n) : ");
       scanf("%s",&ch);
     }while(ch=='Y' || ch=='y');
    fclose(ptr);
  }

 void Search()
  {
    FILE *ptr;
    int cho,flag=0;
    char vId[3],sch[20];
    char ch3;
    ptr=fopen("vaccine_details.bin","rb+");
    cleardevice();
    settextstyle(6,0,3);
  	outtextxy(200,100,"Enter the Option");
  	outtextxy(200,150,"1.Search by Vaccination ID");
  	outtextxy(200,200,"2.Search by Name");
  	scanf("%d",&cho);
  	switch(cho)
     {
       case 1:cleardevice();
              outtextxy(200,100,"Enter the vaccination Id");
  	          scanf("%s",vId);
              cleardevice();
              i=0;
              printf("ID\t Name\t     Place\t  DOB\t   First Dose\t  Second Dose\n");
  		        while(feof(ptr)==0)
               {
                 fread(&D[i],sizeof(D[i]),1,ptr);
  		           if(strcmpi(D[i].ID,vId)==0)
                  {
  	                printf("%s\t%s\t\t%s\t%d/%d/%d\t%s\t\t%s\n",D[i].ID,D[i].Name,D[i].Address,D[i].dd,D[i].mm,D[i].yy,D[i].DT1,D[i].DT2);
                    flag=1;
                  }
	               i++;
               }
              printf("Press Any key\n");
	            scanf("%s",&ch3);
              break;
  	   case 2:cleardevice();
         		  outtextxy(200,100,"Enter the Name");
  		        scanf("%s",sch);
              i=0;
              printf("ID\t Name\t    Place\t  DOB\t   First Dose\t  Second Dose\n");
  		        while(feof(ptr)==0)
               {
                 fread(&D[i],sizeof(D[i]),1,ptr);
  			         if(strcmpi(D[i].Name,sch)==0)
                  {
  			            printf("%s\t%s\t\t%s\t%d/%d/%d\t%s\t\t%s\n",D[i].ID,D[i].Name,D[i].Address,D[i].dd,D[i].mm,D[i].yy,D[i].DT1,D[i].DT2);
                    flag=1;
                  }
			           i++;
               }
              printf("Press Any key\n");
	            scanf("%s",&ch3);
              break;
     }
    if(flag==0)
     {
       cleardevice();
       outtextxy(100,100,"Couldn't find");
     }
  }
  
 void Vacc_Display()
  {
    FILE *ptr;
  	int a;
    char ch3;
    cleardevice();
    ptr=fopen("vaccine_details.bin","rb+");
    settextstyle(6,0,2);
  	outtextxy(200,50,"Enter the Option");
  	outtextxy(200,100,"1.Partially Vaccinated List");
  	outtextxy(200,150,"2.Fully Vaccinated list");
  	scanf("%d",&a);
  	switch(a)
     {
       case 1:cleardevice();
              i=0;
              printf("Partially Vaccinated List\n");
              printf("ID\t Name\t    Place\t  DOB\t   First Dose\t  Second Dose\n");
  		        while(feof(ptr)==0)
               {
   	             fread(&D[i],sizeof(D[i]),1,ptr);
                 if((strcmpi(D[i].DT1,"Y")==0) && (strcmpi(D[i].DT2,"N")==0))
                  printf("%s\t%s\t\t%s\t%d/%d/%d\t%s\t\t%s\n",D[i].ID,D[i].Name,D[i].Address,D[i].dd,D[i].mm,D[i].yy,D[i].DT1,D[i].DT2);
                 i++;
               }
              printf("Press Any key\n");
	            scanf("%s",&ch3);
              break;
       case 2:cleardevice();
              i=0;
              printf("Fully Vaccinated List\n");
              printf("ID\t Name\t    Place\t  DOB\t   First Dose\t  Second Dose\n");
  		        while(feof(ptr)==0)
               {
   	             fread(&D[i],sizeof(D[i]),1,ptr);
                 if((strcmpi(D[i].DT1,"Y")==0) && (strcmpi(D[i].DT2,"Y")==0))
                  printf("%s\t%s\t\t%s\t%d/%d/%d\t%s\t\t%s\n",D[i].ID,D[i].Name,D[i].Address,D[i].dd,D[i].mm,D[i].yy,D[i].DT1,D[i].DT2);
                 i++;
               }
              printf("Press Any key\n");
	            scanf("%s",&ch3);
              break;
     }        
    fclose(ptr);
  }

 void Del()
  { 
    char del[5];
    FILE *ptr,*temp;
    cleardevice();
    temp=fopen("vaccine_details_temp.bin","wb+");
	  outtextxy(100,100,"Do you want to delete entire data");
    outtextxy(100,150,"Enter 'Delete' to delete");
	  scanf("%s",del);
    i=0;
	  if(strcmpi(del,"Delete")==0)
     {
       rename("vaccine_details_temp.bin","vaccine_details.bin");
       remove("vaccine_details.bin");
       outtextxy(200,200,"Record Deleted");
     }
    else
    outtextxy(100,100,"Entire Data is safe");
    fclose(temp);
    delay(1000);
  }
 
 void Admin()
  {
    int op1;
    char ch1,ch2;
    char Admin_Name[20],Password[10];
    cleardevice();
    settextstyle(6,0,5);
    outtextxy(200,100,"Welcome Administrator");
    delay(1000);
    cleardevice();
    settextstyle(5,0,5);
    for(i=0;i<2;i++)
     {
       outtextxy(200,100,"Enter the Username");
       scanf("%s",Admin_Name);
       if(strcmp(Admin_Name,"1a2b3c4d")==0)
        {
         for(i=0;i<2;i++)
          {
            cleardevice();
            settextstyle(5,0,5);
            outtextxy(200,100,"Enter the Password");
            scanf("%s",Password);
            if(strcmp(Password,"1a2b3c4d")==0)
             {
               do
                {
                  cleardevice();
                  settextstyle(6,0,2);
                  outtextxy(200,50,"Main Menu");
                  outtextxy(150,100,"1.Write Data");
                  outtextxy(150,150,"2.Display Details");
                  outtextxy(150,200,"3.Vaccination Details (Partial/Fully List)");
                  outtextxy(150,250,"4.Search for Particular Detail");
                  outtextxy(150,300,"5.Append Data");
                  outtextxy(150,350,"6.Delete entire data");
                  outtextxy(150,400,"7.Exit");
                  scanf("%d",&op1);
			       	    settextstyle(6,0,2);
                  cleardevice();
                  switch(op1)
                   {
                     case 1:outtextxy(100,100,"Do You Wish to Continue\n Existing Data will be erased (Y/n)");
                           scanf("%s",&ch2);
						               cleardevice();
                           if(ch2=='y'||ch2=='Y')
                            Write();
                           cleardevice(); 
                           outtextxy(100,100,"Data Entered Successfully");
                           break;
                     case 2:Read();
                            break;
                     case 3:Vacc_Display();
                            break;
                     case 4:Search();
                            break;
                     case 5:Append();
                            break;
                     case 6:Del();
                            break;
                     case 7:exit(0);
                   }
                  delay(1000);
                  cleardevice();
                  outtextxy(200,100,"Do you wish to exit out of Administrator Menu");
                  outtextxy(200,150,"If not Press 5");
                  scanf("%s",&ch1);
                }while(ch1=='5');
              exit(0);
            }
           else
            {
              cleardevice();
              settextstyle(6,0,5);
              outtextxy(200,100,"Wrong Password");
              if(i==0)
               outtextxy(200,150,"Try Again");
              delay(1000);
            }
          }
        break;
       }
      else
       {
         cleardevice();
         settextstyle(6,0,5);
         outtextxy(200,100,"Wrong Username");
         if(i==0)
          outtextxy(200,150,"Try Again");
         delay(1000);
         cleardevice();
       }
     }
  }

 void Display()
  {
    int op;
    char ch3;
    setbkcolor(EGA_BLUE);
    setcolor(WHITE);
    settextstyle(7,0,7);
    outtextxy(150,50,"Main Menu");
    settextstyle(6,0,2);
    outtextxy(200,150,"1.Administrator");
    outtextxy(200,200,"2.Exit");
    scanf("%d",&op);
    switch(op)
     {
       case 1:Admin();
              break;
       default:exit(0);
              break;
     }
    cleardevice();
  }

 void Loading()
  {
   int g=getmaxx()/2;
   int h=getmaxy()/2;
   for(j=20;j<25;j++)
    {
      setcolor(7);        
      for(k=0;k<360;k++)
       {
        delay(1);
        arc(g,h,0,k,j-10);
       }
    }
   delay(400);
   cleardevice();
  }

 void Welcome()
  {
    settextstyle(1,0,8);
    setbkcolor(LIGHTBLUE);
    setcolor(7);
    outtextxy(200,100,"Loading.");
    Loading();
    outtextxy(200,100,"Loading..");
    Loading();
    outtextxy(200,100,"Loading...");
    Loading();
    outtextxy(200,150,"\t\tWelcome");
    delay(1000);
    cleardevice();
    Display();
  }

 int main()
  {
    int gdriver=DETECT,gmode,errorcode;
    int x,y;
    int midx,midy;
    initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
    Welcome();
  }
  
