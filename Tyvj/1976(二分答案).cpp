#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath> 
using namespace std;
const double pi=acos(-1.0);
const double lit=1e-10;
const int N=50005;
double x[N],y[N],z[N];
double L,R;
int n;
struct data
{
  double l;
  double r;
  int pos;
}node[N];
bool cmp(data p ,data q)
{
   return p.l<q.l;
}
bool check(double H)
{
     int i,tot=0;
	 for(i=1;i<=n;++i)
     {
	   if(y[i]<=H) continue;
	   double t=(y[i]-H)*z[i];
	   double a=x[i]-t;
	   double b=x[i]+t;//横向覆盖
	   if(a>R || b<L) continue;//未覆盖
	   node[++tot].l=a-lit;node[tot].r=b+lit; 
	 }
	if(tot==0) return false;
	sort(&node[1],&node[tot+1],cmp); 
	if(node[1].l>L) return false;
	double maxr=node[1].r;//能覆盖的最右边
	for(i=2;i<=tot;++i)
	{
	  if(node[i].l>maxr) return maxr>=R;
	  maxr=max(maxr,node[i].r); 
	} 
	return maxr>=R;
}
int main()
{
    int i;
    scanf("%d%lf%lf",&n,&L,&R);
    for(i=1;i<=n;++i)
     {
		scanf("%lf%lf%lf",&x[i],&y[i],&z[i]);
	    z[i]=tan(z[i]/180*pi);//转为正切 
	 }
	double l=0,r=1000;
	double ans=0.0;
	while(r-l>=0.00001)
	{
       double mid=(l+r)/2.0;
       if(check(mid)) {ans=mid;l=mid;}
	   else r=mid;  
	} 
	printf("%.3lf",ans);
	//system("pause");
	return 0;
}

