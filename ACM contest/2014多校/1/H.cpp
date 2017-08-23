#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=100005,M=1000000009;;
long long inv[N],fac[N],rfac[N];
void init(){
	inv[0]=inv[1]=fac[0]=fac[1]=rfac[0]=rfac[1]=1ll;
	for(int i=2;i<N;++i){
		inv[i]=(M-M/i)*inv[M%i]%M;
		fac[i]=fac[i-1]*i%M;
		rfac[i]=rfac[i-1]*inv[i]%M;
	}
}
long long C(int x,int y){
	return (fac[x]*rfac[y]%M)*rfac[x-y]%M;
}
int main(){
	int n,m;
	init();
	while(~scanf("%d%d",&n,&m)){
		int f=0;
		int x,l,r;
		for(int i=1;i<=n;++i){
			scanf("%d",&x);
			f=(f+x)%2;
			if(i==1)	{l=r=x;continue;}
			int ll=min(abs(l-x),abs(r-x));
			if(l<=x && x<=r)	ll=0;
			int rr=max(m-abs(l+x-m),m-abs(r+x-m));
			if(l<=m-x && m-x<=r)	rr=m;
			l=ll,r=rr;
		}
		long long ans=0ll;
		for(int i=l;i<=r;++i){
			if(i%2==f)	ans=(ans+C(m,i))%M;
		}
		printf("%I64d\n",ans);
	}
}
