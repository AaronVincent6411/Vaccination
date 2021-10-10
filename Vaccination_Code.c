#include<stdio.h>
#include<dos.h>
#include<graphics.h>

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
       printf("Enter the House Name :");
       scanf("%*c%[^\n]",D[i].Address);
       printf("Enter the Birth Of Date (DD/MM/YYYY) :");
       scanf("%d%d%d",&D[i].dd,&D[i].mm,&D[i].yy);
       printf("Have you taken the first dose(Y/N) :");
       scanf("%s",D[i].DT1);
       printf("Have you taken the second dose(Y/N) :");
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
    printf("ID\t Name\t\tHouse Name\t  DOB\t   First Dose\t  Second Dose\n");
    while(feof(ptr)==0)
     {
   	   i++;
   	   fread(&D[i],sizeof(D[i]),1,ptr);
       printf("%s\t%s\t\t%s\t%d/%d/%d\t%s\t\t%s\n",D[i].ID,D[i].Name,D[i].Address,D[i].dd,D[i].mm,D[i].yy,D[i].DT1,D[i].DT2);
     }  
    fclose(ptr);
    printf("Press Any key\n");
	scanf("%s",&ch3);
  }
  
  void Append()
  {
    FILE *ptr;
    int i=0;
    int ch;
    ptr=fopen("vaccine_details.bin","ab");
    fseek(ptr,0,SEEK_END);
    i=ftell(ptr);
    do
    {
       printf("Enter the ID number :");
       scanf("%s",D[i].ID);
       printf("Enter the name :");
       scanf("%*c%[^\n]",D[i].Name);
       printf("Enter the House Name :");
       scanf("%*c%[^\n]",D[i].Address);

 void Search()
  {
    FILE *ptr;
    ptr=fopen("vaccine_details.bin","rb+");
    cleardevice();
    settextstyle(6,0,3);
    int cho;
  	char vId,sch[20];
  	outtextxy(200,100,"Enter the Option");
  	outtextxy(200,150,"1.Search by Vaccination ID");
  	outtextxy(200,200,"2.Search by Name");
  	scanf("%d",&cho);
  	switch(cho)
     {
       case 1:cleardevice();
              outtextxy(200,100"Enter the vaccination Id");
  	          scanf("%d",&vId);
              cleardevice();
              i=0;
              printf("ID\t Name\t\tHouse Name\t  DOB\t   First Dose\t  Second Dose\n");
  		        while(feof(ptr)==0)
               {
  		          if(strcmp(vId,D[i].ID)==0)
  	             {
                  fread(&D[i],sizeof(D[i]),1,ptr);
                  printf("%s\t%s\t\t%s\t%d/%d/%d\t%s\t\t%s\n",D[i].ID,D[i].Name,D[i].Address,D[i].dd,D[i].mm,D[i].yy,D[i].DT1,D[i].DT2);
	               }
                i++;
               }
  	   case 2:cleardevice();
         		  outtextxy(200,100,"Enter the Name");
  		        scanf("%c%[^\n]",sch);
              printf("ID\t Name\t\tHouse Name\t  DOB\t   First Dose\t  Second Dose\n");
  		        while(feof(ptr)==0)
               {
  			         if(strcmp(sch,D[i].Name)==0)
  			          {
  				          fread(&D[i],sizeof(D[i]),1,ptr);
                    printf("%s\t%s\t\t%s\t%d/%d/%d\t%s\t\t%s\n",D[i].ID,D[i].Name,D[i].Address,D[i].dd,D[i].mm,D[i].yy,D[i].DT1,D[i].DT2);
			            }  
               }
     }
  }
  
 void Display()
  {
  	int a,i;
  	outtextxy(200,100"CHOOSE FROM BELOW");
  	outtextxy(200,100"\n 1.PARTIALLY VACCINATED LIST");
  	outtextxy(200,100"\n");
  	outtextxy(200,100"\n 2.FULLY VACCINATED LIST");
  	outtextxy(200,100"\n");
  	outtextxy(200,100"ENTER YOUR OPTION AS 1 OR 2");
  	scanf("%d",&a);
  	if(a==1)
  	outtextxy(200,100"\n PARTIALLY VACCINATED LIST GIVEN BELOW");
  	for( i=0;i<n;i++)
  		if(DT1[i]!=/DT2[i])
  	   {
  		   outtextxy(200,100"\n%c%d%c",d.name[i],d.ID[i],d.address[i]);
  		   break
	     }
   	else if(a==2)
	    outtextxy(200,100"\n FULLY VACCINATED LIST GIVEN BELOW");
  	for( i=0;i<n;i++)
  	 {
	    else if DT1[i]=DT2[i]
       outtextxy(200,100"\n%c%d%c",d.name[i],d.ID[i],d.address[i]);
     }
    else 
     {
      outtextxy(200,100"\n WRONG INPUT");
     }
    outtextxy(200,100"\n Enter any key to continue");
  }
  
 void Del()
  { 
	 int i;
	 char b;
	 outtextxy(200,100"\n Enter the name to be deleted ");
	 scanf("%c",&b);
	 for( i=0;i<n;i++)
 	  {
 	    if(D[i].Name==b)
	     {
		     if(strcmp(d.Name[i],b)==0) 
          {
            strcpy(d[i].Name, nullStr); 
            strcpy(d[i].ID, nullStr); 
            strcpy(d[i].Address, nullStr); 
            printf("The ID is Removed.\n");
            n--;
            break;
          }
       }
    }
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
    outtextxy(200,100,"Enter the Username");
    scanf("%s",Admin_Name);
    if(strcmp(Admin_Name,"AAAE")==0)
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
                settextstyle(6,0,5);
                outtextxy(200,50,"Main Menu");
                outtextxy(200,100,"1.Write Data");
                outtextxy(200,150,"2.Display Details");
                outtextxy(200,200,"3.Exit");
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
                          break;
                   case 2:Read();
                          break;
                   case 3:exit(0);
                 }
                delay(1000);
                cleardevice();
                outtextxy(200,100,"Do you wish to exit out of Administrator Menu");
                outtextxy(200,150,"If not Press 5");
                scanf("%s",&ch1);
              }while(ch1=='5');
            break;
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
     }
  }
  

 void User()
  {

  }

 void Display()
  {
    int op;
    setbkcolor(EGA_BLUE);
    setcolor(WHITE);
    settextstyle(7,0,7);
    outtextxy(150,50,"Main Menu");
    settextstyle(6,0,2);
    outtextxy(200,150,"1.Administrator");
    outtextxy(200,200,"2.User");
    outtextxy(200,250,"3.Exit");
    scanf("%d",&op);
    switch(op)
     {
       case 1:Admin();
              break;
       case 2:User();
              break;
       default:exit(0);
              break;
     }
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
  