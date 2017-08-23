#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define ls (rt << 1)
#define rs (rt << 1 | 1)
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
const int N = 1e5 + 5, M = N << 2, P = 1e9 + 7;
int a[N], cov[M], sum[M], add[M], mul[M], len[M];
void down(int rt) {
	if (cov[rt]) {
		sum[ls] = (LL)cov[rt] * len[ls] % P, cov[ls] = cov[rt], mul[ls] = 1, add[ls] = 0;
		sum[rs] = (LL)cov[rt] * len[rs] % P, cov[rs] = cov[rt], mul[rs] = 1, add[rs] = 0;
		cov[rt] = 0;
	}
	if (mul[rt] != 1 || add[rt]) {
		sum[ls] = ((LL)sum[ls] * mul[rt] % P + (LL)len[ls] * add[rt] % P) % P;
		sum[rs] = ((LL)sum[rs] * mul[rt] % P + (LL)len[rs] * add[rt] % P) % P;
		mul[ls] = (LL)mul[rt] * mul[ls] % P;
		mul[rs] = (LL)mul[rt] * mul[rs] % P;
		add[ls] = ((LL)add[ls] * mul[rt] % P + add[rt]) % P;
		add[rs] = ((LL)add[rs] * mul[rt] % P + add[rt]) % P;
		mul[rt] = 1, add[rt] = 0;
	}
}
void up(int rt) {
	sum[rt] = (sum[ls] + sum[rs]) % P;
}
void build(int rt, int l, int r) {
	len[rt] = r - l + 1;
	mul[rt] = 1;
	if (l == r)	{
		sum[rt] = a[l];
		return ;
	}
	int mid = l + r >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	up(rt);
}
void Mul(int rt, int l, int r, int L, int R, int c) {
	if (L <= l && R >= r) {
		sum[rt] = (LL)sum[rt] * c % P;
		mul[rt] = (LL)mul[rt] * c % P;
		add[rt] = (LL)add[rt] * c % P;
		return;
	}
	down(rt);
	int mid = l + r >> 1;
	if (L <= mid)	Mul(ls, l, mid, L, R, c);
	if (R > mid)	Mul(rs, mid + 1, r, L, R, c);
	up(rt);
}
void Add(int rt, int l, int r, int L, int R, int c) {
	if (L <= l && R >= r) {
		(sum[rt] += (LL)c * len[rt] % P) %= P;
		(add[rt] += c) %= P;
		return ;
	}
	down(rt);
	int mid = l + r >> 1;
	if (L <= mid)	Add(ls, l, mid, L, R, c);
	if (R > mid)	Add(rs, mid + 1, r, L, R, c);
	up(rt);
}
void Cov(int rt, int l, int r, int L, int R, int c) {
	if (L <= l && R >= r) {
		sum[rt] = (LL)c * len[rt] % P;
		cov[rt] = c;
		mul[rt] = 1, add[rt] = 0;
		return;
	}
	down(rt);
	int mid = l + r >> 1;
	if (L <= mid)	Cov(ls, l, mid, L, R, c);
	if (R > mid)	Cov(rs, mid + 1, r, L, R, c);
	up(rt);
}
int ask(int rt, int l, int r, int L, int R) {
	if (L <= l && R >= r) {
		return sum[rt];
	}
	down(rt);
	int mid = l + r >> 1;
	int t = 0;
	if (L <= mid)	(t += ask(ls, l, mid, L, R)) %= P;
	if (R > mid)	(t += ask(rs, mid + 1, r, L, R)) %= P;
	return t;
}
int main() {
	int n, m;
	read(n), read(m);
	for (int i = 1; i <= n; ++i)	read(a[i]);
	build(1, 1, n);
	while (m--) {
		int op, l, r, c;
		read(op), read(l), read(r);
		if (op != 4)	read(c);
		c %= P;
		if (op == 1)	Add(1, 1, n, l, r, c);
		else if (op == 2)	Mul(1, 1, n, l, r, c);
		else if (op == 3)	Cov(1, 1, n, l, r, c);
		else printf("%d\n", ask(1, 1, n, l, r));
	}
	return 0;
}
