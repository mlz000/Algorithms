#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1005;
vector <int> g[N];
queue <int> q;
bool vis[N];
int n, s, ind, d[N], f[N];
void init() {
	ind = 0;
	while(q.size()) q.pop();
	memset(f, -1, sizeof(f));
	memset(d, 0, sizeof(d));
	memset(vis, 0, sizeof(vis));
}
void bfs() {
	q.push(s);
	d[s] = 0, vis[s] = 1;
	while(q.size()) {
		int u = q.front();
		q.pop();
		for (int i = 0, v; i < g[u].size(); ++i) {
			v = g[u][i];
			if (!vis[v]) {
				d[v] = d[u] + 1;
				vis[v] = 1;
				f[v] = u;
				q.push(v);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ", i);
		if (d[i] == 0 && i != s)	printf("9999 %d\n", f[i]);
		else printf("%d %d\n", d[i], f[i]);
	}
}
void dfs(int u){
	if (vis[u])	return;
	d[u] = ++ind;
	vis[u] = 1;
	for (int i = 0, v; i < g[u].size(); ++i) {
		v = g[u][i];
		if (!vis[v])	dfs(v);
	}
	f[u] = ++ind;
}
int main() {
	while(scanf("%d%d", &n, &s) != EOF) {
		init();
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			for (int j = 0, x; j < n; ++j) {
				scanf("%d", &x);
				if (x)	g[i].push_back(j);
			}
		}
		bfs();
		init();
		for (int i = 0; i < n; ++i)	dfs(i);
		for (int i = 0; i < n; ++i)	printf("%d %d %d\n", i, d[i], f[i]);
	}
	return 0;
}
