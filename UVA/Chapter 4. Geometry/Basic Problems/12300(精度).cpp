#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
double Pi=acos(-1);
struct Point 
{
      int x;
      int y;
};
int main()
{
      Point a,b;
      int n;
      while(scanf("%d%d%d%d%d",&a.x,&a.y,&b.x,&b.y,&n)&&n)
      {
            double d=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
            double rad=2*Pi/n;
            int m=n/2;
            double r=d/2/sin(rad*m/2);
            double ans=n*r*r*sin(rad)/2;
            printf("%.6lf\n",ans);
      }     
      //system("pause");
      return 0;
}
