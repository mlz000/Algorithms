#include <bits/stdc++.h>
using namespace std;
const int N = 500005 * 2, M = 26;
struct SAM {
	int tot, last, step[N], g[N], par[N], son[N][M], cnt[N], Q[N], ch[N], f[N];
	void init() {
		tot = last = 0;
		memset(par, 0, sizeof(par));
		par[0] = -1;
		memset(son, 0, sizeof(son));
	}
	void add(int x) {
		int p = last, np = ++tot;
		step[np] = step[p] + 1, last = np, ++g[np];//right
		ch[np] = x;
		for (; !son[p][x] && ~p; p = par[p])	son[p][x] = np;
		if (p == -1)	return;
		int q = son[p][x];
		if (step[q] == step[p] + 1)	par[np] = q;
		else {
			step[++tot] = step[p] + 1;
			ch[tot] = x;
			int nq = tot;
			memcpy(son[nq], son[q], sizeof(son[q]));
			par[nq] = par[q];
			par[np] = par[q] = nq;
			for (; son[p][x] == q && ~p; p = par[p])	son[p][x] = nq;
		}
	}
	void topo() {
		for (int i = 1; i <= tot; ++i)    ++cnt[step[i]];
		for (int i = 1; i <= tot; ++i)    cnt[i] += cnt[i - 1];
		for (int i = 1; i <= tot; ++i)    Q[cnt[step[i]]--] = i;		
	}
	void gao(int t) {
		for (int i = tot; i >= 0; --i) {
			if(t == 0)	g[Q[i]] = 1;
			else g[par[Q[i]]] += g[Q[i]];
			f[Q[i]] = g[Q[i]];
			for (int j = 0; j < 26; ++j)
				f[Q[i]] += f[son[Q[i]][j]];
		}
	}
}S;
char s[N];
int main() {
	scanf("%s", s);
	S.init();
	int l = strlen(s);
	for (int i = 0; i < l; ++i)	S.add(s[i] - 'a');
	S.topo();
	int t, k;
	scanf("%d%d", &t, &k);
	S.gao(t);
	int rt = 0, sum = 0;
	for (int i = 0; i < 26; ++i)
		sum += S.f[S.son[0][i]];
	if (k > sum)	puts("-1");
	else {
		while (k) {
			for (int i = 0; i < 26; ++i)
				if (S.son[rt][i]) {
					if (S.f[S.son[rt][i]] >= k) {
						printf("%c", 'a' + i);
						k -= S.g[S.son[rt][i]];
						rt = S.son[rt][i];
						break;
					}
					else k -= S.f[S.son[rt][i]];
				}
		}
	}
	return 0;
}
