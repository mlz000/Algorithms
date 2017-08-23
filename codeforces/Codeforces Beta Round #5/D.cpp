#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
double a,v,l,d,w;
double dis(double v,double t)	{return v*t+0.5*a*t*t;}
double calc(double s,double V)
{
	double t1=(sqrt(V*V+2*a*s)-V)/a, T=(v-V)/a;
	return t1>=T?T+(s-dis(V,T))/v:t1;
}
int main()
{
	scanf("%lf%lf%lf%lf%lf",&a,&v,&l,&d,&w);
	double tw=w/a;double dw=dis(0,tw);
	double ans;
	if(v<=w || dw>=d)	ans=calc(l,0);
	else	ans=tw+2*calc(0.5*(d-dw),w)+calc(l-d,w);
	printf("%.10lf\n",ans);
	return 0;
}
