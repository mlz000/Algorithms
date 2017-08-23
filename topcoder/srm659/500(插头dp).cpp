#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 16, M = 1e9 + 7;
int n, m, cur, bb[N][N], g[N][N];
LL dp[2][(1 << N) + 5];
inline void add(LL &x, LL y) {
	x += y;
	if (x >= M)	x -= M;
}
class CampLunch {
	public:
	LL count(int nn, int mm, vector <string> a) {
		n = nn, m = mm;
		dp[0][(1 << m) - 1] = 1;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				cur ^= 1;
				int t = a[i][j] - 'A';
				memset(dp[cur], 0, sizeof(dp[cur]));
				for (int k = 0; k < (1 << m); ++k) {
					if (k >> t & 1) {
						add(dp[cur][k], dp[1 - cur][k]);
						add(dp[cur][k ^ (1 << t)], dp[1 - cur][k]);
						if (j) {
							int c = a[i][j - 1] - 'A';
							if (~k >> c & 1)	add(dp[cur][k ^ (1 << c)], dp[1 - cur][k]);
						}
					}
					else add(dp[cur][k ^ (1 << t)], dp[1 - cur][k]);
				}
			}
		return dp[cur][(1 << m) - 1];
	}
};
