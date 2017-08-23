#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct data {
	int l, r;
}a[N];
bool cmp(const data &p, const data &q) {
	return p.l < q.l || (p.l == q.l && p.r > q.r);
}
int main() {
	int T, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)	scanf("%d%d", &a[i].l, &a[i].r);
		sort(a + 1, a + n + 1, cmp);
		int ans = 0, last = -1;
		int i = 1;
		while (i <= n) {
			++ans;
			last = a[i].r;
			while (i < n && a[i + 1]. l <= last) {
				if (a[i + 1].r < last)	last = a[i + 1].r;
				++i;
			}
			++i;
		}
		printf("%d\n", ans);
	}
	return 0;
}
