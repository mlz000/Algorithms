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
int ans=100000000;
int f(int x)
{
	if(x<0)	return -x;
	else return x;
}
class FoxAndSightseeing
{
        public:
        int getMin(vector <int> a)
        {
           int n=sz(a);
		   for(int i=1;i<n-1;++i)
		   {
			    int sum=0;
				for(int j=1;j<n;++j)
				{
					if(j==i)	continue;
					if(j-1==i)	sum+=f(a[j]-a[j-2]);
					else sum+=f(a[j]-a[j-1]);
				}	
				ans=min(ans,sum);
		   }
		   return ans;
        }
};


