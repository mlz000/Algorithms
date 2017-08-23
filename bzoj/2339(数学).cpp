#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1000005,MOD=100000007;
long long p[N]={1},g[N]={1},f[N];
long long pw(long long x,long long y)
{
      long long res=1ll;
      for(;y;y>>=1)
      {
           if(y&1)    res=(res*x)%MOD;
           x=(x*x)%MOD;   
      }
      return res;
}
int main()
{
      int i,n,m;
      scanf("%d %d",&n,&m);
      for(i=1;i<=n;++i) p[i]=(p[i-1]<<1ll)%MOD;
      for(i=1;i<=m;++i) g[i]=g[i-1]*(p[n]-i)%MOD;
      for(i=3;i<=m;++i) f[i]=(g[i-1]-f[i-1]-f[i-2]*(i-1)%MOD*(p[n]-(i-1))%MOD+MOD*2)%MOD;
      long long tmp=1ll;
      for(i=2;i<=m;++i) tmp=(tmp*i)%MOD;
      printf("%lld",f[m]*pw(tmp,MOD-2)%MOD);
	return 0;
}
