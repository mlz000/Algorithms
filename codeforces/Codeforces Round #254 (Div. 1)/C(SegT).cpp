#include <bits/stdc++.h>
using namespace std;
#define ls (rt << 1)
#define rs (rt << 1 | 1)
const int N = (int)1e5 + 5;
long long add[N << 2], sum[N << 2], color[N << 2];
int n, m;
void down(int rt, int len) {
	if (add[rt]) {
		add[ls] += add[rt];
		add[rs] += add[rt];
		sum[ls] += add[rt] * (len - (len >> 1));
		sum[rs] += add[rt] * (len >> 1);
		add[rt] = 0;
		color[ls] = color[rs] = color[rt];
		color[rt] = 0;
	}
}
void build(int rt, int l, int r) {
	if (l == r) {
		color[rt] = l;
		return;
	}
	int mid = (l + r) >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
}
void modify(int rt, int l, int r, int L, int R, int x) {
	if (L <= l && r <= R && color[rt]) {
		add[rt] += abs(color[rt] - x);
		sum[rt] += (r - l + 1) * abs(color[rt] - x);
		color[rt] = x;
		return;
	}
	down(rt, r - l + 1);
	int mid = (l + r) >> 1;
	if (L <= mid)	modify(ls, l, mid , L, R, x);
	if (mid < R)	modify(rs, mid + 1, r, L, R, x);
	color[rt] = (color[ls] == color[rs]) ? color[ls] : 0;
	sum[rt] = sum[ls] + sum[rs];
}
long long query(int rt, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return sum[rt];
	}
	down(rt, r - l + 1);
	long long t = 0ll;
	int mid = (l + r) >> 1;
	if (L <= mid)	t += query(ls, l, mid, L, R);
	if (mid < R)	t += query(rs, mid + 1, r, L, R);
	return t;
}
int main() {
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	while (m--) {
		int op, l, r, x;
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d%d", &l, &r, &x);
			modify(1, 1, n, l, r, x);
		}
		else {
			scanf("%d%d", &l, &r);
			printf("%I64d\n", query(1, 1, n, l, r));
		}
	}
	return 0;
}
