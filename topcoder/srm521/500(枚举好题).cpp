#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
#define X first
#define Y second
#define sz(x) (int)x.size()
#define mp make_pair
#define in insert
class RangeSquaredSubsets{
        public:
        long long countSubsets(int nlow, int nhigh, vector <int> x, vector <int> y){
            nlow<<=1,nhigh<<=1;
			set<int>sx,sy;
			int n=sz(x);
			for(int i=0;i<n;++i){
				x[i]<<=1,y[i]<<=1;
				sx.in(x[i]-1),sx.in(x[i]),sx.in(x[i]+1);
				sy.in(y[i]-1),sy.in(y[i]),sy.in(y[i]+1);
			}
			vector<int> lx(sx.begin(),sx.end());
			vector<int> ly(sy.begin(),sy.end());
			set<ll> ans;
			pii l[50];
			for(int i=0;i<sz(lx);++i)
				for(int j=0;j<sz(ly);++j)
					for(int dx=-1;dx<=1;dx+=2)
						for(int dy=-1;dy<=1;dy+=2){
							int cnt=0;
							for(int k=0;k<n;++k){
								int px=(x[k]-lx[i])*dx;
								int py=(y[k]-ly[j])*dy;
								if(px<0 || py<0)	continue;
								l[cnt++]=mp(max(px,py),k);
							} 
							sort(l,l+cnt);
							l[cnt].X=(int)2e9;
							ll now=0ll;
							for(int k=0;k<cnt;++k){
								if(l[k].X>nhigh)	break;
								now|=(1ll<<l[k].Y);
								if(l[k].X!=l[k+1].X && l[k+1].X>=nlow)	ans.in(now);
							}
						}
			return sz(ans);
        }
};
