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
int a[40],b[40],c[40];
long long dp[40][2][2][2];
class LittleElephantAndXor
{
        public:
		long long f(int pos,int ta,int tb,int tc)
		{
			if(pos==-1)	return 1;
			long long &tmp=dp[pos][ta][tb][tc];
			if(tmp==-1)
			{
				tmp=0;
				for(int i=0;i<2;++i)
					for(int j=0;j<2;++j)
					{
						int k=i^j;
						if((!ta||(i<=a[pos]))&&(!tb||(j<=b[pos]))&&(!tc||(k<=c[pos])))
						tmp+=f(pos-1,ta&&(i==a[pos]),tb&&(j==b[pos]),tc&&(k==c[pos]));
					}
			}
			return tmp;
		}
        long long getNumber(int A, int B, int C)
        {
			for(int i=0;i<=30;++i)	if(A&(1<<i))	a[i]=1;
			for(int i=0;i<=30;++i)	printf("%d ",a[i]);
			for(int i=0;i<=30;++i)	if(B&(1<<i))	b[i]=1;
			for(int i=0;i<=30;++i)	if(C&(1<<i))	c[i]=1;
			memset(dp,-1,sizeof(dp));
			return f(30,1,1,1);
        }
};
