#include<iostream>//×îÐ¡KÂ·¾¶¸²¸Ç
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
const int N=110<<1,M=N*N<<1,inf=1e9;
int t,S,T,n,m,K,tot,totf,mincost,head[N],d[N],p[N];
bool ok[N];
char s[15][15];
struct data{
	int u,v,next,w,f;
}e[M];
inline int hash1(int x,int y){return (x-1)*m+y;}
inline int hash2(int x,int y){return n*m+(x-1)*m+y;}
void addedge(int u,int v,int f,int w){
	e[tot].u=u,e[tot].v=v,e[tot].w=w,e[tot].f=f,e[tot].next=head[u],head[u]=tot++;
}
void add(int u,int v,int f,int w){
	addedge(u,v,f,w);
	addedge(v,u,0,-w);
}
bool spfa(){
	queue<int>q;
	for(int i=S;i<=T;++i)	d[i]=inf;
	d[S]=0,p[S]=-1;
	q.push(S);
	while(q.size()){
		int u=q.front();
		q.pop();
		ok[u]=false;
		for(int i=head[u];i!=-1;i=e[i].next){
			int v=e[i].v;
			if(e[i].f>0 && d[u]+e[i].w<d[v]){
				d[v]=d[u]+e[i].w;
				p[v]=i;
				if(!ok[v])	ok[v]=true,q.push(v);
			}
		}	
	}
	return d[T]<inf;
}
void solve(){
	int flow=inf;
	for(int i=p[T];i!=-1;i=p[e[i].u])	flow=min(flow,e[i].f);
	for(int i=p[T];i!=-1;i=p[e[i].u])	e[i].f-=flow,e[i^1].f+=flow;
	totf+=flow;
	mincost+=d[T]*flow;
}
int main(){
	scanf("%d",&t);
	for(int tt=1;tt<=t;++tt){
		memset(head,-1,sizeof(head));
		tot=totf=mincost=0;
		printf("Case %d : ",tt);
		scanf("%d%d%d",&n,&m,&K);
		for(int i=1;i<=n;++i)	scanf("%s",s[i]);
		S=0,T=hash2(n,m)+2;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j){
				add(S,hash1(i,j),1,0);
				add(hash2(i,j),T,1,0);
				add(T-1,hash2(i,j),1,0);
				for(int k=j+1;k<=m;++k){
					if(s[i][j-1]==s[i][k-1])	add(hash1(i,j),hash2(i,k),1,k-j-1-s[i][j-1]+'0');
					else add(hash1(i,j),hash2(i,k),1,k-j-1);
				}	
				for(int k=i+1;k<=n;++k){
					if(s[i][j-1]==s[k][j-1])	add(hash1(i,j),hash2(k,j),1,k-i-1-s[i][j-1]+'0');
					else add(hash1(i,j),hash2(k,j),1,k-i-1);
				}
			}
		add(S,T-1,K,0);
		while(spfa())	solve();
		if(totf!=n*m)	printf("-1\n");
		else printf("%d\n",-mincost);
	}	
	return 0;
}
