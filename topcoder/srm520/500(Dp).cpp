#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(x) (int)x.size()
//g[i][j] ith person get j points 
//f[i][j]=g[i][j]*(f[i-1][0...j-1])
//f[i][j]=f[i][j-1]+g[i][j]*f[i-1][j-1]
//g[i][j]=g[i-1][j-r...j-l]
//g[i][j]=g[i][j-1]+g[i-1][j-l]-g[i-1][j-r-1]
//use perfix sum
const int N=200005,M=1000000007;
int f[2][N],g[2][N];
class SRMIntermissionPhase{
        public:
        int countWays(vector <int> a, vector <string> b){
            int n=sz(b);
			int tot=accumulate(a.begin(),a.end(),0);
			fill(f[n&1]-1,f[n&1]+N,1);
			for(int i=n-1;i>=0;--i){
				fill(g[1],g[1]+N,1);
				for(int j=0;j<3;++j){
					int l,r;
					if(b[i][j]=='Y')	l=1,r=a[j];
					else l=r=0;
					g[0][-1]=0;
					for(int k=0;k<=tot;++k)	g[j&1][k]=((g[j&1][k-1]+g[(j&1)^1][k-l])%M-g[(j&1)^1][k-min(k,r)-1]+M)%M;
				}
				f[i&1][-1]=0;
				int gg[N];
				memcpy(gg,g[0],sizeof(gg));
				for(int j=tot;j>=1;--j)	gg[j]-=gg[j-1];
				for(int j=0;j<=tot;++j)	f[i&1][j]=(f[i&1][j-1]+(ll)gg[j]*f[(i&1)^1][j-1]%M)%M;
			}
			return (f[0][tot]+M)%M;
        }
};
