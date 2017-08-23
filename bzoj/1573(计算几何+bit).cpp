#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int N=50005;
struct Point
{
	double ang;
	int id;
	Point(double p=0,int q=0):ang(p),id(q) {}
};
inline bool operator <(const Point p,const Point q)	{return p.ang>q.ang;}
vector<Point> v;
int vis[N],c[N*2];
int size;
int ask(int x)
{
	int sum=0;
	for(;x;x-=x&-x)	sum+=c[x];
	return sum;
}
void add(int x,int num)
{
	for(;x<=size;x+=x&-x)	c[x]+=num;
}
int main()
{
	int i,n,d;
	scanf("%d%d",&n,&d);
	for(i=1;i<=n;++i)
	{
		long long a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		long long tmp = a*a+b*b;
        long long delta2 = d*d*tmp-c*c;
		if (delta2 > 0)
		{
		    double delta = sqrt(delta2), tmp2 = tmp;
		    double x1,x2,y1,y2;
			x1 = (a*c+b*delta)/tmp2,
			x2 = (a*c-b*delta)/tmp2,
			y1 = (b*c-a*delta)/tmp2,
			y2 = (b*c+a*delta)/tmp2;
			v.push_back(Point(atan2(y1, x1), i));
			v.push_back(Point(atan2(y2, x2), i));
		}
	}
	sort(v.begin(),v.end());
	long long ans=0ll;
	size=v.size();
	for(i=0;i<size;++i)
	{
		if(vis[v[i].id])
		{
			ans+=ask(i)-ask(vis[v[i].id]+1);
			add(vis[v[i].id]+1,-1);
		}
		else 
		{
			vis[v[i].id]=i;
			add(i+1,1);
		}
	}
	printf("%lld",ans);
    return 0;
}
