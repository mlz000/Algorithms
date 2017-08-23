#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct data{
	double l,r;
};
const int N=1<<7;
int T,n;;
double R,w[15],v[N];
bool vis[N];
vector<data> g[N];
void init(){
	memset(vis,false,sizeof(vis));
	scanf("%lf%d",&R,&n);
	for(int i=0;i<n;++i)	scanf("%lf",&w[i]);
	for(int i=0;i<1<<n;++i){
		v[i]=0,g[i].clear();
		for(int j=0;j<n;++j)
			if(i&(1<<j))	v[i]+=w[j];
	}
}
void dfs(int sta){
	if(vis[sta])	return ;
	vis[sta]=true;
	bool flag=false;
	data tmp;
	for(int i=(sta-1)&sta;i;i=(i-1)&sta){
		int j=sta^i;
		dfs(i),dfs(j);
		for(int a=0;a<g[i].size();++a)
			for(int b=0;b<g[j].size();++b){
				double x1=v[j]*1.0/(v[j]+v[i]);
				double x2=v[i]*1.0/(v[j]+v[i]);
				tmp.l=max(g[i][a].l+x1,g[j][b].l-x2);
				tmp.r=max(g[j][b].r+x2,g[i][a].r-x1);
				if(tmp.l+tmp.r<R)	g[sta].push_back(tmp);
			}
		flag=true;
	}
	if(!flag){
		tmp.l=tmp.r=0.0;
		g[sta].push_back(tmp);
	}
}
void print(){
	double ans=-1;
	for(int i=0;i<g[(1<<n)-1].size();++i)	ans=max(ans,g[(1<<n)-1][i].l+g[(1<<n)-1][i].r);
	printf("%.10lf\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--){
		init();
		dfs((1<<n)-1);
		print();
	}
	return 0;
}
