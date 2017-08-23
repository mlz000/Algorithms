#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int N=1e5+5;
int v,c,l,r,end,p[N],f[N],ans[N];
map<int,int>g[N];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d%d%d",&v,&c,&l,&r);
		if(!l || g[l].count(r+c)){
			f[i]=f[g[l][r+c]]+v,p[i]=g[l][r+c];
			if(r==0 && f[i]>f[end])	end=i;
			if(f[i]>f[g[l+c][r]])	g[l+c][r]=i;
		}
	} 
	int tot=0;	
	for(;end;end=p[end])	ans[++tot]=end;
	printf("%d\n",tot);
	for(int i=tot;i>=1;--i)	printf("%d ",ans[i]);
	return 0;
}

