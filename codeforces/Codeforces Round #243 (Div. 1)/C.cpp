#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;
const int N=100005,M=305;
int a[N],b[N],f[N][M];
vector<int>pos[N];
vector<int>::iterator it;
int main(){
	int n,m,s,e;
	scanf("%d%d%d%d",&n,&m,&s,&e);
	for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
	for(int i=1;i<=m;++i)	scanf("%d",&b[i]),pos[b[i]].push_back(i);
	memset(f,0x127,sizeof(f));
	for(int i=0;i<=n;++i)	f[i][0]=0;
	int ans=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=s/e;++j){
			f[i][j]=f[i-1][j];
			it=lower_bound(pos[a[i]].begin(),pos[a[i]].end(),f[i-1][j-1]+1);
			if(it!=pos[a[i]].end() && (*it)<f[i][j])	f[i][j]=*it;
			if(j>ans && f[i][j]+i+e*j<=s)	ans=j;
		}
	printf("%d\n",ans);
	return 0;
}
