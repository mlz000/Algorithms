#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define lc (o<<1)
#define rc ((o<<1)|1)
#define mid (l+(r-l)/2)
const int N=25,M=1<<17;
int O,r,c,m,x1,y1,x2,y2,v,anss,ansmin,ansmax;
struct SegT{
	int sum[M],Min[M],Max[M],set[M],addv[M];
	void pushdown(int o){
		if(set[o]>=0){
			set[lc]=set[rc]=set[o];
			addv[lc]=addv[rc]=0;
			set[o]=-1;
		}
		if(addv[o]){
			addv[lc]+=addv[o];
			addv[rc]+=addv[o];
			addv[o]=0;
		}
	}
	void maintain(int o,int l,int r){
		if(r>l){
			sum[o]=sum[lc]+sum[rc];
			Min[o]=min(Min[lc],Min[rc]);
			Max[o]=max(Max[lc],Max[rc]);
		}
		if(set[o]>=0)	Min[o]=Max[o]=set[o],sum[o]=set[o]*(r-l+1);
		if(addv[o])	Min[o]+=addv[o],Max[o]+=addv[o],sum[o]+=addv[o]*(r-l+1);
	}
	void update(int o,int l,int r){
		if(y1<=l && y2>=r){
			if(O==1)	addv[o]+=v;
			else set[o]=v,addv[o]=0;
		}
		else{
			pushdown(o);
			if(y1<=mid)	update(lc,l,mid);
			else maintain(lc,l,mid);
			if(y2>mid)	update(rc,mid+1,r);
			else maintain(rc,mid+1,r);
		}
		maintain(o,l,r);
	}
	void query(int o,int l,int r,int add){
		if(set[o]>=0){
			int w=set[o]+add+addv[o];
			anss+=w*(min(y2,r)-max(y1,l)+1);
			ansmin=min(ansmin,w);
			ansmax=max(ansmax,w);
		}
		else if(y1<=l && y2>=r){
			anss+=sum[o]+add*(r-l+1);
			ansmin=min(ansmin,Min[o]+add);
			ansmax=max(ansmax,Max[o]+add);
		}
		else{
			if(y1<=mid)	query(lc,l,mid,add+addv[o]);
			if(y2>mid)	query(rc,mid+1,r,add+addv[o]);
		}
	}
}tree[N];
int main(){
	while(scanf("%d%d%d",&r,&c,&m)==3){
		memset(tree,0,sizeof(tree));
		for(int i=1;i<=r;++i)	memset(tree[i].set,-1,sizeof(tree[i].set)),tree[i].set[1]=0;
		while(m--){
			scanf("%d",&O);
			if(O<3){
				scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&v);
				for(int i=x1;i<=x2;++i)	tree[i].update(1,1,c);	
			}
			else{
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				anss=0,ansmin=1<<30,ansmax=-(1<<30);
				for(int i=x1;i<=x2;++i)	tree[i].query(1,1,c,0);
				printf("%d %d %d\n",anss,ansmin,ansmax);
			}
		}
	}
	return 0;
}

	
