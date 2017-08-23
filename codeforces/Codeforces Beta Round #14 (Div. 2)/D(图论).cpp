#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int N=205;
bool map[N][N];
int n,dep;
int dfs(int u,int pre){
	int tmp=0,max1=0,max2=0;
	for(int i=1;i<=n;++i){
		if(map[u][i] && i!=pre){
			tmp=max(tmp,dfs(i,u));
			if(dep>max1){
				max2=max1;
				max1=dep;
			}
			else max2=max(max2,dep);
		}
	}
	tmp=max(tmp,max1+max2);
	dep=max1+1;
	return tmp;
}			
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i){
		scanf("%d%d",&u,&v);
		map[u][v]=map[v][u]=true;
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(map[i][j]){
				int x=dfs(i,j);
				int y=dfs(j,i);
				ans=max(ans,x*y);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
