#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
typedef long long LL;
int n, a, b, c, xx, q[N];
LL f[N], sum[N];
inline int fast() {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	int t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	return t * f;
}
inline LL sqr(LL x) {
	return x * x;
}
inline double gao(int x, int y) {
	return (double)(f[y] - f[x] + a * (sqr(sum[y]) - sqr(sum[x])) + b * (sum[x] - sum[y])) / (double)(2 * a * (sum[y] - sum[x]));
}
int main() {
	n = fast(), a = fast(), b = fast(), c = fast();
	for (int i = 1; i <= n; ++i)	xx = fast(), sum[i] = sum[i - 1] + xx;
	int l = 0, r = 0;
	for (int i = 1; i <= n; ++i) {
		while (l < r && gao(q[l], q[l + 1]) < sum[i])	++l;
		int t = q[l];
		f[i] = f[t] + a * sqr(sum[i] - sum[t]) + b * (sum[i] - sum[t]) + c;
		while (l < r && gao(q[r], i) < gao(q[r - 1], q[r]))	--r;
		q[++r] = i;
	}
	printf("%lld\n", f[n]);
	return 0;
}
