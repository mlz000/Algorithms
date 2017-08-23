#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
const int N=105;
double x[N],y[N];
const double Pi=acos(-1);
using namespace std;
int main()
{
	int n;
	double r;
	scanf("%d%lf",&n,&r);
	double ans=2*Pi*r;
	for(int i=1;i<=n;++i)	
	{
		scanf("%lf%lf",&x[i],&y[i]);
		if(i>=2)	ans+=sqrt((x[i]-x[i-1])*(x[i]-x[i-1])+(y[i]-y[i-1])*(y[i]-y[i-1]));
	}
	ans+=sqrt((x[n]-x[1])*(x[n]-x[1])+(y[n]-y[1])*(y[n]-y[1]));
	printf("%.2lf\n",ans);
	return 0;
}
