#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
const int N=1005;
using namespace std;
int a[N];
bool v[N];
int n;
int get(int x)
{
	int now=0;
	while(x<=n && !v[x])
	{
		now++;
		v[x]=true;
		x=a[x];
	}
	return now;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
	int ans=1;
	for(int i=1;i<=n;++i)
	{
		if(!v[i])
		{
			int tmp1=get(i);
			tmp2=__gcd(tmp1,ans);
			ans=ans*tmp1/tmp2;
		}
	}
	printf("%d\n",ans);
	return 0;
}


