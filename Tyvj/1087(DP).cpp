#include<cstdio>//DP f[i][j]表示讲i分为最大数为j的总方案数 
#include<climits> 
#include<iostream>
#include<string> 
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1000005;
const int MOD=1000000000;
int f[N][30];
int dfs(int p)
{
    int j=1;int t=0;
	while(j<=p)
    {
	  t++;  
	  j=1<<t;
	}
    t--;
    return t;
}
int main()
{ 
	 int i,j,k,t,n;
	 int ans=0;
	 scanf("%d",&n);
	 f[0][0]=1;f[1][0]=1;f[2][0]=1;f[2][1]=2;
	 for(i=3;i<=n;++i)
	{
	  k=dfs(i);
	  f[i][0]=1;
	  for(j=1;j<=k;j++)
	  {
	    if(i==(1<<j)) {f[i][j]=f[i][j-1]+1;continue;}
		f[i][j]=(f[i][j]+f[i-(1<<j)][j]+f[i][j-1])%MOD;
		t=j;
	   if((i-(1<<t))<(1<<j))
	   {
			while((i-(1<<t))<(1<<j) && t>=0) 
		     t--;
	    	f[i][j]=(f[i][j]+f[i-(1<<j)][t])%MOD;
	   }
	  }
	}
     k=dfs(n);
	 printf("%d",f[n][k]);
	 return 0; 
} 
