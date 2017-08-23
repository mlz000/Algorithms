#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=4005*105,M=26,MOD=20071027;
int ca,n,d[300005],l[4005];
char s[300005],word[105];
struct Trie{
	int ch[N][M];
	int w[N];
	int sz;
	void clear()	{sz=1,memset(ch[0],0,sizeof(ch[0]));}
	int idx(char c)	{return c-'a';}
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
	}
	void find(const char *s,int len,vector<int>&ans){
		int u=0;
		for(int i=0;i<len;++i){
			if(s[i]=='\0')	break;
			int c=idx(s[i]);
			if(!ch[u][c])	break;
			u=ch[u][c];
			if(w[u])	ans.push_back(w[u]);
		}
	}
}trie;
int main(){
	while(scanf("%s%d",s,&n)==2){
		trie.clear();
		ca++;
		for(int i=1;i<=n;++i){
			scanf("%s",word);
			l[i]=strlen(word);
			trie.insert(word,i);
		}
		memset(d,0,sizeof(d));
		int L=strlen(s);
		d[L]=1;
		for(int i=L-1;i>=0;--i){
			vector<int>p;
			trie.find(&s[i],L-i,p);
			for(int j=0;j<p.size();++j)
				d[i]=(d[i]+d[i+l[p[j]]])%MOD;
		}
		printf("Case %d: %d\n",ca,d[0]);
	}
	return 0;
}
