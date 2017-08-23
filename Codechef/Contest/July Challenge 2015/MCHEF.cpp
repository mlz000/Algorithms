#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ls (rt << 1)
#define rs (rt << 1 | 1)
typedef long long LL;
typedef pair<int, int> pii;
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
const int N = 1e5 + 5;
int x[N];
int Min[N << 2], c[N];
LL f[501];
void down(int rt) {
	Min[ls] = min(Min[ls], Min[rt]);
	Min[rs] = min(Min[rs], Min[rt]);
}
void gao(int rt, int l, int r, int L, int R, int c) {
	if (L <= l && R >= r) {
		Min[rt] = min(Min[rt], c);
		return;
	}
	int mid = l + r >> 1;
	down(rt);
	if (L <= mid)	gao(ls, l, mid, L, R, c);
	if (R > mid)	gao(rs, mid + 1, r, L, R, c);
}
int ask(int rt, int l, int r, int p) {
	if (l == r) {
		return Min[rt];
	}
	int mid = l + r >> 1;
	down(rt);
	if (p <= mid)	return ask(ls, l, mid, p);
	else return ask(rs, mid + 1, r, p);
}
int main() {
	int T, n, k, m;
	read(T);
	while (T--) {
		LL ans = 0;
		vector<pii> b;
		read(n), read(k), read(m);
		for (int i = 1; i <= n; ++i) {
			read(x[i]);
			if (x[i] < 0)	b.pb(mp(i, x[i]));
			ans += x[i];
		}
		for (int i = 0; i <= k; ++i)	f[i] = -1;
		for (int i = 0; i <= n << 2; ++i)	Min[i] = 10000;
		for (int i = 1; i <= m; ++i) {
			int l, r, p;
			read(l), read(r), read(p);
			gao(1, 1, n, l, r, p);
		}
		for (int i = 0; i < b.size(); ++i)	c[i] = ask(1, 1, n, b[i].F);
		f[0] = 0;
		for (int i = 0; i < b.size(); ++i) {
			for (int j = k; j >= 0; --j)
				if (~f[j] && k - j >= c[i]) {
					f[j + c[i]] = max(f[j + c[i]], f[j] - b[i].S);
				}
		}
		LL t = 0;
		for (int i = 0; i <= k; ++i)	t = max(t, f[i]);
		cout << t + ans << endl;
	}
	return 0;
}
