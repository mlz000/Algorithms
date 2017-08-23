#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 50, M = 1e9 + 7;
int d[N], a[N][N], g[N][N];
LL ans[2][N];
class MonsterFarm {
	public:
	int numMonsters(vector <string> transforms) {
		int n = transforms.size();
		for (int i = 0 ; i < n; ++i) {
			istringstream t(transforms[i]);
			for (int x; t >> x; ) {
				--x;
				++a[i][x];
				++d[i];
				g[i][x] = 1;
			}
		}
		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					g[i][j] |= g[i][k] & g[k][j];
		bool ok = 0;
		for (int i = 0; i < n; ++i)
			if (g[0][i] && g[i][i] && d[i] > 1)	ok = 1;
		if (ok)	return -1;//inf
		queue<int> q;
		q.push(0);
		ans[0][0] = 1;
		for (int step = 1; step <= 1000; ++step) {
			memset(ans[1], 0, sizeof(ans[1]));
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					(ans[1][j] += g[i][j] * ans[0][i] * a[i][j] % M) %= M;
			for (int i = 0; i < n; ++i)	ans[0][i] = ans[1][i];
		}
		LL t = 0;
		for (int i = 0; i < n; ++i)	(t += ans[0][i]) %= M;
		return t;
	}
};
