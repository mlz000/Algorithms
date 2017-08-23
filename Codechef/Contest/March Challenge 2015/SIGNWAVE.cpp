#include <bits/stdc++.h>
using namespace std;
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
int main() {
	int T, s, c, k;
	read(T);
	while (T--) {
		read(s), read(c), read(k);
		int p = -1;
		long long ans = 0;
		for (int i = 0; i < 100; ++i) {
			int cnt = 0;
			if (i == 0)	cnt = s;
			else {
				if (s > i)	cnt += s - i;
				if (c - i + 1 > 0)	++cnt;
			}
			if (cnt >= k) {
				if (i == 0)	ans += 3;
				else ans += 1ll << i;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
