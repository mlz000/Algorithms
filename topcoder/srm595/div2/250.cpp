// BEGIN CUT HERE

// END CUT HERE
#line 5 "LittleElephantAndBallsAgain.cpp"
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
#include <ctime>
using namespace std;
typedef long long ll;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
class LittleElephantAndBallsAgain
{
        public:
        int getNumber(string S)
        {
            int i,j,k;
			int l=S.length();
			int cnt=0,Max=0;
			for(i=0;i<l;++i)
			{
				if(i>0 && S[i]==S[i-1])	cnt++;
				else cnt=1;
				Max=max(Max,cnt);
			}	
			return l-Max;
        } 
};
