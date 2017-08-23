#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
const int N=2505,M=1000000007;
ll inv[N],fac[N],rfac[N],dp[N][N];
void init(){
	inv[0]=inv[1]=fac[0]=fac[1]=rfac[0]=rfac[1]=1ll;
	for(int i=2;i<N;++i){
		inv[i]=(M-M/i)*inv[M%i]%M;
		fac[i]=fac[i-1]*i%M;
		rfac[i]=rfac[i-1]*inv[i]%M;
	}	
}
class SRMChallengePhase{
        public:
        ll countWays(vector <string> x, vector <string> y){
            init();
			string a=accumulate(x.begin(),x.end(),string());
			string b=accumulate(y.begin(),y.end(),string());
			int n=sz(a);
			int in=0,out=0,both=0;
			for(int i=0;i<n;++i){
				if(a[i]=='Y'){
					if(b[i]=='Y')	both++;
					else out++;
				}
				else if(b[i]=='Y')	in++;
			}
			if(in>out)	return 0;
			for(int i=0;i<=out+both;++i)
				for(int j=0;j<=both;++j){
					if(!i)	dp[i][j]=j?0:1;
					else{
						dp[i][j]=dp[i-1][j];
						if(j>0)	(dp[i][j]+=dp[i-1][j-1]*(i-j))%=M;
					}
				}
			ll ans=dp[out+both][both];
			ans=ans*fac[out]%M*fac[in]%M*fac[both]%M*fac[out]%M*rfac[in]%M*rfac[out-in]%M;
			for(int i=1;i<=out-in;++i)	ans=ans*(n-1)%M;
			return ans;
        }
};
