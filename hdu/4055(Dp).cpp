#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1005;
const int mod=1000000007;;
int dp[N][N],sum[N][N];
char s[N];
int main(){
	while(scanf("%s",s+2)!=EOF){
		memset(dp,0,sizeof(dp));
		memset(sum,0,sizeof(sum));
		int n=(int)strlen(s+2);
		dp[1][1]=sum[1][1]=1;
		for(int i=2;i<=n+1;i++){
			for(int j=1;j<=i;j++){
				if(s[i]=='I'||s[i]=='?') dp[i][j]=(dp[i][j]+sum[i-1][j-1])%mod;
				if(s[i]=='D'||s[i]=='?'){
					int tmp=((sum[i-1][i-1]-sum[i-1][j-1])%mod+mod)%mod;
					dp[i][j]=(dp[i][j]+tmp)%mod;
				}
				sum[i][j]=(dp[i][j]+sum[i][j-1])%mod;
			}
		}
		printf("%d\n",sum[n+1][n+1]);
	}
	return 0;
}
