#include <bits/stdc++.h>//Ê÷Á´ÆÊ·Ö
using namespace std;
#define ls (rt << 1)
#define rs (rt << 1 | 1)
const int N = 100005, M = N << 2;
int n, m, lcol, rcol, tot, cnt, w[N], q[N], top[N], sz[N], son[N], pre[N], id[N], dep[N], col[N], lc[M], rc[M], sum[M], mark[M], to[M], nxt[M], head[N];
bool vis[N];
inline int readInt() {
	char c;
	while (c = getchar(), c < '0' || c > '9');
	int t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	return t;
}
void add(int u, int v) {
	to[tot] = v, nxt[tot] = head[u], head[u] = tot++;
	to[tot] = u, nxt[tot] = head[v], head[v] = tot++;
}
void pushdown(int rt) {
	if (~mark[rt]) {
		lc[ls] = lc[rs] = rc[ls] = rc[rs] = mark[ls] = mark[rs] = mark[rt];
		sum[ls] = sum[rs] = 1;
		mark[rt] = -1;
	}
}
void pushup(int rt) {
	lc[rt] = lc[ls], rc[rt] = rc[rs];
	sum[rt] = sum[ls] + sum[rs] - (rc[ls] == lc[rs]);
}
void build(int rt, int l, int r) {
	mark[rt] = -1;
	if (l == r) {
		lc[rt] = rc[rt] = w[l];
		sum[rt] = 1;
		return ;
	}
	int mid = l + r >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	pushup(rt);
}
void change(int rt, int l, int r, int L, int R, int c) {
	if (L <= l && R >= r) {
		lc[rt] = rc[rt] = mark[rt] = c;
		sum[rt] = 1;
		return;
	}
	pushdown(rt);
	int mid = l + r >> 1;
	if (L <= mid)	change(ls, l, mid, L, R, c);
	if (R > mid)	change(rs, mid + 1, r, L, R, c);
	pushup(rt);
}
int ask(int rt, int l, int r, int L, int R) {
	if (L == l)	lcol = lc[rt];
	if (R == r)	rcol = rc[rt];
	if (L <= l && R >= r)	return sum[rt];
	pushdown(rt);
	int mid = l + r >> 1, t = 0, t1 = -1, t2 = -1;
	if (L <= mid)	t += ask(ls, l, mid, L, R), t1 = rc[ls];
	if (R > mid)	t += ask(rs, mid + 1, r, L, R), t2 = lc[rs];
	t -= (t1 == t2 && ~t1);
	return t;
}
void work(int a, int b, int c) {
	while (top[a] != top[b]) {
		if (dep[top[a]] < dep[top[b]])	swap(a, b);
		change(1, 1, n, id[top[a]], id[a], c);
		a = pre[top[a]];	
	}
	if (dep[a] < dep[b])	swap(a, b);
	change(1, 1, n, id[b], id[a], c);
}
int work2(int a, int b) {
	int t = 0, t1 = -1, t2 = -1;
	while (top[a] != top[b]) {
		if (dep[top[a]] < dep[top[b]])	swap(a, b), swap(t1, t2);
		t += ask(1, 1, n, id[top[a]], id[a]);
		t -= (t1 == rcol && ~t1);
		t1 = lcol;
		a = pre[top[a]];
	}
	if (dep[a] < dep[b])	swap(a, b), swap(t1, t2);
	t += ask(1, 1, n, id[b], id[a]);
	t -= ((t1 == rcol && ~t1) + (t2 == lcol && ~t2));
	return t;
}
void gao() {
	int r = 0;
	vis[dep[1] = q[0] = 1] = 1;
	for (int i = 0; i <= r; ++i)
		for (int j = head[q[i]]; ~j; j = nxt[j]) 
			if (!vis[to[j]]){
				vis[to[j]] = 1;
				dep[q[++r] = to[j]] = dep[q[i]] + 1;
				pre[q[r]] = q[i];
			}
	for (int i = r; i >= 0; --i) {
		sz[pre[q[i]]] += ++sz[q[i]];
		if (sz[son[pre[q[i]]]] < sz[q[i]])	son[pre[q[i]]] = q[i];
	}
	for (int i = 0; i <= r; ++i)
		if (!top[q[i]]) {
			for (int j = q[i]; j; j = son[j]) {
				top[j] = q[i];
				w[id[j] = ++cnt] = col[j];
			}
		}
	build(1, 1, n);
}
int main() {
	n = readInt(), m = readInt();
	memset(head, -1, sizeof(head));
	for (int i = 1; i <= n; ++i)	col[i] = readInt();
	for (int i = 1, x, y; i < n; ++i) {
		x = readInt(), y = readInt();
		add(x, y);
	}
	gao();
	while (m--) {
		char s[5];
		scanf("%s", s);
		int a, b, c;
		if (s[0] == 'C') {
			a = readInt(), b = readInt(), c = readInt();
			work(a, b, c);
		}
		else {
			a = readInt(), b = readInt();
			printf("%d\n", work2(a, b));
		}
	}
	return 0;
}
