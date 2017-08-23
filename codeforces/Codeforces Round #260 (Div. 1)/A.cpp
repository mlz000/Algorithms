#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100005;
long long cnt[N],dp[N][2];
int main(){
	int n,x;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	scanf("%d",&x),cnt[x]+=x;
	for(int i=1;i<=100000;++i){
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		dp[i][1]=dp[i-1][0]+cnt[i];
	}
	printf("%I64d\n",max(dp[100000][0],dp[100000][1]));
	return 0;
}
