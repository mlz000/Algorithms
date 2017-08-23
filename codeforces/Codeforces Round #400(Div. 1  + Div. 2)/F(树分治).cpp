#include <bits/stdc++.h>
const int N = 1e5 + 5;
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
int root, n, m, cnt, sz[N], ans[N];
vector<int> g[N], g2[N], re[N];
map<pii, int> w;
pair<vector<int>, int> pvi[N];
bool vis[N];
void gao(int x, int y) {
	int now = x;
	re[cnt].pb(x);
	w[mp(x, y)] = cnt;
	while (now != y) {
		re[cnt].pb(y);
		int k = lower_bound(g[y].begin(), g[y].end(), x) - g[y].begin();
		x = y, y = g[y][(k + 1) % g[y].size()];
		w[mp(x, y)] = cnt;
	}
	if (re[cnt].size() == n) {
		for (int i = 0; i < re[cnt].size(); ++i)	w[mp(re[cnt][i], re[cnt][(i + 1) % n])] = -1;
		re[cnt].clear();
	}
	else ++cnt;
}
void getroot(int u, int fa) {
	sz[u] = 1;
	for (int i = 0, v; i < g2[u].size(); ++i) {
		v = g2[u][i];
		if (v != fa && !vis[v]) {
			getroot(v, u);
			sz[u] += sz[v];
		}
	}
}
void fuck(int u, int dep) {
	getroot(u, 0);
	bool ok = 1;
	int now = u;
	while (ok) {
		ok = 0;
		for (int i = 0, v; i < g2[now].size(); ++i) {
			v = g2[now][i];
			if (sz[v] > sz[u] / 2 && sz[v] < sz[now]) {
				now = v;
				ok = 1;
				break;
			}
		}
	}
	vis[now] = 1, ans[now] = dep;
	for (int i = 0, v; i < g2[now].size(); ++i) {
		v = g2[now][i];
		if (!vis[v])	fuck(v, dep + 1);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	if (!m)	{
		puts("1");
		return 0;
	}
	for (int i = 0, x, y; i < m; ++i) {
		scanf("%d%d", &x, &y);
		--x, --y;
		g[x].pb(y), g[y].pb(x);
	}
	for (int i = 0; i < n; ++i)	g[i].pb((i + 1) % n), g[((i + 1) % n)].pb(i);
	for (int i = 0; i < n; ++i)	sort(g[i].begin(), g[i].end());
	for (int i = 0; i < n; ++i)
		for (int j = 0, v; j < g[i].size(); ++j) {
			v = g[i][j];
			if (!w.count(mp(i, v)))	gao(i, v);
		}
	for (int i = 0; i < cnt; ++i) {
		for (int j = 0; j < re[i].size(); ++j) {
			int t = w[mp(re[i][(j + 1) % re[i].size()], re[i][j])];
			if (~t)	g2[i + 1].pb(t + 1);//region adjacent
		}
		vector<int> tmp = re[i];
		sort(tmp.begin(), tmp.end()), reverse(tmp.begin(), tmp.end());
		for (int j = 0; j < tmp.size(); ++j)	tmp[j] = - tmp[j];
		pvi[i] = mp(tmp, i + 1);
	}
	sort(pvi, pvi + cnt), reverse(pvi, pvi + cnt);
	sz[1] = cnt;
	fuck(1, 1);
	for (int i = 0; i < cnt; ++i)	printf("%d ", ans[pvi[i].second]);
	return 0;
}
