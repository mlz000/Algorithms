#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define ls (rt << 1)
#define rs (rt << 1 | 1)
const int N = 100005;
int n, Q, a[N], tot, cnt, to[N << 2], nxt[N << 2], head[N], q[N], num[N], sz[N], top[N], dep[N], pre[N], son[N], id[N], w[N << 2], f[N << 2];
bool vis[N];
inline void read(int &t) {
    int ff = 1;char c;
    while (c = getchar(), c < '0' || c > '9') if (c == '-') ff = -1;
    t = c - '0';
    while (c = getchar(), c >= '0' && c <= '9') t = t * 10 + c - '0';
    t *= ff;
}
void add(int u, int v) {
    to[tot] = v, nxt[tot] = head[u], head[u] = tot++;
    to[tot] = u, nxt[tot] = head[v], head[v] = tot++;
}
void up(int rt) {
    f[rt] = f[ls] ^ f[rs];
}
void change(int rt, int l, int r, int p, int x) {
    if (l == r) {
        f[rt] = x;
        return;
    }
    int mid = l + r >> 1;
    if (p <= mid)   change(ls, l, mid, p, x);
    else change(rs, mid + 1, r, p, x);
    up(rt);
}
int query(int rt, int l, int r, int L, int R) {
    if (L <= l && R >= r)   return f[rt];
    int mid = l + r >> 1;
    if (R <= mid)   return query(ls, l, mid, L, R);
    else if (L > mid)   return query(rs, mid + 1, r, L, R);
    else {
        return query(ls, l, mid, L, R) ^ query(rs, mid + 1, r, L, R);
    }
}
int ask(int a, int b) {
    int ans = 0;
    while (top[a] != top[b]) {
        if (dep[top[a]] < dep[top[b]])  swap(a, b);
        int t = query(1, 1, n, id[top[a]], id[a]);
        ans ^= t;
        a = pre[top[a]];
    }
    if (dep[a] < dep[b])    swap(a, b);
    int t = query(1, 1, n, id[b], id[a]);
    ans ^= t;
    return ans;
}
void build(int rt, int l, int r) {
    if (l == r) {
        f[rt] = num[l];
        return;
    }
    int mid = l + r >> 1;
    build(ls, l, mid), build(rs, mid + 1, r);
    up(rt);
}
void init() {
    memset(head, -1, sizeof(head));
    memset(nxt, 0, sizeof(nxt));
    memset(vis, 0, sizeof(vis));
    memset(dep, 0, sizeof(dep));
    memset(to, 0, sizeof(to));
    memset(q, 0, sizeof(q));
    memset(pre, 0, sizeof(pre));
    memset(sz, 0, sizeof(sz));
    memset(top, 0, sizeof(top));
    memset(son, 0, sizeof(son));
    memset(f, 0, sizeof(f));
    memset(id, 0, sizeof(id));
    memset(num, 0, sizeof(num));
    tot = cnt = 0;
    read(n), read(Q);
    for (int i = 1, x, y; i < n; ++i) {
        scanf("%d%d", &x, &y);
        add(x, y);
    }
	for (int i = 1; i <= n; ++i)    read(a[i]), ++a[i];
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
		if (sz[son[pre[q[i]]]] < sz[q[i]])  son[pre[q[i]]] = q[i];
	}
	for (int i = 0; i <= r; ++i)
		if (!top[q[i]]) {
			for (int j = q[i]; j; j = son[j]) {
				top[j] = q[i];
				num[id[j] = ++cnt] = a[j];
			}
		}
	build(1, 1, n);
}
void gao() {
    int op, x, y;
    for (int i = 1; i <= Q; ++i) {
        read(op), read(x), read(y);
        if (!op)    change(1, 1, n, id[x], y + 1);
        else {
            int t = ask(x, y);
            if (t == 0)    puts("-1");
            else printf("%d\n", t - 1);
        }
    }
}
int main() {
    int T;
    read(T);
    while (T--) {
        init();
        gao();
    }
    return 0;
}
