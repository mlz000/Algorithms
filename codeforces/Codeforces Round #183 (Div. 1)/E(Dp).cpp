#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
const int N=85;
double l[N],r[N],ans[N][N],ago[N],now[N],dp[N][N];
int main(){
	vector<double>g;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%lf%lf",&l[i],&r[i]);
		g.push_back(l[i]),g.push_back(r[i]);
	}
	sort(g.begin(),g.end());
	g.erase(unique(g.begin(), g.end()), g.end());
	vector<pair<double,double> >p;
	for(int i=0;i<g.size()-1;++i)	p.push_back(mp(g[i],g[i+1]));
	for(int t=0;t<p.size();++t){
		for(int i=1;i<=n;++i){
			double L=p[t].first,R=p[t].second;
			if(!(l[i]>=R || r[i]<=L)){
				for(int j=0;j<=n;++j)
					for(int k=0;k<=n;++k)
						dp[j][k]=0.0;
				dp[0][0]=1.0;
				int cnt=0;
				vector<int>used;
				for(int k=1;k<=n;++k){
					if(l[k]>=R || r[k]<=L){
						now[k]=0.0;
						if(r[k]<=L)	cnt++;
					}
					else now[k]=(R-L)/(r[k]-l[k]),used.push_back(k);
				}
				int m=used.size();//dp[i][j][k]表示前i个人j个在此区间前k个在此区间里
				for(int _=0;_<m;++_){
					int x=used[_];
					if(x==i)	continue;
					for(int k=_+1;k>=0;--k)
						for(int o=_+1-k;o>=0;--o){
							dp[k+1][o]+=dp[k][o]*ago[x];
							dp[k][o+1]+=dp[k][o]*now[x];
							dp[k][o]*=1.0-now[x]-ago[x];
						}
				}
				for(int j=0;j<m;++j)
					for(int k=0;k<m-j;++k){
						ans[i][cnt+j]+=dp[j][k]*now[i]/(1+k);
						ans[i][cnt+j+k+1]-=dp[j][k]*now[i]/(1+k);
					}
			}
		}
		for(int i=1;i<=n;++i)	ago[i]+=now[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<n;++j){
			if(j){
				ans[i][j]+=ans[i][j - 1];
			}
			printf("%.12f%c", ans[i][j],j==n - 1?'\n':' ');
		}
	}
	return 0;
}
