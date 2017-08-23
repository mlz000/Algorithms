#include <bits/stdc++.h>//À¨ºÅĞòÁĞ ²ÜÇÕÏè
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;
const int N = 100010, inf = 1e9;
int n, q, tot, cnt, dfn[N * 3], to[N << 1], nxt[N << 1], head[N], pos[N], cc[N];
struct Node {
	int l, r, l1, r1, l2, r2, c1, c2, dis;
	void init(int x) {
		dis = -inf;
		c1 = c2 = 0;
		if (dfn[x] == -2)	c2 = 1;//(
		if (dfn[x] == -5)	c1 = 1;//)
		if (dfn[x] > 0 && !cc[dfn[x]])	l1 = r1 = l2 = r2 = 0;
		else l1 = r1 = l2 = r2 = -inf;
	}
}a[N * 12];
inline int read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
void add(int u, int v) {
	to[tot] = v, nxt[tot] = head[u], head[u] = tot++;
	to[tot] = u, nxt[tot] = head[v], head[v] = tot++;
}
void dfs(int u, int fa) {
	dfn[++cnt] = -2;//
	dfn[++cnt] = u; 
	pos[u] = cnt;
	for (int i = head[u], v; ~i; i = nxt[i]) {
		v = to[i];
		if (v != fa)	dfs(v, u);
	}
	dfn[++cnt] = -5;//)
}
Node merge(Node a, Node b) {
	Node c;
	c.l = a.l, c.r = b.r;
	c.dis = max(a.dis, b.dis);
	c.dis = max(c.dis, max(a.r2 + b.l1, a.r1 + b.l2));
	if (b.c1 < a.c2)	c.c1 = a.c1, c.c2 = a.c2 - b.c1 + b.c2;
	else c.c1 = a.c1 + b.c1 - a.c2, c.c2 = b.c2;
	c.l1 = max(a.l1, max(b.l1 + a.c1 - a.c2, b.l2 + a.c1 + a.c2));
	c.r1 = max(b.r1, max(a.r1 - b.c1 + b.c2, a.r2 + b.c1 + b.c2));
	c.l2 = max(a.l2, b.l2 + a.c2 - a.c1);
	c.r2 = max(b.r2, a.r2 + b.c1 - b.c2);
	return c;
}
void change(int rt, int p) {
	if (a[rt].l == a[rt].r) {
		a[rt].init(a[rt].l);
		return;
	}
	int mid = a[rt].l + a[rt].r >> 1;
	if (p <= mid)	change(ls, p);
	else change(rs, p);
	a[rt] = merge(a[ls], a[rs]);
}
void build(int rt, int l, int r) {
	if (l == r) {
		a[rt].l = l, a[rt].r = r;
		a[rt].init(l);
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	a[rt] = merge(a[ls], a[rs]);
}
int main() {
	memset(head, -1, sizeof(head));
	read(n);
	int now = n;
	for (int i = 1, x, y; i < n; ++i) {
		read(x), read(y);
		add(x, y);
	}
	dfs(1, 0);
	build(1, 1, cnt);
	read(q);
	while (q--) {
		char s[10];
		int x;
		scanf("%s", s);
		if (s[0] == 'C') {
			read(x);
			if (!cc[x])	--now;
			else ++now;
			cc[x] ^= 1;
			change(1, pos[x]);
		}	
		else {
			if (!now)	puts("-1");
			else if (now == 1)	puts("0");
			else printf("%d\n", a[1].dis);
		}
	}
	return 0;
}
