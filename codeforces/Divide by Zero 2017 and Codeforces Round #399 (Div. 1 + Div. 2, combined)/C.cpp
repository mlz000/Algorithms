#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = 1024;
typedef long long LL;
int cnt[2][M];
int main() {
	int n, k, x;
	scanf("%d%d%d", &n, &k, &x);
	int mn = N, mx = 0;
	for (int i = 1, y; i <= n; ++i) {
		scanf("%d", &y);
		++cnt[0][y];
	}
	for (int i = 1; i <= k; ++i) {
		int now = 1;
		for (int j = 0, t; j < M; ++j) {
			t = cnt[~i & 1][j];
			if (t) {
				if (!(t & 1)) {
					cnt[i & 1][j ^ x] += t / 2;
					cnt[i & 1][j] += t / 2;
				}
				else if (now & 1) {
					cnt[i & 1][j ^ x] += t / 2 + 1;
					cnt[i & 1][j] += t / 2;
				}
				else {
					cnt[i & 1][j ^ x] += t / 2;
					cnt[i & 1][j] += t / 2 + 1;
				}
				now += t;
			}
		}
		memset(cnt[~i & 1], 0, sizeof(cnt[~i & 1]));
	}
	for (int j = 0; j < M; ++j)
		if (cnt[k & 1][j]) {
			mn = min(mn, j);
			mx = max(mx, j);
		}
	printf("%d %d\n", mx, mn);
	return 0;
}

