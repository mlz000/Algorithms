#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
const int N=20005;
int T,n,f[N],d[N];
char s[10];
int find(int x){
	if(f[x]!=x){
		int fa=find(f[x]);
		d[x]+=d[f[x]];
		return f[x]=fa;
	}
	else return f[x];
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)	f[i]=i,d[i]=0;
		while(scanf("%s",s)&&s[0]!='O'){
			int u,v;
			if(s[0]=='I'){
				scanf("%d%d",&u,&v);
				f[u]=v,d[u]=abs(u-v)%1000;
			}
			else{
				scanf("%d",&u);
				find(u);
				printf("%d\n",d[u]);
			}
		}
	}
	return 0;
}
				
