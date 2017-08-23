#include <bits/stdc++.h>//×îÓÅ±êºÅ
using namespace std;
const int N = 510, M = 3510, inf = 1e7;
int n, tot, x[M], y[M], id[N], p[N], head[N], sum[N], pre[N], dis[N], cur[N];
bool vis[N];
struct data {
	int v, f, next;
}e[M << 2];
void add(int x, int y, int z) {
	e[tot].v = y, e[tot].f = z, e[tot].next = head[x], head[x] = tot++;
	e[tot].v = x, e[tot].f = 0, e[tot].next = head[y], head[y] = tot++;
}
void isap(int st, int ed) {
	memset(sum, 0, sizeof(sum));
	memset(pre, -1, sizeof(pre));
	memset(dis, 0, sizeof(dis));
	for (int i = 0; i < n; ++i)	cur[i] = head[i];
	int aug = -1;
	int u = pre[st] = st;
	bool flag;
	sum[0] = n;
	while (dis[st] < n) {
		flag = 0;
		for (int &i = cur[u]; ~i; i = e[i].next) {
			int v = e[i].v;
			if (e[i].f && dis[u] == dis[v] + 1) {
				flag = 1;
				pre[v] = u;
				u = v;
				aug = (aug == -1) ? e[i].f : min(e[i].f, aug);
				if (v == ed) {
					for (u = pre[v]; v != st; v = u, u = pre[u]) {
						e[cur[u]].f -= aug;
						e[cur[u] ^ 1].f +=aug;
					}
					aug = -1;
				}
				break;
			}
		}
		if (flag)	continue;
		int Min = n;
		for (int i = head[u]; ~i; i = e[i].next) {
			int v = e[i].v;
			if (e[i].f && Min > dis[v]) {
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
void dfs(int u, int k) {
	vis[u] = 1;
	p[u] |= 1 << k;
	for (int i = head[u]; ~i; i = e[i].next) {
		int v = e[i].v;
		if (e[i].f && !vis[v])	dfs(v, k);
	}
}
int main() {
	int m, k, T;
	scanf("%d", &T);
	while (T--) {
		memset(p, 0, sizeof(p));
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; ++i)	scanf("%d%d", &x[i], &y[i]);
		scanf("%d", &k);
		for (int i = 1, f; i <= k; ++i)	scanf("%d%d", &id[i], &f), p[id[i]] = f;
		n += 2;
		for (int i = 0; i < 31; ++i) {
			memset(head, -1, sizeof(head));
			tot = 0;
			for (int j = 1; j <= m; ++j)	add(x[j], y[j], 1), add(y[j], x[j], 1);
			for (int j = 1; j <= k; ++j) {
				if (p[id[j]] >> i & 1)	add(0, id[j], inf);
				else add(id[j], n - 1, inf);
			}
			isap(0, n - 1);
			memset(vis, 0, sizeof(vis));
			dfs(0, i);
		}
		for (int i = 1; i <= n - 2; ++i)	printf("%d\n", p[i]);
	}
	return 0;
}
