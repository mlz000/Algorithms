#include<algorithm>
#include<iostream> 
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
const int N=500,MOD=1000000;
int dp[N][1005];
int s[N];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=200;++i) s[i]=500;
    dp[1][500]=k-1,dp[0][500]=1;
    for(int i=2;i<=n;++i)
    {
        s[i]=s[i-1];
        int left=0;
        for(int j=500;j>=s[i];--j)  
        {
            dp[i][j]=(k-1)*(dp[i-1][j]+dp[i-2][j])+left;
            left=dp[i][j]/MOD;
            dp[i][j]%=MOD;                                            
        }
        while(left)
        {
           dp[i][--s[i]]=left%MOD;
           left/=MOD;
        }
    printf("%d",dp[n][s[n]]);
    for(++s[n];s[n]<=500;++s[n])  printf("%06d",dp[n][s[n]]);
    } 
    return 0;
} 
