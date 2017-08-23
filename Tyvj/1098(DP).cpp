#include<cstdio>
#include<iostream>
#include<algorithm>
#include<climits> 
#include<cstring>
using namespace std;
const int N=5005;  
long long t[N],f[N],dp[N]; 
int main()
{ 
	int i,j,n,s;
	scanf("%d%d",&n,&s); 
	for(i=1;i<=n;++i)
		scanf("%d%d",&t[i],&f[i]);
	for(i=1;i<=n;++i) 
		t[i]+=t[i-1]; 
	for(i=n;i>=1;--i)
	 f[i]=f[i+1]+f[i];//i~n 的系数和
	for(i=1;i<=n;++i)
	{
	  dp[i]=INT_MAX;	 
	 for(j=1;j<=i;++j)
	 {
	   dp[i]=min(dp[i],dp[j-1]+(s+t[i]-t[j-1])*f[j]); //每选一次，对后面的费用都有影响 
	 }
	}  
	  cout<<dp[n]<<endl; 
	  return 0; 
} 
