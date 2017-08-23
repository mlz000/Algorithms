#include <bits/stdc++.h>//SAM
using namespace std;
const int N = (int)2e6 + 5;
int hashtime, last, tot, step[N], son[N][26], par[N], cnt[N], g[N], Q[N], vis[N];
char s[N >> 1];
void add(int x, int l) {
	int p = last, np = ++tot;
	step[np] = l, last = np, ++g[np];//right
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
int gao() {
	int l = strlen(s), t = 0;
	++hashtime;
	for (int i = 0; i < l; ++i)	s[i + l] = s[i];
	l <<= 1;
	for (int i = 0, rt = 0, mx = 0; i < l; ++i) {
		int c = s[i] - 'a';
		while (~rt && !son[rt][c])	rt = par[rt];
		if (rt == -1)	mx = 0, rt = 0;
		else {
			mx = min(mx, step[rt]) + 1;
			rt = son[rt][c];
		}
		while (step[par[rt]] >= l / 2)	rt = par[rt], mx = step[rt];
		if (mx >= l / 2 && vis[rt] != hashtime) {
			t += g[rt];
			vis[rt] = hashtime;
		}
	}
	return t;
}
int main() {
	int n;
	par[0] = -1;
	scanf("%s", s); 
	for (int i = 0; s[i]; ++i)	add(s[i] - 'a', i + 1);
	for (int i = 1; i <= tot; ++i)	++cnt[step[i]];
	for (int i = 1; i <= tot; ++i)	cnt[i] += cnt[i - 1];
	for (int i = 1; i <= tot; ++i)	Q[cnt[step[i]]--] = i;
	for (int i = tot; i >= 1; --i)	g[par[Q[i]]] += g[Q[i]];
	scanf("%d", &n);
	while (n--) {
		scanf("%s", s);
		printf("%d\n", gao());
	}
	return 0;
}
