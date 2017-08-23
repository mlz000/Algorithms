#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x)	x.size() 
const int N = 1005, inf = ~0u >> 1;
bool v[N];
vector<int> g[N], c;
int dp[N][2];
class CandyCollection {
    public:
	int solve(vector <int> t1, vector <int> n1, vector <int> t2, vector <int> n2) {
		int n = sz(t1), ans = 0;
		for (int i = 0; i < n; ++i) {
			g[t1[i]].pb(i);
			g[t2[i]].pb(i);
		}
		for (int i = 0; i < n; ++i) {//考虑每个环上每种shape
			if (v[i])	continue;
			c.clear();
			c.pb(i);
			int t = t2[i];
			while (1) {
				int p = g[t][0] + g[t][1] - c.back();
				v[p] = 1;
				if (t2[p] == t)	swap(t1[p], t2[p]), swap(n1[p], n2[p]);
				if (p == c[0])	break;
				c.pb(p);
				t = t2[p];
			}
			dp[0][1] = max(n1[c[0]], n2[c[0]]) + 1;//搞定右favor
			dp[0][0] = n2[c[0]] + 1;//搞定左
			for (int j = 1; j < sz(c); ++j) {
				dp[j][1] = min(dp[j - 1][1] + n1[c[j]] + 1, max(n1[c[j]], n2[c[j]]) + 1 + dp[j - 1][0]);
				dp[j][0] = min(dp[j - 1][1], n2[c[j]] + 1 + dp[j - 1][0]);
			}
			int cur = min(dp[sz(c) - 1][0], dp[sz(c) - 1][1]);
			dp[0][1] = n1[c[0]] + 1;
			dp[0][0] = 0;
			for (int j = 1; j < sz(c); ++j) {
				dp[j][1] = min(dp[j - 1][1] + n1[c[j]] + 1, max(n1[c[j]], n2[c[j]]) + 1 + dp[j - 1][0]);
				dp[j][0] = min(dp[j - 1][1], n2[c[j]] + 1 + dp[j - 1][0]);
			}
			cur = min(cur, dp[sz(c) - 1][1]);
			ans += cur;
		}
		return ans;
	}
};
