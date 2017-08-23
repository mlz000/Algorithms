#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=15;
long long f[N][N],d[N],sum[N];;
int c[N];
long long work(long long x)
{
    if(x<10)    return x;
    int l=0;
    while(x) {c[++l]=x%10;x/=10;}
    long long ans=sum[l-1];
    for(int i=l;i>=1;--i)
    {
        if(i==l)    for(int j=1;j<c[i];++j)    ans+=f[i][j];
        else 
        {
           if(i!=1) {for(int j=0;j<c[i];++j) if(abs(j-c[i+1])>=2) ans+=f[i][j];}
           else  {for(int j=0;j<=c[i];++j) if(abs(j-c[i+1])>=2) ans+=f[i][j];}
        }
        if(i!=l && abs(c[i]-c[i+1])<=1) break;
    }
    return ans;
}
int main()
{
    int i,j,k;
    for(i=0;i<=9;++i)   f[1][i]=1;
    for(i=2;i<=10;++i)
     for(j=0;j<=9;++j)
      for(k=0;k<=9;++k)
      if(abs(j-k)>=2) f[i][j]+=f[i-1][k];
    for(i=1;i<=10;++i)
     for(j=1;j<=9;++j)
      d[i]+=f[i][j]; 
    for(i=1;i<=10;++i)  sum[i]=sum[i-1]+d[i];  
    long long a,b;
    scanf("%lld%lld",&a,&b);
    printf("%lld",work(b)-work(a-1));
    return 0;
}
