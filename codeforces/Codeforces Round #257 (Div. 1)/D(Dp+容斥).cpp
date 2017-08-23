#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=20,M=1000000007;
int n,b[1<<21],c[1<<21],p[1000005];
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;++i)	scanf("%d",&x),b[x]++;
	p[0]=1;
	for(int i=1;i<=n;++i)	p[i]=(p[i-1]<<1)%M;
	for(int i=0;i<N;++i)
		for(int j=0;j<(1<<N);++j)
			if(!(j>>i&1))	b[j]+=b[j|(1<<i)];
			else c[j]++;
	long long ans=0ll;
	for(int i=0;i<(1<<N);++i)	ans=(ans+1ll*((c[i]&1)?-1:1)*p[b[i]]%M+M)%M;
	printf("%I64d\n",ans);
	return 0;
}
