#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int ans = N, a[N], f[N], dep[N];
bool v[N];
void dfs(int u, int fa, int now) {
	if (v[u]) {
		if (f[u] == fa)	ans = min(ans, now - dep[u]);
	}
	else {
		dep[u] = now;
		v[u] = 1;
		f[u] = fa;
		dfs(a[u], fa, now + 1);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
		if (!v[i])	dfs(i, i, 1);
	printf("%d\n", ans);
	return 0;
}
