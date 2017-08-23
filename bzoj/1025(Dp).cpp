#include<iostream>//f[i][j]表示将j分解后质因数最大不超过a[i]的方案数，排数即位拆分后的数字的最小公倍数 
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1005;
int n,tot,prime[N];
long long f[N][N];
bool isprime[N];
long long ans=0ll;
void shai()
{
      for(int i=2;i<=1000;++i)
      {
            if(!isprime[i])   prime[++tot]=i;
            for(int j=1;j<=tot && prime[j]*i<=1000;++j) 
            {
                  isprime[prime[j]*i]=true;
                  if(i%prime[j]==0) break;
            }
      }
}
void solve()
{
      f[0][0]=1;
      for(int i=1;i<=tot;++i)
       for(int j=0;j<=n;++j)
       {
            f[i][j]=f[i-1][j];
            int tmp=prime[i];
            while(tmp<=j)
            {
                  f[i][j]+=f[i-1][j-tmp];
                  tmp*=prime[i];
            } 
       }
       for(int i=0;i<=n;++i)   ans+=f[tot][i];   
       printf("%lld",ans);     
}
void init()
{
      scanf("%d",&n);
      shai();
      solve();
}
int main()
{
        init();
        shai();   
        return 0;
}
