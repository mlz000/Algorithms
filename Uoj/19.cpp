#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 10005, inf = 0x3f3f3f3f;
vector<int> g[2][N];
bool vis[N], can[N];
int s, t, step[N];
queue<int> q;
void bfs1() {
	q.push(t);
	can[t] = 1;
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (int i = 0, v; i < g[0][u].size(); ++i) {
			v = g[0][u][i];
			if (!can[v]) {
				can[v] = 1;
				q.push(v);
			}
		}
	}
}
void bfs2() {
	memset(step, 0x3f3f3f3f, sizeof(step));
	int dummy = 10001;
	q.push(dummy);
	g[1][dummy].pb(s), step[dummy] = -1, vis[dummy] = 1;
	while (q.size()) {
		int u = q.front();
		q.pop();
		bool ok = 1;
		for (int i = 0, v; i < g[1][u].size(); ++i) {
			v = g[1][u][i];
			if (!can[v]) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			for (int i = 0, v; i < g[1][u].size(); ++i) {
				v = g[1][u][i];
				if (!vis[v]) {
					step[v] = step[u] + 1;
					vis[v] = 1;
					q.push(v);
				}
			}			
		}
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1, x, y; i <= m; ++i) {
		scanf("%d%d", &x, &y);
		g[1][x].pb(y);
		g[0][y].pb(x);
	}
	scanf("%d%d", &s, &t);
	bfs1();
	bfs2();
	if (step[t] == inf)	puts("-1");
	else printf("%d\n", step[t]);
	return 0;
}
