#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
#define sqr(x)	((x)*(x))
const int N=10000005;
long long a[N];
int main()
{
	int n,A,B,C;
	scanf("%d%d%d%d%d",&n,&A,&B,&C,a+1); 
	for (int i=2;i<=n;i++) a[i] = ((long long)a[i-1] * A + B) % 100000001;
	double ans=0.0;
	for (int i=1;i<=n;i++) a[i] = a[i] % C + 1;
	for(int i=1;i<n;++i)
	ans+=(double)min(a[i],a[i+1])/(a[i]*a[i+1]);
	ans+=(double)min(a[n],a[1])/(a[1]*a[n]);
	printf("%.3lf",ans);
	return 0;
}
