#include<stdio.h>
#include<dos.h>
#include<graphics.h>

  int i,j,k;

 void Admin()
  {
    cleardevice();
    outtextxy(200,100,"Welcome Aministrator");
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