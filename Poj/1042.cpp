#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
using namespace std;
const int N=30;
int f[N],ff[N],d[N],t[N];
int dp[N],l[N];
int ans[N][N];
int main()
{
     int i,j,k,n,h;
     while(scanf("%d",&n)&&n)
	{
	   scanf("%d",&h);
	   h=h*12;
	   for(i=1;i<=n;++i)
	    scanf("%d",&f[i]);
	   for(i=1;i<=n;++i)
	    scanf("%d",&d[i]);
	   for(i=1;i<n;++i)
	    {
			scanf("%d",&t[i]);
		    t[i]=t[i]+t[i-1];
		}
		int flag;
		int MAX;
		for(i=1;i<=n;++i)
		  {
			MAX=-1;	
            l[i]=h-t[i-1];//剩下的打渔时间	    
		     for(j=1;j<=i;++j)
		      ff[j]=f[j];
			 while(l[i]--)
			  {
				for(k=i;k>=1;--k)
		          {
			       if(MAX<=ff[k]) {MAX=ff[k];flag=k;}
			      }
			     dp[i]+=ff[flag];
			     if(ff[flag]>=d[flag])
				 ff[flag]-=d[flag]; 
				 else ff[flag]=0;
				 MAX=ff[flag];
				 ans[i][flag]++;	
			  }
		  }	 
		  for(i=1;i<=n;++i)
		  {
		   if(MAX<dp[i]) {MAX=dp[i];flag=i;}
		  }
		  for(j=1;j<n;j++)
		    printf("%d, ",ans[flag][j]*5);
		  printf("%d\n",ans[flag][n]*5);
	printf("Number of fish expected: %d\n\n",dp[flag]);	 
	 memset(ans,0,sizeof(ans)); 
	 memset(dp,0,sizeof(dp));
	}
    system("pause");
    return 0;
}
