#include <bits/stdc++.h>
using namespace std;
const int N = 505, M = 500005, inf = ~0u >> 1;
int tot, type[N], to[M], cap[M], nxt[M], head[N], pre[N], cur[N], sum[N], dis[N];
map<string, int> mp;
void add(int u, int v, int w) {
	to[tot] = v, cap[tot] = w, nxt[tot] = head[u], head[u] = tot++;
	to[tot] = u, cap[tot] = 0, nxt[tot] = head[v], head[v] = tot++;
}
void init() {
	tot = 0;
	memset(pre, -1, sizeof(pre));
	memset(head, -1, sizeof(head));
	memset(cap, 0, sizeof(cap));
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
int main() {
	int n, m, k, cnt = 0;
	init();
	scanf("%d", &n);
	string x, y;
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		mp[x] = ++cnt;
		type[cnt] = 1;
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		int a, b;
		cin >> x >> y;
		mp[x] = ++cnt;
		a = cnt;
		type[cnt] = 2;
		if (!mp[y])	mp[y] = ++cnt, b = cnt, type[cnt] = 3;//mid
		else b = mp[y];
		add(a, b, 1);
	}
	scanf("%d", &k);
	for (int i = 1; i <= k; ++i) {
		cin >> x >> y;
		add(mp[x], mp[y], inf);
	}
	for (int i = 1; i <= cnt; ++i) {
		if (type[i] == 1)	add(i, n + m + k + 1, 1);
		else if (type[i] == 2)	add(0, i, 1);	
	}
	printf("%d\n", m - isap(0, n + m + k + 1));
	return 0;
}
