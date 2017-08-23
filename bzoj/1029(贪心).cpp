#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
const int N=150005;
struct Seg
{
      int w,r;
}a[N];
bool operator  < (const Seg &a,const Seg &b){  return a.w<b.w;  }
priority_queue<Seg> q;
bool cmp(const Seg a,const Seg b)   {return a.r<b.r;}
int main()
{
      int n,i;
      scanf("%d",&n);
      for(i=1;i<=n;++i) scanf("%d%d",&a[i].w,&a[i].r);
      sort(&a[1],&a[n+1],cmp);
      int sum=0,ans=0;
      for(i=1;i<=n;++i)
      {
            if(sum+a[i].w<=a[i].r)  {sum+=a[i].w;ans++;q.push(a[i]);}
            else if(a[i].w<q.top().w)     {sum=sum-q.top().w+a[i].w;q.pop();q.push(a[i]);}
      }
      printf("%d",ans);
	return 0;
}
