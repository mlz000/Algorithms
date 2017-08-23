#include<bits/stdc++.h>//dp[i][j] at first row,first row remove i items and second row remove j
using namespace std;
typedef long long ll;
const int N=3505;
int dp[N][N];
class PatternLock{
        public:
        int solve(int n, int M){
            dp[0][0]=1;
			for(int sum=1;sum<=n*2;++sum)
				for(int i=1;i<=sum && i<=n;++i){
					int j=sum-i;
					if(j>n)	continue;
					dp[i][j]=2*dp[i-1][j]%M;
					if(j)	(dp[i][j]+=(ll)i*dp[j][i-1]%M)%=M;
				}
			return dp[n][n];
        }
};
