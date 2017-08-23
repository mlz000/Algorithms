#include<cstdio>		
#include<algorithm>
#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;
const int N=12,K=N*N;
int n,k,cnt[1<<11];;
long long f[N][K][1<<11];
bool c1[1<<11],c2[1<<11][1<<11];
void init()
{
	for(int i=0;i<=(1<<n)-1;++i)
	if((i&(i>>1))==0)
	 {
		c1[i]=true;
		cnt[i]=__builtin_popcount(i);
	 }
	for(int i=0;i<=(1<<n)-1;++i)
	 if(c1[i])
	 {
		for(int j=0;j<=(1<<n)-1;++j)
		if(c1[j])
		{
			if(i&j || i&(j>>1) || j&(i>>1))	continue;
			c2[i][j]=true;
		}
	 } 
}
int main()
{
	scanf("%d%d",&n,&k);
	init();
	f[0][0][0]=1;
	for(int i=1;i<=n;++i)
	 for(int j=0;j<=(1<<n)-1;++j)	if(c1[j])
	  for(int l=0;l<=(1<<n)-1;++l)	if(c1[l])
	  if(c2[j][l])
	  {
		for(int m=__builtin_popcount(j);m+__builtin_popcount(l)<=k;++m)
		f[i][m+__builtin_popcount(l)][l]+=f[i-1][m][j];
	  }
	long long ans=0ll;
	for(int i=0;i<=(1<<n)-1;++i)
	ans+=f[n][k][i];  
	printf("%lld",ans);
	return 0;
}
