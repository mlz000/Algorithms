#include <bits/stdc++.h>
using namespace std;
const int N = 60, M = 1e5 + 5;
#define ls (rt << 1)
#define rs (rt << 1 | 1)
int tree[M << 2][N];
void up(int rt) {
	for (int i = 0; i < N; ++i) {
		int t = tree[ls][i];
		tree[rt][i] = t + tree[rs][(i + t) % 60];
	}
}
void modify(int rt, int l, int r, int p, int x) {
	if (l == r) {
		for (int i = 0; i < N; ++i) {
			if (0 == i % x)	tree[rt][i] = 2;
			else tree[rt][i] = 1;
		}
		return;
	}
	int mid = l + r >> 1;
	if (p <= mid)	modify(ls, l, mid, p, x);
	else modify(rs, mid + 1, r, p, x);
	up(rt);
}
int ask(int t, int rt, int l, int r, int L, int R) {
	if (L <= l && r <= R)	return t + tree[rt][t % 60];
	int mid = l + r >> 1;
	if (L <= mid)	t = ask(t, ls, l, mid, L, R);
	if (R > mid)	t = ask(t, rs, mid + 1, r, L, R);
	return t;
}
int main() {
	int n, q, x, y;
	char op[5];
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &x);
		modify(1, 1, n, i, x);
	}
	scanf("%d", &q);
	while (q--) {
		scanf("%s%d%d", op, &x, &y);
		if (op[0] == 'A')	printf("%d\n", ask(0, 1, 1, n, x, y - 1));
		else modify(1, 1, n, x, y);
	}
	return 0;
}
