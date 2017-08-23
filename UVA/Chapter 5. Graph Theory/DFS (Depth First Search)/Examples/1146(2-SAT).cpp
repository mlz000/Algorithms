#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int N=2005;
vector<int>g[N<<1];
int n,t[N][2],c,l,r,s[N<<1];
bool mark[N<<1];
void init(){
	l=r=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<=1;++j)
			scanf("%d",&t[i][j]),r=max(r,t[i][j]);
}
void add(int x,int xv,int y,int yv){
	x=2*x+xv,y=2*y+yv;
	g[x^1].push_back(y);
	g[y^1].push_back(x);
}
bool dfs(int x){
	if(mark[x^1])	return false;
	if(mark[x])	return true;
	mark[x]=true;
	s[c++]=x;
	for(int i=0;i<g[x].size();++i)
		if(!dfs(g[x][i]))	return false;
	return true;
}
bool solve(){
	for(int i=0;i<n*2;i+=2){
		if(!mark[i] && !mark[i+1]){
			c=0;
			if(!dfs(i)){
				while(c>0)	mark[s[--c]]=false;
				if(!dfs(i+1))	return false;
			}
		}
	}
	return true;
}
bool check(int time){
	memset(mark,0,sizeof(mark));
	for(int i=0;i<n*2;++i)	g[i].clear();
	for(int i=0;i<n;++i)
		for(int a=0;a<=1;++a)
			for(int j=i+1;j<n;++j)
				for(int b=0;b<=1;++b)
					if(abs(t[i][a]-t[j][b])<time)	add(i,a^1,j,b^1);
	return solve();
}
void work(){
	while(l<r){
		int mid=l+(r-l+1)/2;
		if(check(mid))	l=mid;
		else r=mid-1;
	}
	printf("%d\n",r);
}
int main(){
	while(scanf("%d",&n)!=EOF){
		init();
		work();
	}
	return 0;
}
