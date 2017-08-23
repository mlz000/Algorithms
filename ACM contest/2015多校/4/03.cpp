#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1e5 + 5;
int n, tot, a[N], cir[N], sz[N], f[N], cnt[N], cnt2[N], sum[N];
bool is[N];
vector<int> g[N];
void dfs(int u) {
	sz[u] = 1;
	for (int i = 0, v; i < g[u].size(); ++i) {
		v = g[u][i];
		if (!is[v]) {
			dfs(v);
			sz[u] += sz[v];
		}
	}
}
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
int check(int x) {
	for (int i = 0; i < x; ++i)	cnt2[i] = 0;
	for (int i = 1; i <= tot; ++i)	++cnt2[sum[i] = (sum[i - 1] + sz[cir[i]]) % x];
	int mx = cnt2[sum[tot]];
	for (int i = 1; i < tot; ++i) {
		--cnt2[sum[i]];
		++cnt2[(sum[tot] + sum[i]) % x];
		mx = max(mx, cnt2[(sum[tot] + sum[i]) % x]);
	}
	return mx;
}
int main() {
	while (~scanf("%d", &n)) {
		tot = 0;
		for (int i = 1; i <= n; ++i)	g[i].clear();
		memset(is, 0, sizeof(is));
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]), f[i] = i;
			g[a[i]].pb(i);
		}
		for (int i = 1; i <= n; ++i) {
			int fx = find(a[i]), fy = find(i);
			if (fx != fy)	f[fx] = fy;
			else {
				is[i] = 1;
				cir[++tot] = i;
				break;
			}
		}
		int x = a[cir[1]];
		while (x != cir[1]) {
			is[cir[++tot] = x] = 1;
			x = a[x];
		}
		for (int i = 1; i <= tot; ++i)	dfs(cir[i]);
		for (int i = 1; i <= n; ++i)	if (!is[i])	++cnt[sz[i]];
		for (int i = 1; i <= n; ++i)
			for (int j = i + i; j <= n; j += i)
				cnt[i] += cnt[j];
		int ans = 0;
		for (int i = 1; i <= n; ++i)
			if (n % i == 0 && check(i) + cnt[i] == n / i)	++ans;
		printf("%d\n", ans);
	}
	return 0;
}
