#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
const int N = 65;
const double inf = 1e10;
vector<int> g[N];
int tot, n, m, fa[N], cir[N], num[N];
double k, p[N], c[N], f[N][N][N];
void gao(int u, int dep, int len) {
	for (int i = 0, v; i < g[u].size(); ++i) {
		v = g[u][i];
		gao(v, dep + 1, len);
	}
	for (int i = 0; i <= dep; ++i) {
		if (num[u] == len && i != 1)	continue;
		if (u != 1 && num[u] && num[u] < len  && i != (len - (tot - dep)))	continue;
		f[u][i][0] = c[u] * p[i] / (1.0 - p[len]);
		for (int j = 0, v; j < g[u].size(); ++j) {
			v = g[u][j];
			for (int k = m; k >= 0; --k) {
				if (!k)	f[u][i][k] += f[v][i + 1][k];
				else {
					double t = -inf;
					for (int l = 0; l <= k; ++l)
						f[u][i][k] = max(f[u][i][k], f[u][i][k - l] + max(f[v][i + 1][l], l ? f[v][1][l - 1] : -inf));
					f[u][i][k] = t;
				}
			}
		}
	}
}
int main() {
	read(n), read(m);
	scanf("%lf", &k);
	p[0] = 1.0;
	for (int i = 1; i <= n; ++i)	p[i] = p[i - 1] * k;
	for (int i = 1; i <= n; ++i) {
		read(fa[i]);
		if (i != 1)	g[fa[i]].pb(i);
	}
	for (int i = 1; i <= n; ++i)	scanf("%lf", &c[i]);
	cir[++tot] = 1, num[1] = 1;
	int now = fa[1];
	while (now != 1) {
		cir[++tot] = now;
		num[now] = tot;
		now = fa[now];
	}
	double ans = 0.0;
	for (int i = tot; i >= 2; --i) {//enum circle length
		for (int j = 1; j <= n; ++j)
			for (int k = 0; k <= n; ++k)
				for (int l = 0; l <= n; ++l)
					f[j][k][l] = -inf;
		gao(1, 0, i);
		ans = max(ans, f[1][0][m]);
	}
	printf("%.2lf\n", ans);
	return 0;
}
