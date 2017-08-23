#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
const int N=100005;
int a[N],n,m,x,y;
struct Node{
	Node* ch[2];
	int s,w;
	bool flip;
	Node(int w=0):w(w){s=1;flip=0;ch[0]=ch[1]=NULL;}
	int cmp(int k){
		int l=(ch[0]==NULL)?0:ch[0]->s;
		if(k==l+1)	return -1;
		return k>l;
	}
	void maintain(){
		s=1;
		for(int i=0;i<2;++i){
			if(ch[i]!=NULL)	s+=ch[i]->s;
		}
	}
	void pushdown(){
		if(flip){
			flip=0;
			for(int i=0;i<2;++i){
				if(ch[i]!=NULL){
					swap(ch[i]->ch[0],ch[i]->ch[1]);
					ch[i]->flip=!ch[i]->flip;
				}
			}
		}
	}
	void print(){
		pushdown();
		if(ch[0]!=NULL)	ch[0]->print();
		if(w)	printf("%d\n",w);
		if(ch[1]!=NULL)	ch[1]->print();
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
	if(d==1)	k-=(o->ch[0]==NULL)?1:o->ch[0]->s+1;
	if(d!=-1){
		Node* p=o->ch[d];
		p->pushdown();
		int d2=p->cmp(k),l=(p->ch[0]==NULL)?0:p->ch[0]->s;
		int k2=(d2==0)?k:k-l-1;
		if(d2!=-1){
			splay(p->ch[d2],k2);
			if(d==d2)	rotate(o,d^1);//一字型
			else rotate(o->ch[d],d);//之字形
		}
		rotate(o,d^1);
	}
}
void build(Node* &o,int l,int r){
	int m=(l+r)>>1;
	o=Newnode(a[m]);
	if(l<m)	build(o->ch[0],l,m-1);
	if(r>m)	build(o->ch[1],m+1,r);
	o->maintain();
}
void init(){
	a[1]=0,a[n+2]=0;
	for(int i=2;i<=n+1;++i)	a[i]=i-1;
	build(root,1,n+2);
}
int main(){
	scanf("%d%d",&n,&m);
	init();
	while(m--){
		scanf("%d%d",&x,&y);
		splay(root,y+2);
		splay(root->ch[0],x);
		Node* k=root->ch[0]->ch[1];
		root->ch[0]->ch[1]=NULL;
		root->ch[0]->maintain();
		root->maintain();
		swap(k->ch[0],k->ch[1]);
		k->flip=!k->flip;
		splay(root,root->s-1);
		root->ch[1]->ch[0]=k;
		root->ch[1]->maintain();
		root->maintain();
	}
	root->print();
	return 0;
}


