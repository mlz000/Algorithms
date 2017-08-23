#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
const double Pi=acos(-1);
int main()
{
	double a,b,c;
	int tot=1;
	//freopen("1.in","r",stdin);
	while(scanf("%lf%lf%lf",&a,&b,&c)&& a && b && c)
	{
	    printf("Case %d: ",tot);
	    double p=(a+b+c)/2;
	    double s=sqrt(p*(p-a)*(p-b)*(p-c));
	    double ra=s/(p-a);
	    double rb=s/(p-b);
	    double rc=s/(p-c);
		double S=a*ra/2+b*rb/2+c*rc/2+s;
		double anga=acos((b*b+c*c-a*a)/2/b/c);
		double angb=acos((a*a+c*c-b*b)/2/a/c);
	    double angc=acos((a*a+b*b-c*c)/2/a/b);
	    double angd=(angb+angc)/2;
	    double ange=(anga+angc)/2;
	    double angf=(anga+angb)/2;
	    double SS=angd*ra*ra/2+ange*rb*rb/2+angf*rc*rc/2;
	    printf("%.2lf %.2lf\n",S,SS);
	    tot++;
	}
    return 0;
}
