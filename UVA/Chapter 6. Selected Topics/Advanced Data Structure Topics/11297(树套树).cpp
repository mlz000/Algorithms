#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
#define lo (o<<1)
#define ro ((o<<1)|1)
const int N=2005,INF=1<<25;
int a[505][505];
struct SegT{
	int Max[N][N],Min[N][N],n,m,w,wmax,wmin;
	int row,xo,x1,y1,x2,y2,x,y;
	bool xleaf;
	void modify1D(int o,int l,int r){
		if(l==r){
			if(xleaf)	{Max[xo][o]=Min[xo][o]=w;return;}
			Max[xo][o]=max(Max[xo<<1][o],Max[(xo<<1)|1][o]);
			Min[xo][o]=min(Min[xo<<1][o],Min[(xo<<1)|1][o]);
		}
		else{
			int mid=l+(r-l)/2;
			if(y<=mid)	modify1D(lo,l,mid);
			else modify1D(ro,mid+1,r);
			Max[xo][o]=max(Max[xo][lo],Max[xo][ro]);
			Min[xo][o]=min(Min[xo][lo],Min[xo][ro]);
		}
	}
	void modify2D(int o,int l,int r){
		if(l==r)	{xo=o;xleaf=1;modify1D(1,1,m);}
		else{
			int mid=l+(r-l)/2;
			if(x<=mid)	modify2D(lo,l,mid);
			else modify2D(ro,mid+1,r);
			xo=o,xleaf=0,modify1D(1,1,m);
		}
	}
	void modify(){
		modify2D(1,1,n);
	}
	void query1D(int o,int l,int r){
		if(y1<=l && y2>=r)	{wmax=max(wmax,Max[xo][o]);wmin=min(wmin,Min[xo][o]);}
		else{
			int mid=l+(r-l)/2;
			if(y1<=mid)	query1D(lo,l,mid);
			if(y2>mid)	query1D(ro,mid+1,r);
		}
	}
	void query2D(int o,int l,int r){
		if(x1<=l && x2>=r)	{xo=o;query1D(1,1,m);}
		else{
			int mid=l+(r-l)/2;
			if(x1<=mid)	query2D(lo,l,mid);
			if(x2>mid)	query2D(ro,mid+1,r);
		}
	}
	void query(){
		wmax=-INF,wmin=INF;
		query2D(1,1,n);
	}
	void build1D(int o,int l,int r){
		if(l==r)	Max[xo][o]=Min[xo][o]=a[row][l];
		else{
			int mid=l+(r-l)/2;
			build1D(lo,l,mid);
			build1D(ro,mid+1,r);
			Max[xo][o]=max(Max[xo][lo],Max[xo][ro]);
			Min[xo][o]=min(Min[xo][lo],Min[xo][ro]);
		}
	}
	void build2D(int o,int l,int r){
		if(l==r)	{xo=o,row=l,build1D(1,1,m);}
		else{
			int mid=l+(r-l)/2;
			build2D(lo,l,mid);
			build2D(ro,mid+1,r);
			for(int i=1;i<=m*4;++i){
				Max[o][i]=max(Max[lo][i],Max[ro][i]);
				Min[o][i]=min(Min[lo][i],Min[ro][i]);
			}
		}
	}
	void build(){
		build2D(1,1,n);
	}
}t;
int main(){
	char op[10];
	int n,m,q;
	scanf("%d%d",&n,&m);
	t.n=n,t.m=m;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	t.build();
	scanf("%d",&q);
	while(q--){
		scanf("%s",op);
		if(op[0]=='q'){
			scanf("%d%d%d%d",&t.x1,&t.y1,&t.x2,&t.y2);
			t.query();
			printf("%d %d\n",t.wmax,t.wmin);
		}
		else{
			scanf("%d%d%d",&t.x,&t.y,&t.w);
			t.modify();
		}
	}
	return 0;
}
