#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=505;
const double Pi=acos(-1);
struct Point
{
	double x;
	double y;
	Point(double p=0,double q=0):x(p),y(q) {}
}a[N];
Point operator - (Point p,Point q)
{
	return Point(p.x-q.x,p.y-q.y);
}
double Cross(Point p,Point q)
{
    return p.x*q.y-p.y*q.x;
}
double S(Point x,Point y,Point z) {return fabs(Cross(z-x,y-x));}
int main()
{
      int i,j,k,n,r;
      while(scanf("%d%d",&n,&r) && n && r)
      {
            for(i=1;i<=n;++i) 
            {
                  double ang;
                  scanf("%lf",&ang);
                  ang=ang*Pi/180;
                  a[i].x=r*cos(ang);
                  a[i].y=r*sin(ang);
            }
            double ans=0.0;
            for(i=1;i<=n;++i)
             for(j=i+1;j<=n;++j)
              for(k=j+1;k<=n;++k)
               ans+=S(a[i],a[j],a[k])/2;
           printf("%.0lf\n",ans);    
      }
      //system("pause");
      return 0;
}
