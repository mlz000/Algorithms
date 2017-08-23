#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int N=1005;
int a[N][N],dp[2][N][N];
char s[N*2];
int main()
{
    int i,j,k,n,m;
    memset(dp,0x3f,sizeof(dp));
    scanf("%d",&n);
    for(i=1;i<=n;++i)
     for(j=1;j<=n;++j)
     scanf("%d",&a[i][j]);
    dp[0][1][0]=dp[0][0][1]=dp[1][1][0]=dp[1][0][1]=0;
    int ii=0,jj=0;
    for(i=1;i<=n;++i)
     for(j=1;j<=n;++j)
     {
        if(a[i][j]==0)  ii=i,jj=j;
        dp[0][i][j]=0;
        while(a[i][j] && a[i][j]%2==0)  dp[0][i][j]++,a[i][j]>>=1;
        dp[0][i][j]+=dp[0][i-1][j]<dp[0][i][j-1]?dp[0][i-1][j]:dp[0][i][j-1];
        dp[1][i][j]=0;
        while(a[i][j] && a[i][j]%5==0)  dp[1][i][j]++,a[i][j]/=5;
        dp[1][i][j]+=dp[1][i-1][j]<dp[1][i][j-1]?dp[1][i-1][j]:dp[1][i][j-1];
     }
    if(ii&&dp[0][n][n]&&dp[1][n][n])
	{
	   puts("1");
	   for(k=1;k<ii;k++)putchar('D');
	   for(k=1;k<jj;k++)putchar('R');
	   for(k=ii;k<n;k++)putchar('D');
       for(k=jj;k<n;k++)putchar('R');
	   return 0;
	} 
    int ans=dp[0][n][n]<dp[1][n][n]?0:1;
    printf("%d\n",dp[ans][n][n]); 
    int tot=0;
    for(i=n;i>=1;)
     for(j=n;j>=1;)
     {
        if(dp[ans][i-1][j]<dp[ans][i][j-1])  s[++tot]='D',--i;
        else s[++tot]='R',--j;
        if(i==1 && j==1)  
        {
            for(k=tot;k>=1;--k) printf("%c",s[k]);
	        return 0;
        }
     }
    return 0;
} 
