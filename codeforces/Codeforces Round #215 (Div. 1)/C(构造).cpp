#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n,m,q,w[N];
bool cmp(const int &p,const int &q)	{return p>q;}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)	scanf("%d%d",&q,&w[i]);
	sort(&w[1],&w[m+1],cmp);
	int k=0,ans=0;
	while(k/2*k+k%2<=n)	++k;
	--k;
	k=min(k,m);
	for(int i=1;i<=k;++i)	ans+=w[i];
	printf("%d",ans);
	return 0;
}
