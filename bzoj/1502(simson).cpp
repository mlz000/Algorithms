#include<cstdio>//simpson»ý·ÖÊÇÀ÷º¦°¡¡£¡£¡£
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define sqr(x)	((x)*(x))
const int N=505;
const double eps=1e-6;
int n;
double x[N],r[N],fx1[N],fx2[N],fy1[N],fy2[N];
double f(double X)
{
	double s=0.0;
	for(int i=1;i<=n;++i)
	{
		if(fabs(X-x[i])<=r[i])	s=max(s,sqrt(sqr(r[i])-sqr(X-x[i])));
		if(x[i+1]-x[i]>=fabs(r[i+1]-r[i]) && X>=fx1[i] && X<=fx2[i])	
		s=max(s,(X-fx1[i])*(fy2[i]-fy1[i])/(fx2[i]-fx1[i])+fy1[i]);
	}
	return s;
}
double simpson(double L,double R,double fL,double fm,double fR)	{return (R-L)*(fL+fR+4*fm)/6;}
double area(double L,double fL,double m,double fm,double R,double fR,double tot)
{
	double m1=(L+m)*0.5,m2=(m+R)*0.5,fm1=f(m1),fm2=f(m2);
	double tmp1=simpson(L,m,fL,fm1,fm),tmp2=simpson(m,R,fm,fm2,fR);
	if(fabs(tmp1+tmp2-tot)<=eps)	return tmp1+tmp2;
	else return area(L,fL,m1,fm1,m,fm,tmp1)+area(m,fm,m2,fm2,R,fR,tmp2);
}
int main()
{
	double ang;
	scanf("%d%lf",&n,&ang);
	ang=1/tan(ang);
	double h=0.0;
	for(int i=1;i<=n+1;++i)	scanf("%lf",&x[i]),h+=x[i],x[i]=h*ang;
	double L=x[n+1],R=L;
	for(int i=1;i<=n;++i)	
	{
		scanf("%lf",&r[i]);
		L=min(L,x[i]-r[i]);
		R=max(R,x[i]+r[i]);
	}
	for(int i=1;i<=n;++i)
	{
		fx1[i]=x[i]-r[i]*(r[i+1]-r[i])/(x[i+1]-x[i]),fy1[i]=sqrt(sqr(r[i])-sqr(x[i]-fx1[i]));
		fx2[i]=x[i+1]-r[i+1]*(r[i+1]-r[i])/(x[i+1]-x[i]),fy2[i]=sqrt(sqr(r[i+1])-sqr(x[i+1]-fx2[i]));
	}
	double m=(L+R)*0.5,fm=f(m),fL=f(L),fR=f(R);
	printf("%.2lf",2*area(L,fL,m,fm,R,fR,simpson(L,R,fL,fm,fR)));
	return 0;
}
