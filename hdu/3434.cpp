#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
const int N=1000005;
int a[N],b[N],c[N];
int main()
{
	int n,tt,T;
	scanf("%d",&T);
	for(tt=1;tt<=T;++tt)
	{
		printf("Case %d: ",tt);
		scanf("%d",&n);
		long long ans1=0ll,ans2=0ll;
		for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
		for(int i=2;i<=n;++i)
		{
			if(a[i]>a[i-1])	ans1+=a[i]-a[i-1];
			else ans2+=a[i-1]-a[i];
		}
		int MAX=max(a[1],a[n]);
		int MIN=min(a[1],a[n]);
		long long ans=min(ans1,ans2);
		printf("%I64d %d\n",ans,MAX-MIN+1);
	}
	return 0;
}
