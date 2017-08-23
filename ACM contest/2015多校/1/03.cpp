//Dp
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#pragma comment(linker, "/STACK:1024000000,1024000000") 
typedef long long LL;
inline void read(int &t) {
    int f = 1;char c;
    while (c = getchar(), c < '0' || c > '9') if (c == '-') f = -1;
    t = c - '0';
    while (c = getchar(), c >= '0' && c <= '9') t = t * 10 + c - '0';
    t *= f;
}
const int N = 1e5 + 10, M = 105;
int mx, w[N], f[N][M], g[N][M], ff[N][M], gg[N][M], sum1[M], sum2[M];
vector<int> G[N];
void dp(int u, int fa) {
	for (int i = 0, v; i < G[u].size(); ++i) {
		v = G[u][i];
		if (v == fa)	continue;
		dp(v, u);
	}
	for (int j = 0; j <= mx + 1; ++j)	f[u][j] = g[u][j] = N, sum1[j] = sum2[j] = 0;
	int t = 0, t1 = 0, t2 = 0;
	for (int i = 0, v; i < G[u].size(); ++i) {
		v = G[u][i];
		if (v == fa)	continue;
		t += ff[v][0];
		for (int j = 0; j <= mx; ++j) {
			if (!j)	sum1[j] += ff[v][j + 1];
			else sum1[j] += min(ff[v][j + 1], gg[v][j - 1]);
			sum2[j] += min(ff[v][j], gg[v][j - 1]);
		}
	}
	f[u][w[u]] = min(f[u][w[u]], 1 + sum1[w[u]]);
	for (int i = 0, v; i < G[u].size(); ++i) {
		v = G[u][i];
		if (v == fa)	continue;
		for (int j = 0; j <= mx; ++j) {
			if (!j)	t1 = ff[v][j + 1];
			else t1 = min(ff[v][j + 1], gg[v][j - 1]), g[u][j] = min(g[u][j], g[v][j - 1] + sum2[j] - min(ff[v][j], gg[v][j - 1]));
			f[u][j] = min(f[u][j], f[v][j + 1] + sum1[j] - t1);
		}
	}
	ff[u][0] = f[u][0], gg[u][0] = g[u][0] = t;
	for (int j = 1; j <= mx + 1; ++j) {
		ff[u][j] = min(ff[u][j - 1], f[u][j]);
		gg[u][j] = min(gg[u][j - 1], g[u][j]);
	}
}
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		mx = 0;
		for (int i = 1; i <= n; ++i)	read(w[i]), mx = max(w[i], mx), G[i].clear();
		for (int i = 1, x, y; i < n; ++i) {
			read(x), read(y);
			G[x].pb(y), G[y].pb(x);
		}
		dp(1, 0);
		printf("%d\n", ff[1][mx]);
	}
	return 0;
}



