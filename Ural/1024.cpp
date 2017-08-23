#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1005;
int n,p[N];
bool v[N];
int dfs(int x)
{
	int tmp=0;
	while(x<=n && !v[x])
	{
		tmp++;
		v[x]=true;
		x=p[x];
	}
	return tmp;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	scanf("%d",&p[i]);
	int ans=1;
	for(int i=1;i<=n;++i)
	{
		if(!v[i])
		{	
			int tmp1=dfs(i);
			int tmp2=__gcd(ans,tmp1);
			ans=ans*tmp1/tmp2;
		}

	}
	printf("%d\n",ans);
	return 0;
}
