#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
class BinaryCards{
        public:
        long long largestNumber(long long A, long long B){
        	long long ans=B;
			for(int i=0;i<62;++i){
				long long t=(B>>i)<<i;
				if(t<=A)	continue;
				t+=(1ll<<i)-1;
				ans=max(ans,t);
			}
			return ans;
        }
};


