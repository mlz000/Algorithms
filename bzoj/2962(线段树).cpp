#include <bits/stdc++.h>//Êı¾İ·¶Î§¶ºÎÒ£¿
using namespace std;
typedef long long LL;
#define ls (rt << 1)
#define rs (rt << 1 | 1)
const int N = 60050, M = 19940417;
int a[N], b[25], c[N][25], add[N << 2], rev[N << 2];
struct node {
    int f[25];
}p[N << 2];
inline int read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
inline void U(int &x, int y) {
	x += y;
	if (x >= M)	x -= M;
	if (x < 0)	x += M;
}
void calc(int rt, int l, int r, int x) {
	for (int i = 1; i <= 20; ++i) {
		int t = 0, tx = 1;
		for (int j = i; j >= 0; --j) {
			U(t, (LL)p[rt].f[j] * c[r - l + 1 - j][i - j] % M * tx % M);
			tx = (LL)tx * x % M;
		}
		b[i] = t;
	}	
	for (int i = 1; i <= 20; ++i)	p[rt].f[i] = b[i];
}
void down(int rt, int l, int r) {
	if (rev[rt]) {
		rev[ls] ^= 1, rev[rs] ^= 1;
		for (int i = 1; i <= 20; i += 2)	p[ls].f[i] = (M - p[ls].f[i]) % M;
		for (int i = 1; i <= 20; i += 2)	p[rs].f[i] = (M - p[rs].f[i]) % M;
		add[ls] = (M - add[ls]) % M, add[rs] = (M - add[rs]) % M;
		rev[rt] = 0;
	}
	if (add[rt]) {
		int mid = l + r >> 1;
		U(add[ls], add[rt]), U(add[rs], add[rt]);
		calc(ls, l, mid, add[rt]), calc(rs, mid + 1, r, add[rt]);
		add[rt] = 0;
	}
} 
void up(int rt) {
    for (int i = 1; i <= 20; ++i)   p[rt].f[i] = 0;
    for (int i = 0; i <= 20; ++i)   
        for (int j = 0; i + j <= 20; ++j) {
            if (i + j == 0) continue;
            U(p[rt].f[i + j], (LL)p[ls].f[i] * p[rs].f[j] % M);
        }
}
void build(int rt, int l, int r) {
    p[rt].f[0] = 1;
    if (l == r) {
        p[rt].f[1] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(ls, l, mid), build(rs, mid + 1, r);
    up(rt);
}
void reverse(int rt, int l, int r, int L, int R) {
    if (L <= l && R >= r) {
        rev[rt] ^= 1;
		add[rt] = (M - add[rt]) % M;
		for (int i = 1; i <= 20; i += 2) p[rt].f[i] = (M - p[rt].f[i]) % M;
        return;
    }
    down(rt, l, r);
    int mid = l + r >> 1;
    if (L <= mid)   reverse(ls, l, mid, L, R);
    if (R > mid)    reverse(rs, mid + 1, r, L, R);
	up(rt);
}
void inc(int rt, int l, int r, int L, int R, int x) {
    if (L <= l && R >= r) {
		U(add[rt], x);
		calc(rt, l, r, x);
        return;
    }
    int mid = l + r >> 1;
    down(rt, l, r);
	if (L <= mid)   inc(ls, l, mid, L, R, x);
    if (R > mid)    inc(rs, mid + 1, r, L, R, x);
    up(rt);
}
node ask(int rt, int l, int r, int L, int R) {
    if (L <= l && R >= r) {
        return p[rt];
    }
    down(rt, l, r);
    int mid = l + r >> 1;
    node t, t1, t2;
    if (L > mid)    t = ask(rs, mid + 1, r, L, R);
    else if (R <= mid)  t = ask(ls, l, mid, L, R);
    else {
        t.f[0] = 1;
        for (int i = 1; i <= 20; ++i)   t.f[i] = 0;
        t1 = ask(ls, l, mid, L, mid), t2 = ask(rs, mid + 1, r, mid + 1, R);
        for (int i = 0; i <= 20; ++i)
            for (int j = 0; j + i <= 20; ++j) {
                if (i + j == 0) continue;
                U(t.f[i + j], (LL)t1.f[i] * t2.f[j] % M);
            }
    }   
    return t;
}   
int main() {
    int n, q;
    read(n), read(q);
    for (int i = 0; i <= n; ++i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
    }
    for (int i = 1; i <= n; ++i)    read(a[i]), a[i] = (a[i] % M + M) % M;
    build(1, 1, n);
    char s[5];
    int x, y, z;
    while (q--) {
        scanf("%s", s);
        if (s[0] == 'I') {
            read(x), read(y), read(z);
			z = (z % M + M) % M;
            inc(1, 1, n, x, y, z);
        }
        else if (s[0] == 'R') {
            read(x), read(y);
            reverse(1, 1, n, x, y);
        }
        else {
            read(x), read(y), read(z);
			z = (z % M + M) % M;
            node t = ask(1, 1, n, x, y);
            printf("%d\n", t.f[z] % M);
        }
    }
    return 0;
}
