#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
class SRMCodingPhase{
        public:
        int countScore(vector <int> points, vector <int> skills, int luck){
   			int ans=0;
			for(int i=0;i<1<<3;++i){
				vector<int> s=skills;
				int tot=0,tmp=0,rp=luck;
				for(int j=2;j>=0;--j)
					if((1<<j)&i){
						int t=min(s[j]-1,rp);
						s[j]-=t,rp-=t;
						tot+=s[j],tmp+=points[j]-(1<<(j+1))*s[j];
					}
				if(tot<=75)	ans=max(ans,tmp);
			}
			return ans;
        }
};
