#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=205,M=1005;
struct data{
	int u,v,w;
	friend bool operator<(const data &p,const data &q){
		return p.w<q.w;
	}
}e[M];
int n,m,k,st,ed,ste,ede,f[N];
int find(int x){
	if(f[x]==x)	return f[x];
	return f[x]=find(f[x]);
}
int main(){
	while(scanf("%d%d",&n,&m)==2){
		for(int i=1;i<=m;++i)	scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		sort(e+1,e+m+1);
		scanf("%d%d",&ste,&ede);
		scanf("%d",&k);
		while(k--){
			scanf("%d%d",&st,&ed);
			int ans=1<<30;
			for(int i=1;i<=m;++i){
				for(int j=1;j<=n;++j)	f[j]=j;
				for(int j=i;j<=m;++j){
					int fu=find(e[j].u);
					int fv=find(e[j].v);
					if(fu!=fv)	f[fu]=fv;
					if(find(st)==find(ed))	{ans=min(ans,e[j].w-e[i].w);break;}
				}
			}
			printf("%d\n",ans+ste+ede);
		}
	}
	return 0;
}
