#include<cstdio>
#include<iostream>
#include<algorithm>
#include<climits> 
using namespace std;
#define INF 0x7ffffffffffll
const int N=100005;
long long a[N],b[N];
long long f[N]; 
long long cnt(long long x,long long y) 
{
      if(x==y)    return INF;
      else return abs(x-y);
} 
long long min(long long x,long long y)
{
      return x<y?x:y;
}
int main()
{
      int i,n;
      scanf("%d",&n);
      for(i=1;i<=n;++i) scanf("%lld%lld",&a[i],&b[i]);
      sort(&a[1],&a[n+1]);sort(&b[1],&b[n+1]);
      f[1]=cnt(a[1],b[1]); 
      f[2]=min(f[1]+cnt(a[2],b[2]),cnt(a[1],b[2])+cnt(a[2],b[1]));
      for(i=3;i<=n;++i)
      {
            f[i]=f[i-1]+cnt(a[i],b[i]);
            f[i]=min(f[i],f[i-2]+cnt(a[i],b[i-1])+cnt(a[i-1],b[i]));
            f[i]=min(f[i],f[i-3]+min(cnt(a[i-2],b[i-1])+cnt(a[i-1],b[i])+cnt(a[i],b[i-2]),
            cnt(a[i-2],b[i])+cnt(a[i-1],b[i-2])+cnt(a[i],b[i-1])));
      }
      if(f[n]>=INF)     printf("-1");
      else printf("%lld",f[n]);
      return 0; 
} 
