#include<bits/stdc++.h>//dsu
using namespace std;
typedef long long ll;
#define sz(x) (int)x.size()
#define pb push_back
const int N=2005,M=(int)1e9+7;
vector<int>g[N];
int p[N],f[N],w[N];
int find(int x){
	return f[x]=f[x]==x?f[x]:find(f[x]);
}
class CandyCupRunningCompetition{
        public:
        int findMaximum(int n, vector <int> A, vector <int> B){
            int m=sz(A);
			for(int i=0;i<n;++i)	f[i]=i;
			w[0]=1;
			int ans=0;
			for(int i=0;i<m;++i){
				g[A[i]].pb(B[i]);
				g[B[i]].pb(A[i]);
				if(i>0)	w[i]=(ll)w[i-1]*3%M;
			}	
			for(int i=m-1;i>=0;--i){
				int fa=find(A[i]);
				int fb=find(B[i]);
				int st=find(0);
				int ed=find(n-1);
				if((fa==st && fb==ed)||(fa==ed && fb==st))	(ans+=w[i])%=M;
				else	f[fb]=fa;
			}
			return ans;
        }
};

