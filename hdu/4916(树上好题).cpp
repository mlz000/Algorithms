#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000005,inf=1e9;
int n,q,tot,min3,belong[N],Q[N],head[N],next[N<<1],to[N<<1],fa[N],ans[N];
pair<int,int>a[N];
#define mp make_pair 
void add(int u,int v){
	to[++tot]=v;
	next[tot]=head[u];
	head[u]=tot;
}
int ask(int x,int y){
	if(x>y)	swap(x,y);
	if(x==1 || y==1){
		if(x==1 && y==1)	return 2;
		if(min(belong[y],ans[belong[y]])!=a[1].first)	return	a[1].first;
		return min(a[1].second,ans[y]);
	}
	else{
		if(belong[x]==belong[y])	return 1;
		int tmp1=min(belong[x],a[belong[x]].first),tmp2=min(belong[y],a[belong[y]].first);
		if(min(tmp1,tmp2)!=a[1].first)	return a[1].first;
		int now=0;
		if(tmp1!=a[1].second && tmp2!=a[1].second)	 now=a[1].second;
		else now=min3;
		now=min(now,min(ans[x],ans[y]));
		return now;
	}
}
int main(){
	while(~scanf("%d%d",&n,&q)){
		int last=0;
		tot=0;
		memset(head,0,sizeof(head));
		for(int i=1,x,y;i<n;++i){
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		Q[1]=1;
		for(int h=1,r=1;h<=r;++h){
			int now=Q[h];
			for(int i=head[now];i;i=next[i]){
				if(to[i]==fa[now])	continue;
				if(belong[now])	belong[to[i]]=belong[now];
				else belong[to[i]]=to[i];
				fa[to[i]]=now;
				Q[++r]=to[i];
			}
		}
		for(int i=1;i<=n;++i)	a[i]=mp(inf,inf);
		for(int i=n;i>=1;--i){
			int now=Q[i];
			int tmp=min(now,a[now].first);
			int father=fa[now];
			if(tmp<a[father].second){
				a[father].second=tmp;
				if(a[father].second<a[father].first)	swap(a[father].first,a[father].second);
			}
		}
		min3=inf;
		for(int i=head[1];i;i=next[i]){
			int now=min(to[i],a[to[i]].first);
			if(now!=a[1].first && now!=a[1].second)	min3=min(min3,now);
		}
		for(int i=2;i<=n;++i){
			int minnow=min(Q[i],a[Q[i]].first);
			int father=fa[Q[i]];
			if(father!=1){
				ans[Q[i]]=ans[father];
				if(minnow==a[father].first)	ans[Q[i]]=min(ans[Q[i]],a[father].second);
				else ans[Q[i]]=min(ans[Q[i]],a[father].first);
			}
			else ans[Q[i]]=inf;
		}
		for(int i=2;i<=n;++i)	ans[i]=min(ans[i],a[i].first);
		while(q--){
			int x,y;
			scanf("%d%d",&x,&y);
			x=x^last;
			y=y^last;
			last=ask(x,y);
			printf("%d\n",last);
		}
	}
	return 0;
}
