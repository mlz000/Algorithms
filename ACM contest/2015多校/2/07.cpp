#include <bits/stdc++.h>//Segment tree
using namespace std;
#define ls (rt << 1)
#define rs (rt << 1 | 1)
typedef long long LL;
char *ch, *ch1, buf[40*1024000+5], buf1[40*1024000+5];      
void read(int &x)   {      
    for (++ch; *ch <= 32; ++ch);      
    for (x = 0; '0' <= *ch; ch++)    x = x * 10 + *ch - '0';      
}  
const int N = 1e6 + 5;
int a[N];
struct data {
	int l, r, mx, tag, cov;
	LL s;
}t[N << 2];
void up(int rt) {
	t[rt].mx = max(t[ls].mx, t[rs].mx);
	t[rt].s = t[ls].s + t[rs].s;
	t[rt].cov = t[ls].cov + t[rs].cov;
}
void maintain(int rt, int x) {
	if (t[rt].tag != 0 && t[rt].tag <= x)	return;
	t[rt].tag = x;
	if (t[rt].cov != t[rt].r - t[rt].l + 1) {
		t[rt].mx = x;
		t[rt].s += 1ll * (t[rt].r - t[rt].l + 1 - t[rt].cov) * x;
		t[rt].cov = t[rt].r - t[rt].l + 1;
	}
}
void down(int rt) {
	if (!t[rt].tag)	return;
	maintain(ls, t[rt].tag), maintain(rs, t[rt].tag);
}
void build(int rt, int l, int r) {
	t[rt].l = l, t[rt].r = r, t[rt].tag = 0;
	int mid = l + r >> 1;
	if (l == r) {
		t[rt].tag = t[rt].s = t[rt].mx = a[l];
		t[rt].cov = 1;
		return;
	}
	build(ls, l, mid), build(rs, mid + 1, r);
	up(rt);
}
void dfs(int rt, int x) {
	if (t[rt].mx <= x)	return;
	t[rt].tag = 0;
	if (t[rt].l == t[rt].r) {
		t[rt].s = t[rt].mx = t[rt].cov = 0;
		return;
	}
	dfs(ls, x), dfs(rs, x);
	up(rt);
}
void change(int rt, int l, int r, int x) {
	if (t[rt].mx <= x)	return;
	if (l <= t[rt].l && r >= t[rt].r) {
		dfs(rt, x);
		maintain(rt, x);
		return;
	}
	int mid = (t[rt].l + t[rt].r) >> 1;
	down(rt);
	if (l <= mid)	change(ls, l, r, x);
	if (r > mid)	change(rs, l, r, x);
	up(rt);
}
void query(int rt, int l, int r, LL &s, int &mx) {
	if (l <= t[rt].l && r >= t[rt].r) {
		s += t[rt].s;
		mx = max(mx, t[rt].mx);
		return;
	}
	int mid = (t[rt].l + t[rt].r) >> 1;
	down(rt);
	if (l <= mid)	query(ls, l, r, s, mx);
	if (r > mid)	query(rs, l, r, s, mx);
	up(rt);
}
int main() {
	ch = buf - 1;      
	ch1 = buf1 - 1;      
	fread(buf, 1, 1000 * 35 * 1024, stdin);  
	int T;
	read(T);
	while (T--) {
		int n, m;
		read(n), read(m);
		for (int i = 1; i <= n; ++i)	read(a[i]);
		build(1, 1, n);
		while (m--) {
			int op, x, y, t;
			read(op), read(x), read(y);
			if (!op) {
				read(t);
				change(1, x, y, t);
			}
			else {
				LL s = 0;
				int mx = 0;
				query(1, x, y, s, mx);
				if (op == 1)	cout << mx << endl;
				else cout << s << endl;
			}
		}
	}
	return 0;
}
