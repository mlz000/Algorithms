#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int ans[501];
int main()
{
	int s=500;
	int i,j,k,n,m,t;
	ans[500]=1;
	scanf("%d",&n);
	int nn=n;
	int x=n;n-=2;
	for(i=1;i<=nn;++i)
	{
		scanf("%d",&t);
		if(--t==-2) continue;
		for(m=j=0;j<t;++j)
		{
			for(k=500;k>=s;--k)
			{
				ans[k]=ans[k]*(n-j)+m;
				m=ans[k]/1000000;
				ans[k]%=1000000;
			}
			while(m)
			{
				ans[--s]=m%1000000;
				m/=1000000;
			}
	    }
		for(j=2;j<=t;++j)
		{
			m=0;
			for(k=s;k<=500;++k)
			{
				ans[k]+=m*1000000;
				m=ans[k]%j;
				ans[k]/=j;
			}
			while(!ans[s]) s++;
		}
		n-=t;x--;
	}
	while(n--)
	{
		m=0;
		for(i=500;i>=s;--i)
		{
			ans[i]=ans[i]*x+m;
			m=ans[i]/1000000;
			ans[i]%=1000000;
		}
		while(m)
		{
			ans[--s]=m%1000000;
			m/=1000000;
		}
	}
	printf("%d",ans[s]);
	for(s++;s<=500;++s) printf("%06d",ans[s]);
    return 0;
}
