#include <bits/stdc++.h>//SAM
using namespace std;
const int N = 100005;
int tot, last, q[N << 1], cnt[N << 1], mx[N << 1], mn[N << 1], step[N << 1], son[N << 1][26], par[N << 1];
char s[N];
void insert(int x, int l) {
	int p = last, np = ++tot;
	step[np] = mn[np] = step[p] + 1, last = np;
	for (; !son[p][x] && p != -1; p = par[p])	son[p][x] = np;
	if (p == -1)	return;
	else {
		int q = son[p][x];
		if (step[q] == step[p] + 1)	par[np] = q;
		else {
			step[++tot] = mn[tot] = step[p] + 1;
			int nq = tot;
			memcpy(son[nq], son[q], sizeof(son[q]));
			par[nq] = par[q];
			par[np] = par[q] = nq;
			for (; son[p][x] == q && p != -1; p = par[p])	son[p][x] = nq;
		}
	}
}
int main() {
	scanf("%s", s);
	int l = strlen(s), ans = 0;
	par[0] = -1;
	for (int i = 0;i < l; ++i)	insert(s[i] - 'a', i + 1);
	for (int i = 1; i <= tot; ++i)	++cnt[step[i]];
	for (int i = 1; i <= tot; ++i)	cnt[i] += cnt[i - 1];
	for (int i = 1; i <= tot; ++i)	q[cnt[step[i]]--] = i;
	while (~scanf("%s", s)) {
		int root = 0;
		l = strlen(s);
		for (int i = 0, now = 0; i < l; ++i) {
			int c = s[i] - 'a';
			if (son[root][c])	++now, root = son[root][c];
			else {
				while (~root && !son[root][c])	root = par[root];
				if (root == -1)	now = 0, root = 0;
				else now = step[root] + 1, root = son[root][c];
			}
			if (now > mx[root])	mx[root] = now;
		}
		for (int i = tot; i >= 1; --i) {
			int t = q[i];
			if (mx[t] < mn[t])	mn[t] = mx[t];
			if (mx[par[t]] < mx[t])	mx[par[t]] = mx[t];
			mx[t] = 0;
		}
	}
	for (int i = 1; i <= tot; ++i)	ans = max(ans, mn[i]);
	printf("%d\n", ans);
	return 0;
}
