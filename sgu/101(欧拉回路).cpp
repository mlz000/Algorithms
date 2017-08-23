#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,d[10];
struct data{
	int u,v,vis;
}e[N];
vector<int>a[10];
vector<pair<int,char> >ans;
void dfs(int u){
	for(int i=0,v;i<a[u].size();++i)
		if(!e[v=a[u][i]].vis){
			e[v].vis=1;
			if(e[v].u==u){
				dfs(e[v].v);
				ans.push_back(make_pair(v+1,'+'));
			}
			else{
				dfs(e[v].u);
				ans.push_back(make_pair(v+1,'-'));
			}
		}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		e[i].vis=0;
		scanf("%d%d",&e[i].u,&e[i].v);
		++d[e[i].u],++d[e[i].v];
		a[e[i].u].push_back(i);
		a[e[i].v].push_back(i);
	}
	int cnt=0;
	for(int i=0;i<7;++i)	cnt+=d[i]&1;
	if(cnt!=0 && cnt!=2)	puts("No solution");
	else{
		if(cnt){
			for(int i=0;i<7;++i)
				if(d[i]&1){
					dfs(i);
					break;
				}
		}
		else{
			for(int i=0;i<7;++i)
				if(d[i]){
					dfs(i);
					break;
				}
		}
	}
	if(ans.size()<n)	puts("No solution");
	else{
		for(int i=n-1;i>=0;--i)	printf("%d %c\n",ans[i].first,ans[i].second);
	}
	return 0;
}
