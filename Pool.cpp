#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include "graphics.h"

#define PIE 3.14159265
#define G 9.8065
#define HOLEN 6
#define HOLER 30
#define BALLN 7
#define BALLR 22

void *image;

using namespace std;

void zastavka();
int menu();
int game();
void help();
void about();
bool check();
void checkall();
void move();
void colissionwall();
void colissionball();
void matan();

int x=0,y=1;

float hole1[2] = { 64,64 };
float hole2[2] = { 500,54 };
float hole3[2] = { 936,64 };
float hole4[2] = { 64,534 };
float hole5[2] = { 500,544 };
float hole6[2] = { 936,534 };

struct kek
{
   float coord[8][2] = {0,0,250,300,704,300,750,324,750,276,796,348,796,300,796,252};
   
   float spd[8]={0,0,0,0,0,0,0,0};
   float rect[8]={0,0,0,0,0,0,0,0};
   
   float fric = 0.0001;
   
}ball;


struct point
{
   float x, y, x2, y2;
};


void move(int i)
{
   if (ball.spd[i]>ball.fric*G)
   {
      ball.spd[i] -= ball.fric * G;
           
      ball.coord[i][x] += cos((ball.rect[i]*PIE) / 180)*ball.spd[i];
      ball.coord[i][y] += sin((ball.rect[i]*PIE) / 180)*ball.spd[i];
   }
   else
      ball.spd[i] = 0;
}

void colissionwall(int i)
{
   float move1=ball.coord[i][x]+cos(ball.rect[i]*PIE/180)*ball.spd[i];
   float move2=ball.coord[i][y]+sin(ball.rect[i]*PIE/180)*ball.spd[i];
   
   if(move1-64 <= BALLR+1 || move1 >= 1000-64-BALLR-1)
   {
      ball.rect[i]=180-ball.rect[i];
      if(ball.rect[i]<0)
      {
         ball.rect[i]+=360;
      }
      ball.spd[i]*=0.55;
   }
   
   else if(move2-64 <= BALLR+1 || move2 >= 600-64-BALLR-1)
   {
      ball.rect[i]=360-ball.rect[i];
      if(ball.rect[i]<0)
      {
         ball.rect[i]+=360;
      }
      ball.spd[i]*=0.55;
   }
}

bool checkball(int i, int j)
{
   float move1=(ball.coord[i][x]+cos((ball.rect[i]*PIE/180)*ball.spd[i]))-(ball.coord[j][x]+cos((ball.rect[j]*PIE/180)*ball.spd[j]));
   float move2=(ball.coord[i][y]+sin((ball.rect[i]*PIE/180)*ball.spd[i]))-(ball.coord[j][y]+sin((ball.rect[j]*PIE/180)*ball.spd[j]));
   
   if(pow(move1,2)+pow(move2,2) <= pow(BALLR*2,2)+1)
      return true;
   else
      return false;
}

void colissionball(int i,int j)
{
   float angle = atan2(ball.coord[i][y]-ball.coord[j][y],ball.coord[i][x]-ball.coord[j][x]);
   
   angle*=180;
   angle/=PIE;
   
   ball.spd[i]*=0.55;
   ball.spd[j]*=0.55;
   
   float bx1,bx2,by1,by2;
   
   bx1=cos((ball.rect[i]-angle)*PIE/180)*ball.spd[i];
   by1=sin((ball.rect[i]-angle)*PIE/180)*ball.spd[i];
   
   bx2=cos((ball.rect[j]-angle)*PIE/180)*ball.spd[j];
   by2=sin((ball.rect[j]-angle)*PIE/180)*ball.spd[j];
   
   
   ball.spd[i]=sqrt(pow(bx2,2)+pow(by1,2));
   
   ball.spd[j]=sqrt(pow(bx1,2)+pow(by2,2));
   
   
   ball.rect[i]=angle+(atan2(by1,bx2)*180/PIE);
   
   ball.rect[j]=angle+(atan2(by2,bx1)*180/PIE);
}


void checkall()
{
   for(int i=1;i<=BALLN;i++)
   {
      for(int j=i+1;j<=BALLN;j++)
      {
         if(checkball(j,i)==TRUE)
         {
            colissionball(i,j);
         }
      }
   }
   
   for(int i=1;i<=BALLN;i++)
   {
      colissionwall(i);
   }
}

void matan()
{
   checkall();
   for(int i=1;i<=BALLN;i++)
   {
      move(i);
   }
}

void init()
{
   initwindow(1050, 600);
}

