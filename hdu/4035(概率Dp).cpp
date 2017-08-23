#include<iostream>//Âí¶û¿Æ·òÁ´
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
const int N=10005;
const double eps=1e-10;
double A[N],B[N],C[N],k[N],e[N];
vector<int>edge[N];
void dfs(int u,int f){
	double a=0.0,b=0.0,c=0.0;
	int m=0;
	for(int i=0;i<edge[u].size();++i){
		int v=edge[u][i];
		if(v==f)	continue;
		dfs(v,u);
		a+=A[v];
		b+=B[v];
		c+=C[v];
		++m;
	}
	if(f)	++m;
	double p=(1-k[u]-e[u])/m;
	A[u]=(k[u]+p*a)/(1-p*b);
	B[u]=p/(1-p*b);
	C[u]=(1-k[u]-e[u]+p*c)/(1-p*b);
}
int main(){
	int T,n;
	scanf("%d",&T);
	for(int tt=1;tt<=T;++tt){
		printf("Case %d: ",tt);
		scanf("%d",&n);
		for(int i=1;i<N;++i)	edge[i].clear(),A[i]=0,B[i]=0,C[i]=0;
		for(int i=1,x,y;i<n;++i){
			scanf("%d%d",&x,&y);
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		for(int i=1;i<=n;++i)	scanf("%lf%lf",&k[i],&e[i]),k[i]/=100.0,e[i]/=100.0;
		dfs(1,0);
		if(fabs(1-A[1])<eps)	printf("impossible\n");
		else	printf("%.6lf\n",C[1]/(1-A[1]));
	}
	return 0;
}
