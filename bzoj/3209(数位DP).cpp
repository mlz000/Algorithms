#include<cstdio>//N转为二进制，用f[less][dep][sum]表示枚举到当前位是否已经小于N，枚举到dep位，1的个数为sum的乘积 
#include<algorithm>
#include<iostream>
typedef long long LL;
const int N=55,MOD=10000007;
int a[N],f[2][N][N];
int dp(bool less,int dep,int sum)
{
    if(!dep)  return sum?sum:1;  
    if(f[less][dep][sum])   return f[less][dep][sum];
    f[less][dep][sum]=1;
    int top=less?1:a[dep];
    for(int i=0;i<=top;++i)
    f[less][dep][sum]=LL(f[less][dep][sum])*(dp(less || i<a[dep],dep-1,sum+i))%MOD;
    return f[less][dep][sum];
}
int main()
{
    LL n;
    scanf("%lld",&n);
    for(;n;n>>=1)   a[++a[0]]=(n&1);
    printf("%d",dp(0,a[0],0));
    return 0;
}
