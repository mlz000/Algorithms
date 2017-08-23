#include<bits/stdc++.h>//Scapegoat Tree
using namespace std;
const double a=0.85;
const int N=100005;
struct node{
	int s[2],f,sz,num;
}t[N<<4];
int tnum,root,e[N<<4],esz;
inline void init(){
	tnum=2,root=1;
	t[1].num=INT_MIN,t[1].sz=2,t[1].s[1]=2;
	t[2].num=INT_MAX,t[2].sz=1,t[2].f=1;
}
inline bool bal(int x){
	return (double)t[x].sz*a>=(double)t[t[x].s[0]].sz && (double)t[x].sz*a>=(double)t[t[x].s[1]].sz;
}
int build(int l,int r){
	if(l>r)	return 0;
	int mid=(l+r)>>1;
	int p=e[mid];
	t[t[p].s[0]=build(l,mid-1)].f=p;
	t[t[p].s[1]=build(mid+1,r)].f=p;
	t[p].sz=t[t[p].s[0]].sz+t[t[p].s[1]].sz+1;
	return p;
}
void travel(int x){
	if(t[x].s[0])	travel(t[x].s[0]);
	e[++esz]=x;
	if(t[x].s[1])	travel(t[x].s[1]);
}
void rebuild(int x){
	esz=0;
	travel(x);
	int fa=t[x].f;
	int d=(t[fa].s[1]==x);
	int p=build(1,esz);
	t[t[fa].s[d]=p].f=fa;
	if(x==root)	root=p;
}
void insert(int x){
	int now=root;
	t[++tnum].sz=1,t[tnum].num=x;
	while(1){
		++t[now].sz;
		int d=(x>=t[now].num);
		if(t[now].s[d])	now=t[now].s[d];
		else{
			t[now].s[d]=tnum;
			t[tnum].f=now;
			break;
		}
	}
	int inv=0;
	for(int i=tnum;i;i=t[i].f)	
		if(!bal(i))	inv=i;
	if(inv)	rebuild(inv);
}
inline void erase(int x){
	if(t[x].s[0] && t[x].s[1]){
		int p=t[x].s[0];
		while(t[p].s[1])	p=t[p].s[1];
		t[x].num=t[p].num;
		x=p;
	}
	int son=t[x].s[0]?t[x].s[0]:t[x].s[1];
	int d=(t[t[x].f].s[1]==x);
	t[t[x].f].s[d]=son;
	t[son].f=t[x].f;
	for(int i=t[x].f;i;i=t[i].f)	--t[i].sz;
	if(x==root)	root=son;
}
inline int get(int x){
	int now=root;
	while(1){
		if(t[now].num==x)	return now;
		else now=t[now].s[t[now].num<=x];
	}
}
inline int rank(int x){
	int now=root,ans=0;
	while(now){
		if(t[now].num<x)	ans+=t[t[now].s[0]].sz+1,now=t[now].s[1];
		else now=t[now].s[0];
	}
	return ans;
}
inline int getkth(int k){
	int now=root;
	while(1){
		if(t[t[now].s[0]].sz==k-1)	return now;
		else if(t[t[now].s[0]].sz>=k)	now=t[now].s[0];
		else k-=t[t[now].s[0]].sz+1,now=t[now].s[1];
	}
}
inline int pre(int x){
	int now=root,ans=INT_MIN;
	while(now){
		if(t[now].num<x)	ans=max(ans,t[now].num),now=t[now].s[1];
		else now=t[now].s[0];
	}
	return ans;
}
inline int suc(int x){
	int now=root,ans=INT_MAX;
	while(now){
		if(t[now].num>x)	ans=min(ans,t[now].num),now=t[now].s[0];
		else now=t[now].s[1];
	}
	return ans;
}
int main(){
	init();
	int n,x,y;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&x,&y);
		if(x==1)	insert(y);
		else if(x==2)	erase(get(y));
		else if(x==3)	printf("%d\n",rank(y));
		else if(x==4)	printf("%d\n",t[getkth(y+1)].num);
		else if(x==5)	printf("%d\n",pre(y));
		else printf("%d\n",suc(y));
	}
	return 0;
}
