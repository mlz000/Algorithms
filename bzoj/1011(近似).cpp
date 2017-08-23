#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define eps 1e-8 
#define N  100010 
using namespace std;
long long m[N],sum[N];
double f[N];
int n;
double a;
void solve()
{
    for(int i=min(2000,n);i>=1;--i)
    {
        int k=(int)(eps+floor(a*i));
        for(int j=1;j<=k;++j)   f[i]+=m[i]*m[j]/(double)(i-j);
    }
    for(int i=2001;i<=n;++i)
    {
        int k=(int)(a*i);
        for(int j=1;j<=k;++j)   f[i]=sum[k]*m[i]/(double)(i-k/2);//½üËÆ¼ÆËã 
    }
}
int main()
{
    scanf("%d%lf",&n,&a);
    for(int i=1;i<=n;++i)
    {
        scanf("%I64d",&m[i]);
        sum[i]=sum[i-1]+m[i];
    }
    solve();
    for(int i=1;i<=n;++i) printf("%.6lf\n",f[i]);
    return 0;
}
