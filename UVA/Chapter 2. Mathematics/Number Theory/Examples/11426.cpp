#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=4000005;
int n,tot,p[N];
long long phi[N],f[N],g[N];
bool check[N];
void init(){
	phi[1]=1;
	for(int i=2;i<N-4;++i){
		if(!check[i])	p[++tot]=i,phi[i]=i-1;
		for(int j=1;j<=tot && i*p[j]<N-4;++j){
			check[i*p[j]]=true;
			if(i%p[j]==0)	{phi[i*p[j]]=phi[i]*p[j];break;}
			else phi[i*p[j]]=phi[i]*(p[j]-1);
		}
	}
	for(int i=1;i<N-4;++i)
		for(int j=i+i;j<N-4;j+=i)
			f[j]+=phi[j/i]*i;
	g[2]=f[2];
	for(int i=3;i<N-4;++i)	g[i]=g[i-1]+f[i];
}
int main(){
	init();
	while(scanf("%d",&n)&&n)	printf("%lld\n",g[n]);
	return 0;
}
