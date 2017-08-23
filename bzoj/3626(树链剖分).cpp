#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ls (rt << 1)
#define rs (rt << 1 | 1)
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
const int N = 50010, M = 201314;
int n, qq, tot, cnt, z[N], ans[N][2], to[N << 1], nxt[N << 1], dep[N], id[N], head[N], q[N], sz[N], son[N], top[N], vis[N], pre[N];
int sum[N << 2], tag[N << 2], s[N << 2];
struct data {
	int p, id, f;
}a[N << 1];
void add(int u, int v) {
	to[tot] = v, nxt[tot] = head[u], head[u] = tot++;
}
bool cmp(const data &a, const data &b) {
	return a.p < b.p;
}
void down(int rt) {
	tag[ls] += tag[rt], (sum[ls] += tag[rt] * s[ls]) %= M;
	tag[rs] += tag[rt], (sum[rs] += tag[rt] * s[rs]) %= M;
	tag[rt] = 0;
}
void up(int rt) {
	sum[rt] = (sum[ls] + sum[rs]) % M;
}
void build(int rt, int l, int r) {
	if (l == r) {
		sum[rt] = tag[rt] = 0;
		s[rt] = r - l + 1;
		return ;
	}
	int mid = l + r >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	up(rt);
	s[rt] = s[ls] + s[rs];
}
void change(int rt, int l, int r, int L, int R) {
	if (L <= l && R >= r) {
		++tag[rt];
		(sum[rt] += s[rt]) %= M;
		return ;
	}
	down(rt);
	int mid = l + r >> 1;
	if (L <= mid)	change(ls, l, mid, L, R);
	if (R > mid)	change(rs, mid + 1, r, L, R);
	up(rt);
}
int ask(int rt, int l, int r, int L, int R) {
	if (L <= l && R >= r) {
		return sum[rt];
	}
	down(rt);
	int mid = l + r >> 1;
	int t = 0;
	if (L <= mid)	(t += ask(ls, l, mid, L, R)) % M;
	if (R > mid)	(t += ask(rs, mid + 1, r, L, R)) % M;
	return t;
}
void gao1(int a, int b) {
	while (top[a] != top[b]) {
		if (dep[top[a]] < dep[top[b]])	swap(a, b);
		change(1, 1, n, id[top[a]], id[a]);
		a = pre[top[a]];
	}
	if (dep[a] < dep[b])	swap(a, b);
	change(1, 1, n, id[b], id[a]);
}
int gao2(int a, int b) {
	int t = 0;
	while (top[a] != top[b]) {
		if (dep[top[a]] < dep[top[b]])	swap(a, b);
		(t += ask(1, 1, n, id[top[a]], id[a])) %= M;
		a = pre[top[a]];
	}
	if (dep[a] < dep[b])	swap(a, b);
	(t += ask(1, 1, n, id[b], id[a])) %= M;
	return t;
}
void init() {
	int r = 0;
	vis[q[0] = dep[1] = 1] = 1;
	for (int i = 0; i <= r; ++i)
		for (int j = head[q[i]]; ~j; j = nxt[j]) {
			if (!vis[to[j]]) {
				vis[to[j]] = 1;
				dep[q[++r] = to[j]] = dep[q[i]] + 1;
				pre[q[r]] = q[i];
			}
		}
	for (int i = r; i >= 0; --i) {
		sz[pre[q[i]]] += ++sz[q[i]];
		if (sz[son[pre[q[i]]]] < sz[q[i]])	son[pre[q[i]]] = q[i];
	}
	for (int i = 0; i <= r; ++i)
		if (!top[q[i]]) {
			for (int j = q[i]; j; j = son[j]) {
				top[j] = q[i];
				id[j] = ++cnt;
			}
		}
	build(1, 1, n);
}
int main() {
	read(n), read(qq);
	memset(head, -1, sizeof(head));
	for (int i = 2, x; i <= n; ++i) {
		read(x);
		add(x + 1, i);
	}
	init();
	cnt = 0;
	for (int i = 1; i <= qq; ++i) {
		int l, r;
		read(l), read(r), read(z[i]);
		++z[i];
		a[++cnt].p = l, a[cnt].id = i, a[cnt].f = 0;
		a[++cnt].p = r + 1, a[cnt].id = i, a[cnt].f = 1;
	}
	sort(a + 1, a + cnt + 1, cmp);
	int now = 0;
	for (int i = 1; i <= cnt; ++i) {
		while (now + 1 <= a[i].p) {
			++now;
			gao1(1, now);
		}
		int t = a[i].id;
		if (!a[i].f)	ans[t][0] = gao2(1, z[t]);
		else	ans[t][1] = gao2(1, z[t]);
	}
	for (int i = 1; i <= qq; ++i)	printf("%d\n", (ans[i][1] - ans[i][0] + M) % M);
	return 0;
}
