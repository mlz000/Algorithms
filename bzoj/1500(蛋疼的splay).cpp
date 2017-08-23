#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
#define maxn 500010
#define keytree (ch[ch[root][1]][0])
int num[maxn];
char s[20];
struct splay_tree
{
	int sz[maxn], ch[maxn][2], pre[maxn], root;
    int top1, top2, sta[maxn], que[maxn];
    int sum[maxn], maxm[maxn], maxl[maxn], maxr[maxn], val[maxn];
    bool ro[maxn], same[maxn];
    inline void rotate(int x,int c)// c = 1 右旋，c = 0 左旋
    {
		int y=pre[x];
		pushdown(y);
		pushdown(x);
		ch[y][!c]=ch[x][c];
		if(ch[x][c])	pre[ch[x][c]]=y;
		pre[x]=pre[y];
		if(pre[y])	ch[pre[y]][ch[pre[y]][1]==y]=x;
		ch[x][c]=y;
		pre[y]=x;
		updata(y);
		if(y==root)	root=x;
	}
    inline void splay(int x,int f) // 把x节点转到f节点的下面
    {
		pushdown(x);
		while(pre[x]!=f)
		{
			if(pre[pre[x]]==f)	rotate(x,ch[pre[x]][0]==x); // 单旋转
			else 
			{
				int y=pre[x];int z=pre[y];
				int c=(ch[z][0]==y);
				if(ch[y][c]==x)	{rotate(x,!c);rotate(x,c);}// 之字型旋转
				else {rotate(y,c);rotate(x,c);}// 一字型旋转
			}
		}
		updata(x);
		if(f==0)	root=x;
	}
    inline void samenode(int x,int c)
    {
		if(x==0)	return;
		val[x]=c;
		sum[x]=sz[x]*val[x];
		maxm[x]=maxl[x]=maxr[x]=max(sum[x],val[x]);
		same[x]=1;
	}
    inline void reversenode(int x)
    {
		if(x==0)	return;
		ch[x][0]^=ch[x][1]^=ch[x][0]^=ch[x][1];
		maxl[x]^=maxr[x]^=maxl[x]^=maxr[x];
		ro[x]^=1;
	}
    inline void pushdown(int x)  // 将节点标记向下传递
    {
		if(x==0)	return;
		if(ro[x])
		{
			reversenode(ch[x][0]);
			reversenode(ch[x][1]);
			ro[x]^=1;
		}
		if(same[x])
		{
			samenode(ch[x][0],val[x]);
			samenode(ch[x][1],val[x]);
			same[x]=0;
		}
	}
    inline void select(int k,int f)// 将第k个元素转到f节点的下面
    {
		int x=root;k++;
		while(1)
		{
			pushdown(x);
			if(k==sz[ch[x][0]]+1)	break;
			if(k<=sz[ch[x][0]])	x=ch[x][0];
			else k-=sz[ch[x][0]]+1,x=ch[x][1];
		}
		splay(x,f);
	}
    void insert()
    {
		int pos,tot;
		scanf("%d%d",&pos,&tot);
		for(int i=1;i<=tot;++i)	scanf("%d",&num[i]);
		select(pos,0);
		select(pos+1,root);
		build_tree(keytree,1,tot,ch[root][1]);
        updata(ch[root][1]);
        updata(root);
	}
	inline void newnode(int &x,int c)
	{
		if(top2)	x=sta[top2--];
		else x=++top1;
		ch[x][0]=ch[x][1]=pre[x]=0;
		sz[x]=1;
		ro[x]=same[x]=0;
		val[x] = sum[x] = maxm[x] = maxl[x] = maxr[x] = c;
	}
	inline void updata(int x)   // 维护当前节点
	{
		if(x==0)	return;
		sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
		sum[x]=val[x]+sum[ch[x][0]]+sum[ch[x][1]];
		maxl[x]=max(maxl[ch[x][0]],sum[ch[x][0]]+val[x]+max(0,maxl[ch[x][1]]));//子树左边界开始的和最大的序列
		maxr[x]=max(maxr[ch[x][1]],sum[ch[x][1]]+val[x]+max(0,maxr[ch[x][0]]));//子树右边界开始的和最大的序列
		maxm[x]=max(max(maxr[ch[x][0]],0)+val[x]+max(maxl[ch[x][1]],0),max(maxm[ch[x][0]],maxm[ch[x][1]]));
	}
	inline void build_tree(int &x,int l,int r,int f)// 建树
	{
		if(l>r)	return ;
		int mid=(l+r)>>1;
		newnode(x,num[mid]);
		build_tree(ch[x][0],l,mid-1,x);
		build_tree(ch[x][1],mid+1,r,x);
		pre[x]=f;//father
		updata(x);
	}
	inline void init(int n)    // 初始化，注意0节点的处理，左右各插入一个空节点
	{
		ch[0][0]=ch[0][1]=pre[0]=sz[0]=0;
		ro[0]=same[0]=0;
		maxr[0] = maxl[0] = maxm[0] = -1000;
		sum[0]=0;
		root=top1=top2=0;
		newnode(root,-1);
		newnode(ch[root][1],-1);
		pre[top1]=root;
		sz[root]=2;
		for(int i=1;i<=n;++i)	scanf("%d",&num[i]);
		build_tree(keytree,1,n,ch[root][1]);
		updata(ch[root][1]);
		updata(root);
	}
	inline void erase(int x)// 删除以x节点为祖先的子树，回收内存
	{
		int h=1;int r=1;
		que[h]=x;
		while(h<=r)
		{
			sta[++top2]=que[h];
			if(ch[que[h]][0])	que[++r]=ch[que[h]][0];
			if(ch[que[h]][1])	que[++r]=ch[que[h]][1];
			++h;
		}
	}
	inline void del()
	{
		int a,b;
		scanf("%d%d",&a,&b);
		select(a-1,0);
		select(a+b,root);
		erase(keytree);
		keytree=0;
		updata(ch[root][1]);
		updata(root);
	}
	void makesame()
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		select(a-1,0);
		select(a+b,root);
		samenode(keytree,c);
	}
	void reverse()
	{
		int a,b;
		scanf("%d%d",&a,&b);
		select(a-1,0);
		select(a+b,root);
		reversenode(keytree);
	}
	void get()
	{
		int a,b;
		scanf("%d%d",&a,&b);
		select(a-1,0);
		select(a+b,root);
		printf("%d\n",sum[keytree]);
	}
	void maxsum()
	{
		select(0,0);
		select(sz[root]-1,root);
		printf("%d\n",maxm[keytree]);
	}
}spt;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	spt.init(n);
	while(m--)
	{
		scanf("%s",s);
		if(s[0]=='I')	spt.insert();
		else if(s[0]=='D')	spt.del();
		else if(s[0]=='M' && s[2]=='K')	spt.makesame();	
		else if(s[0]=='R')	spt.reverse();
		else if(s[0]=='G')	spt.get();
		else if (s[0] == 'M' && s[2] == 'X')spt.maxsum();
	}
	return 0;
}
