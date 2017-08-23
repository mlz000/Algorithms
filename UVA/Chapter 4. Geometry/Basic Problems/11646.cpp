#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
const double eps=1e-12;
const double Pi=acos(-1);
struct Point
{
	double x;
	double y;
	Point(double p=0,double q=0):x(p),y(q) {}
};
double dot(Point p,Point q)
{
	return p.x*q.x+p.y*q.y;
}
double Cross(Point p,Point q)
{
    return p.x*q.y-p.y*q.x;
}
Point operator - (Point p,Point q)
{
	return Point(p.x-q.x,p.y-q.y);
}
Point operator + (Point p,Point q)
{
	return Point(p.x+q.x,p.y+q.y);
}
Point operator * (Point p,double q)
{
	return Point(p.x*q,p.y*q);
}
Point operator / (Point p,double q)
{
	return Point(p.x/q,p.y/q);
}
Point rot(Point p,double rad)
{
	return Point(p.x*cos(rad)-p.y*sin(rad),p.x*sin(rad)+p.y*cos(rad));
}
int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    else return x<0?-1:1;
}
bool operator < (const Point &p,const Point &q)
{
    return p.x<q.x || (p.x==q.x && p.y<q.y);
}
bool operator == (const Point p,const Point q)
{
	return (dcmp(p.x-q.x)==0 && dcmp(p.y-q.y)==0);
}
double len(Point x) {return sqrt(dot(x,x));}
double ang(Point p,Point q) {return acos(dot(p,q)/len(p)/len(q));}
double S(Point x,Point y,Point z) {return Cross(z-x,y-x);}
int main()
{
	int tot=1;
	int x,y;
	while(scanf("%d : %d",&x,&y)!=EOF)
	{
       double k=atan2(y,x);
       double a=200/(k*y/sin(k)+x);
       printf("Case %d: %.10lf %.10lf\n",tot,a*x,a*y);
       tot++;
    }
    return 0;
}
