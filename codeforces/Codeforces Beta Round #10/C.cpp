#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long cnt[15];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	cnt[(i-1)%9+1]++;
	long long ans=0ll;
	for(int i=1;i<=9;++i)
		for(int j=1;j<=9;++j)
		{
			int k=(i*j-1)%9+1;
			ans+=cnt[i]*cnt[j]*cnt[k];
		}
	for(int i=1;i<=n;++i)	ans-=n/i;
	printf("%I64d",ans);
	return 0;
}

