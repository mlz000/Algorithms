#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int N=100005;
priority_queue<long long,vector<long long > >q;
struct data
{
	long long d;
	long long p;
}a[N];
bool operator < (const data a,const data b)	{return a.d < b.d;}
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;++i)	scanf("%lld%lld",&a[i].d,&a[i].p);
	sort(&a[1],&a[n+1]);
	long long ans=0ll;
	long long now=1000000000;
	for(i=n;i>=0;--i)
	{
		while(now>a[i].d && q.size()>0)
		{
			now--;
			ans+=q.top();
			q.pop();
		}
		now=a[i].d;
		q.push(a[i].p);	
	}
	printf("%lld",ans);
    return 0;
}
