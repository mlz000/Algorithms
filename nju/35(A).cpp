#include <bits/stdc++.h>
using namespace std;
const int N = 50;
int tot, to[N * N], cap[N * N], nxt[N * N], head[N], sum[N], pre[N], cur[N], dis[N], ans[N >> 1][N >> 1];
void add(int u, int v, int w) {
	to[tot] = v, cap[tot] = w, nxt[tot] = head[u], head[u] = tot++;
	to[tot] = u, cap[tot] = 0, nxt[tot] = head[v], head[v] = tot++;
}
void init() {
	tot = 0;
	memset(pre, -1, sizeof(pre));
	memset(head, -1, sizeof(head));
	memset(cap, 0, sizeof(cap));
	memset(sum, 0, sizeof(sum));
	memset(dis, 0, sizeof(dis));
}
void isap(int st, int ed) {
	int n = ed + 1;
	sum[0] = n;
	for (int i = st; i <= ed; ++i)	cur[i] = head[i];
	int u = pre[st] = st;
	int flow = 0, aug = -1;
	bool ok;
	while (dis[st] < n) {
		ok = 0;
		for (int &i = cur[u]; ~i; i = nxt[i]) {
			int v = to[i];
			if (cap[i] && dis[u] == dis[v] + 1) {
				ok = 1;
				pre[v] = u;
				u = v;
				aug = (aug == -1) ? cap[i] : min(cap[i], aug);
				if (v == ed) {
					flow += aug;
					for (u = pre[v]; v != st; v = u, u = pre[u]) {
						cap[cur[u]] -= aug;
						cap[cur[u] ^ 1] += aug;
					}
					aug = -1;
				}
				break;
			}
		}
		if (ok)	continue;
		int Min = n;
		for (int i = head[u]; ~i; i = nxt[i]) {
			int v = to[i];
			if (cap[i] && dis[v] < Min) {
				cur[u] = i;
				Min = dis[v];
			}
		}
		if (--sum[dis[u]] == 0)	break;
		dis[u] = Min + 1;
		++sum[dis[u]];
		u = pre[u];
	}
}
int main() {
	int n, m, T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; ++tt) {
		init();
		printf("Matrix %d\n", tt);
		scanf("%d%d",  &n, &m);
		int sum = 0;
		for (int i = 1, x; i <= n; ++i)	scanf("%d", &x), add(0, i, x - sum - m), sum = x;
		sum = 0;
		for (int i = 1, x; i <= m; ++i)	scanf("%d", &x), add(i + n, n + m + 1, x - sum - n), sum = x;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				add(i, j + n, 19);
		isap(0, n + m + 1);
		for (int i = 1; i <= n; ++i)
			for (int j = head[i]; ~j; j = nxt[j]) {
				if (to[j] > n && to[j] <= n + m)	ans[i][to[j] - n] = 20 - cap[j];
			}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j < m; ++j)	printf("%d ", ans[i][j]);
			printf("%d\n", ans[i][m]);
		}
	}	
	return 0;
}
