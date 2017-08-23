#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
typedef long long LL;
LL dp[55][55], c[55][55];
vector<int> p;
LL gao(int l, int r) {
	if (l == r)	return 1;
	LL &t = dp[l][r];
	if (~t)	return t;
	t = 0;
	for (int i = l + 1; i <= r; ++i) {
		int cnt = 0;
		bool f = 1;
		for (int j = l; j < i; ++j)
			for (int k = i; k <= r; ++k)
				if (p[j] > p[k]) {
					++cnt;
					if (cnt > 1) {
						f = 0;
						break;
					}
				}
		if (!f)	continue;
		(t += gao(l, i - 1) * gao(i, r) % M * c[r - l - 1][i - l - 1] % M) %= M;
	}
	return t;
}
class AdjacentSwaps {
	public:
	LL theCount(vector <int> _p) {
		for (int i = 0; i <= 50; ++i) {
			c[i][0] = c[i][i] = 1;
			for (int j = 1; j < i; ++j)	c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
		}
		p = _p;
		memset(dp, -1, sizeof(dp));
		int n = p.size();
		int cnt = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < i; ++j)
				if (p[j] > p[i])	++cnt;
		if (cnt != n - 1)	return 0;
		LL ans = gao(0, n - 1);
		return ans;
	}
};
