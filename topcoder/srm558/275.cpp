#include <bits/stdc++.h>
using namespace std ;
typedef long long LL;
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int N = 55, inf = 1e7;
int a[N], dp[N];
class Stamp {
	public:
		int getMinimumCost(string s, int A, int B) {
			int n = s.size();
			for (int i = 0; i < n; ++i) {
				if (s[i] == 'R')	a[i] = 1;
				if (s[i] == 'G')	a[i] = 2;
				if (s[i] == 'B')	a[i] = 4;
				if (s[i] == '*')	a[i] = 7;
			}
			int ans = inf;
			for (int l = 1; l <= n; ++l) {
				fill(dp, dp + n + 1, inf);
				dp[0] = 0;
				for (int i = 0; i < n; ++i) {
					int now = 7;
					for (int j = i; j < n; ++j) {
						now &= a[j];
						if (!now)	break;
						int len = j - i + 1;
						if (len >= l && dp[i] != inf)	dp[j + 1] = min(dp[j + 1], dp[i] + ((len + l - 1) / l) * B);
					}
				}
				if (dp[n] != inf)	ans = min(ans, dp[n] + A * l);
			}
			return ans;
		}
};
