#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define MAX 60
vector<long long> ret,ans;
int cnt[65];bool is[65];
class BitwiseAnd
{
        public:
        vector<long long> lexSmallest(vector<long long> a, int N)
        {
			//每位最多有2个1
			//任意一对至少有一位为1
			int n=sz(a);
			for(int i=0;i<n;++i)
				for(int j=0;j<MAX;++j)	
					cnt[j]+=((a[i]>>j)&1);
			for(int i=0;i<n;++i)
				for(int j=i+1;j<n;++j)
					if((a[i]&a[j])==0)	return ret;
			for(int i=0;i<n;++i)
				for(int j=i+1;j<n;++j)
				{
					ll tmp=a[i]&a[j];
					for(int k=0;k<MAX;++k)
						if(tmp&(1ll<<k))
						{
							if(is[k])	return ret;
							is[k]=true;
						}
				}
			for(int i=0;i<N-n;++i)
			{
				ll tmp=0ll;
				for(int j=0,k;j<n;++j)
				{
					for(k=0;k<MAX;++k)
					if(!is[k] && (a[j]&(1ll<<k)))
					{
						is[k]=true;
						tmp|=1ll<<k;
						break;
					}
					if(k==MAX)	return ret;
				}
				ans.pb(tmp);
			}
			for(int i=0;i<N-n;++i)
				for(int j=i+1,k;j<N-n;++j)
				{
					for(k=0;k<MAX;++k)
					if(!cnt[k])
					{
						cnt[k]=1;
						ans[i]|=1ll<<k;
						ans[j]|=1ll<<k;
						cout<<k<<endl;
						break;
					}
					if(k==MAX)	return ret;
				}
			for(int i=0;i<n;++i)	ans.pb(a[i]);
			sort(ans.begin(),ans.end());
			return ans;
		}
};
