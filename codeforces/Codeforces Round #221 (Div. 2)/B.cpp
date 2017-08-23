#include<cstdio>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=105;
int w[N];
int main(){
	int n,m,a,b,c;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&a,&b,&c);
		w[b]+=c;
		w[a]-=c;
	}
	sort(w+1,w+n+1);
	int ans=0;
	for(int i=1;i<=n;++i)	if(w[i]>0)	ans+=w[i];
	printf("%d\n",ans);
	return 0;
}

