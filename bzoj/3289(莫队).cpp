#include <bits/stdc++.h>//·Ö¿é
using namespace std;
#define X first 
#define Y second
const int N = 50005;
int n, m, s, a[N], b[N], c[N];
long long ans[N];
struct data {
	int l, r, id;
}Q[N];
inline int getInt() {
	char c;
	while (c = getchar(), c < '0' || c > '9');
	int t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	return t;
}
bool cmp(const data &p, const data &q) {
	return p.l / s < q.l / s || (p.l / s == q.l / s && p.r < q.r);
}
void add(int p, int x) {
	for (; p <= n; p += p & -p)	c[p] += x;
}
long long query(int p) {
	long long t = 0ll;
	for (; p; p -= p & -p)	t += c[p];
	return t;
}
int main() {
	n = getInt();
	s = sqrt(n + 1);
	for (int i = 0; i < n; ++i)	b[i] = a[i] = getInt();
	sort(b, b + n);
	for (int i = 0; i < n; ++i)	a[i] = lower_bound(b, b + n, a[i]) - b + 1;
	m = getInt();
	for (int i = 0; i < m; ++i) {
		Q[i].l = getInt() - 1, Q[i].r = getInt() - 1;
		Q[i].id = i;
	}
	sort(Q, Q + m, cmp);
	int L, R;
	long long t = 0ll;
	for (int i = 0; i < m; ++i) {
		if (!i) {
			for (int j = Q[i].l; j <= Q[i].r; ++j)	t += j - Q[i].l - query(a[j]), add(a[j], 1);
			L = Q[i].l, R = Q[i].r;
			ans[Q[i].id] = t;
		}
		else {
			while (L > Q[i].l)	t += query(a[--L] - 1), add(a[L], 1);
			while (L < Q[i].l)	t -= query(a[L] - 1), add(a[L++], -1);
			while (R < Q[i].r) 	t += R - L + 1 - query(a[++R]), add(a[R], 1);	
			while (R > Q[i].r)	t -= R - L + 1 - query(a[R]), add(a[R--], -1);
			ans[Q[i].id] = t;
		}
	}
	for (int i = 0; i < m; ++i)	printf("%lld\n", ans[i]);
	return 0;
}
