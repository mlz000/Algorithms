#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=25;
int w,d,a[N],b[N],vis[N];
int main(){
	while(scanf("%d%d",&w,&d)&&w&&d){
		int ans=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=w;++i)	scanf("%d",&a[i]),++vis[a[i]],ans+=a[i];
		for(int i=1;i<=d;++i){
			scanf("%d",&b[i]);
			if(vis[b[i]])	--vis[b[i]];
			else ans+=b[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}

