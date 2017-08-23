#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int N=200005;
long long n,m,s; 
struct data
{
  int w;
  int v;
}a[N];
struct data2
{
    int l;
    int r;
}b[N];
long long sumw[N],sumv[N];
void work(long long k)
{
   int i;
   sumw[0]=sumv[0]=0ll;
   for(i=1;i<=n;++i)
   {
     if(a[i].w>=k)
	 {
	    sumw[i]=sumw[i-1]+1;
	    sumv[i]=sumv[i-1]+a[i].v;
	 }	
	 else 
	 {
			sumw[i]=sumw[i-1];
            sumv[i]=sumv[i-1];
	 }
   }
}
long long calc(long long k)
{
    int i;
    long long tmp=0ll;
    for(i=1;i<=m;++i)
    {
	   tmp+=(sumw[b[i].r]-sumw[b[i].l-1])*(sumv[b[i].r]-sumv[b[i].l-1]);
	}
	return tmp;
}
long long cnt(long long p,long long q)
{
    if(p>q) return p-q;
    else return q-p;
}
int main()
{
   int i;
   cin>>n>>m>>s;
   int MIN=20000000,MAX=-1;
   for(i=1;i<=n;++i)
    {
		scanf("%d%d",&a[i].w,&a[i].v);
        if(a[i].w>MAX) MAX=a[i].w;
        if(a[i].w<MIN) MIN=a[i].w;
	}
	for(i=1;i<=m;++i)
	 scanf("%d %d",&b[i].l,&b[i].r);
   long long l=MIN,r=MAX;	
   long long ans=9223372036854775807ll;
   while(l<=r)
   {
      long long mid=(l+r)/2;
      work(mid);
      long long t=calc(mid);
      if(cnt(t,s)<ans) ans=cnt(t,s);
      if(ans==0) break;
     if(s<t) l=mid+1;
	 else r=mid-1; 
   }
   cout<<ans<<endl;
   return 0;
}

