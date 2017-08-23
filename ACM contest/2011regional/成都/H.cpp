#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N = 100005;
int n, tot, head[N], to[N << 1], w[N << 1], next[N << 1], s[N];
long long ans;
void add(int x, int y, int z) {
	to[++tot] = y;
	w[tot] = z;
	next[tot] = head[x];
	head[x] = tot;
}
void dfs(int u, int fa) {
	s[u] = 1;
	for (int i = head[u], v; i != -1 ; i = next[i]) {
		v = to[i];
		if (v == fa)	continue;
		dfs(v, u);
		ans += (long long)w[i] * min(n - s[v], s[v]) * 2;
		s[u] += s[v];
	}
}
int main() {
	int T, x, y, z;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; ++tt) {
		tot = 0;
		memset(next, 0, sizeof(next));
		memset(head, -1, sizeof(head));
		memset(w, 0, sizeof(w));
		memset(s, 0, sizeof(s));
		printf("Case #%d: ", tt);
		scanf("%d", &n);
		for (int i = 1; i < n; ++i) {
			scanf("%d%d%d", &x, &y, &z);
			add(x, y, z);
			add(y, x, z);
		}
		ans = 0ll;
		dfs(1, -1);
		printf("%I64d\n", ans);
	}
	return 0;
}
