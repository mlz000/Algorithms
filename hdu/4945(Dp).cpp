#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=100005,M=998244353;
int a[N],c[2100];
long long p[N],dp[20][N],inv[N],fac[N],rfac[N];
int F(int x){
	return x==1?0:F(x/2)+1;
}
long long C(int x, int y) {
	if(y>x||y<0||x<0)	return 0;
	return fac[x]*rfac[y]%M*rfac[x-y]%M;
}
void inc(long long &x,long long y) {
	x+=y;
	if(x>=M) x-=M;
}
void dec(long long &x, long long y) {
	x-=y;
	if(x<0)	x+=M;
}
int main(){
	inv[0]=inv[1]=fac[0]=fac[1]=rfac[0]=rfac[1]=1ll;
	for(int i=2;i<=100000;++i){
		inv[i]=(M-M/i)*inv[M%i]%M;
		fac[i]=fac[i-1]*i%M;
		rfac[i]=rfac[i-1]*inv[i]%M;
	}
	p[0]=1;
	for(int i=1;i<=100000;++i)	p[i]=p[i-1]*2%M;
	int n,tot=0;
	while(scanf("%d",&n)&&n){
		printf("Case #%d: ",++tot);
		memset(c,0,sizeof(c));
		memset(dp,0,sizeof(dp));
		int cnt=0;
		for(int i=1,x;i<=n;++i){
			scanf("%d",&x);
			if(x!=0 && (x&x-1)==0)	++c[F(x)];
			else ++cnt;
		}
		dp[0][0]=1;
		for(int i=0;i<11;++i){
			for(int j=0;j<=1<<(11-i);++j){
				if(dp[i][j]){
					long long t=p[c[i]];
					for(int k=0;k+j<=(1<<(11-i)) && k<=c[i];++k){
						long long cc=C(c[i],k);
						inc(dp[i+1][(j+k)/2],dp[i][j]*cc%M);
						dec(t,cc);
					}
					inc(dp[i+1][1<<(10-i)],dp[i][j]*t%M);
				}
			}
		}
		long long ans=dp[11][1]*p[cnt]%M;
		inc(ans,p[n]);
		dec(ans,p[n-c[11]]);
		printf("%I64d\n",ans);
	}
	return 0;
}

