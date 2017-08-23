/*叉积判断三角形 Cross(A,B,P),Cross(B,C,P),Cross(C,A,P)同时>=0 或者同时<=0
int Cross(Point a, Point b, Point c) 
{  
	 return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);  
 } */ 
#include<cstdio> 
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=100;
struct data 
{
   int t;int r;int x1;int x2;int x3;int y1;int y2;int y3;
}a[N];
int n;
char s[10];
int check(int x0,int y0,int x1,int y1,int x2,int y2)
{ 
	return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0); 
}
bool judge(int x,int y)
{
   int i;
   for(i=1;i<=n;++i)
   {
      if(a[i].t==1)
       {
	     if((x-a[i].x1)*(x-a[i].x1)+(y-a[i].y1)*(y-a[i].y1)<=a[i].r*a[i].r)
	      return true;
	   }
	  if(a[i].t==2)
	  {
       if((check(a[i].x1,a[i].y1,a[i].x2,a[i].y2,x,y)>=0 && check(a[i].x2,a[i].y2,a[i].x3,a[i].y3,x,y)>=0 && check(a[i].x3,a[i].y3,a[i].x1,a[i].y1,x,y)>=0)||
	   (check(a[i].x1,a[i].y1,a[i].x2,a[i].y2,x,y)<=0 && check(a[i].x2,a[i].y2,a[i].x3,a[i].y3,x,y)<=0 && check(a[i].x3,a[i].y3,a[i].x1,a[i].y1,x,y)<=0))
	   return true;
	  }  
      if(a[i].t==3) 
      {
	    if(a[i].x1<=x && x<=a[i].x1+a[i].r && a[i].y1<=y && y<=a[i].y1+a[i].r)
	     return true;
	  }
   }
   return false;
}
int main()
{
   int i;
   int ans=0;
   scanf("%d",&n);
   for(i=1;i<=n;++i) 
   {
      scanf("%s",s);
      if(s[0]=='C') {a[i].t=1;scanf("%d%d%d",&a[i].x1,&a[i].y1,&a[i].r);}
      if(s[0]=='T') {a[i].t=2;scanf("%d%d%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2,&a[i].x3,&a[i].y3);}
      if(s[0]=='S') {a[i].t=3;scanf("%d%d%d",&a[i].x1,&a[i].y1,&a[i].r);}
   }
   int x,y;
   for(x=-50;x<=100;++x)
    for(y=-50;y<=100;++y)
     if(judge(x,y)) ans++;
    printf("%d\n",ans);
   return 0;
}

