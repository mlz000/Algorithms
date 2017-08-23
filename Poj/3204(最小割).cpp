#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 505;
bool v1[N], v2[N];
int n, m;
struct Maxflow {
	int tot, to[N * N], nxt[N * N], cap[N * N << 1], head[N << 1],  cur[N << 1], pre[N << 1], dis[N * N], sum[N << 1];
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
	int isap(int st, int ed) {
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
		return flow;
	}
	void dfs1(int u) {
		v1[u] = 1;
		for (int i = head[u]; ~i; i = nxt[i]) {
			int v = to[i];
			if (!v1[v] && cap[i])	dfs1(v);
		}
	}
	void dfs2(int u) {
		v2[u] = 1;
		for (int i = head[u]; ~i; i = nxt[i]) {
			int v = to[i];
			if (!v2[v] && cap[i ^ 1])	dfs2(v);
		}
	}
	int gao() {
		int t = 0;
		for (int i = 0; i < tot; i += 2)
			if (v2[to[i]] && v1[to[i ^ 1]])	++t;
		return t;
	}
}P;
int main() {
	P.init();
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v, w; i <= m; ++i) {
		scanf("%d%d%d", &u, &v, &w);
		++u, ++v;
		P.add(u, v, w);
	}
	P.isap(1, n);
	P.dfs1(1);
	P.dfs2(n);
	int ans = P.gao();
	printf("%d\n", ans);
	return 0;
}
