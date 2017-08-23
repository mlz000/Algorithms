#include <bits/stdc++.h>//Ïß¶ÎÊ÷
using namespace std;
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#pragma comment(linker, "/STACK:1024000000,1024000000") 
typedef long long LL;
inline void read(int &t) {
    int f = 1;char c;
    while (c = getchar(), c < '0' || c > '9') if (c == '-') f = -1;
    t = c - '0';
    while (c = getchar(), c >= '0' && c <= '9') t = t * 10 + c - '0';
    t *= f;
}
const int N = 1e5 + 5;
int a[N];
struct data {
	LL od[2], ev[2];	
}b[N << 2];
data up(data l, data r) {
	data t;
	t.od[0] = max(l.od[0] + r.ev[0], l.od[1] + r.od[0]);
	t.od[0] = max(t.od[0], max(l.od[0], r.od[0]));
	t.od[1] = max(l.od[0] + r.ev[1], l.od[1] + r.od[1]);
	t.od[1] = max(t.od[1], max(l.od[1], r.od[1]));
	t.ev[0] = max(l.ev[0] + r.ev[0], l.ev[1] + r.od[0]);
	t.ev[0] = max(t.ev[0], max(l.ev[0], r.ev[0]));
	t.ev[1] = max(l.ev[0] + r.ev[1], l.ev[1] + r.od[1]);
	t.ev[1] = max(t.ev[1], max(l.ev[1], r.ev[1]));
	return t;
}
void build(int rt, int l, int r) {
	if (l == r) {
		if (l & 1)	b[rt].od[0] = a[l];//odd
		else b[rt].ev[1] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	b[rt] = up(b[ls], b[rs]);
}
void change(int rt, int l, int r, int p, int x) {
	if (l == r) {
		if (l & 1)	b[rt].od[0] = x;//odd
		else b[rt].ev[1] = x;	
		return;
	}
	int mid = l + r >> 1;
	if (p <= mid)	change(ls, l, mid, p, x);
	else change(rs, mid + 1, r, p, x);
	b[rt] = up(b[ls], b[rs]);
}
data ask(int rt, int l, int r, int L, int R) {
	if (L <= l && R >= r) {
		return b[rt];
	}
	int mid = l + r >> 1;
	if (R <= mid)	return ask(ls, l, mid, L, R);
	else if (L > mid)	return ask(rs, mid + 1, r, L, R);
	else {
		data t1 = ask(ls, l, mid, L, mid), t2 = ask(rs, mid + 1, r, mid + 1, R);
		data t = up(t1, t2);
		return t;
	}
}
int main() {
	int T, n, m;
	read(T);
	while (T--) {
		read(n), read(m);
		for (int i = 1; i <= (n << 2); ++i)
			for (int j = 0; j < 2; ++j)
				b[i].od[j] = b[i].ev[j] = -1e18;
		for (int i = 1; i <= n; ++i)	read(a[i]);
		build(1, 1, n);
		while (m--) {
			int op, a, b;
			read(op), read(a), read(b);
			if (op == 1)	change(1, 1, n, a, b);
			else {
				data t = ask(1, 1, n, a, b);
				LL ans = max(t.od[0], t.od[1]);
				ans = max(ans, max(t.ev[0], t.ev[1]));
				printf("%I64d\n", ans);
			}
		}
	}
	return 0;
}
