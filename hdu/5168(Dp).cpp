#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define X first
#define Y second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef long long LL;
const int N = 100005, M = 200005;
const long long inf = (LL)1e16;
LL dp[N], dp1[M];
template <typename A, typename B> inline void mdf(A &p, B q) {
	if (q < p)	p = q;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		vector<pair<int, pii> > e;
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 2; i <= n; ++i)	dp[i] = inf;
		for (int i = 0; i <= m; ++i)	dp1[i] = inf;
		for (int i = 0, x, y, z; i < m; ++i) {
			scanf("%d%d%d", &x, &y, &z);
			e.pb(mp(z, mp(x, y)));
		}
		dp[1] = 0;
		sort(e.begin(), e.end());
		for (int i = 0, j = 0; ; ++i) {
			while (j < m && (i == m || e[j].X + k <= e[i].X)) {
				mdf(dp[e[j].Y.Y], dp1[j]);
				++j;
			}
			if (i == m)	break;
			pii t = e[i].Y;
			long long x = inf;
			mdf(x, dp[t.X] + e[i].X);
			dp1[i] = x;
		}
		if (dp[n] == inf)	puts("-1");
		else printf("%I64d\n", dp[n]);
	}
	return 0;
}

