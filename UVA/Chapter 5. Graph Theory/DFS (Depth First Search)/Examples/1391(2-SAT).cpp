#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int N=100005;
vector<int>g[N<<1];
int n,m,a,b,age[N],sum,c,l,r,s[N<<1];
bool mark[N<<1];
void add(int x,int y){
	g[x].push_back(y);
}
void init(){
	c=sum=0;
	memset(mark,0,sizeof(mark));
	for(int i=0;i<n*2;++i)	g[i].clear();
	for(int i=0;i<n;++i)	scanf("%d",&age[i]),sum+=age[i];
	for(int i=0;i<m;++i){
		scanf("%d%d",&a,&b);
		a--,b--;
		if(a==b)	continue;
		if((age[a]*n>=sum && age[b]*n>=sum) || (age[a]*n<sum && age[b]*n<sum)){//同类
			add(2*a+1,2*b);
			add(2*b+1,2*a);
		}
		add(2*a,2*b+1),add(2*b,2*a+1);//不能同去C
	}
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
void work(){
	if(!solve())	{printf("No solution.\n");return;}
	for(int i=0;i<n;++i){
		if(mark[i*2])	printf("C\n");
		else printf("%c\n",(age[i]*n>=sum)?'A':'B');
	}
}
int main(){
	while(scanf("%d%d",&n,&m)&&n&&m){
		init();
		work();
	}
	return 0;
}
