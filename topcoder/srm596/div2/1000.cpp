#line 5 "SparseFactorialDiv2.cpp"
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
long long D;
class SparseFactorialDiv2
{
        public:
		long long get(long long x)
		{
			long long mark[1005];
			clr(mark,0);
			mark[0]=1;
			long long ans=0ll;
			for(long long i=1;i*i<x;++i)	if(!mark[(i*i)%D])	mark[(i*i)%D]=i*i;
			for(int i=0;i<D;++i)
				if(mark[i])
				{
					if(i==0)	mark[i]=0;
					ans+=(x-mark[i])/D;
				}
			return ans;
		}
        long long getCount(long long lo, long long hi, long long d)
        {
			D=d;
			return get(hi)-get(lo-1);
        }
};
