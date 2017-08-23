#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
class ConvexSequence{
        public:
        long long getMinimum(vector <int> a){
 			int l=sz(a);     
			long long ans=0ll;
			bool f=1;
			while(f){
				f=0;
				for(int i=1;i<l-1;++i){
					if(a[i-1]-a[i]<a[i]-a[i+1]){
						ans+=a[i]-(a[i-1]+a[i+1])/2;
						a[i]=(a[i-1]+a[i+1])/2;
						f=1;
					}
				}
			}
			return ans;
        }
};
