#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define lc (o<<1)
#define rc ((o<<1)|1)
#define mid (l+(r-l)/2)
const int N=100005,M=1000005;
int maxy,n,m,T,a,b,x[N],y[N],ans1,ans2;
char s[10];
struct SegT{
	int add1[M<<2],add2[M<<2];
	void init(int x){
		memset(add1,0,sizeof(int)*x*4);
		memset(add2,0,sizeof(int)*x*4);
	}
	void update(int o,int l,int r,int x,int y,int ad1,int ad2){
		if(x<=l && y>=r){
			add1[o]+=ad1;
			add2[o]+=ad2;
			return;
		}
		if(x<=mid)	update(lc,l,mid,x,y,ad1,ad2);
		if(y>mid)	update(rc,mid+1,r,x,y,ad1,ad2);
	}	
	void query(int o,int l,int r,int y){
		ans1+=add2[o];
		ans2+=add1[o];
		if(l==r)	return;
		if(y<=mid)	query(lc,l,mid,y);
		else query(rc,mid+1,r,y);
	}
}tree;
struct union_found{
	int Min[N],Max[N],f[N],num[N];
	int find(int x){
		if(f[x]==x)	return f[x];
		return f[x]=find(f[x]);
	}
	void init(){
		for(int i=1;i<=n;++i){
			f[i]=i;
			Min[i]=Max[i]=y[i]+1;
			num[i]=1;
		}
	}
	void merge(int a,int b){
		int fa=find(a);
		int fb=find(b);
		if(fa!=fb){
			if(Max[fa]>Min[fa])	tree.update(1,1,maxy,Min[fa],Max[fa]-1,-num[fa],-1);
			if(Max[fb]>Min[fb])	tree.update(1,1,maxy,Min[fb],Max[fb]-1,-num[fb],-1);
			num[fb]+=num[fa];
			Max[fb]=max(Max[fb],Max[fa]);
			Min[fb]=min(Min[fb],Min[fa]);
			f[fa]=fb;
			if(Max[fb]>Min[fb])	tree.update(1,1,maxy,Min[fb],Max[fb]-1,num[fb],1);
		}
	}
}uf;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		maxy=0;
		for(int i=1;i<=n;++i)	scanf("%d%d",&x[i],&y[i]),maxy=max(maxy,y[i]+1);
		uf.init();
		tree.init(maxy);
		scanf("%d",&m);
		while(m--){
			scanf("%s",s);
			if(s[0]=='r'){
				scanf("%d%d",&a,&b);
				uf.merge(a+1,b+1);
			}
			else{
				double num;
				ans1=ans2=0;
				scanf("%lf",&num);
				tree.query(1,1,maxy,(int)(num+0.5));
				printf("%d %d\n",ans1,ans2);
			}
		}
	}
	return 0;
}

