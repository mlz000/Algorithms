#include <bits/stdc++.h>//ÀëÏßdfsĞò
using namespace std;
typedef long long LL;
#define ls (rt << 1)
#define rs (rt << 1 | 1)
const int N = 300005, inf = ~0u >> 1;
int n, q, cnt, a[N], f[N], w[N], dfn[N], nxt[N], tail[N], add[N << 2], mx[N << 2];
struct data {
	int op, x, y;
}Q[N];
inline int read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
void down(int rt) {
	if (add[rt]) {
		add[ls] += add[rt], add[rs] += add[rt];
		mx[ls] += add[rt], mx[rs] += add[rt];
		add[rt] = 0;
	}
}
void up(int rt) {
	mx[rt] = max(mx[ls], mx[rs]);
}
void change(int rt, int l, int r, int L, int R, int c) {
	if (L <= l && R >= r) {
		add[rt] += c;
		mx[rt] += c;
		return;
	}
	down(rt);
	int mid = l + r >> 1;
	if (L <= mid)	change(ls, l, mid, L, R, c);
	if (R > mid)	change(rs, mid + 1, r, L, R, c);
	up(rt);
}
void build(int rt, int l, int r) {
	if (l == r) {
		mx[rt] = w[l];
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	up(rt);
}
int ask(int rt, int l, int r, int L, int R) {
	if (L <= l && R >= r)	return mx[rt];
	down(rt);
	int mid = l + r >> 1;
	int t = -inf;
	if (L <= mid)	t = max(t, ask(ls, l, mid, L, R));
	if (R > mid)	t = max(t, ask(rs, mid + 1, r, L, R));
	return t;
}
void init() {
	read(n);
	for (int i = 1; i <= n; ++i)	read(a[i]);
	read(q);
	for (int i = 1; i <= n; ++i)	f[i] = tail[i] = i;
	for (int i = 1; i <= q; ++i) {
		char s[2];
		int x, y;
		scanf("%s", s);
		if (s[0] == 'U') {
			Q[i].op = 1;
			read(Q[i].x), read(Q[i].y);
			int fx = find(Q[i].x), fy = find(Q[i].y);
			if (fx != fy) {
				f[fx] = fy;
				nxt[tail[fy]] = fx, tail[fy] = tail[fx];
			}
		}
		else if (s[0] == 'A') {
			if (s[1] == '1') Q[i].op = 2, read(Q[i].x), read(Q[i].y);
			else if (s[1] == '2')	Q[i].op = 3, read(Q[i].x), read(Q[i].y);
			else Q[i].op = 4, read(Q[i].x);
		}
		else {
			if (s[1] == '1') Q[i].op = 5, read(Q[i].x);
			else if (s[1] == '2')	Q[i].op = 6, read(Q[i].x);
			else Q[i].op = 7;
		}
	}
	for (int i = 1; i <= n; ++i)
		if (find(i) == i) {
			for (int j = i; j; j = nxt[j]) {
				dfn[j] = ++cnt;
				w[cnt] = a[j];
			}
		}
	build(1, 1, n);
	for (int i = 1; i <= n; ++i)	f[i] = tail[i] = i, nxt[i] = 0;
}
void gao() {
	for (int i = 1; i <= q; ++i) {
		if (Q[i].op == 1) {
			int fx = find(Q[i].x), fy = find(Q[i].y);
			if (fx != fy) {
				f[fx] = fy;
				nxt[tail[fy]] = fx, tail[fy] = tail[fx];
			}
		}
		else if (Q[i].op == 2)	change(1, 1, n, dfn[Q[i].x], dfn[Q[i].x], Q[i].y);
		else if (Q[i].op == 3)	{
			int fx = find(Q[i].x);
			change(1, 1, n, dfn[fx], dfn[tail[fx]], Q[i].y);
		}
		else if (Q[i].op == 4)	change(1, 1, n, 1, n, Q[i].x);
		else if (Q[i].op == 5)	printf("%d\n", ask(1, 1, n, dfn[Q[i].x], dfn[Q[i].x]));
		else if (Q[i].op == 6) {
			int fx = find(Q[i].x);
			printf("%d\n", ask(1, 1, n, dfn[fx], dfn[tail[fx]]));
		}
		else printf("%d\n", ask(1, 1, n, 1, n));
	}
}
int main() {
	init();
	gao();
	return 0;
}
