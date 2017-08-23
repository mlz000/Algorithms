// BEGIN CUT HERE

// END CUT HERE
#line 5 "LittleElephantAndIntervalsDiv1.cpp"
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
int p[1005];
bool f[1005];
class LittleElephantAndIntervalsDiv1
{
        public:
        long long getNumber(int M, vector <int> L, vector <int> R)
        {
           int n=L.size();
		   long long ans=1ll;
		   for(int i=0;i<n;++i)
		   {
		   		for(int j=L[i];j<=R[i];++j)	p[j]=i+1;
		   }
		   for(int i=1;i<=M;++i)
		   {
		   		if(p[i] && !f[p[i]])
				{
				   f[p[i]]=true;
				   ans*=2;
				}
		   }
		   return ans;
        }
};
