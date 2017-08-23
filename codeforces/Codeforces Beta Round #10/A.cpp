#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int l[105],r[105];
int main()
{
	int n,p1,p2,p3,t1,t2;
	scanf("%d%d%d%d%d%d",&n,&p1,&p2,&p3,&t1,&t2);
	long long ans=0ll;
	for(int i=1;i<=n;++i)	scanf("%d%d",&l[i],&r[i]),ans+=(r[i]-l[i])*p1;
	for(int i=2;i<=n;++i)
	{
		if(l[i]-r[i-1]<=t1)	ans+=(l[i]-r[i-1])*p1;
		else if(l[i]-r[i-1]>t1 && l[i]-r[i-1]<=t1+t2) ans+=t1*p1+(l[i]-r[i-1]-t1)*p2;
		else ans+=t1*p1+t2*p2+(l[i]-r[i-1]-t1-t2)*p3;
	}
	printf("%I64d",ans);
	return 0;
}
