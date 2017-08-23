#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int N = 50005;
typedef pair<int, int> pii;
typedef long long LL;
pii a[N];
int q[N];
LL x[N], y[N], f[N];
inline int read() {
	char c;
	while (c = getchar(), c < '0' || c > '9');
	int t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	return t;
}
inline double gao(int a, int b) {
	return (double)(f[b] - f[a]) / (y[a + 1] - y[b + 1]);
}
bool cmp(const pii &p, const pii &q) {
	return p.X < q.X || (p.X == q.X && p.Y < q.Y);
}
int main() {
	int n = read();
	for (int i = 1; i <= n; ++i)	a[i].X = read(), a[i].Y = read();
	sort(a + 1, a + n + 1, cmp);
	int tot = 0;
	for (int i = 1; i <= n; ++i) {
		while (tot && a[i].Y >= y[tot])	--tot;
		x[++tot] = a[i].X, y[tot] = a[i].Y;
	}
	int l = 0, r = 0;
	for (int i = 1; i <= tot; ++i) {
		while(l < r && gao(q[l], q[l + 1]) <= x[i])	++l;
		int t = q[l];
		f[i] = f[t] + x[i] * y[t + 1];
		while(l < r && gao(q[r], i) < gao(q[r - 1], q[r]))	--r;
		q[++r] = i;
	}
	printf("%lld\n", f[tot]);
	return 0;
}
