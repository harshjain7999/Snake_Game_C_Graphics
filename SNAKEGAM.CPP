#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
void snake();
void set();
void food();
int ch;
int n=3;
int score=0;
int highscore=0;
int x[100][4]={
{100,100,110,110},
{90,100,100,110},
{80,100,90,110}
};
int r1,r2;
void main()
{
int a=DETECT;
int b;
r1=random(500)+50;
r2=random(350)+50;
clrscr();
initgraph(&a,&b,"");
setbkcolor(BLUE);
do
{
ch=getch();
snake();
}while(ch!=97);
getch();
}
void snake()
{
while(kbhit()==0)
{
food();
int i;
setcolor(WHITE);
for(i=0;i<n;i++)
{
rectangle(x[i][0],x[i][1],x[i][2],x[i][3]);
}
if(ch==77)
{
set();
x[0][0]+=10;
x[0][2]+=10;
}
if(ch==75)
{
set();
x[0][0]-=10;
x[0][2]-=10;
}
if(ch==72)
{
set();
x[0][1]-=10;
x[0][3]-=10;
}
if(ch==80)
{
set();
x[0][1]+=10;
x[0][3]+=10;
}
if(x[0][0]==r1 && x[0][1]==r2)
{
n++;
score+=10;
if(score>highscore)
highscore=score;
r1=random(500)+50;
r2=random(350)+50;
}
delay(100);
cleardevice();
setcolor(CYAN);
rectangle(10,10,630,470);
char s[20],hs[20];
sprintf(s,"Score: %d",score);
sprintf(hs,"High Score: %d",highscore);
settextstyle(1,0,2);
setcolor(RED);
outtextxy(30,20,s);
outtextxy(450,20,hs);

if(x[0][0]<=20||x[0][1]<=20||x[0][2]>=620||x[0][3]>=460)
{
setcolor(BLACK);
cleardevice;

settextstyle(7,0,6);
setcolor(GREEN);

outtextxy(80,180,"G A M E O V E R !");
settextstyle(1,0,2);
setcolor(WHITE);
outtextxy(180,260,"Press any key to exit...");
while(!kbhit())
{
delay(100);
}
closegraph();
exit(0);
}
}
}
void set()
{
int i;
for(i=n-1;i>0;i--)
{
x[i][0]=x[i-1][0];
x[i][1]=x[i-1][1];
x[i][2]=x[i-1][2];
x[i][3]=x[i-1][3];
}
}
void food()
{
r1=r1-r1%10;
r2=r2-r2%10;
setcolor(YELLOW);
rectangle(r1,r2,r1+10,r2+10);
}