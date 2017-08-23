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
#define inf 10000000
#define sqr(x)	((x)*(x))
int f[20][5];
class ColorfulRoad
{
        public:
        int getMin(string s)
        {
            int l=s.size();
			for(int i=0;i<20;++i)
				for(int j=0;j<4;++j)	f[i][j]=inf;
			f[0][0]=f[0][1]=f[0][2]=0;
			for(int i=1;i<l;++i)
			{
				if(s[i]=='R')
				{
					for(int j=0;j<i;++j)	if(s[j]=='B')	f[i][0]=min(f[i][0],f[j][2]+sqr(i-j));
				}
				else if(s[i]=='G')
				{
					for(int j=0;j<i;++j)	if(s[j]=='R')	f[i][1]=min(f[i][1],f[j][0]+sqr(i-j));
				}
				else  for(int j=0;j<i;++j)	if(s[j]=='G')	f[i][2]=min(f[i][2],f[j][1]+sqr(i-j));
			}
			if(s[l-1]=='R')	
			{
				if(f[l-1][0]==inf)	return -1;
				return f[l-1][0];
			}
			else if(s[l-1]=='G')	
			{
				if(f[l-1][1]==inf)	return -1;
				return f[l-1][1];
			}
			else	
			{
				if(f[l-1][2]==inf)	return -1;
				return f[l-1][2];
			}
        }
};


