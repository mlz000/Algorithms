#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
const int N=505,M=64;
double pi[M];
int n,l,k,T,idx[256];
char s[25][25],t[N];
struct AC{
	int ch[N][M],p[N],sz;
	double d[N][105];
	bool match[N];
	inline void clear()	{sz=1;memset(match,0,sizeof(match));memset(d,0,sizeof(d));memset(ch[0],0,sizeof(ch[0]));}
	void insert(char *s){
		int u=0,n=strlen(s);
		for(int i=0;i<n;++i){
			int c=idx[s[i]];
			if(!ch[u][c]){
				memset(ch[sz],0,sizeof(ch[sz]));
				match[sz]=false;
				ch[u][c]=sz++;
			}
			u=ch[u][c];
		}
		match[u]=true;
	}
	void getfail(){
		queue<int>q;
		p[0]=0;
		for(int c=0;c<M;++c){
			int u=ch[0][c];
			if(u)	{p[u]=0;q.push(u);}
		}
		while(q.size()){
			int tmp=q.front();
			q.pop();
			for(int c=0;c<M;++c){
				int u=ch[tmp][c];
				if(!u)	{ch[tmp][c]=ch[p[tmp]][c];continue;}
				q.push(u);
				int v=p[tmp];
				while(v && !ch[v][c])	v=p[v];
				p[u]=ch[v][c];
				match[u]|=match[p[u]];
			}
		}
	}
	double dp(int u,int l){
		if(!l)	return 1.0;
		if(d[u][l])	return d[u][l];
		double tmp=0.0;
		for(int i=0;i<n;++i)
			if(!match[ch[u][i]])	tmp+=pi[i]*dp(ch[u][i],l-1);
		return d[u][l]=tmp;
	}
}ac;			
int main(){
	scanf("%d",&T);
	for(int tt=1;tt<=T;++tt){
		printf("Case #%d: ",tt);
		ac.clear();
		scanf("%d",&k);
		for(int i=0;i<k;++i)	scanf("%s",s[i]);
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%s%lf",t,&pi[i]);
			idx[t[0]]=i;
		}
		for(int i=0;i<k;++i)	ac.insert(s[i]);
		ac.getfail();
		scanf("%d",&l);
		printf("%lf\n",ac.dp(0,l));
	}
	return 0;
}
