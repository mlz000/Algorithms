#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const double eps=1e-12;
const double Pi=acos(-1);
struct Point
{
	double x;
	double y;
	Point(double p=0,double q=0):x(p),y(q) {}
};
typedef Point Vector;
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
Point cnt(Point P,Vector v,Point Q,Vector w)
{
      Vector u=P-Q;
      double t=Cross(w,u)/Cross(v,w);
      return P+v*t;
}
Point get(Point A,Point B,Point C)
{
      Vector v1=C-B;
      double a1=ang(A-B,v1);
      v1=rot(v1,a1/3);
      Vector v2=B-C;
      double a2=ang(A-C,v2);
      v2=rot(v2,-a2/3);
      return cnt(B,v1,C,v2);
}
int main()
{
      int t;
      scanf("%d",&t);
      while(t--)
      {
            Point A,B,C,D,E,F;
            scanf("%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y);
            D=get(A,B,C);
            E=get(B,C,A);
            F=get(C,A,B);  
            printf("%.6lf % .6lf %.6lf %.6lf %.6lf %.6lf\n",D.x,D.y,E.x,E.y,F.x,F.y);
      }
      //system("pause");
      return 0;
}
