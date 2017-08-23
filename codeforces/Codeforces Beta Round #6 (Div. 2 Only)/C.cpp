#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int t[100005];
long long sum1[100005],sum2[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	
	{
		scanf("%d",&t[i]);
		sum1[i]=sum1[i-1]+t[i];
	}
	for(int i=n;i>=1;--i)	sum2[i]=sum2[i+1]+t[i];
	int i=1;
	while(i<=n)
	{
		if(sum1[i-1]<=sum2[i+1])	++i;
		else break;
	}
	printf("%d %d",i-1,n-i+1);
	return 0;
}

