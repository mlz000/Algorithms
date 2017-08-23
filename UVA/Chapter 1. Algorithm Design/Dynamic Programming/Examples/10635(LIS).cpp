#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=255*255,INF=1<<30;
int T,s[N],g[N],d[N],num[N];
int main(){
	scanf("%d",&T);
	for(int tt=1;tt<=T;++tt){
		int n,p,q,x;
		scanf("%d%d%d",&n,&p,&q);
		memset(num,0,sizeof(num));
		for(int i=1;i<=p+1;++i)	scanf("%d",&x),num[x]=i;
		int tot=0;
		for(int i=1;i<=q+1;++i){
			scanf("%d",&x);
			if(num[x]) s[++tot]=num[x];
		}
		for(int i=1;i<=tot;++i)	g[i]=INF;
		int ans=0;
		for(int i=1;i<=tot;++i){
			int k=lower_bound(g+1,g+tot+1,s[i])-g;
			d[i]=k;
			g[k]=s[i];
			ans=max(ans,d[i]);
		}
		printf("Case %d: %d\n",tt,ans);
	}
	return 0;
}
