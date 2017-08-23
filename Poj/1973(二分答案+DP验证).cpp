#include<iostream>//二分时间t，背包问题，dp[i][j]表示前i个人做了j个1任务所能做的最多的2任务数，dp[n][m]>=m验证 
#include<stack> 
#include<cstdio> 
#include<cstring> 
#include<climits> 
#include<algorithm>
using namespace std; 
const int N=105;
int dp[N][N],x[N],y[N]; 
int n,m; 
bool judge(int t)
{
   int i,j,k; 
   memset(dp,-0x3f,sizeof(dp));
   dp[0][0]=0; 
   for(i=1;i<=n;++i)
    for(j=0;j<=m;++j)
     for(k=0;t-k*x[i]>=0 && k<=j;++k)
     {
       dp[i][j]=max(dp[i][j],dp[i-1][j-k]+(t-k*x[i])/y[i]); 
     }
   return dp[n][m]>=m;   
} 
int main()
{
     int i,t,l,r; 
     scanf("%d",&t);
     while(t--) 
     { 
         scanf("%d%d",&n,&m);
         for(i=1;i<=n;++i) 
          scanf("%d%d",&x[i],&y[i]); 
         l=0;r=10000;
         while(l<=r)
         {
           if(l==r) break; 
           int mid=(l+r)>>1;
           if(judge(mid))  r=mid;
           else l=mid+1; 
         } 
         cout<<r<<endl; 
     } 
     //system("pause"); 
     return 0;
}

