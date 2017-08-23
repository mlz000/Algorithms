#include<cstdio>//◊‘  ”¶simpson
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
#define sqr(x)  ((x)*(x)) 
const double eps=1e-6,Pi=acos(-1);
const int N=1005;
int n,st,ed;
double xl[N],xr[N];
struct Cir
{
	double x,y,r;
	Cir(){}
	Cir(double x0,double y0,double r0)	{x=x0,y=y0,r=r0;}
}list[N],tmp[N];
pair<double,double> seg[N];  
bool cmp1(const Cir &a,const Cir &b)	{return a.r>b.r;}
bool cmp2(const Cir &a,const Cir &b){return a.x-a.r<b.x-b.r||fabs(a.x-a.r-(b.x-b.r))<=eps&&a.x+a.r<b.x+b.r;}  
inline bool in(int i,int j)	{return sqr(tmp[i].x-list[j].x)+sqr(tmp[i].y-list[j].y)<=sqr(tmp[i].r-list[j].r);}
void init()
{
	int j,cnt;
	scanf("%d",&cnt);
	for(int i=1;i<=cnt;++i)
	{
		double x0,y0,r0;
		scanf("%lf%lf%lf",&x0,&y0,&r0);
		if(r0)	list[++n]=Cir(x0,y0,r0);
	}
	sort(list+1,list+n+1,cmp1);
	int k=0;
	for(int i=1;i<=n;++i)
	{
		for(j=1;j<=k;++j)	if(in(j,i))	break;
		if(j>k)	tmp[++k]=list[i];	
	}
	n=k;
	for(int i=1;i<=n;++i)	list[i]=tmp[i];
}
double f(double x)
{
	int j,tot=0;  
    double ret=0,dis,l,r; 
	for(int i=st;i<=ed;++i)
	{
		if(x<=xl[i] || x>=xr[i])	continue;
		dis=sqrt(list[i].r-sqr(list[i].x-x));
		seg[++tot]=make_pair(list[i].y-dis,list[i].y+dis);
	}
	sort(seg+1,seg+1+tot);
	for(int i=1;i<=tot;++i)
	{
		l=seg[i].first,r=seg[i].second;
		for(j=i+1;j<=tot;++j)
		{
			if(seg[j].first>r)	break;
			else r=max(r,seg[j].second);
		}
		ret+=r-l;i=j-1;
	}
	return ret;
}
double calc(double s,double fl,double fr,double fmid)	{return (fl+fr+4*fmid)*s/6;}
double simpson(double l,double mid,double r,double fl,double fmid,double fr,double tot)
{
	double m1=(l+mid)*0.5,m2=(mid+r)*0.5;
	double fm1=f(m1),fm2=f(m2);
	double tmp1=calc(mid-l,fl,fmid,fm1),tmp2=calc(r-mid,fmid,fr,fm2);
	if(fabs(tmp1+tmp2-tot)<=eps)	return tmp1+tmp2;
	else return simpson(l,m1,mid,fl,fm1,fmid,tmp1)+simpson(mid,m2,r,fmid,fm2,fr,tmp2);
}
void solve()
{
	int j;
	sort(list+1,list+1+n,cmp2);
	for(int i=1;i<=n;++i)	xl[i]=list[i].x-list[i].r,xr[i]=list[i].x+list[i].r,list[i].r*=list[i].r;
	double l,r,mid,fl,fr,fmid;
	double ans=0;
	for(int i=1;i<=n;++i)
	{
		l=xl[i],r=xr[i];
		for(j=i+1;j<=n;++j)
		{
			if(xl[j]>r)	break;
			else r=max(xr[j],r);
		}
		mid=(l+r)*0.5;
		st=i,ed=j-1,i=j-1;
		fl=f(l),fmid=f(mid),fr=f(r);
		ans+=simpson(l,mid,r,fl,fmid,fr,calc(r-l,fl,fr,fmid));
	}
	printf("%.3lf",ans);
}
int main()
{
	init();
	solve();
	return 0;
}
