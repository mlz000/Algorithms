#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
inline void read(LL &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
const int N = 10005, M = 61;
LL n, a[N], p[M];
int tot;
bool ok;
void gauss() {
	tot = ok = 0;
	for (int i = 60; i >= 0; --i) {
		int j = tot + 1;
		while (!(p[i] & a[j]) && j <= n)	++j;
		if (j == n + 1)	continue;
		++tot;
		swap(a[tot], a[j]);
		for (int k = 1; k <= n; ++k)
			if (k != tot && (a[k] & p[i]))	
				a[k] ^= a[tot];
	}
	if (tot != n)	ok = 1;//0
}
LL gao(int k) {
	if (ok)	--k;
	if (!k)	return 0;
	if (k >= p[tot])	return -1;
	LL t = 0;
	for (int i = 1; i <= tot; ++i)
		if (k & p[tot - i])	t ^= a[i];
	return t;
}
int main() {
	p[0] = 1;
	for (int i = 1; i <= 60; ++i)	p[i] = p[i - 1] << 1ll;
	long long q, k, T;
	read(T);
	for (int tt = 1; tt <= T; ++tt) {
		printf("Case #%d:\n", tt);
		read(n);
		for (int i = 1; i <= n; ++i)	read(a[i]);
		gauss();
		read(q);
		while (q--) {
			read(k);
			printf("%I64d\n", gao(k));
		}
	}
	return 0;
}
