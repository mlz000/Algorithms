#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
const int N=20005,M=100005;
int T,n,a[N],c[M],l[N];
int sum(int x){
	int tmp=0;
	for(;x;x-=x&-x)	tmp+=c[x];
	return tmp;
}
void add(int x){
	for(;x<=M-5;x+=x&-x)	c[x]++;
}
int main(){
	scanf("%d",&T);
	while(T--){
		memset(c,0,sizeof(c));
		scanf("%d",&n);
		long long ans=0ll;
		for(int i=1;i<=n;++i)	scanf("%d",&a[i]),add(a[i]),l[i]=sum(a[i]-1);
		memset(c,0,sizeof(c));
		for(int i=n;i>=1;--i){
			add(a[i]);	
			int r=sum(a[i]-1);
			ans+=l[i]*(n-i-r)+r*(i-1-l[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
