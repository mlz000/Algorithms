#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int N=100005;
int a,b,f[N];
int find(int x){
	if(f[x]==x)	return f[x];
	return f[x]=find(f[x]);
}
int main(){
	while(scanf("%d",&a)==1){
		for(int i=0;i<N;++i)	f[i]=i;
		int ans=0;
		while(a!=-1){
			scanf("%d",&b);
			int fa=find(a),fb=find(b);
			if(fa==fb)	ans++;
			else f[fb]=fa;
			scanf("%d",&a);
		}
		printf("%d\n",ans);
	}
	return 0;
}
