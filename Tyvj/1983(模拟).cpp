#include<cstdio>
#include<climits>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue> 
#include<cstring>
using namespace std;
const int N=100005;
long long a[N];
int main()
{
	int i,n;
	long long m;
	scanf("%d%I64d",&n,&m);
	for(i=1;i<=n;++i)
	 scanf("%I64d",&a[i]);
	sort(&a[1],&a[n+1]);
	long long ans=INT_MAX;
	if(a[1]<=m)
	{
	  for(i=2;i<=n;++i)
	   ans=min(ans,(a[i])/(i-1));
	} 
	else 
	{
	  for(i=2;i<=n;++i)
	   ans=min(ans,(a[i]-(a[1]-m))/(i-1));
	}
	printf("%I64d",ans);
//	system("pause");
	return 0;
} 
