#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
#define eps 1e-8
const int N=2005;
inline int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    else return x<0?-1:1;
} 
struct Point 
{
      double x,y;
      Point(double p=0,double q=0):x(p),y(q) {}
}a[N],p[N*2];
bool operator <(const Point p,const Point q)
{
      return p.x<q.x || (p.x==q.x && p.y<q.y);
}
double Cross(Point p,Point q)
{
    return p.x*q.y-p.y*q.x;
}
Point operator - (Point p,Point q)
{
	return Point(p.x-q.x,p.y-q.y);
}
int main()
{
      int i,n;
      scanf("%d",&n);
      for(i=1;i<=n;++i) scanf("%lf%lf",&a[i].x,&a[i].y);
      sort(&a[1],&a[n+1]);
      int tot=0;
      for(i=1;i<=n;++i)
      {
            while(tot>=2 && dcmp(Cross(p[tot]-p[tot-1],a[i]-p[tot]))<=0)      tot--;
            p[++tot]=a[i];
      }
      int tmp=tot;
      for(i=n-1;i>=1;--i)
      {
            while(tot>tmp && dcmp(Cross(p[tot]-p[tot-1],a[i]-p[tot]))<=0)     tot--;
            p[++tot]=a[i];
      }
      for(i=1;i<tot;++i)     p[tot+i-1]=p[i];
      double ans=0.0;
      for(i=1;i<tot;++i)
      {
            int p1=i+1;
            int p2=p1+1;
            int p3=p2+1;
            for(;p2<i+tot-1;++p2)
            {
                while(1)
                {
                      double tmp1=abs(Cross(p[p2]-p[i],p[p1]-p[i]));
                      double tmp2=abs(Cross(p[p2]-p[i],p[p1+1]-p[i]));
                      if(dcmp(tmp1-tmp2)>=0)    break;
                      else p1++;   
                }  
                while(1)
                {
                      double tmp1=abs(Cross(p[p2]-p[i],p[p3]-p[i]));
                      double tmp2=abs(Cross(p[p2]-p[i],p[p3+1]-p[i]));
                      if(dcmp(tmp1-tmp2)>=0)    break;
                      else p3++;
                      if(p3-i>=tot-1)     break;   
                } 
                if(p3-i>=tot-1)     break; 
                ans=max(ans,(fabs(Cross(p[p2]-p[i],p[p1]-p[i]))+fabs(Cross(p[p2]-p[i],p[p3]-p[i])))/2.0);
            }
      } 
      printf("%.3lf",ans); 
      return 0;
}
