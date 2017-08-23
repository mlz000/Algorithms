#include<stdio.h>
#define XLEN 50
#define YLEN 20
#define LUC 218
#define RUC 191
#define LBC 192
#define RBC 217
#define VBL 179
#define HBL 196
#define REP 0
int rest=0;
struct squa
{
int x,y,size;
}square[100];
unsigned char a[XLEN][YLEN];

int quickjudge(int x,int y)
{
if(a[x][y]!=LUC&&a[x][y]!=REP)return 0;
if(a[x+1][y]!=RUC&&a[x+1][y]!=HBL&&a[x+1][y]!=REP)return 0;
if(a[x][y+1]!=LBC&&a[x][y+1]!=VBL&&a[x][y+1]!=REP)return 0;
return 1;
}
int check(int x,int y,int add)
{
int rx,ry,own,i,j;
rx=x+add;
ry=y+add;
own=0;
if(a[rx][ry]!=RBC&&a[rx][ry]!=REP)return 0;
if(a[rx][y]!=RUC&&a[rx][y]!=REP)return 0;
if(a[x][ry]!=LBC&&a[x][ry]!=REP)return 0;
if(a[rx][ry]!=REP||a[rx][y]!=REP||a[x][ry]!=REP||a[x][y]!=REP)own++;
for(i=x+1;i<rx;i++)
{
if(a[i][y]==HBL)own++;
else if(a[i][y]!=REP)return 0;
if(a[i][ry]==HBL)own++;
else if(a[i][ry]!=REP)return 0;
}
for(j=y+1;j<ry;j++)
{
if(a[x][j]==VBL)own++;
else if(a[x][j]!=REP)return 0;
if(a[rx][j]==VBL)own++;
else if(a[rx][j]!=REP)return 0;
}
if (own>0)return 1;else return 0;
}
void clean(int x,int y,int add)
{
int i,j;
for(i=x;i<=x+add;i++)
{
   if (a[i][y]!=REP)--rest;
   if(a[i][y+add]!=REP)--rest;
   a[i][y]=a[i][y+add]=REP;
}
for(j=y;j<=y+add;j++)
{
   if(a[x][j]!=REP)--rest;
   if(a[x+add][j]!=REP)--rest;
   a[x][j]=a[x+add][j]=REP;
}
}

int min(int a1,int a2)
{
if(a1>a2)return a2;
return a1;
}

void scan()
{
int j,i,k,maxadd,tot;
tot=0;
while(rest>0)
{
for(j=0;j<19;j++)
   for(i=0;i<49;i++)
   if( quickjudge(i,j) )
   {
             maxadd=min(19-j,49-i);
              for(k=1;k<=maxadd;k++)
     if(check(i,j,k))
     {
      tot++;
      square[tot].x=i;
      square[tot].y=j;
      square[tot].size=k+1;
      clean(i,j,k);
     }
   }
}
printf("%d\n",tot);
for(i=tot;i>=1;i--)
printf("%d %d %d\n",square[i].x,square[i].y,square[i].size);
}
int main()
{
int i,j;
rest=0;
for(j=0;j<20;j++)
{
   for(i=0;i<50;i++)
   {
    a[i][j]=getchar();
             if(a[i][j]!=46)rest++;
   }
   getchar();
}
scan();
}
