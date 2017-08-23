#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
const int N=11005,M=26;
int n;
char p[155][75],text[1000005];
map<string,int>mp;
struct AC{
	int ch[N][M],w[N],last[N],p[N],cnt[155],sz;
	inline int idx(char c)	{return c-'a';}
	inline void clear(){sz=1;memset(ch[0],0,sizeof(ch[0]));memset(cnt,0,sizeof(cnt));mp.clear();}
	void insert(char *s,int v){
		int u=0,n=strlen(s);
		for(int i=0;i<n;++i){
			int c=idx(s[i]);
			if(!ch[u][c]){
				memset(ch[sz],0,sizeof(ch[sz]));
				w[sz]=0;
				ch[u][c]=sz++;
			}
			u=ch[u][c];
		}
		w[u]=v;
		mp[string(s)]=v;
	}
	void getfail(){
		p[0]=0;
		queue<int>q;
		for(int c=0;c<M;++c){
			int u=ch[0][c];
			if(u)	{p[u]=0;q.push(u);last[u]=0;}
		}
		while(q.size()){
			int tmp=q.front();
			q.pop();
			for(int c=0;c<M;++c){
				int u=ch[tmp][c];
				if(!u)	continue;
				q.push(u);
				int v=p[tmp];
				while(v && !ch[v][c] )	v=p[v];
				p[u]=ch[v][c];
				last[u]=w[p[u]] ? p[u] : last[p[u]];
			}
		}
	}
	void print(int x){
		if(x){
			cnt[w[x]]++;
			print(last[x]);
		}
	}
	void find(char *s){
		int n=strlen(s);
		int u=0;
		for(int i=0;i<n;++i){
			int c=idx(s[i]);
			while(u && !ch[u][c])	u=p[u];
			u=ch[u][c];
			if(w[u])	print(u);
			else if(last[u])	print(last[u]);
		}
	}
}ac;
int main(){
	while(scanf("%d",&n)&&n){
		ac.clear();
		for(int i=1;i<=n;++i){
			scanf("%s",p[i]);
			ac.insert(p[i],i);
		}
		ac.getfail();
		scanf("%s",text);
		ac.find(text);
		int ans=0;
		for(int i=1;i<=n;++i)
			if(ac.cnt[i]>ans)	ans=ac.cnt[i];
		printf("%d\n",ans);
		for(int i=1;i<=n;++i)
			if(ac.cnt[mp[string(p[i])]]==ans)	printf("%s\n",p[i]);
	}
	return 0;
}
