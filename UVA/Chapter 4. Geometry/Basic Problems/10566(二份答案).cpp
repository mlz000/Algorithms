#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
double x,y,c;
bool cnt(double p)
{
    return (1.0/sqrt(x*x-p*p)+1.0/sqrt(y*y-p*p)>=1.0/c); 
}
int main()
{
      while(scanf("%lf%lf%lf",&x,&y,&c)!=EOF)
      {
            double l=0.0;
            double r=min(x,y);
            while(r-l>0.0000000001)
            {
                 double mid=(l+r)/2;
                 if(cnt(mid)) r=mid;
                 else l=mid;
            }
            printf("%.3lf\n",r);
      }
      //system("pause");
      return 0;
}
