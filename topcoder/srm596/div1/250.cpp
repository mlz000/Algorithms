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
int ans;
int calc(int x,int y)
{
	int tmp=0;
	while(x>0)
	{
		if(x%2==1||y==0)	x--,tmp++;
		if(y>0)	x/=2,y--;
	}
	return tmp;
}
class IncrementAndDoubling
{
        public:
        int getMin(vector <int> a)
        {
			ans=100000;
			for(int i=0,cnt;i<=12;++i)
			{
				cnt=0;
				for(int j=0;j<a.size();++j)	cnt+=calc(a[j],i);
				ans=min(ans,cnt+i);
			}
			return ans;
        }
};
