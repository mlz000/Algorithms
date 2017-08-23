#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=17;
int ca,n,a[N],sum[1<<N];
bool f[1<<N][105],v[1<<N][105];
bool dp(int s,int x){
	if(v[s][x])	return f[s][x];
	v[s][x]=true;
	if(__builtin_popcount(s)==1)	return f[s][x]=true;
	int y=sum[s]/x;
	for(int s0=(s-1)&s;s0;s0=(s0-1)&s){
		int s1=s^s0;
		if(sum[s0]%x==0 && dp(s0,min(x,sum[s0]/x)) && dp(s1,min(x,sum[s1]/x)))	return f[s][x]=true;
		if(sum[s0]%y==0 && dp(s0,min(y,sum[s0]/y)) && dp(s1,min(y,sum[s1]/y)))	return f[s][x]=true;
	}
	return f[s][x]=false;
}
int main(){
	while(scanf("%d",&n)&&n){
		ca++;
		memset(v,0,sizeof(v));
		memset(f,0,sizeof(f));
		int x,y;
		scanf("%d%d",&x,&y);
		for(int i=0;i<n;++i)	scanf("%d",&a[i]);
		memset(sum,0,sizeof(sum));
		for(int i=0;i<(1<<n);++i)
			for(int j=0;j<n;++j)
				if(i&(1<<j))	sum[i]+=a[j];
		int all=(1<<n)-1;
		int ans;
		if(sum[all]!=x*y || sum[all]%x!=0)	ans=0;
		else ans=dp(all,min(x,y));
		printf("Case %d: %s\n",ca,ans?"Yes":"No");
	}
	return 0;
}

