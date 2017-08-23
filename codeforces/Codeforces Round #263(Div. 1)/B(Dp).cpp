#include<bits/stdc++.h>
using namespace std;
const int N=(int)1e5+5,M=(int)1e9+7;
int n,ans,x[N];
long long d[N][2];
vector<int>g[N];
void dfs(int u,int f){
	d[u][x[u]]=1;
	for(int i=0,v;i<g[u].size();++i)
		if((v=g[u][i])!=f){
			dfs(v,u);
			d[u][1]=(d[u][0]*d[v][1]%M+d[u][1]*(d[v][0]+d[v][1])%M)%M;
			d[u][0]=d[u][0]*(d[v][0]+d[v][1])%M;
		}
}
int main(){
	scanf("%d",&n);
	for(int i=0,a;i<n-1;++i){
		scanf("%d",&a);
		g[a].push_back(i+1);
		g[i+1].push_back(a);
	}
	int pos=-1;
	for(int i=0;i<n;++i)	scanf("%d",&x[i]);
	dfs(0,-1);
	printf("%I64d\n",d[0][1]);
	return 0;
}
