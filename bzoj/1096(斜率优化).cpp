#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
typedef long long LL;
int n,q[N];
LL f[N], sum[N], x[N], p[N], b[N], c[N];
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
inline double gao(int j, int k) {
	return (double)(f[k] - f[j] + b[k] - b[j]) / (double)(sum[k] - sum[j]);
}
int main() {
	n = fast();
	for (int i = 1; i <= n; ++i) {
		x[i] = fast(), p[i] = fast(), c[i] = fast();
		sum[i] = sum[i - 1] + p[i];
		b[i] = b[i - 1] + p[i] * x[i];
	}
	int l = 0, r = 0;
	for (int i = 1; i <= n; ++i) {
		while (l < r && gao(q[l], q[l + 1]) < x[i])	++l;
		int t = q[l];
		f[i] = f[t] + b[t] - b[i] + (sum[i] - sum[t]) * x[i] + c[i];
		while (l < r && gao(q[r], i) < gao(q[r - 1], q[r]))	--r;
		q[++r] = i;
	}
	printf("%lld\n", f[n]);
	return 0;
}
