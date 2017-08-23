#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int cnt[105*2],a[105*2],ans[105*2],use[105*2];
int main()
{
	int n;
	scanf("%d",&n);
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n*2;++i)
	{
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	for(int i=10;i<=99;++i)	
		if(cnt[i]==1)	cnt1++;
		else if(cnt[i]>=2)	cnt2++;
	int tmp=(cnt2+(cnt1/2))*(cnt2+((cnt1+1)/2));
	printf("%d\n",tmp);
	tmp=0;
	int size1=0;
	for(int i=1;i<=n*2;++i)
	{
		if(cnt[a[i]]>=2 && use[a[i]]<2)
		{
			ans[i]=++use[a[i]];
			if(ans[i]==1)	size1++;
		}
		else if(cnt[a[i]]==1)
		{
			if(tmp<cnt1/2)
			{
				ans[i]=1;
				size1++;
				tmp++;
			}
			else ans[i]=2;
		}
	}
	for(int i=1;i<=n*2;++i)	
	{
		if(ans[i])	printf("%d ",ans[i]);
		else if(size1<n)	printf("1 "),size1++;
		else printf("2 ");
	}
	return 0;
}

