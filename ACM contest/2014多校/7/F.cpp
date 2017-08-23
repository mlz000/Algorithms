#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=205;
int x[N],y[N];
int main(){
	int T,n,m,u,v,d,b;
	scanf("%d",&T);
	for(int tt=1;tt<=T;++tt){
		printf("Case #%d: ",tt);
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;++i){
			scanf("%d%d%d%d",&u,&v,&d,&b);
			x[u]+=d;
			y[v]+=d+b;
		}
		bool f=false;
		for(int i=1;i<=n;++i){
			if(y[i]<x[i]){
				f=true;
				break;
			}
		}
		if(f)	puts("unhappy");
		else puts("happy");
	}
	return 0;
}
