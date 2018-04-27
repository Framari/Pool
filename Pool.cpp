
#include <iostream>
#include <cmath>
#include <conio.h>
#include <windows.h>
#include "graphics.h"

#define PIE 3.14159265
#define G 9.8065
#define HOLEN 6
#define HOLER 24
#define BALLN 7
#define BALLR 22

void *image;

using namespace std;

void zastavka();
int menu();
void game();
void help();
void about();
int vibor();
void move();

float hole1[2]={64,64};
float hole2[2]={500,64};
float hole3[2]={936,64};
float hole4[2]={64,534};
float hole5[2]={500,534};
float hole6[2]={936,534};

   
float ball1[2]={250,300};
float ball2[2]={704,300};
float ball3[2]={750,324};
float ball4[2]={750,276};
float ball5[2]={796,346};
float ball6[2]={796,300};
float ball7[2]={796,254};

float ballspd=3;
float ballfric=0.001;


struct point
{
   float x,y,x2,y2;
};


void move()
{
   if(ballspd>ballfric*G)
   {
      ballspd-=ballfric*G;
      ball1[0]+=cos((BALLR*PIE)/180)*ballspd;
      ball1[1]+=sin((BALLR*PIE)/180)*ballspd;
   }
   else
      ballspd=0;
}

int main()
{
   initwindow(1000,600);
   zastavka();
   menu();
   if(vibor()==0)
   {
      return 0;
   }
   else
   {
      getch();
   }
}

int vibor()
{
   if(1==menu())
   {
      game();
   }
   else if(2==menu())
   {
      help();
   }
   else if(3==menu())
   {
      about();
   }
   else if(4==menu())
   {
      return 0;
   }
}

void zastavka()
{
   image=loadBMP("zastavka.jpg");
   putimage(100,0,image,COPY_PUT);
   Sleep(1000);
   free(image);
}

int menu()
{
   image=loadBMP("menu.jpg");
   putimage(100,0,image,COPY_PUT);
   
   struct point menu[4];
   
   menu[1].x=30; menu[1].y=30;
   menu[1].x2=186;menu[1].y2=98;
   
   menu[2].x=30; menu[2].y=128;
   menu[2].x2=186;menu[2].y2=196;
   
   menu[3].x=30; menu[3].y=226;
   menu[3].x2=186;menu[3].y2=294;
   
   menu[4].x=30; menu[4].y=324;
   menu[4].x2=186;menu[4].y2=392;
   
   image=loadBMP("knopka.jpg");
   
   putimage(menu[1].x,menu[1].y,image,COPY_PUT);
   putimage(menu[2].x,menu[2].y,image,COPY_PUT);
   putimage(menu[3].x,menu[3].y,image,COPY_PUT);
   putimage(menu[4].x,menu[4].y,image,COPY_PUT);
   
   while(true)
   {
      if(mousebuttons()==1)
      {
         if((mousex()>=menu[1].x && mousex()<=menu[1].x2)&&(mousey()>=menu[1].y && mousey()<=menu[1].y2))
         {
            return 1;
         }
         if((mousex()>=menu[2].x && mousex()<=menu[2].x2)&&(mousey()>=menu[2].y && mousey()<=menu[2].y2))
         {
            return 2;
         }
         if((mousex()>=menu[3].x && mousex()<=menu[3].x2)&&(mousey()>=menu[3].y && mousey()<=menu[3].y2))
         {
            return 3;
         }
         if((mousex()>=menu[4].x && mousex()<=menu[4].x2)&&(mousey()>=menu[4].y && mousey()<=menu[4].y2))
         {
            return 4;
         }
      }
   }
}
void game()
{
   int p=0;
   int t=0;
   int i,j,k;
   
   
   while(1)
  {
      p=1-p;
      setactivepage(p); // активная страница == 1-видимая
      setbkcolor(COLOR(117,51,19));// цвет фона
      clearviewport();
      ++t;
     
      move();
      setfillstyle(SOLID_FILL,GREEN);
      bar(hole1[0],hole1[1],hole6[0],hole6[1]);
      
      setfillstyle(SOLID_FILL,COLOR(128,128,128));
      fillellipse(hole1[0],hole1[1],HOLER,HOLER);
      fillellipse(hole2[0],hole2[1],HOLER,HOLER);
      fillellipse(hole3[0],hole3[1],HOLER,HOLER);
      fillellipse(hole4[0],hole4[1],HOLER,HOLER);
      fillellipse(hole5[0],hole5[1],HOLER,HOLER);
      fillellipse(hole6[0],hole6[1],HOLER,HOLER);
     
      setfillstyle(SOLID_FILL,WHITE);
      fillellipse(ball1[0],ball1[1],BALLR,BALLR);
      fillellipse(ball2[0],ball2[1],BALLR,BALLR);
      fillellipse(ball3[0],ball3[1],BALLR,BALLR);
      fillellipse(ball4[0],ball4[1],BALLR,BALLR);
      fillellipse(ball5[0],ball5[1],BALLR,BALLR);
      fillellipse(ball6[0],ball6[1],BALLR,BALLR);
      fillellipse(ball7[0],ball7[1],BALLR,BALLR);
     
      // рисование изображения
      setvisualpage(p); // делаем активную страницу видимой
      delay(15); // задержка на 1/30 секунды
      if(kbhit()) break; // если нажата клавиша - завершить работу
  }
}
void help()
{
}
void about()
{
}
