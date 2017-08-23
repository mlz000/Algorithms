#include<cstdio>//±©ËÑ
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a,b,h[20],rec[100];
bool dfs(int tot,int x,int pos)
{
	if(tot==0)
	{
		for(int i=1;i<=n;++i)	if(h[i]>=0)	return false;
		return true;
	}
	if(h[x]<0)	return dfs(tot,x+1,pos);
	if(x==n)
	{
		h[n]-=b,rec[tot]=n-1;
		if(dfs(tot-1,x,pos))	return true;
		h[n]+=b;
	}
	else 
	{
		for(int i=max(x,pos);i<=x+1;++i)
		if(i>1 && i<n)	
		{
			rec[tot]=i;
			h[i]-=a,h[i-1]-=b,h[i+1]-=b;
			if(dfs(tot-1,x,i))	return true;
			h[i]+=a,h[i-1]+=b,h[i+1]+=b;
		}
	}
	return false;
}
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;++i)	scanf("%d",&h[i]);
	for(int ans=1;;++ans)
	{
		if(dfs(ans,1,2))
		{
			printf("%d\n",ans);
			for(int i=1;i<=ans;++i)	printf("%d ",rec[i]);
			return 0;
		}
	}
	return 0;
}

