#include <bits/stdc++.h>
using namespace std;
const int N = 55;
char s[N][N];
int id[N][N];
long long r[N];
int main() {
	int T, n, m;
	scanf("%d", &T);
	while (T--) {
		int cnt = 0;
		memset(id, -1, sizeof(id));
		memset(r, 0, sizeof(r));
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)	scanf("%s", s[i]);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				if (s[i][j] == 'L')	id[i][j] = cnt++;
				else if (s[i][j] == 'E')	r[i] |= 1ll << j;	
			}
		bool f = 0;
		for (int k = 0; k < (1 << cnt); ++k) {//Ã¶¾ÙÏòÉÏ
			bool can = 1;
			long long up = 0ll;
			for (int i = n - 1; i >= 0; --i) {
				long long t = r[i] & ~up;
				int L = 100, R = 0;
				for (int j = 0; j < m; ++j) {
					if (~id[i][j] && (k >> id[i][j] & 1))	up |= 1ll << j;
					else if (~id[i][j]) {
						L = min(L, j);
						R = max(R, j);
					}
				}
				if (L < R || !t)	continue;
				if (L > R && t) {
					can = 0;
					break;
				}
				bool canl = 0, canr = 0;
				for (int j = 0; j < L; ++j)
					if (t >> j & 1)	canl = 1;
				for (int j = L + 1; j < m; ++j)
					if (t >> j & 1)	canr = 1;
				if (canl && canr) {
					can = 0;
					break;
				}
			}
			if (can) {
				f = 1;
				break;
			}
		}
		printf("%s\n", f ? "Possible" : "Impossible");
	}
	return 0;
}
