#include<cstdio>//略神...10年何朴藩国家集训队作业
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=405;
int a[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
	int ans=-1;
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
		{
			int x=a[i]-1,s=0;
			int cnt=0;
			for(int k=i;k<=j;++k)	cnt+=x/a[k],s+=x/a[k]*a[k],x%=a[k];
			cnt++,x=(s+=a[j]);
			for(int k=1;k<=n;++k)	cnt-=x/a[k],x%=a[k];
			if(cnt<0)	ans=(unsigned)ans<s?ans:s;
		}
	printf("%d\n",ans);
	return 0;
}



