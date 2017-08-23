#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
const int N=400005;
unsigned p[N];
char s[N];
int n,m,op;
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
			if(d==d2)	rotate(o,d^1);//һ����
			else rotate(o->ch[d],d);//֮����
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
int main(){
	p[0]=1;
	for(int i=1;i<N-4;++i)	p[i]=p[i-1]*131;
	while(scanf("%d%d%s",&n,&m,s+1)!=EOF){
		init();
		int pos,x,y;
		while(m--){
			scanf("%d",&op);
			if(op==1){
				scanf("%d%d",&pos,&x);
				splay(root,pos+1);
				splay(root->ch[1],1);
				root->ch[1]->ch[0]=Newnode(x+'0');
				root->ch[1]->maintain(),root->maintain();
			}
			else if(op==2){
				scanf("%d",&pos);
				splay(root,pos);
				splay(root->ch[1],2);
				root->ch[1]->ch[0]=null;
				root->ch[1]->maintain(),root->maintain();
			}
			else if(op==3){
				scanf("%d%d",&x,&y);
				splay(root,x);
				splay(root->ch[1],y-x+2);
				root->ch[1]->ch[0]->reverse();
				root->ch[1]->maintain(),root->maintain();
			}
			else{
				scanf("%d%d",&x,&y);
				int L=0,R=root->s-y;
				while(L<R-1){
					int M=L+(R-L)/2;
					splay(root,x);
					splay(root->ch[1],M+1);
					unsigned h1=root->ch[1]->ch[0]->h1;
					unsigned h2=root->ch[1]->ch[0]->h2;
					splay(root,y);
					splay(root->ch[1],M+1);
					unsigned hh1=root->ch[1]->ch[0]->h1;
					unsigned hh2=root->ch[1]->ch[0]->h2;
					if(h1==hh1 && h2==hh2)	L=M;
					else R=M;
				}
				printf("%d\n",L);
			}
		}
	}
	return 0;
}
