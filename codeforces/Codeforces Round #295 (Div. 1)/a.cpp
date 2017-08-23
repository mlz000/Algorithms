#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = (int)1e9 + 7;
char s[N];
int cnt[5];
long long P(long long x, long long y) {
	long long t = 1ll;
	for (; y; y >>= 1) {
		if (y & 1)	t = t * x % M;
		x = x * x % M;
	}
	return t;
}
int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'A')	++cnt[1];
		if (s[i] == 'G')	++cnt[2];
		if (s[i] == 'C')	++cnt[3];
		if (s[i] == 'T')	++cnt[4];
	}
	sort(cnt + 1, cnt + 5);
	cnt[0] = -1;
	int ans = 1;
	for (int i = 4; i >= 1; --i) {
		if (cnt[i] == cnt[i - 1])	++ans;
		else break;
	}
	printf("%I64d\n", P(ans, n));
	return 0;
}
