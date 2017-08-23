#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int cnt[N];
int main() {
	int T, n;
	scanf("%d", &T);
	while (T--) {
		int ans = 0;
		memset(cnt, 0, sizeof(cnt));
		scanf("%d", &n);
		for (int i = 1, x; i <= n; ++i) scanf("%d", &x), ++cnt[x];
		for (int i = 1; i <= (int)1e5; ++i)	ans = max(ans, cnt[i]);
		printf("%d\n", n - ans);
	}
	return 0;
}
