#include<algorithm>
#include<iostream> 
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
const int N=105;
long long dp[N];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    dp[1]=k-1,dp[2]=(k-1)*k;
    for(int i=3;i<=n;++i)
    {
        dp[i]=(k-1)*(dp[i-1]+dp[i-2]);
    }
    cout<<dp[n]<<endl;
    return 0;
} 
