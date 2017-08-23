#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps=1e-12;
const double Pi=acos(-1);
struct Point
{
	double x;
	double y;
	Point(double p=0,double q=0):x(p),y(q) {}
}p[2500],ch[2500];
typedef Point Vector;
double Cross(Point p,Point q)
{
    return p.x*q.y-p.y*q.x;
}
int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    else return x<0?-1:1;
}
Point operator - (Point p,Point q)
{
	return Point(p.x-q.x,p.y-q.y);
}
Point operator + (Point p,Point q)
{
	return Point(p.x+q.x,p.y+q.y);
}
bool operator < (const Point &p,const Point &q)
{
    return p.x<q.x || (p.x==q.x && p.y<q.y);
}
bool operator == (const Point p,const Point q)
{
	return (dcmp(p.x-q.x)==0 && dcmp(p.y-q.y)==0);
}
Point rot(Point p,double rad)
{
	return Point(p.x*cos(rad)-p.y*sin(rad),p.x*sin(rad)+p.y*cos(rad));
}
double torad(double rad) {return rad*Pi/180;}
int convexhull(int n,Point p[],Point ch[])
{
    sort(&p[1],&p[n+1]);
    int m=0;
    for(int i=1;i<=n;++i)
    {
        while(m>=2 && Cross(ch[m]-ch[m-1],p[i]-ch[m])<=0) m--;
        ch[++m]=p[i];
    }
    int k=m;
    for(int i=n-1;i>=1;--i)
    {
        while(m>k && Cross(ch[m]-ch[m-1],p[i]-ch[m])<=0) m--;
        ch[++m]=p[i];
    }
    return m;
}
double cnt(Point ch[],int n)
{
    double tmp=0.0;
    for(int i=2;i<=n-1;++i)
       tmp+=Cross(ch[i]-ch[1],ch[i+1]-ch[1]);
    return fabs(tmp/2);    
}
int main()
{
	int n,T;
    scanf("%d",&T);
	while(T--)
	{
        int num=0;
        double s=0.0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            double x,y,w,h,j,ang;
            scanf("%lf%lf%lf%lf%lf",&x,&y,&w,&h,&j);
            Point o(x,y);
            j=torad(j);
            p[++num]=o+rot(Vector(w/2,h/2),-j);
            p[++num]=o+rot(Vector(w/2,-h/2),-j);
            p[++num]=o+rot(Vector(-w/2,h/2),-j);
            p[++num]=o+rot(Vector(-w/2,-h/2),-j);
            s+=w*h;
        }
        int m=convexhull(num,p,ch); 
        double S=cnt(ch,m);
        printf("%.1lf %%\n",s*100/S);
    }
   // system("pause");
    return 0;
}
