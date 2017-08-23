#include <bits/stdc++.h>//SAM
using namespace std;
const int N = 250005;
int tot, last, step[N << 1], son[N << 1][26], par[N << 1];
char a[N], b[N];
void insert(int x, int l) {
	int p = last, np = ++tot;
	step[np] = step[p] + 1, last = np;
	for (; !son[p][x] && p != -1; p = par[p])	son[p][x] = np;
	if (p == -1)	return;
	else {
		int q = son[p][x];
		if (step[q] == step[p] + 1)	par[np] = q;
		else {
			step[++tot] = step[p] + 1;
			int nq = tot;
			memcpy(son[nq], son[q], sizeof(son[q]));
			par[nq] = par[q];
			par[np] = par[q] = nq;
			for (; son[p][x] == q && p != -1; p = par[p])	son[p][x] = nq;
		}
	}
}
int main() {
	scanf("%s", a);
	int l1 = strlen(a);
	par[0] = -1;
	for (int i = 0;i < l1; ++i)	insert(a[i] - 'a', i + 1);
	scanf("%s", b);
	int l2 = strlen(b);
	int ans = 0, root = 0, now = 0;
	for (int i = 0; i < l2; ++i) {
		b[i] -= 'a';
		if (son[root][b[i]]) {
			++now;
			root = son[root][b[i]];
		}
		else {
			while (~root && !son[root][b[i]])	root = par[root];
			if (root == -1)	root = 0, now = 0;
			else {
				now = step[root] + 1;
				root = son[root][b[i]];
			}
		}
		ans = max(ans, now);
	}
	printf("%d\n", ans);
	return 0;
}
