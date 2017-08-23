#include <bits/stdc++.h>
using namespace std;
const int N = 50005;
int a[N], sum1[N], sum2[N];
int getint() {
	char c;
	while (c = getchar(), c < '0' || c > '9');
	int t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	return t;
}
int main() {
	int T, n, q;
	T = getint();
	while (T--) {
		n = getint(), q = getint();
		for (int i = 1; i <= n; ++i)	a[i] = getint();
		for (int i = 1; i <= n; ++i) {
			if (i == 1)	sum1[i] = a[i], sum2[n - i + 1] = a[n - i + 1];
			else sum1[i] = __gcd(sum1[i - 1], a[i]), sum2[n - i + 1] = __gcd(sum2[n - i + 2], a[n - i + 1]);
		}
		while (q--) {
			int l, r, t1, t2;
			l = getint(), r = getint();
			t1 = (l == 1) ? 0 : sum1[l - 1];
			t2 = (r == n) ? 0 : sum2[r + 1];
			if (t1 == 0 || t2 == 0)	printf("%d\n", t1 + t2);
			else printf("%d\n", __gcd(t1, t2));
		}
	}
	return 0;
}
