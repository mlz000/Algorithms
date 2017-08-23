#include <bits/stdc++.h>//Segment tree
using namespace std;
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#pragma comment(linker, "/STACK:102400000,102400000")
typedef pair<int, int> pii;
typedef long long LL;
const int N = 1e5 + 5, M = 998244353;
int n, now, a[N], hashtime, tmax, tsum;
struct data {
	int x, i, l, r;
	data(){}
	data(int x, int i, int l, int r) : x(x), i(i), l(l), r(r) {}
}Q[N * 25];
vector<pii> g[2];
bool cmp(const data &p, const data &q) {
	return p.x < q.x || p.x == q.x && p.l < q.l;
}
int Max[N << 2], sum[N << 2], add[N << 2], vis[N << 2];
void check(int rt) {
	if (vis[rt] < hashtime)	{
		vis[rt] = hashtime;
		sum[rt]= add[rt] = Max[rt] = 0;
	}
}
void maintain(int rt, int l, int r, int mx, int s) {
	if (mx > Max[rt]) {
		Max[rt] = mx;
		add[rt] = s;
		sum[rt] = (LL)(r - l + 1) * s % M;
	}
	else if (mx == Max[rt]) {
		(add[rt] += s) %= M;
		(sum[rt] += (LL)(r - l + 1) * s % M) %= M;
	}
}
void up(int rt) {
	check(ls), check(rs);
	if (Max[ls] == Max[rs]) {
		Max[rt] = Max[ls];
		sum[rt] = (sum[ls] + sum[rs]) % M;
	}
	else if (Max[ls] > Max[rs]) {
		Max[rt] = Max[ls];
		sum[rt] = sum[ls];
	}
	else Max[rt] = Max[rs], sum[rt] = sum[rs];
}
void down(int rt, int l, int r) {
	if (add[rt]) {
		int mid = l + r >> 1;
		check(ls), maintain(ls, l, mid, Max[rt], add[rt]);
		check(rs), maintain(rs, mid + 1, r, Max[rt], add[rt]);
		add[rt] = 0;
	}
}
void change(int rt, int l, int r, int L, int R, int mx, int s) {
	check(rt);
	if (L <= l && R >= r) {
		maintain(rt, l, r, mx, s);
		return;
	}
	down(rt, l, r);
	int mid = l + r >> 1;
	if (L <= mid)	change(ls, l, mid, L, R, mx, s);
	if (R > mid)	change(rs, mid + 1, r, L, R, mx, s);
	up(rt);
}
void ask(int rt, int l, int r, int L, int R) {
	//if (R < L)	return;
	check(rt);
	if (L <= l && R >= r) {
		if (tmax == Max[rt])	(tsum += sum[rt]) %= M;
		else if (Max[rt] > tmax) {
			tmax = Max[rt];
			tsum = sum[rt];
		}
		return;
	}
	down(rt, l, r);
	int mid = l + r >> 1;
	if (L <= mid)	ask(ls, l, mid, L, R);
	if (R > mid)	ask(rs, mid + 1, r, L, R);
}
void init() {
	now = 0;
	for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]);
	Q[++now] = data(a[n], n, n, n);
	int cur = 0;
	g[cur].clear();
	g[cur].pb(mp(a[n], n));
	for (int i = n - 1; i >= 1; --i) {
		cur ^= 1;
		g[cur].clear();
		g[cur].pb(mp(a[i], i));
		int pre = a[i];
		int cnt = 1;
		for (int j = 0; j < g[cur ^ 1].size(); ++j) {
			pii t = g[cur ^ 1][j];
			int x = __gcd(pre, t.F);
			if (x != pre) {
				g[cur].pb(mp(x, t.S));
				Q[++now] = data(pre, i, g[cur][cnt - 1].S, g[cur][cnt].S - 1);
				++cnt;
			}
			pre = x;
		}
		Q[++now] = data(pre, i, g[cur][cnt - 1].S, n);
	}
	sort(Q + 1, Q + now + 1, cmp);
}
void gao() {
	int ans1 = 0, ans2 = 0;
	for (int i = 1, j = 1; i <= now; i = j) {
		while (Q[j].x == Q[i].x && j <= now)	++j;
		++hashtime;
		change(1, 1, n, Q[i].l, Q[i].r, 1, 1);
		for (int k = i + 1; k < j; ++k) {
			tmax = tsum = 0;
			int p = Q[k].i;
			if (p > 1)	ask(1, 1, n, 1, p - 1);
			if (!tmax)	tsum = 1;
			change(1, 1, n, Q[k].l, Q[k].r, tmax + 1, tsum);
		}
		if (ans1 < Max[1]) {
			ans1 = Max[1];
			ans2 = sum[1];
		}
		else if (ans1 == Max[1]) {
			(ans2 += sum[1]) %= M;
		}
	}
	printf("%d %d\n", ans1, ans2);
}
int main() {
	while (~scanf("%d", &n)) {
		init();	
		gao();
	}
	return 0;
}
