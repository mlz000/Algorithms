#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
const int N=25;
int a[N],sum[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			for(int k=j+1;k<=n;++k)
				for(int l=k+1;l<=n;++l)
					if(sum[j]-sum[i]==sum[l]-sum[k] && sum[k]-sum[j]==sum[n]-(sum[l]-sum[i]))	++ans;
	printf("%d\n",ans);
	return 0;
}
