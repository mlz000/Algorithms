#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define inf 0x3f3f3f3f
#define Max 110
int dp[2][3900][2];
int v[3900];
int n,m;
int main()
{
    int i,j,k,ans;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&v[i]);
    for(j=0;j<=m;j++)
    {
        dp[1][j][0]=-inf;
        dp[1][j][1]=-inf;
    }
    dp[1][1][1]=0;
    for(i=2;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            dp[i&1][j][0]=-inf;
            dp[i&1][j][1]=-inf;
        }
        for(j=0;j<=m;j++)
        {
            dp[i&1][j][0]=max(dp[(i-1)&1][j][0],dp[(i-1)&1][j][1]);
            if(j>0)
                dp[i&1][j][1]=max(dp[(i-1)&1][j-1][0],dp[(i-1)&1][j-1][1]+v[i]);
        }
    }
    ans=max(dp[n&1][m][0],dp[n&1][m][1]+v[1]);
    for(j=0;j<=m;j++)
    {
        dp[1][j][0]=-inf;
        dp[1][j][1]=-inf;
    }
    dp[1][0][0]=0;
    for(i=2;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            dp[i&1][j][0]=-inf;
            dp[i&1][j][1]=-inf;
        }
        for(j=0;j<=m;j++)
        {
            dp[i&1][j][0]=max(dp[(i-1)&1][j][0],dp[(i-1)&1][j][1]);
            if(j>0)
                dp[i&1][j][1]=max(dp[(i-1)&1][j-1][0],dp[(i-1)&1][j-1][1]+v[i]);
        }
    }
    ans=max(ans,dp[n&1][m][0]);
    ans=max(ans,dp[n&1][m][1]);
    printf("%d\n",ans);
    //system("pause");
    return 0;
}