void zastavka()
{
   image = loadBMP("zastavka.jpg");
   putimage(100, 0, image, COPY_PUT);
   Sleep(1000);
   free(image);
}

int menu()
{
   image = loadBMP("menu.jpg");
   putimage(100, 0, image, COPY_PUT);

   struct point menu[4];

   menu[1].x = 30; menu[1].y = 30;
   menu[1].x2 = 186; menu[1].y2 = 98;

   menu[2].x = 30; menu[2].y = 128;
   menu[2].x2 = 186; menu[2].y2 = 196;

   menu[3].x = 30; menu[3].y = 226;
   menu[3].x2 = 186; menu[3].y2 = 294;

   menu[4].x = 30; menu[4].y = 324;
   menu[4].x2 = 186; menu[4].y2 = 392;

   image = loadBMP("knopka.jpg");
   putimage(menu[1].x, menu[1].y, image, COPY_PUT);
   putimage(menu[2].x, menu[2].y, image, COPY_PUT);
   putimage(menu[3].x, menu[3].y, image, COPY_PUT);
   putimage(menu[4].x, menu[4].y, image, COPY_PUT);

   while (true)
   {
      if (mousebuttons() == 1)
      {
         if ((mousex() >= menu[1].x && mousex() <= menu[1].x2) && (mousey() >= menu[1].y && mousey() <= menu[1].y2))
         {
            zastavka();
            return 1;
         }
         if ((mousex() >= menu[2].x && mousex() <= menu[2].x2) && (mousey() >= menu[2].y && mousey() <= menu[2].y2))
         {
            return 2;
         }
         if ((mousex() >= menu[3].x && mousex() <= menu[3].x2) && (mousey() >= menu[3].y && mousey() <= menu[3].y2))
         {
            return 3;
         }
         if ((mousex() >= menu[4].x && mousex() <= menu[4].x2) && (mousey() >= menu[4].y && mousey() <= menu[4].y2))
         {
            return 4;
         }
      }
   }
}

int game()
{
   while (1)
   {
      setcolor(BLACK);
      
      int a=int(roundf(ball.coord[1][x]));
      int b=int(roundf(ball.coord[1][y]));
      
      matan();

      setlinestyle(SOLID_LINE, EMPTY_FILL,0);

      setfillstyle(SOLID_FILL, GREEN);
      bar(hole1[x], hole1[y], hole6[x], hole6[y]);

      setfillstyle(SOLID_FILL, COLOR(128, 128, 128));
      fillellipse(hole1[x], hole1[y], HOLER, HOLER);
      fillellipse(hole2[x], hole2[y], HOLER, HOLER);
      fillellipse(hole3[x], hole3[y], HOLER, HOLER);
      fillellipse(hole4[x], hole4[y], HOLER, HOLER);
      fillellipse(hole5[x], hole5[y], HOLER, HOLER);
      fillellipse(hole6[x], hole6[y], HOLER, HOLER);
      
      setfillstyle(SOLID_FILL, WHITE);
      fillellipse(ball.coord[2][x], ball.coord[2][y], BALLR, BALLR);
      fillellipse(ball.coord[3][x], ball.coord[3][y], BALLR, BALLR);
      fillellipse(ball.coord[4][x], ball.coord[4][y], BALLR, BALLR);
      fillellipse(ball.coord[5][x], ball.coord[5][y], BALLR, BALLR);
      fillellipse(ball.coord[6][x], ball.coord[6][y], BALLR, BALLR);
      fillellipse(ball.coord[7][x], ball.coord[7][y], BALLR, BALLR);
      
      setcolor(LIGHTGRAY);
      
      line(1000,0,1000,600);
      
      setlinestyle(SOLID_LINE, EMPTY_FILL,10);
      
      if(ball.spd[1]==0)
      {
         line(a,b,mousex(),mousey());
         if(mousebuttons()==1)
         {
            ball.spd[1]=9;
            ball.rect[1]=atan2(mousey()-ball.coord[1][y],mousex()-ball.coord[1][x])*180/PIE+180;
         }
      }
      
      setlinestyle(SOLID_LINE, EMPTY_FILL,0);
      
      setcolor(RED);
      
      setfillstyle(SOLID_FILL, BLACK);
      fillellipse(ball.coord[1][x], ball.coord[1][y], BALLR, BALLR);
      
      Sleep(1);
   }
}

void help()
{
}

void about()
{
}

int main()
{
   init();
   while(1)
   {
      if (1 == menu())
      {
         game();
      }
      else if (2 == menu())
      {
         help();
      }
      else if (3 == menu())
      {
         about();
      }
      else if (4 == menu())
      {
         return 0;
      }
   }
}
