#include <bits/stdc++.h>
typedef long long LL;
const int N = 105;
int n, T;
char s[N];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		scanf("%d", &n);
		n = n * 12;
		int l = strlen(s);
		int t = 1;
		for (int i = 0; i < l; ++i)
			if (s[i] == 'T')	t += 2;
			else ++t;
		LL ans = 0;
		for (int i = 1; i <= 84; ++i) {
			if (t * i - (i - 1) <= n) {
				ans += n - t * i + (i - 1) + 1;
			}
			else break;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
