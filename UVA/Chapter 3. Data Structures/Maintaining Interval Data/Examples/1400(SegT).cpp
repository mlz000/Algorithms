#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define mid (l+(r-l)/2)
#define rl (root<<1)
#define rr ((root<<1)|1)
const int N=500005;
struct Tree{
	int l,r,lpos,rpos;
	long long sum,Max,lsum,rsum;
}tree[N<<2];
int ca,n,m,a,b;
void build(int root,int l,int r){
	if(l==r){
		scanf("%lld",&tree[root].sum);
		tree[root].Max=tree[root].lsum=tree[root].rsum=tree[root].sum;
		tree[root].l=tree[root].r=tree[root].lpos=tree[root].rpos=l;
		return;
	}
	build(rl,l,mid);
	build(rr,mid+1,r);
	tree[root].sum=tree[rl].sum+tree[rr].sum;
	tree[root].lsum=tree[rl].lsum;
	tree[root].lpos=tree[rl].lpos;
	tree[root].rsum=tree[rr].rsum;
	tree[root].rpos=tree[rr].rpos;
	if(tree[rl].sum+tree[rr].lsum>tree[root].lsum)	tree[root].lsum=tree[rl].sum+tree[rr].lsum,tree[root].lpos=tree[rr].lpos;
	if(tree[rl].rsum+tree[rr].sum>=tree[root].rsum)	tree[root].rsum=tree[rl].rsum+tree[rr].sum,tree[root].rpos=tree[rl].rpos;
	int troot;
	if(tree[rl].Max>=tree[rr].Max)	troot=rl;
	else troot=rr;
	tree[root].Max=tree[troot].Max,tree[root].l=tree[troot].l,tree[root].r=tree[troot].r;
	if(tree[rl].rsum+tree[rr].lsum>tree[root].Max || (tree[rl].rsum+tree[rr].lsum==tree[root].Max && tree[rl].rpos<tree[root].l) || (tree[rl].rsum+tree[rr].lsum==tree[root].Max && tree[rl].rpos==tree[root].l && tree[rr].lpos<tree[root].r)){
		tree[root].Max=tree[rl].rsum+tree[rr].lsum;
		tree[root].l=tree[rl].rpos;
		tree[root].r=tree[rr].lpos;
	}
}			
Tree query(int root,int l,int r,int x,int y){
	if(l==x && r==y)	return tree[root];
	if(y<=mid)	return query(rl,l,mid,x,y);
	else if(x>mid)	return query(rr,mid+1,r,x,y);
	else{
		Tree t1=query(rl,l,mid,x,mid);
		Tree t2=query(rr,mid+1,r,mid+1,y);
		Tree tmp;
		if(t1.Max>=t2.Max)	tmp=t1;
		else tmp=t2;
		if(t1.rsum+t2.lsum>tmp.Max || (t1.rsum+t2.lsum==tmp.Max && t1.rpos<tmp.l) || (t1.rsum+t2.lsum==tmp.Max && t1.rpos==tmp.l && t2.lpos<tmp.r)){
			tmp.Max=t1.rsum+t2.lsum;
			tmp.l=t1.rpos;
			tmp.r=t2.lpos;
		}
		tmp.lsum=t1.lsum;	
		tmp.lpos=t1.lpos;
		tmp.rsum=t2.rsum;
		tmp.rpos=t2.rpos;
		if(t1.sum+t2.lsum>tmp.lsum)	tmp.lsum=t1.sum+t2.lsum,tmp.lpos=t2.lpos;
		if(t1.rsum+t2.sum>=tmp.rsum)	tmp.rsum=t1.rsum+t2.sum,tmp.rpos=t1.rpos; 	
		return tmp;
	}
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		ca++;
		printf("Case %d:\n",ca);
		build(1,1,n);
		while(m--){
			scanf("%d%d",&a,&b);
			Tree ans=query(1,1,n,a,b);
			printf("%d %d\n",ans.l,ans.r);
		}
	}
	return 0;
}
