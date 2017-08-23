#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int N=505,M=1005<<1,INF=1<<20;
vector<int>g[N],ans;
int ca,n,m,s,e,x,y,z,tot,dis[N][2],head[N][2],to[M][2],next[M][2],w[M][2];
bool vis[N];
struct data{
	int to,d;
	friend bool operator<(const data &p,const data &q)	{return p.d>q.d;}
};
void add(int u,int v,int val,int f){
	to[++tot][f]=v;
	w[tot][f]=val;
	next[tot][f]=head[u][f];
	head[u][f]=tot;
}
void init(){
	tot=0;
	ans.clear();
	memset(head,0,sizeof(head));
	memset(next,0,sizeof(next));
	scanf("%d",&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z,0),add(y,x,z,0);
	}
	scanf("%d",&m);
	tot=0;
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z,1),add(y,x,z,1);
	}
}
void dij(int x,int f){
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i)	dis[i][f]=INF;
	dis[x][f]=0;
	priority_queue<data>q;
	data tmp=(data){x,0};
	q.push(tmp);
	while(q.size()){
		tmp=q.top();
		q.pop();
		if(vis[tmp.to])	continue;
		vis[tmp.to]=true;
		for(int j=head[tmp.to][0];j;j=next[j][0]){
			if(dis[tmp.to][f]+w[j][0]<dis[to[j][0]][f]){
				dis[to[j][0]][f]=dis[tmp.to][f]+w[j][0];
				data tmp2=(data){to[j][0],dis[to[j][0]][f]};
				q.push(tmp2);
			}
		}
	}
}
void work(){
	dij(s,0);
	dij(e,1);
	int Min=INF,Minh=-1,Mine=-1;
	for(int i=1;i<=n;++i)
		if(dis[i][0]+dis[i][1]<Min)
			Min=dis[i][0]+dis[i][1],Minh=i;
	for(int i=1;i<=n;++i)
		for(int j=head[i][1];j;j=next[j][1])
			if(dis[i][0]+dis[to[j][1]][1]+w[j][1]<Min)
				Min=dis[i][0]+dis[to[j][1]][1]+w[j][1],Minh=i,Mine=j;
	ans.push_back(Minh);
	for(int i=Minh;;){
		for(int j=head[i][0];j;j=next[j][0]){
			if(dis[i][0]==dis[to[j][0]][0]+w[j][0]){
				ans.push_back(to[j][0]);
				i=to[j][0];
				break;
			}
		}
		if(i==s)	break;
	}
	for(int i=ans.size()-1;i>=0;--i)	printf("%d ",ans[i]);
	ans.clear();
	int pos;
	if(Mine!=-1)	pos=to[Mine][1];
	else pos=Minh;
	if(pos!=Minh)	ans.push_back(pos);
	for(int i=pos;;){
		for(int j=head[i][0];j;j=next[j][0]){
			if(dis[i][1]==dis[to[j][0]][1]+w[j][0]){
				ans.push_back(to[j][0]);
				i=to[j][0];
				break;
			}
		}
		if(i==e)	break;
	}
	for(int i=0;i<ans.size()-1;++i)	printf("%d ",ans[i]);
	printf("%d\n",ans[ans.size()-1]);
	if(Mine!=-1)	printf("%d\n",Minh);
	else printf("Ticket Not Used\n");
	printf("%d\n",Min);
}
int main(){
	while(scanf("%d%d%d",&n,&s,&e)!=EOF){
		if(ca++)	printf("\n");
		init();
		work();
	}
	return 0;
}
