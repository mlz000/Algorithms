#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
#define p(a)	((a)*(a))
const double eps=1e-7;
double x[3],y[3],r[3],t[3],dx,dy;
double check(double X,double Y)
{
	double tmp=0.0;
	for(int i=0;i<3;++i) t[i]=sqrt(p(X-x[i])+p(Y-y[i]))/r[i];
	for(int i=0;i<3;++i) tmp+=p(t[i]-t[(i+1)%3]);
	return tmp;
}
int main()
{
	double s=1.0;
	for(int i=0;i<3;++i)	scanf("%lf%lf%lf",&x[i],&y[i],&r[i]),dx+=x[i]/3,dy+=y[i]/3;
	int f=0;
	for(;s>1e-5;f=0)
	{
		if(check(dx,dy)>check(dx+s,dy))	dx+=s,f=1;
		else if(check(dx,dy)>check(dx-s,dy)) dx-=s,f=1;
		else if(check(dx,dy)>check(dx,dy+s)) dy+=s,f=1;
		else if(check(dx,dy)>check(dx,dy-s)) dy-=s,f=1;
		if(!f)	s*=0.7;
	}
	if(check(dx,dy)<1e-5)	printf("%.5lf %.5lf",dx,dy);
	return 0;
}
