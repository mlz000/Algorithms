#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define F first
#define S second
#define ls (rt << 1)
#define rs (rt << 1 | 1)
typedef long long LL;
typedef pair<int, int> pii;
const int N = 1e5 + 5, M = 1e9 + 7;
int h, w, n, ans[N];
set<pair<int, int> > Set[N << 2];
struct data {
	int h, row, l, r, id, f;
	data(){}
	data(int h, int row, int l, int r, int id, int f) : h(h), row(row), l(l), r(r), id(id), f(f){}
	bool operator < (const data & p) const{
		return h < p.h || (h == p.h && f < p.f);
	}
}d[N << 1];
void add(int rt, int l, int r, int L, int R, pii p, int f) {
	if (L <= l && r <= R) {
		if (f)	Set[rt].insert(p);
		else Set[rt].erase(p);
		return;
	}
	int mid = l + r >> 1;
	if (R <= mid)	add(ls, l, mid, L, R, p, f);
	else if (mid < L)	add(rs, mid + 1, r, L, R, p, f);
	else add(ls, l, mid, L, mid, p, f), add(rs, mid + 1, r, mid + 1, R, p, f);
}
void ask2(int rt, int l, int r, int p, pii &t) {
	if (Set[rt].size()) {
		pii now = *Set[rt].rbegin();
		if (t.F < now.F)	t = now;;
	}
	if (l == r)	return;
	int mid = l + r >> 1;
	if (p <= mid)	ask2(ls, l, mid, p, t);
	else ask2(rs, mid + 1, r, p, t);
}
int ask(int x) {
	pii t = mp(-1, -1);
	ask2(1, 1, w, x, t);
	if (~t.S)	return ans[t.S];
	else return 1;
}
int main() {
	scanf("%d%d%d", &h, &w, &n);
	for (int i = 0; i < n; ++i) {
		int u, l, r, s;
		scanf("%d%d%d%d", &u, &l, &r, &s);
		d[i << 1] = data(u, u, l, r, i, 1);
		d[i << 1 | 1] = data(u + s + 1, u, l, r, i, 0); 
	}
	n <<= 1;
	sort(d, d + n);
	for (int i = 0; i < n; ++i) {
		if (d[i].h > h + 1)	continue;
		if (!d[i].f)	add(1, 1, w, d[i].l, d[i].r, mp(d[i].row, d[i].id), 0);
		else {
			if (d[i].l == 1)	ans[d[i].id] = ask(d[i].r + 1) * 2 % M;
			else if (d[i].r == w)	ans[d[i].id] = ask(d[i].l - 1) * 2 % M;
			else ans[d[i].id] = (ask(d[i].l - 1) + ask(d[i].r + 1)) % M;
			add(1, 1, w, d[i].l, d[i].r, mp(d[i].row, d[i].id), 1);
		}
	}
	int t = 0;
	for (int i = 1; i <= w; ++i)	(t += ask(i)) %= M;
	printf("%d\n", t);
	return 0;
}

