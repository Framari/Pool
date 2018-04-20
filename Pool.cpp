#include <iostream>
#include <cmath>
#include <conio.h>
#include <windows.h>
#include "graphics.h"

#define PIE 3.14159265
#define G 9.8065
#define HOLEN 6
#define HOLER 22
#define BALLN 7
#define BALLR 20

void *image;

using namespace std;

void zastavka();
int menu();
void game();
void help();
void about();
int vibor();

struct point
{
   float x,y,x2,y2;
};

struct hole
{
   float 
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
   int i=0;
   image=loadBMP("table.jpg");
   putimage(0,0,image,COPY_PUT);
   
   while(1)
  {
      p=1-p;
      setactivepage(p); // активная страница == 1-видимая
      putimage(0,0,image,COPY_PUT); // цвет фона
      ++t;
     
      fillellipse(i,55,25,25);
      i++;
      Sleep(100);
     
      // рисование изображения
      setvisualpage(p); // делаем активную страницу видимой
      delay(30); // задержка на 1/30 секунды
      if(kbhit()) break; // если нажата клавиша - завершить работу
  }
}
void help()
{
}

void about()
{
}
