#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 105;
int n, m, d[N];
bool vis[N];
#define F first
#define S second
pair<int, int> a[1005];
struct Maxflow {
	int tot, to[N * N], nxt[N * N], head[N << 1],  cur[N << 1], pre[N << 1], dis[N * N], sum[N << 1];
	double cap[N * N << 1];
	void add(int u, int v, double w) {
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
	double isap(int st, int ed) {
		int n = ed + 1;
		sum[0] = n;
		for (int i = st; i <= ed; ++i)	cur[i] = head[i];
		int u = pre[st] = st;
		double flow = 0, aug = -1;
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
	void build(double g) {
		init();
		for (int i = 1; i <= n; ++i)	add(0, i, m), add(i, n + 1, 2.0 * g + m - d[i]);
		for (int i = 1; i <= m; ++i)	add(a[i].F, a[i].S, 1.0), add(a[i].S, a[i].F, 1.0);
	}
	void dfs(int u) {
		vis[u] = 1;
		for (int i = head[u]; ~i; i = nxt[i]) {
			int v = to[i];
			if (cap[i] > 1e-6 && !vis[v])	dfs(v);
		}
	}
}P;
int main() {
	while (~scanf("%d%d", &n, &m)) {
		if(m == 0) {
			puts("1\n1\n"); 
			continue; 
		}
		memset(d, 0, sizeof(d));
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d", &a[i].F, &a[i].S);
			++d[a[i].F], ++d[a[i].S];
		}
		double r = m, l = 1.0 / n;
		while (r - l >= 1.0 / (n * n)) {
			double mid = (l + r) * 0.5;
			P.build(mid);
			double c = P.isap(0, n + 1);
			double t = (double)(m * n - c) / 2.0;
			if (t > 1e-6)	l = mid;
			else r = mid;
		}
		P.build(l);
		P.isap(0, n + 1);
		P.dfs(0);
		int ans = 0;
		for (int i = 1; i <= n; ++i)	
			if (vis[i])	++ans;
		printf("%d\n", ans);
		for (int i = 1; i <= n; ++i)
			if (vis[i])	printf("%d\n", i);
	}
	return 0;
}
