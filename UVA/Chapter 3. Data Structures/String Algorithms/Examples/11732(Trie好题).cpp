#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=4005*1005;
int n,ca;
char s[N];
struct Trie{
	char ch[N];
	int sz,tot[N],head[N],next[N];
	long long ans;
	inline void clear()	{sz=1;ans=tot[0]=head[0]=next[0]=0;}
	void insert(char *s){//插入'\0'
		int u=0,n=strlen(s),v;
		tot[0]++;
		for(int i=0;i<=n;++i){
			bool found=false;
			for(v=head[u];v;v=next[v])
				if(ch[v]==s[i]){
					found=true;
					break;
				}
			if(!found){
				v=sz++;
				tot[v]=0;
				ch[v]=s[i];
				next[v]=head[u];
				head[u]=v;
				head[v]=0;
			}
			u=v;
			tot[u]++;
		}
	}
	void dfs(int dep,int u){
    	if(head[u] == 0) // 叶结点即同一单词
      		ans += tot[u] * (tot[u] - 1) * dep;
		else{		
			int sum=0;
			for(int v=head[u];v;v=next[v])	sum+=tot[v]*(tot[u]-tot[v]);// 子树v中选一个串，其他子树中再选一个
			ans+=sum*(2*dep+1)/2;// 除以2是每种选法统计了两次
			for(int v=head[u];v;v=next[v])	dfs(dep+1,v);
		}
	}
	long long count(){
		dfs(0,0);
		return ans;
	}
}trie;
int main(){
	while(scanf("%d",&n)&&n){
		trie.clear();
		ca++;
		for(int i=1;i<=n;++i){
			scanf("%s",s);
			trie.insert(s);
		}
		printf("Case %d: %lld\n",ca,trie.count());
	}
	return 0;
}
