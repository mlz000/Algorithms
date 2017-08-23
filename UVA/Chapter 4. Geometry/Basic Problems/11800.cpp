#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct Point
{
	int x;
	int y;
	Point(int p=0,int q=0):x(p),y(q) {}
};
int dot(Point p,Point q)
{
	return p.x*q.x+p.y*q.y;
}
int Cross(Point p,Point q)
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
bool operator <(const Point &p,const Point &q)
{
    return p.x<q.x || (p.x==q.x && p.y<q.y);
}
int main()
{
      int i,j,n;
      scanf("%d",&n);
      for(i=1;i<=n;++i)
      {
	     Point a[5];
	     for(j=1;j<=4;++j) scanf("%d%d\n",&a[j].x,&a[j].y);
	     sort(&a[1],&a[5]);
	     printf("Case %d: ",i);
	     if(!Cross(a[1]-a[2],a[3]-a[4]) && !Cross(a[1]-a[3],a[2]-a[4])) 
	     {
			 if(!dot(a[1]-a[4],a[2]-a[3])) 
			 {
				 if(!dot(a[1]-a[2],a[1]-a[3])) printf("Square\n");
			     else printf("Rhombus\n");
			 }
			 else if(!dot(a[1]-a[2],a[1]-a[3])) printf("Rectangle\n");
	         else printf("Parallelogram\n");
	     }
	     else if(!Cross(a[1]-a[2],a[3]-a[4]) || !Cross(a[1]-a[3],a[2]-a[4]) || !Cross(a[1]-a[4],a[2]-a[3]))
	     {
		    printf("Trapezium\n");
		 }
		 else printf("Ordinary Quadrilateral\n");
	  }    
      return 0;
}
