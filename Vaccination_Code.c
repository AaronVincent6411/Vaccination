#include<stdio.h>
#include<dos.h>
#include<graphics.h>

 int i,j,k;

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
  }

 void Welcome()
  {
    settextstyle(1,0,8);
    setbkcolor(LIGHTBLUE);
    setcolor(7);
    outtextxy(200,100,"Loading.");
    Loading();
    delay(800);
    cleardevice();
    outtextxy(200,100,"Loading..");
    Loading();
    delay(800);
    cleardevice();
    outtextxy(200,100,"Loading...");
    Loading();
    delay(800);
    cleardevice();
    outtextxy(200,150,"\t\tWelcome");
    delay(1000);
    cleardevice();
  }

 int main()
  {
    int gdriver=DETECT,gmode,errorcode;
    int x,y;
    int midx,midy;
    initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
    Welcome();
  }