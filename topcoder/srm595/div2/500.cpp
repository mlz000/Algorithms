#line 5 "LittleElephantAndIntervalsDiv2.cpp"
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
class LittleElephantAndIntervalsDiv2
{
        public:
        int getNumber(int M, vector <int> L, vector <int> R)
        {
			int n=sz(L);
			set<string> S;
			for(int i=0;i<(1<<n);++i)
			{
				string s(M,'W');
				for(int j=0;j<n;++j)
					for(int k=L[j]-1;k<R[j];++k)
						s[k]=((i&(1<<j))?'B':'W');
        		S.insert(s);
			}
			return sz(S);
		}
};
