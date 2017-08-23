#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
void solve()
{
    double r,m1,m2,m3,n1,n2,n3;
    scanf("%lf",&r);
    scanf("%lf%lf%lf%lf%lf%lf",&m1,&n1,&m2,&n2,&m3,&n3);
    double a=m1+n1;//*bi;
    double b=m1+m1*m3/n3;//*bi
    double c=n1+n1*n2/m2;//*bi
    double C=a+b+c;//*bi
    double p=C/2;//*bi
    double s=sqrt(p*(p-a)*(p-b)*(p-c));
    double bi=C*r/2/s;
    s=s*bi*bi;
    printf("%.10lf\n",s);
}
int main()
{
	int T;
    scanf("%d",&T);
	while(T--)
	{
        solve();
    }
    return 0;
}
