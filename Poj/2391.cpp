#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 510, M = 100010, inf = ~0u >> 1;
int n, m, a[N], b[N], sum;
LL g[N][N];
struct Maxflow {
	int tot, to[M], nxt[M], head[N], cur[M], pre[N], dis[M], sum[N];
	LL cap[M];
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
	LL isap(int st, int ed) {
		int n = ed + 1;
		sum[0] = n;
		for (int i = st; i <= ed; ++i)	cur[i] = head[i];
		int u = pre[st] = st;
		LL flow = 0, aug = -1;
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
}P;
bool check(LL t) {
	P.init();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (g[i][j] <= t)	P.add(i, j + n, inf);
	for (int i = 1; i <= n; ++i)	P.add(0, i, a[i]), P.add(i + n, n + n + 1, b[i]);
	LL tmp = P.isap(0, n + n + 1);
	return tmp == sum;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)	scanf("%d%d", &a[i], &b[i]), sum += a[i];
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)	
			g[i][j] = (LL)1e16;
		g[i][i] = 0;
	}
	LL l = 0, r = 0;
	while (m--) {
		int x, y;
		LL z;
		scanf("%d%d%I64d", &x, &y, &z);
		if (g[x][y] > z)	g[x][y] = g[y][x] = z;
		r += z;
	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	LL ans = -1;
	while (l <= r) {
		LL mid = l + r >> 1ll;
		if (check(mid))	ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%I64d\n", ans);
	return 0;
}

