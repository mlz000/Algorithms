#include <bits/stdc++.h>//¶þ·Ö+hash
using namespace std;
const int N = 500005;
unsigned long long hash1[N], hash2[N], p[N];
char s[N];
int main() {
	int n;
	long long ans = 0ll;
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i)	hash1[i] = hash1[i - 1] * 131 + s[i] - '0';
	for (int i = n; i >= 1; --i)	hash2[i] = hash2[i + 1] * 131 + '1' - s[i];
	p[0] = 1;
	for (int i = 1; i <= n; ++i)	p[i] = p[i - 1] * 131;
	for (int i = 1; i < n; ++i) {
		int l = 1, r = min(i, n - i), t = 0;
		while (l <= r) {
			int mid = l + r >> 1;
			if (hash1[i] - hash1[i - mid] * p[mid] == hash2[i + 1] - hash2[i + mid + 1] * p[mid])
				t = mid, l = mid + 1;
			else r = mid - 1;
		}
		ans += t;
	}
	printf("%lld\n", ans);
	return 0;
}



