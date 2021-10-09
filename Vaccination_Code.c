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
  
 void Admin()
  {
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
  
  void search()
  {
  	int cho,i, vId,sch;
  	
  	outtextxy(200,100"CHOOSE ANY FROM BELOW");
  	outtextxy(200,100"\n 1.VACCINATION ID");
  	outtextxy(200,100"\n");
  	outtextxy(200,100"\n 2.NAME");
  	outtextxy(200,100"\n");
  	outtextxy(200,100"ENTER YOUR OPTION AS 1 OR 2");
  	scanf("%d",&cho);
  	
  	if (cho==1)
  	outtextxy(200,100"Enter the vaccination Id");
  	scanf("%d",&vId);
  	
  	for( i=0;i<n;i++)
  		if vId==d.ID[i]
  	{
  		outtextxy(200,100"\n%c%d%c",d.name[i],d.ID[i],d.address[i]);
	  }
  	
  	else if (cho==2)
  		outtextxy(200,100"\nEnter Name");
  		scanf("%c",&sch);
  		for(i=0,i<n,i++)
  		{
  			if(strcmp(d[i],sch)==0)
  			{
  				outtextxy(200,100"\n%c%d%c",d.name[i],d.ID[i],d.address[i]);
			  }  
	else
	outtextxy(200,100"\n WRONG INPUT);		
  	}
  outtextxy(200,100"\n ENTER ANY KEY TO CONTINUE");		
  }
  
  
  void display()
  {
  	int a,i;
  	outtextxy(200,100"CHOOSE FROM BELOW");
  	outtextxy(200,100"\n 1.PARTIALLY VACCINATED LIST");
  	outtextxy(200,100"\n");
  	outtextxy(200,100"\n 2.FULLY VACCINATED LIST");
  	outtextxy(200,100"\n");
  	outtextxy(200,100"ENTER YOUR OPTION AS 1 OR 2");
  	scanf("%d",&a);
  	if a==1
  	outtextxy(200,100"\n PARTIALLY VACCINATED LIST GIVEN BELOW");
  	for( i=0;i<n;i++)
  		if DT1[i]!=/DT2[i]
  	{
  		outtextxy(200,100"\n%c%d%c",d.name[i],d.ID[i],d.address[i]);
  		break
	  }
	else if a==2
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
  
void del()
{
	int i;
	char b;
	outtextxy(200,100"\n Enter the name to be deleted ");
	scanf("%c",&b);
	for( i=0;i<n;i++)
	{
	if d.Name[i]==b
	{
		if (strcmp(d.Name[i],b ) == 0) 
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
        
        
        
        
        a
        
    }
    a



