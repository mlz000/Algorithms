#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=20;
int n,m,g[N][N],h[1<<N][N];
long long f[1<<N][N];
long long dp(int m,int s,int t){//状态为m,以t为终点的简单路径
	if(f[m][t])	return f[m][t];
	f[m][t]=0;
	for(int i=s;i<n;++i)
		if(g[t][i]){
			if(i==s&&m!=(1<<s)+(1<<t))	++f[m][t];
			else if((m&(1<<i))==0)	f[m][t]+=dp(m|(1<<i),s,i);
		}
	return f[m][t];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,a,b;i<=m;++i){
		scanf("%d%d",&a,&b);
		g[a-1][b-1]=g[b-1][a-1]=true;
	}
	long long ans=1ll;
	for(int i=0;i<n;++i)	ans+=dp(1<<i,i,i);
    printf("%I64d\n",ans>>1ll);
	return 0;
} 
