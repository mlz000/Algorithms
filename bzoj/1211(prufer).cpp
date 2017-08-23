#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=155;
int a[N];
bool v[N][N];
int main()
{
	int n;
	long long ans=1ll;
	int sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	{scanf("%d",&a[i]);sum+=a[i]-1;if(a[i]>=n) {printf("0");return 0;}}
	if(sum!=n-2)	{printf("0");return 0;}
	for(int i=2;i<=n-2;++i)
	{
		ans=ans*i;
		for(int j=1;j<=n;++j)
		   for(int k=2;k<=a[j]-1;++k)
		   {
			  if(!v[j][k] && ans>=k && ans%k==0)
			  {
			  	ans/=k;
				v[j][k]=true;
			  }
		   }
	}
	printf("%lld",ans);
	return 0;
}

