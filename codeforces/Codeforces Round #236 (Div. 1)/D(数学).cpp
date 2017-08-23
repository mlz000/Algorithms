#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int p=1000000007;
const int N=1005;
LL c[N][N],fac[N],part[N][N],ans[N][N];
int t,n,k;
int main(){
	fac[0]=part[0][0]=c[0][0]=1;
	memset(ans,-1,sizeof(ans));
	for(int i=1;i<=1000;++i){
		for(int j=1;j<=i;++j)
			part[i][j]=(part[i-j][j-1]+part[i-j][j])%p;
	}
	for(int i=1;i<=1000;++i){
		fac[i]=fac[i-1]*i%p;
		c[i][0]=1;
		for(int j=1;j<=i;++j)	c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		if(ans[n][k]==-1){
			ans[n][k]=0;
			for(int s=k*(k-1)/2;s+k<=n;++s)	ans[n][k]=(ans[n][k]+part[s+k][k]*c[n-s][k])%p;
			ans[n][k]=ans[n][k]*fac[k]%p;
		}
		printf("%I64d\n",ans[n][k]);
	}			
	return 0;
}
