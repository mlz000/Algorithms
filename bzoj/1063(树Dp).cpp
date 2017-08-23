#include <bits/stdc++.h>//Ê÷Dp
using namespace std;
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
const int N = 100005;
typedef long long LL;
vector<int> g[N];
#define pb push_back
int n, m, q;
LL f[N][11][3];
inline LL gao(LL x) {
	if (x && x % q == 0)	return q;
	return x % q;
}
void dfs(int u, int fa) {
	for (int i = 0; i <= 10; ++i)	f[u][i][0] = 1;
	for (int i = 0, v; i < g[u].size(); ++i) {
		v = g[u][i];
		if (v == fa)	continue;
		dfs(v, u);
		for (int j = 0; j <= 10; ++j) {
			LL t1 = gao(f[v][j][0] + f[v][j][1]);
			LL t2 = 0;
			if (j)	t2 = gao(f[v][j - 1][0] + f[v][j - 1][1] + f[v][j - 1][2]);
			f[u][j][2] = gao(f[u][j][2] * t2 + f[u][j][1] * t1);
			f[u][j][1] = gao(f[u][j][1] * t2 + f[u][j][0] * t1);
			f[u][j][0] = gao(f[u][j][0] * t2);
		}
	}
}
int main() {
	read(n), read(m), read(q);
	for (int i = 1, u, v; i <= m; ++i) {
		read(u), read(v);
		g[u].pb(v), g[v].pb(u);
	}
	if (m != n - 1)	puts("-1"), puts("-1");
	else {
		dfs(1, 0);
		for (int i = 0; i <= 10; ++i) {
			LL t = f[1][i][0] + f[1][i][1] + f[1][i][2];
			if (t > 0) {
				printf("%d\n", i);
				printf("%lld\n", t % q);
				break;
			}
		}
	}
	return 0;
}
