#include <bits/stdc++.h>//dilworth
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const int N = 55;
int n, l[N];
bool g[N][N], v[N];
struct Incubator {
    bool can(int u) {
		for (int i = 0; i < n; ++i) 
			if (g[u][i] && !v[i]) {
				v[i] = 1;
				if (l[i] == -1 || can(l[i])) {
					l[i] = u;
					return 1;
				}
			}
		return 0;
	}
	int maxMagicalGirls(vector <string> s) {
         n = s.size();
		 for (int i = 0; i < n; ++i) 
			 for (int j = 0; j < n; ++j)
				 g[i][j] = s[i][j] == 'Y';
		 for (int k = 0; k < n; ++k)
			 for (int i = 0; i < n; ++i)
				 for (int j = 0; j < n; ++j)
					 g[i][j] |= g[i][k] & g[k][j];
		 int t = 0;
		 memset(l, -1, sizeof(l));
		 for (int i = 0; i < n; ++i) {
			 memset(v, 0, sizeof(v));
			 if (can(i))	++t;
		 }
		 return n - t;
    }
};
