#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=35;
int n,g[N];
long long f[N];
inline long long C(long long n,long long m){
	double ans = 1.0;
 	for(int i = 0; i < m; ++i)
  	ans *= n-i;
 	for(int j = 1; j <= m; ++j)
  	ans /= j;
 	return (long long) (ans+0.5);
}
void dp(int s,int res,int cur){
	if(res==0){
		long long tmp=1ll;
		for(int i=1;i<cur;++i)	tmp*=C(f[i]+g[i]-1,g[i]);
		f[cur]+=tmp;
	}
	else{
		int size=min(res,cur-1);
		for(int i=s;i<=size;++i){
			g[i]++;
			dp(i,res-i,cur);
			g[i]--;
		}
	}
}
void init(){
	memset(g,0,sizeof(g));
	memset(f,0,sizeof(f));
	f[1]=1;
	for(int i=2;i<=30;++i)	dp(1,i,i);
}
int main(){
	init();
	while(scanf("%d",&n)&&n)	printf("%lld\n",n==1?1:f[n]<<1ll);
	return 0;
}
