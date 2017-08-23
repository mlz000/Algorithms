#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 10000;
const LL inf = (LL)1e12;
int tot, cnt;
LL d[N], ans[N * 100];
void dfs1(LL v, int dep) {
	if (dep > 12)	return;
	d[++tot] = v * 10 + 4;
	d[++tot] = v * 10 + 7;
	dfs1(v * 10 + 4, dep + 1);
	dfs1(v * 10 + 7, dep + 1);
}
void dfs2(LL v, int p) {
	for (int i = p; i <= tot; ++i) {
		LL t = v * d[i];
		if (t < inf && t > 0)	ans[cnt++] = t, dfs2(t, i);
		else break;
	}
}
int gao(LL x) {
	int l = 0, r = cnt;
	while (l < r - 1) {
		int mid = l + r >> 1;
		if (ans[mid] <= x)	l = mid;
		else r = mid;
	}
	return l;
}
int main() {
	int T;
	dfs1(0, 1);
	sort(d + 1, d + tot + 1);
	ans[cnt++] = 0;
	dfs2(1, 1);
	sort(ans, ans + cnt);
	cnt = unique(ans, ans + cnt) - ans;
	ans[cnt] = inf + 1;
	scanf("%d", &T);
	while (T--) {
		LL a, b;
		scanf("%lld%lld", &a, &b);
		printf("%d\n", gao(b) - gao(a - 1));
	}
	return 0;
}
