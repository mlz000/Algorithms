#include <bits/stdc++.h>//Ê÷Á´ÆÊ·Ö
using namespace std;
#define ls (rt << 1)
#define rs (rt << 1 | 1)
const int N = 100005;
int n, Q, tot, cnt, to[N << 1], nxt[N << 1], head[N], q[N], num[N], sz[N], top[N], dep[N], pre[N], son[N], id[N], w[N << 2], f[N << 2];
bool vis[N];
inline int read(int &t) {
	int ff = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	ff = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= ff;
}
void add(int u, int v) {
	to[tot] = v, nxt[tot] = head[u], head[u] = tot++;
	to[tot] = u, nxt[tot] = head[v], head[v] = tot++;
}
void up(int rt) {
	if (w[ls])	w[rt] = w[ls], f[rt] = f[ls];
	else w[rt] = w[rs], f[rt] = f[rs];
}
void change(int rt, int l, int r, int p) {
	if (l == r) {
		w[rt] ^= 1;
		if (w[rt])	f[rt] = num[l];
		else f[rt] = 0;
		return;
	}
	int mid = l + r >> 1;
	if (p <= mid)	change(ls, l, mid, p);
	else change(rs, mid + 1, r, p);
	up(rt);
}
int query(int rt, int l, int r, int L, int R) {
	if (!w[rt])	return 0;
	if (L <= l && R >= r)	return f[rt];
	int mid = l + r >> 1;
	if (R <= mid)	return query(ls, l, mid, L, R);
	else if (L > mid)	return query(rs, mid + 1, r, L, R);
	else {
		int t = query(ls, l, mid, L, R);
		if (t)	return t;
		return query(rs, mid + 1, r, L, R);
	}
}
int ask(int a, int b) {
	int ans = -1;
	while (top[a] != top[b]) {
		if (dep[top[a]] < dep[top[b]])	swap(a, b);
		int t = query(1, 1, n, id[top[a]], id[a]);
		if (t)	ans = t;
		a = pre[top[a]];
	}
	if (dep[a] > dep[b])	swap(a, b);
	int t = query(1, 1, n, id[a], id[b]);
	if (t)	ans = t;
	return ans;
}
void init() {
	memset(head, -1, sizeof(head));
	read(n), read(Q);
	for (int i = 1, x, y; i < n; ++i) {
		scanf("%d%d", &x, &y);
		add(x, y);
	}
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
				num[id[j] = ++cnt] = j;
			}
		}
}
void gao() {
	int op, x;
	for (int i = 1; i <= Q; ++i) {
		read(op), read(x);
		if (!op)	change(1, 1, n, id[x]);
		else	printf("%d\n",ask(1, x));
	}
}
int main() {
	init();
	gao();
	return 0;
}
