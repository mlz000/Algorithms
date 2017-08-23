#include <bits/stdc++.h>
using namespace std;
#define ls (rt << 1)
#define rs (rt << 1 | 1)
const int N = 100005;
char s[N];
int a[N], tt = 100001 << 2;
long long t[N << 5], w[N << 5], sum[N << 5], tl[N << 5][3], tr[N << 5][3];
void up(int rt, int lson, int rson) {
	w[rt] = (w[lson] + w[rson]) % 3;
	sum[rt] = sum[lson] + sum[rson];
	for (int k = 0; k < 3; ++k) {
		tl[rt][k] = tl[lson][k], tr[rt][k] = tr[rson][k];	
		sum[rt] += tr[lson][k] * tl[rson][(3 - k) % 3];
		tl[rt][k] += tl[rson][(3 + k - w[lson]) % 3];
		tr[rt][k] += tr[lson][(3 + k - w[rson]) % 3];
	}
}
void build(int rt, int l, int r) {
	if (l == r) {
		w[rt] = a[l] % 3;
		memset(tl[rt], 0, sizeof(tl[rt]));
		memset(tr[rt], 0, sizeof(tr[rt]));
		tl[rt][w[rt]] = tr[rt][w[rt]] = 1;
		sum[rt] = (!w[rt]) ? 1 : 0;
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	up(rt, ls, rs);
}
void change(int rt, int l, int r, int p, int x) {
	if (l == r) {
		w[rt] = x % 3;
		memset(tl[rt], 0, sizeof(tl[rt]));
		memset(tr[rt], 0, sizeof(tr[rt]));
		tl[rt][w[rt]] = tr[rt][w[rt]] = 1;
		sum[rt] = (!w[rt]) ? 1 : 0;
		return;
	}
	int mid = l + r >> 1;
	if (p <= mid)	change(ls, l, mid, p, x);
	else change(rs, mid + 1, r, p, x);
	up(rt, ls, rs);
}
int query(int rt, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return rt;
	}
	int mid = l + r >> 1;
	if (R <= mid) {
		return query(ls, l, mid, L, R);
	}
	else if (L > mid) {
		return query(rs, mid + 1, r, L, R);
	}
	else {
		int t1 = query(ls, l, mid, L, mid);
		int t2 = query(rs, mid + 1, r, mid + 1, R);;
		up(++tt, t1, t2);
		return tt;
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	for (int i = 1; i <= n; ++i)	a[i] = s[i - 1] - '0';
	build(1, 1, n);
	while (m--) {
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1)	change(1, 1, n, x, y);
		else printf("%lld\n", sum[query(1, 1, n, x, y)]);
	}
	return 0;
}

