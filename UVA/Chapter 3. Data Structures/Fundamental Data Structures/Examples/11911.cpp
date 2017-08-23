#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int N=1000005;
int n,m;
vector<int> a[N];
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1;i<=n;++i)	a[i].clear();
		for(int i=1,x;i<=n;++i){
			scanf("%d",&x);
			a[x].push_back(i);
		}
		for(int i=1,k,v;i<=m;++i){
			scanf("%d%d",&k,&v);
			if(a[v].size()<k)	printf("0\n");
			else printf("%d\n",a[v][k-1]);
		}
	}
	return 0;
}
