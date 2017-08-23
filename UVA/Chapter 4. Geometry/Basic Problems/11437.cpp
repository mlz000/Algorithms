#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
struct data
{
    double x;
    double y;
};
double Cross(double x1,double y1 ,double x2,double y2)
{
  return x1*y2-x2*y1>0?x1*y2-x2*y1:x2*y1-x1*y2;
} 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
      data a,b,c;
      scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
      printf("%.0lf\n",Cross(c.x-a.x,c.y-a.y,b.x-a.x,b.y-a.y)/14);
    }
   // system("pause");
    return 0;
} 
