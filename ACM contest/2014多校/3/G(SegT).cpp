#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int N=100005;
long long f[100];
struct data{
	bool add,flag;//是否都为fibonacci数
	long long num,sum;
}t[N<<2];
void build(int root,int l,int r){
	 t[root].add=t[root].flag=t[root].sum=0;
	 int mid=(l+r)>>1;
	 if(l==r){
	 	t[root].num=1;
		return;
	 }
	 build(root<<1,l,mid);
	 build((root<<1)|1,mid+1,r);
     t[root].sum=t[root<<1].sum+t[(root<<1)|1].sum;	
 	 t[root].num=t[root<<1].num+t[(root<<1)|1].num;
}
inline void pushdown(int root){
	if(t[root].add){
		t[root<<1].add=t[(root<<1)|1].add=t[root<<1].flag=t[(root<<1)|1].flag=1;
		t[root<<1].sum=t[root<<1].num,t[(root<<1)|1].sum=t[(root<<1)|1].num;
		t[root].add=0;
	}
}
void change1(int root,int l,int r,int k,int d){
	if(k<l || k>r)	return;
	int mid=(l+r)>>1;
	if(l==r){
		if(t[root].flag){
			t[root].sum=t[root].num+d;
			t[root].add=t[root].flag=0;
		}
		else	t[root].sum+=d;
		int pos=lower_bound(f,f+90,t[root].sum)-f;
		if(pos==0)	t[root].num=1;
		else t[root].num=(f[pos]-t[root].sum<t[root].sum-f[pos-1]?f[pos]:f[pos-1]);
		return;	
	}
	pushdown(root);
	if(k<=mid)	change1(root<<1,l,mid,k,d);
	else change1((root<<1)|1,mid+1,r,k,d);
	t[root].sum=t[root<<1].sum+t[(root<<1)|1].sum;	
	t[root].num=t[root<<1].num+t[(root<<1)|1].num;
}
long long query(int root,int l,int r,int L,int R){ 
	if(L<=l && r<=R)	return t[root].sum;
	int mid=(l+r)>>1;
	pushdown(root);
	long long tmp=0ll;
	if(L<=mid)	tmp+=query(root<<1,l,mid,L,R);
	if(R>mid)	tmp+=query((root<<1)|1,mid+1,r,L,R);
	return tmp;
}
void change2(int root,int l,int r,int L,int R){
	if(L<=l && r<=R){
		t[root].sum=t[root].num;
		t[root].flag=1;
		t[root].add=1;
		return;
	}
	pushdown(root);
	int mid=(l+r)>>1;
	if(L<=mid)	change2(root<<1,l,mid,L,R);
	if(R>mid)	change2((root<<1)|1,mid+1,r,L,R);
	t[root].sum=t[root<<1].sum+t[(root<<1)|1].sum;	
	t[root].num=t[root<<1].num+t[(root<<1)|1].num;
}
int main(){
	f[0]=f[1]=1ll;
	for(int i=2;i<=90;++i)	f[i]=f[i-1]+f[i-2];
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		build(1,1,n);
		while(m--){
			int op,x,y;
			scanf("%d%d%d",&op,&x,&y);
			if(op==1)	change1(1,1,n,x,y);
			else if(op==2)	printf("%I64d\n",query(1,1,n,x,y));
			else change2(1,1,n,x,y);
		}
	}
	return 0;
}
