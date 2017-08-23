#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1005;
vector<int> v, g1[N], g2[N];
int mp[N], ans[N], a[N][N], head[N], nxt[N * N], to[N * N], col[N], vis[N], tot, f[N][N], g[N][N];
bool flag;
inline void read(int &t) {
    int f = 1;char c;
    while (c = getchar(), c < '0' || c > '9') if (c == '-') f = -1;
    t = c - '0';
    while (c = getchar(), c >= '0' && c <= '9') t = t * 10 + c - '0';
    t *= f;
}
void add(int x, int y) {
	to[tot] = y, nxt[tot] = head[x], head[x] = tot++;
}
void dfs(int x, int f) {
	col[x] = f;
	vis[x] = 1;
	if (!flag) return;
	for (int i = head[x]; ~i; i = nxt[i]) {
		int y = to[i];
		if (vis[y]) {
			if (col[y] == f) {
				flag = 0;
				return;
			}
		}
		else	dfs(y, 3 - f);
	}
}
int main() {
	int n, T;
	read(T);
	for (int tt = 1; tt <= T; ++tt) {
		read(n);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) 
				read(a[i][j]);
		tot = 0;
		int t = 0;
		flag = 1;
		for (int i = 0; i <= n; ++i)
			for (int j = 0; j <= n; ++j)	
				f[i][j] = g[i][j] = 0;
		memset(head, -1, sizeof(head));
		memset(vis, 0, sizeof(vis));
		memset(col, 0, sizeof(col));
		v.clear();
		for (int i = 1; i <= 1000; ++i) g1[i].clear(), g2[i].clear();
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (a[i][j])	add(i, j);
		dfs(1, 1);
		for (int i = 1; i <= n; ++i)
			if (col[i] == 1) v.pb(i);
		for (int i = 2; i <= n; ++i) {
			if (vis[i])	continue;
			memset(col, 0, sizeof(col));
			dfs(i, 1);
			if (!flag) break;//can
			++t;
			for (int j = 1; j <= n; ++j) { 
				if (col[j] == 1) g1[t].pb(j);
				else if (col[j] == 2) g2[t].pb(j);
			}
		}
		f[0][v.size()] = 1;
		for (int i = 1; i <= t; ++i)
			for (int j = 1; j <= n; ++j) {
				if (j >= g1[i].size() && f[i - 1][j - g1[i].size()]) {
					f[i][j] = 1;
					g[i][j] = 1;
				}
				if (j >= g2[i].size() && f[i - 1][j - g2[i].size()]) {
					f[i][j] = 1;
					g[i][j] = 2;
				}
			}
		if (flag) {
			int Min = 1e7, ansx;
			for (int i = 1; i <= n; ++i) {
				if (!f[t][i]) continue;
				if (abs(i - n / 2) < Min){
					Min = abs(i - n / 2);
					ansx = i;
				}
			}
			for (int i = t; i >= 1; --i) {
				if (g[i][ansx] == 1) {
					for (int j = 0; j < g1[i].size(); ++j) v.pb(g1[i][j]);
					ansx -= g1[i].size();
				}
				else {
					for (int j = 0; j < g2[i].size(); ++j) v.pb(g2[i][j]);
					ansx -= g2[i].size();
				}
			}
		}
		if (!flag) puts("-1");
		else {
			for (int i = 1; i <= n; ++i) mp[i] = 1;
			for (int i = 0; i < v.size(); ++i) mp[v[i]] = 0;
			ans[1] = 0;
			for (int i = 2; i <= n; ++i) ans[i] = mp[i];
			for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
			puts("");
		}
	}
	return 0;
}

