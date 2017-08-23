#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <queue>
using namespace std;
const int N=200005,M=60005;
int n,m,ctot,weight[N],u[M],v[M],f[N];
bool rem[M];
double ans1,ans2;
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
void Merge(Node* &src,Node* &last){
	if(src->ch[0]!=NULL)	Merge(src->ch[0],last);
	if(src->ch[1]!=NULL)	Merge(src->ch[1],last);
	insert(last,src->w);
	Q.push(src);
	src=NULL;
}
void addedge(int x){
	int fu=find(u[x]);
	int fv=find(v[x]);
	if(fu!=fv){
		if(a[fu]->s < a[fv]->s){
			f[fu]=fv;
			Merge(a[fu],a[fv]);
		}
		else{
			f[fv]=fu;
			Merge(a[fv],a[fu]);
		}
	}
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
void query(int x,int k){
	ans2++;
	ans1+=kth(a[find(x)],k);
}
void change(int x,int v){
	int t=find(x);
	del2(a[t],weight[x]);
	insert(a[t],v);
	weight[x]=v;
}
int main(){
	int tt=0;
	while(scanf("%d%d",&n,&m)==2 && n){
		++tt;
		srand(time(0));
		memset(rem,false,sizeof(rem));
		ctot=0;
		for(int i=1;i<=n;++i)	scanf("%d",&weight[i]);
		for(int i=1;i<=m;++i)	scanf("%d%d",&u[i],&v[i]);
		char s[5];
		int t,x,p,v;
		while(1){
			scanf("%s",s);
			if(s[0]=='E')	break;
			scanf("%d",&x);
			if(s[0]=='D')	rem[x]=true,t=0;
			if(s[0]=='Q')	scanf("%d",&p),t=1;
			if(s[0]=='C'){
				scanf("%d",&v);
				p=weight[x];
				weight[x]=v;
				t=2;
			}
			c[++ctot]=(Command){t,x,p};
		}
		for(int i=1;i<=n;++i){
			f[i]=i;	
			if(a[i]!=NULL)	del(a[i]);
			a[i]=newNode(weight[i]);//final map
		}
		for(int i=1;i<=m;++i)
			if(!rem[i])	
				addedge(i);
		ans1=0.0,ans2=0.0;
		for(int i=ctot;i>=1;--i){
			if(c[i].type==0)	addedge(c[i].x);
			else if(c[i].type==1)	query(c[i].x,c[i].p);
			else change(c[i].x,c[i].p);
		}
		printf("Case %d: %.6lf\n",tt,ans1/ans2);
	}
	return 0;
}

