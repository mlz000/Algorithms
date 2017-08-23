//treap
struct Node{
	Node *ch[2];
	int w,s;
	long long fix;
	bool operator< (const Node &b) const{
		return fix<b.fix;
	}	
	int cmp(int x) const{
		if(x==w)	return -1;
		return x<w?0:1;
	}
	void maintain(){
		s=1;
		if(ch[0]!=NULL)	s+=ch[0]->s;
		if(ch[1]!=NULL)	s+=ch[1]->s;
	}
}*a[N],b[N],*tot=b; 
struct Command{
	int type,x,p;
}c[500005];
queue<Node*>Q;
Node *newNode(int x){
	Node *t;
	if(Q.size()){
		t=Q.front();
		Q.pop();
	}
	else t=++tot;
	t->w=x,t->s=1,t->fix=rand()*rand(),t->ch[0]=t->ch[1]=NULL;
	return t;
}
int find(int x){
	if(f[x]==x)	return f[x];
	else return f[x]=find(f[x]);
}
void rotate(Node* &o,int d){
	Node *k=o->ch[d^1];
	o->ch[d^1]=k->ch[d];
	k->ch[d]=o;
	o->maintain();
	k->maintain();
	o=k;
}
void insert(Node* &o,int x){
	if(o==NULL)	o=newNode(x);
	else{
		int d=(x<o->w?0:1);
		insert(o->ch[d],x);
		if(o->ch[d]>o)	rotate(o,d^1);
	}
	o->maintain();
}
void del(Node* &x){
	if(x->ch[0]!=NULL)	del(x->ch[0]);
	if(x->ch[1]!=NULL)	del(x->ch[1]);
	Q.push(x);
	x=NULL;
}
void del2(Node* &o,int x){
	if(o==NULL)	return;
	int d=o->cmp(x);
	if(d==-1){
		Node* t=o;
		if(o->ch[0]!=NULL && o->ch[1]!=NULL){
			int d2=(o->ch[0]<o->ch[1]?0:1);
			rotate(o,d2);
			del2(o->ch[d2],x);
		}
		else{
			if(o->ch[0]==NULL)	o=o->ch[1];
			else o=o->ch[0];
			Q.push(t);
			t=NULL;
		}
	}
	else del2(o->ch[d],x);
	if(o!=NULL)	o->maintain();
}
int kth(Node* o,int k){
	if(o==NULL || k<=0 || k>o->s)	return 0;
	int tmp=(o->ch[1]==NULL?0:o->ch[1]->s);
	if(k==tmp+1)	return o->w;
	else if(k<=tmp)	kth(o->ch[1],k);
	else kth(o->ch[0],k-tmp-1);
}
//splay
struct Node* null;
struct Node{
	Node* ch[2];
	int s,w;
	unsigned h1,h2;//hash
	bool flip;
	Node() {}
	Node(int w):s(1),flip(0),h1(w),h2(w),w(w){ch[0]=ch[1]=null;}
	int cmp(int k){
		int d=k-ch[0]->s;
		if(d==1)	return -1;
		return d<=0?0:1;
	}
	void maintain(){
		s=ch[0]->s+ch[1]->s+1;
		h1=ch[0]->h1*p[ch[1]->s+1]+w*p[ch[1]->s]+ch[1]->h1;
		h2=ch[1]->h2*p[ch[0]->s+1]+w*p[ch[0]->s]+ch[0]->h2;
	}
	void reverse(){	
		swap(ch[0],ch[1]);
		swap(h1,h2);
		flip^=1;
	}
	void pushdown(){
		if(flip){
			flip=0;
			ch[0]->reverse();
			ch[1]->reverse();
		}
	}
}T[N],*root,*c=T;
queue<Node*>Q;
Node* Newnode(int x){
	Node* t;
	if(Q.size()){
		t=Q.front();
		Q.pop();
	}
	else t=++c;
	*t=Node(x);
	return t;
}
void rotate(Node* &o,int d){
	o->pushdown();
	Node* k=o->ch[d^1];
	k->pushdown();
	o->ch[d^1]=k->ch[d];k->ch[d]=o;
	o->maintain();k->maintain();o=k;
}
void splay(Node* &o,int k){
	o->pushdown();
	int d=o->cmp(k);
	if(d==1)	k-=o->ch[0]->s+1;
	if(d!=-1){
		Node* p=o->ch[d];
		p->pushdown();
		int d2=p->cmp(k);
		int k2=(d2== 0?k:k-p->ch[0]->s-1);
		if(d2!=-1){
			splay(p->ch[d2],k2);
			if(d==d2)	rotate(o,d^1);//一字型
			else rotate(o->ch[d],d);//之字形
		}
		rotate(o,d^1);
	}
}
void build(Node*& o,int l,int r){
	int m=(l+r)>>1;
	o=Newnode(s[m]);
	if(l<m)	build(o->ch[0],l,m-1);
	if(r>m)	build(o->ch[1],m+1,r);
	o->maintain();
}
void init(){
	null=new Node();
	null->s=0;
	root=Newnode('[');
	root->ch[1]=Newnode(']');
	build(root->ch[1]->ch[0],1,strlen(s+1));
	root->ch[1]->maintain(),root->maintain();
}
//左偏树 
//v值 l:左儿子 r:右儿子 d深度
int merge(int x,int y){
	if(!x)	return y;
	if(!y)	return x;
	if(v[x]<v[y])	swap(x,y);
	r[x]=merge(r[x],y);
	if(d[l[x]]<d[r[x]])	swap(l[x],r[x]);
	d[x]=d[r[x]]+1;
	return x;
}
//树链剖分
void gao() {
	int r = 0;
	vis[dep[1] = q[0] = 1] = 1;
	for (int i = 0; i <= r; ++i)
		for (int j = head[q[i]]; ~j; j = nxt[j]) 
			if (!vis[to[j]]){
				vis[to[j]] = 1;
				dep[q[++r] = to[j]] = dep[q[i]] + 1;
				pre[q[r]] = q[i];
			}
	for (int i = r; i >= 0; --i) {
		sz[pre[q[i]]] += ++sz[q[i]];
		if (sz[son[pre[q[i]]]] < sz[q[i]])	son[pre[q[i]]] = q[i];
	}
	for (int i = 0; i <= r; ++i)
		if (!top[q[i]]) {
			for (int j = q[i]; j; j = son[j]) {
				top[j] = q[i];
				w[id[j] = ++cnt] = col[j];
			}
		}
	build(1, 1, n);
}
//点分治
void getroot(int u, int fa) {
	f[u] = 0, sz[u] = 1;
	for (int i = head[u], v; ~i; i = nxt[i]) {
		v = to[i];
		if (v != fa && !vis[v]) {
			getroot(v, u);
			sz[u] += sz[v];
			f[u] = max(f[u], sz[v]);
		}
	}
	f[u] = max(f[u], size - sz[u]);
	if (f[u] < f[root])	root = u;
}
void dfs(int u, int fa, int d) {
	dis[cnt++] = d;
	for (int i = head[u], v; ~i; i = nxt[i]) {
		v = to[i];
		if (v != fa && !vis[v])	dfs(v, u, d + 1);
	}
}
long long calc(int u, int d) {
	int mx = 0;
	long long t = 0;
	cnt = 0;
	dfs(u, 0, d);
	//***
}
void gao(int u) {
	f[root = 0] = size;
	getroot(u, 0);
	ans += calc(root, 0);
	vis[root] = 1;
	for (int i = head[root], v; ~i; i = nxt[i]) {
		v = to[i];
		if (!vis[v]) {
			ans -= calc(v, 1);
			size = sz[v];
			gao(v);
		}
	}
}
