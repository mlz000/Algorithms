#include <bits/stdc++.h>//greedy
using namespace std;
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
const int N = 1005;
#define pb push_back
vector<int> g[N];
int n, fa[N], tot, c[N][5];
bool vis[N];
void gao() {
	int v, mx = -1;
	for (int i = 1; i <= n; ++i) {
		int t = c[i][1] + c[i][2] + c[i][3] + c[i][4];
		if (!vis[i] && t > mx) {
			v = i;
			mx = t;
		}
	}
	vis[v] = 1;
	for (int i = 1; i <= 4; ++i)
		if (!c[v][i]) {
			printf("%d %d\n", v, i);
			fflush(stdout);
			for (int j = 0; j < g[v].size(); ++j)	c[g[v][j]][i] = 1;
			break;
		}
}
int main() {
	read(n);
	for (int i = 1, u, v; i < n; ++i) {
		read(u), read(v);
		g[u].pb(v), g[v].pb(u);
	}
	while (1) {
		gao();
		int x, y;
		read(x), read(y);
		if (x == -1 && y == -1)	break;
		vis[x] = 1;
		for (int i = 0; i < g[x].size(); ++i)	c[g[x][i]][y] = 1;
	}
	return 0;
}
