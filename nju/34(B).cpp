#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
const int N = 205, inf = 1e9;
char s[N][N];
vector<pair<int, int> > a, b;
int tot, S, T, p[N], fr[N * N * 2], to[N * N * 2], cap[N * N * 2], nxt[N * N * 2], w[N * N * 2], head[N], d[N];
bool vis[N];
long long ans;
void add(int u, int v, int f, int cost) {
	fr[tot] = u, to[tot] = v, cap[tot] = f, w[tot] = cost, nxt[tot] = head[u], head[u] = tot++;
	fr[tot] = v, to[tot] = u, cap[tot] = 0, w[tot] = -cost, nxt[tot] = head[v], head[v] = tot++;
}
bool spfa() {
	queue<int> q;
	for (int i = S; i <= T; ++i)	d[i] = inf;
	d[S] = 0, p[S] = -1;
	q.push(S);
	while (q.size()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (int i = head[u], v; ~i; i = nxt[i]) {
			v = to[i];
			if (cap[i] > 0 && d[u] + w[i] < d[v]) {
				d[v] = d[u] + w[i];
				p[v] = i;
				if (!vis[v])	vis[v] = 1, q.push(v);
			}
		}
	}
	return d[T] < inf;
}
void solve() {
	int flow = inf;
	for (int i = p[T]; ~i; i = p[fr[i]])	flow = min(flow, cap[i]);
	for (int i = p[T]; ~i; i = p[fr[i]])	cap[i] -= flow, cap[i ^ 1] += flow;
	ans += d[T] * flow;
}
void init() {
	ans = tot = 0;
	memset(head, -1, sizeof(head));
	memset(vis, 0, sizeof(vis));
	memset(p, 0, sizeof(p));
	a.clear(), b.clear();
}
int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) && n && m) {
		init();
		for (int i = 1; i <= n; ++i)	scanf("%s", s[i] + 1);
		for (int i = 1; i <= n; ++i) 
			for (int j = 1; j <= m; ++j) {
				if (s[i][j] == 'm')	a.pb(mp(i, j));
				else if (s[i][j] == 'H')	b.pb(mp(i, j));
			}
		S = 0, T = sz(a) + sz(b) + 1;
		for (int i = 0; i < sz(a); ++i) {
			for (int j = 0; j < sz(b); ++j) {
				int cost = abs(a[i].X - b[j].X) + abs(a[i].Y - b[j].Y);
				add(i + 1, j + sz(a) + 1, 1, cost);
			}
		}
		for (int i = 1; i <= sz(a); ++i)	add(S, i, 1, 0);
		for (int i = 1; i <= sz(b); ++i)	add(i + sz(a),  T, 1, 0);
		while (spfa())	solve();
		printf("%d\n", ans);
	}
	return 0;
}
