#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=20,MOD=1000000007;
int sum[N],f[16][16][16][16][16][16];
long long dp(int a,int b,int c,int d,int e,int last)
{
      long long tmp=0ll;
      if(f[a][b][c][d][e][last])    return f[a][b][c][d][e][last];
      if(a+b+c+d+e==0)  return f[a][b][c][d][e][last]=1;
      if(a) tmp+=(a-(last==2))*dp(a-1,b,c,d,e,1),tmp%=MOD; 
      if(b) tmp+=(b-(last==3))*dp(a+1,b-1,c,d,e,2),tmp%=MOD;
      if(c) tmp+=(c-(last==4))*dp(a,b+1,c-1,d,e,3),tmp%=MOD;
      if(d) tmp+=(d-(last==5))*dp(a,b,c+1,d-1,e,4),tmp%=MOD;
      if(e) tmp+=e*dp(a,b,c,d+1,e-1,5),tmp%=MOD;
      f[a][b][c][d][e][last]=tmp;
      return tmp;
}
int main()
{
      int i,n,x;
      scanf("%d",&n);
      for(i=1;i<=n;++i) scanf("%d",&x),sum[x]++;
      long long ans=dp(sum[1],sum[2],sum[3],sum[4],sum[5],0);
      printf("%lld",ans);
      return 0;
}
