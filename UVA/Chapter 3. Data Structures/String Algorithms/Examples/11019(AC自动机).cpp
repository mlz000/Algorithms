#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int N=11111,M=26;
char s[1005][1005],word[105][105];
int T,n,m,x,y,ans,cnt[1005][1005];
struct AC{
	int sz,ch[N][M],w[N],pre[N],last[N],p[N];
	inline void init(){
		ans=0;
		sz=1;
		memset(ch[0],0,sizeof(ch[0]));
		memset(cnt,0,sizeof(cnt));
		memset(w,0,sizeof(w));
		memset(p,0,sizeof(p));
		memset(last,0,sizeof(last));
	}
	inline int idx(char c){	return c-'a';}
	void insert(char *s,int v){
		int u=0,n=strlen(s);
		for(int i=0;i<n;++i){
			int c=idx(s[i]);
			if(!ch[u][c]){
				memset(ch[sz],0,sizeof(ch[sz]));
				ch[u][c]=sz++;
			}
			u=ch[u][c];
		}
		pre[v]=w[u];
		w[u]=v;
	}
	void getfail(){
		queue<int> q;
		p[0]=0;
		for(int i=0;i<26;++i){
			int c=ch[0][i];
			if(c)	q.push(c),p[c]=0,last[c]=0;
		}
		while(q.size()){
			int u=q.front();
			q.pop();
			for(int i=0;i<26;++i){
				int v=ch[u][i];
				if(!v)	{ch[u][i]=ch[p[u]][i];continue;}
				q.push(v);
				p[v]=ch[p[u]][i];
				last[v]=w[p[v]]?p[v]:last[p[v]];
			}
		}
	}
	void work(int row,int pos,int v){
		if(v){
			int r=w[v];
			int c=pos-y+1;
			while(r){
				if(row>=r)	cnt[row-r][c]++;
				r=pre[r];
			}
			work(row,pos,last[v]);
		}		
	}
	void find(int row,char *s){
		int n=strlen(s);
		int u=0;
		for(int i=0;i<n;++i){
			int c=idx(s[i]);
			int u=ch[u][c];
			if(w[u])	work(row,i,u);				
			else if(last[u])	work(row,i,last[u]);
		}
	}
}ac;
int main(){
	scanf("%d",&T);
	while(T--){
		ac.init();
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i)	scanf("%s",s[i]);
		scanf("%d%d",&x,&y);
		for(int i=0;i<x;++i){
			scanf("%s",word[i]);
			ac.insert(word[i],i+1);
		}
		ac.getfail();
		for(int i=0;i<n;++i)	ac.find(i+1,s[i]);
		for(int i=0;i<n-x+1;++i)
			for(int j=0;j<m-y+1;++j)
				if(cnt[i][j]==x)	ans++;
		printf("%d\n",ans);
	}
	return 0;
}
