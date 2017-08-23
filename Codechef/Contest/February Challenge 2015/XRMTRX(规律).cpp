#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 60, M = 1e9 + 7;
LL p[N];
LL solve(LL l, LL r) {
	LL ans, ans2 = 0ll, left, t, delta;
	delta = r - l + 1;
	int i, rr;
	for (i = 60; i >= 0; --i)
		if (r + 1 >= p[i]) {
			ans = p[rr = i]; //×óÉÏ½Ç
			left = (r + 1) - p[i];//ÓÒÏÂ½Ç
			break;
		}
	for (; i >= 0; --i)
		if (left * 2 > p[i]) {
			ans2 = p[i];
			break;
		}
	for (i = rr - 1; i >= 0; --i) {	
		if (l >= p[i]) {
			l -= p[i];
			ans /= 2;
		}
		else break;
	}
	if (left <= delta)	return max(ans, ans2) - 1;
	else return solve(r - p[rr] - delta + 1, r - p[rr]);
}
LL gao(LL l, LL r, LL k) {
	LL t = 0;
	LL p1 = (l % k ? (l - l % k + k) : l) + k / 2;
	if (p1 <= r) {
		(t += min(r - p1 + 1, k / 2) % M * (k / 2 % M)) %= M;
		if (p1 + k <= r)	(t += min(r - p1 - k + 1, k / 2) % M * (k / 2 % M)) %= M;
	}
	LL p2 = ((r + 1) % k ? (r - r % k - 1) : r) - k / 2;
	if (p2 >= l) {
		(t += min(p2 - l + 1, k / 2) % M * (k / 2 % M)) %= M;
		if (p2 - k >= l)	(t += min(p2 - k - l + 1, k / 2) % M * (k / 2 % M)) %= M;
	}
	return t * 2 % M;
}
int main() {
	int T;
	p[0] = 1;
	for (int i = 1; i <= 60; ++i)	p[i] = p[i - 1] * 2ll;
	scanf("%d", &T);
	while (T--) {
		LL l, r;
		scanf("%lld%lld", &l, &r);
		LL k = solve(l, r);
		LL t = (r - l + 1);
		if (k != 0)	t = gao(l, r, k + 1);
		printf("%lld %lld\n", k, t);
	}
	return 0;
}


