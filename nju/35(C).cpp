#include <bits/stdc++.h>
using namespace std;
const int N = 505, M = 500005, inf = ~0u >> 1;
int tot, type[N], to[M], cap[M], nxt[M], head[N], pre[N], cur[N], sum[N], dis[N], num[N], ww[N];
int b[N];
double x[N], y[N];
void add(int u, int v, int w) {
	to[tot] = v, cap[tot] = w, nxt[tot] = head[u], head[u] = tot++;
	to[tot] = u, cap[tot] = 0, nxt[tot] = head[v], head[v] = tot++;
}
void init() {
	tot = 0;
	memset(head, -1, sizeof(head));
	memset(cap, 0, sizeof(cap));
	memset(pre, -1, sizeof(pre));
	memset(sum, 0, sizeof(sum));
	memset(dis, 0, sizeof(dis));
}
int isap(int st, int ed, int n) {
	sum[0] = n;
	for (int i = 0; i < n; ++i)	cur[i] = head[i];
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
	return flow;
}
int main() {
	int n, T;
	double d;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%lf", &n, &d);
		int cnt = 0, ans = 0;
		for (int i = 1; i <= n; ++i)	scanf("%lf%lf%d%d", &x[i], &y[i], &num[i], &ww[i]), cnt += num[i];
		for (int k = 1; k <= n; ++k) {
			init();
			for (int i = 1; i <= n; ++i)	add(0, i, num[i]), add(i, i + n, ww[i]);
			for (int i = 1; i <= n; ++i)
				for (int j = i + 1; j <= n; ++j) {
					double dis = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
					if (dis <= d * d)	add(i + n, j, inf), add(j + n, i, inf);
				}
			int t = isap(0, k, n * 2 + 2);
			if (t == cnt)	b[++ans] = k - 1;
		}
		if (!ans)	puts("-1");
		else {
			for (int i = 1; i < ans; ++i)	printf("%d ", b[i]);
			printf("%d\n", b[ans]);
		}
	}
	return 0;
}
