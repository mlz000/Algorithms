#include<cstdio>//f[j][i]=sigma f[j-1][k](sum[j]-sum[k-1]<=ans)
#include<iostream>//g[j][i]=sigma f[j][k](0<=k<=i)
#include<algorithm>//p[i]=pos (sum[i]-sum[pos-1]<=ans)
#include<cmath>//f[j][i]=g[j-1][i-1][p[i]-1]
#include<cstring>
const int N=50005,MOD=10007;
using namespace std;
int n,m,ans,a[N],q[N],sum[N],p[N];
long long f[2][N],g[N];
bool check(int len)
{
    int p=1,tot=m-1;
    while(tot && p<=n)
    {
        int sm=0;
        while(p<=n && sm+a[p]<=len)    sm+=a[p++];
        --tot;
    }
    if(p<=n && sum[n]-sum[p-1]>len) return false;
    return true;     
}
void step1()
{
    int l=1,r=sum[n];
    while(l<=r)
    {
        if(l==r)    break;
        int mid=(l+r)>>1;
        if(check(mid))  r=mid;
        else l=mid+1;
    }
    ans=l;
    printf("%d ",l);
} 
void add(long long &x,long long y)
{
    x+=y;
    x%=MOD;
    if(x<0) x+=MOD;
}
void step2()
{
    for(int i=0;i<=n;++i)   g[i]=1;
    int pos=0;
    for(int i=1;i<=n;++i)
    {
      while(sum[i]-sum[pos]>ans)  ++pos;
      p[i]=pos;
    }
    int now=1;
    long long ANS=0ll;
    for(int j=1;j<=m;++j)   //dp[j][i]Ç°i¸öÇÐj¶Î 
    {
        memset(f[now],0,sizeof(f[now]));
        for(int i=1;i<=n;++i)   add(f[now][i],g[i-1]-g[p[i]-1]);
        g[0]=0;
        add(ANS,f[now][n]);
        for(int i=1;i<=n;++i)   g[i]=g[i-1]+f[now][i];
        now=!now;
    } 
    printf("%lld",ANS);
}
int main()
{
    scanf("%d%d",&n,&m);
    ++m;
    for(int i=1;i<=n;++i)   scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
    step1();
    step2();
    return 0;
}
