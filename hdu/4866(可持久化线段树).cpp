#include<iostream>//可持久化线段树
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=100005;
int n,m,x,p,cnt,h[N],root[N*40],ct[N*40],l[N*40],r[N*40];
long long sum[N*40];
struct data{
	int l,r,d;
}a[N];
struct Q{
	int d,pos,add;
	bool operator < (const Q &p)const{
		return pos<p.pos;
	}
}b[N<<1];
void insert(int x,int &y,int L,int R,int num,int add){
	y=++cnt;
	sum[y]=sum[x]+h[num]*add;
	ct[y]=ct[x]+add;
	l[y]=l[x],r[y]=r[x];
	if(L==R)	return;
	int mid=(L+R)>>1;
	if(num<=mid)	insert(l[x],l[y],L,mid,num,add);
	else insert(r[x],r[y],mid+1,R,num,add);
}
long long findkth(int x,int L,int R,int k){
	if(L==R)	return (long long)k*h[L];
	int mid=(L+R)>>1;
	if(k<=ct[l[x]])	return findkth(l[x],L,mid,k);
	else return sum[l[x]]+findkth(r[x],mid+1,R,k-ct[l[x]]);
}
void solve(){
	int tot=0,tot2=0;
	cnt=0;
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].d);
		h[++tot]=a[i].d;
	}
	sort(h+1,h+tot+1);
	tot=unique(h+1,h+tot+1)-h-1;
	for(int i=1;i<=n;++i){
		a[i].d=lower_bound(h+1,h+tot+1,a[i].d)-h;
		b[++tot2].d=a[i].d,b[tot2].pos=a[i].l,b[tot2].add=1;
		b[++tot2].d=a[i].d,b[tot2].pos=a[i].r+1,b[tot2].add=-1;
	}
	sort(b+1,b+tot2+1);
	root[1]=sum[1]=ct[1]=l[1]=r[1]=0;
	for(int i=1;i<=tot2;++i)	insert(root[i-1],root[i],1,tot,b[i].d,b[i].add);
	long long pre=1ll;
	int f=0;
	while(m--){
		int x;
		long long aa,bb,cc,k;
		scanf("%d%I64d%I64d%I64d",&x,&aa,&bb,&cc);
		k=(aa*pre+bb)%cc;
		Q tmp;tmp.pos=x,tmp.d=tmp.add=0;
		int now=upper_bound(b+1,b+tot2+1,tmp)-b-1;
		if(now<1)	{puts("0");pre=0;continue;}
		long long ans=findkth(root[now],1,tot,k);
		if(f)	ans*=2;
		if(ans>p)	f=1;
		else f=0;
		printf("%I64d\n",ans);
		pre=ans;
	}
}
int main(){
	while(scanf("%d%d%d%d",&n,&m,&x,&p)!=EOF)	solve();
	return 0;
}
