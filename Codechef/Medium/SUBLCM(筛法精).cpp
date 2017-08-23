#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 5;
int a[N], d[N], l[N], v[N], p[N][20];
void init() {
	for (int i = 2; i < N; ++i) {
		if (!v[i])
			for (int j = i; j < N; j += i) {
				v[j] = 1;
				p[j][++l[j]] = i;	
			}
	}
}
int main() {
	int T, n;
	scanf("%d", &T);
	init();
	while (T--) {
		scanf("%d", &n);
		int ans = 0, t = 0;
		memset(d, 0, sizeof(d));
		for (int i = 1, x; i <= n; ++i) {
			scanf("%d", &x);
			++t;
			for (int j = 1; j <= l[x]; ++j) {
				int y = p[x][j];
				t = min(t, i - d[y] + 1);
				d[y] = i + 1;
			}
			ans = max(ans, t);
		}
		if (ans == 1)	ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}
