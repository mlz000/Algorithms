#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1e6+5,M=1000000007;
int tot,p[N];
long long n,m,f[N],f1[N],f2[N],f3[N],g[N];
bool check[N];
long long calc(long long x){
	long long a=x,b=x+1,c=2*x+1;
	if(a%3==0)	a/=3;
	else if(b%3==0)	b/=3;
	else c/=3;
	return a*b%M*c%M;
}
void init(){
	f[1]=1ll;
	for(int i=2;i<N;++i){
		if(!check[i])	p[++tot]=i,f[i]=i-1;
		for(int j=1;j<=tot && i*p[j]<N;++j){
			check[i*p[j]]=true;
			if(i%p[j]==0){
				f[i*p[j]]=f[i]*p[j];
				break;
			}
			else f[i*p[j]]=f[i]*(p[j]-1);
		}
	}
	for(int i=1;i<N;++i)
		for(int j=i;j<N;j+=i)
			g[j]=(g[j]+1ll*f[j/i]*i%M)%M;
	for(int i=1;i<N;++i){
		g[i]=(g[i]*2+1ll*i*i%M*i%M-1ll*i*i%M*(i+1)%M-2ll*i*i%M+calc(i)+M*2)%M;
	}
	for(int i=1;i<N;++i){
		f1[i]=(f1[i-1]+1ll*g[i])%M;
		f2[i]=(f2[i-1]+1ll*g[i]*i%M)%M;
		f3[i]=(f3[i-1]+1ll*g[i]*i%M*i%M)%M;
	}
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%I64d%I64d",&n,&m);
		if(n>m)	swap(n,m);
		long long ans=((n*m+n+m+1)%M*f1[n]%M-(m+n+2)*f2[n]%M+f3[n]+M)%M;
		printf("%I64d\n",ans);		
	}
	return 0;
}


