#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=25;
int w[N],dp[N*100000];
int main()
{
    int i,n,x,sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&w[i]);
        sum+=w[i];  
    }
    int v=(sum>>1);
    for(int i=1;i<=n;++i)
     for(int j=v;j>=w[i];--j)
     if(dp[j]<dp[j-w[i]]+w[i]) dp[j]=dp[j-w[i]]+w[i];
    printf("%d\n",sum-dp[v]*2);
    return 0;
} 
