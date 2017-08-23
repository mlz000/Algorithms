#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
const int N = 210, M = 1e5 + 5;
int cnt, tot, a[N], p[M];
bool check[M], vis[N];
vector<int> g[N], path[N];
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
}P;
void init() {
	for (int i = 2; i <= 1e5; ++i) {
		if (!check[i])	p[++tot] = i;
		for (int j = 1; j <= tot && (LL)p[j] * i <= 1e5; ++j) {
			check[p[j] * i] = 1;
			if (i % p[j] == 0)	break;
		}
	}
}
void dfs(int u) {
	vis[u] = 1, path[cnt].pb(u);
	for (int i = 0, v; i < g[u].size(); ++i) {
		v = g[u][i];
		if (!vis[v])	dfs(v);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	init();
	for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]);
	int st = 0, ed = n + 1;
	P.init();
	for (int i = 1; i <= n; ++i) {
		if (a[i] & 1)	P.add(st, i, 2);
		else P.add(i, ed, 2);
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) 
			if (!check[a[i] + a[j]] && (a[i] & 1))	P.add(i, j, 1);
	int ans = P.isap(st, ed);
	if (ans != n)	puts("Impossible");
	else {
		for (int i = 1; i <= n; ++i)
			if (a[i] & 1) {
				for (int j = P.head[i]; j; j = P.nxt[j]) {
					int v = P.to[j];
					if (P.cap[j] == 0 && v >= 1 && v <= n) {
					//	printf("XX%d %d\n", i, v);
						g[i].pb(v), g[v].pb(i);
					}
				}
			}
		for (int i = 1; i <= n; ++i) {
			if (!vis[i]) {
				dfs(i);
				++cnt;
			}
		}
		printf("%d\n", cnt);
		for (int i = 0; i < cnt; ++i) {
			printf("%d ", path[i].size());
			for (int j = 0; j < path[i].size(); ++j)	printf("%d ", path[i][j]);
			puts("");
		}
	}
	return 0;
}
