#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 10010, M = 1e9 + 7;
int last, tot, step[N], son[N][26], par[N], cnt[N], g[N], Q[N], vis[N];
int f[5005], c[5005][5005];
char s[N];
void add(int x) {
	int p = last, np = ++tot;
	step[np] = step[p] + 1, last = np, ++g[np];//right
	for (; !son[p][x] && ~p; p = par[p])	son[p][x] = np;
	if (p == -1)	return;
	int q = son[p][x];
	if (step[q] == step[p] + 1)	par[np] = q;
	else {
		step[++tot] = step[p] + 1;
		int nq = tot;
		memcpy(son[nq], son[q], sizeof(son[q]));
		par[nq] = par[q];
		par[np] = par[q] = nq;
		for (; son[p][x] == q && ~p; p = par[p])	son[p][x] = nq;
	}
}
int main() {
	int n, q, T;
	for (int i = 0; i <= 5000; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j)	c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
	}
	scanf("%d", &T);
	while (T--) {
		memset(par, 0, sizeof(par));
		memset(son, 0, sizeof(son));
		memset(g, 0, sizeof(g));
		memset(cnt, 0, sizeof(cnt));
		memset(step, 0, sizeof(step));
		memset(f, 0, sizeof(f));
		scanf("%d%d", &n, &q);
		scanf("%s", s);
		last = tot = 0;
		par[0] = -1;
		for (int i = 0; i < n; ++i)	add(s[i] - 'a');
		for (int i = 1; i <= tot; ++i)	++cnt[step[i]];
		for (int i = 1; i <= tot; ++i)	cnt[i] += cnt[i - 1];
		for (int i = 1; i <= tot; ++i)	Q[cnt[step[i]]--] = i;
		for (int i = tot; i >= 1; --i) {
			int t = step[Q[i]] - step[par[Q[i]]];
			for (int j = 1; j <= 5000; ++j)
				if (g[Q[i]] >= j)	(f[j] += (LL)t * c[g[Q[i]]][j] % M) %= M;
			g[par[Q[i]]] += g[Q[i]];
		}
		while (q--) {
			int k;
			scanf("%d", &k);
			if (k > n)	puts("0");
			else printf("%d\n", f[k]);
		}
	}
	return 0;
}
