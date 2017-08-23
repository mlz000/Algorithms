#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = (int)1e9 + 7;
typedef long long LL;
LL f[N], h[N];
struct data {
	LL a, b, c, d, v;
	data(){}
	data(LL a, LL b, LL c, LL d, LL v): a(a), b(b), c(c), d(d), v(v)	{}
	friend bool operator < (const data &p, const data &q) {
		return p.c > q.c || (p.c == q.c && p.d > q.d);
	}
}g[N];
LL P(LL x, LL y) {
	LL t = 1;
	for (; y; y >>= 1) {
		if (y & 1)	t = t * x % M;
		x = x * x % M;
	}
	return t;
}
bool cmp(const data &p, const data &q) {
	return p.a < q.a || (p.a == q.a && p.b < q.b);
}
priority_queue<data> Q;
int main() {
	LL n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= k; ++i)	cin >> g[i].a >> g[i].b >> g[i].c >> g[i].d;
	sort(g + 1, g + k + 1, cmp);
	int pos = 1;
	LL i = 0ll, j, sum;
	sum = f[0] = 1ll;
	while (pos <= k || Q.size()) {
		j = g[pos].a;
		if (pos == k + 1)	j = Q.top().c;
		if (Q.size())	j = min(j, Q.top().c);
		LL t = sum * P(m, max(0ll, j - i - 1)) % M;
		if (i < j && j <= n) sum = t * m % M;
		else sum = t;
		while (Q.size() && (Q.top().c == j)) {
			data tmp = Q.top();
			if (h[tmp.d] != j)	f[tmp.d] = t, h[tmp.d] = j;
			(f[tmp.d] += tmp.v) %= M;
			(sum += tmp.v) %= M;
			Q.pop();
		}
		while (pos <= k && (g[pos].a == j)) {
			g[pos].v = t;
			if (h[g[pos].b] == j)	g[pos].v = f[g[pos].b];
			Q.push(g[pos++]);
		}
		i = j;
	}
	LL ans = sum * P(m, max(0ll, n - i)) % M;
	cout << ans << endl;
	return 0;
}
