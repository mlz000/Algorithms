#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
const int maxn=100005,pp=1000003,inf=1000000000;
struct edge {
	int da,next;
} g[2*maxn];
struct node {
	int da,loc,l,r;
} tree[2*maxn];
int sta[maxn],b[maxn],size[maxn];
long long val[2*maxn],num[2*maxn],yi[2000001];
bool v[maxn],del[maxn];
int root2,size2,ans1,ans2,i,j,k,m,n,tot,m2,t1,t2;

long long power(int x,int n) {
	if (!n) return 1;
	long long tmp=power(x,n>>1);
	tmp=tmp*tmp%pp;
	if (n & 1) tmp=tmp*x%pp;
	return tmp;
}

void insert(int a,int b) {
	tot++;
	g[tot].da=b;
	g[tot].next=sta[a];
	sta[a]=tot;
}

void insert(int &i,int x,int y) {
	if (!i) {
		size2++;i=size2;
		tree[i].da=x;tree[i].loc=y;
		tree[i].l=tree[i].r=0;
	}
	if (x==tree[i].da) {
		tree[i].loc=min(tree[i].loc,y);
		return;
	}
	if (x<tree[i].da) insert(tree[i].l,x,y);else insert(tree[i].r,x,y);
}

void find(int i,int x,int y) {
	if (!i) return;
	if (x==tree[i].da) {
		if (tree[i].loc<y) {t1=tree[i].loc;t2=y;}else {t1=y;t2=tree[i].loc;}
		if (t1<ans1) {ans1=t1;ans2=t2;}
		if ((t1==ans1) && (t2<ans2)) ans2=t2;
		return;
	}
	if (x<tree[i].da) find(tree[i].l,x,y);else find(tree[i].r,x,y);
}

void calc(int s) {
	int x,root,f,r,i,j,k,p,q,m2,tmp;
	f=r=1;b[f]=s;v[s]=true;
	while (f<=r) {
		i=b[f];
		for (p=sta[i];p;p=g[p].next)
			if ((!v[g[p].da]) && (!del[g[p].da])) {
				b[++r]=g[p].da;
				v[g[p].da]=true;
			}
		f++;
	}
	m2=inf;root=0;
	for (i=r;i>=1;i--) {
		x=b[i];
		size[x]=1;tmp=0;
		for (p=sta[x];p;p=g[p].next)
			if ((!v[g[p].da]) && (!del[g[p].da])) {
				size[x]+=size[g[p].da];
				tmp=max(tmp,size[g[p].da]);
			}
		tmp=max(tmp,r-size[x]);
		if (tmp<m2) {m2=tmp;root=x;}
		v[x]=false;
	}
	//cout<<root<<endl;
	del[root]=true;
	root2=size2=0;
	for (p=sta[root];p;p=g[p].next)
		if (!(v[g[p].da]) && (!del[g[p].da])) {
			//if (root==2) cout<<g[p].da<<endl;
			f=r=1;b[f]=g[p].da;v[g[p].da]=true;
			num[g[p].da]=val[g[p].da]%pp;
			while (f<=r) {
				i=b[f];
				if ((val[root]*num[i]%pp)==m) {
					if (i<root) {t1=i;t2=root;}else {t1=root;t2=i;}
					if (t1<ans1) {ans1=t1;ans2=t2;}
					if ((t1==ans1) && (t2<ans2)) ans2=t2;
				}
				find(root2,yi[num[i]*val[root]%pp]*m%pp,i);
				//if (root==2) cout<<i<<' '<<yi[num[i]*val[root]%pp]*m%pp<<endl;
				for (q=sta[i];q;q=g[q].next)
					if ((!v[g[q].da]) && (!del[g[q].da])) {
						v[g[q].da]=true;
						b[++r]=g[q].da;
						num[g[q].da]=num[i]*val[g[q].da]%pp;
					}
				f++;
			}
			for (i=1;i<=r;i++) {
				v[b[i]]=false;
				insert(root2,num[b[i]],b[i]);
				//if (root==2) cout<<g[p].da<<' '<<b[i]<<' '<<num[b[i]]<<endl;
			}
		}
	for (p=sta[root];p;p=g[p].next)
		if (!del[g[p].da]) calc(g[p].da);
}

int main() {
	for (i=1;i<pp;i++) yi[i]=power(i,pp-2);
	while (scanf("%d%d",&n,&m)!=EOF) {
		for (i=1;i<=n;i++) scanf("%I64d",&val[i]);
		memset(sta,0,sizeof(sta));
		tot=0;
		for (i=1;i<=n-1;i++) {
			scanf("%d%d",&j,&k);
			insert(j,k);insert(k,j);
		}
		ans1=ans2=inf;
		if (!m) {printf("No solution\n");continue;}
		memset(del,0,sizeof(del));
		calc(1);
		if (ans1==inf) printf("No solution\n");else printf("%d %d\n",ans1,ans2);
	}
	return 0;
}

