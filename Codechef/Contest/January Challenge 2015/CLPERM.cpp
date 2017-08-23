#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
long long a[N];
int main() {
	int T, k;
	long long n;
	scanf("%d", &T);
	while (T--) {
		scanf("%lld%d", &n, &k);
		LL sum = (n + 1) * n / 2;
		for (int i = 0; i < k; ++i)	scanf("%lld", &a[i]), sum -= a[i];
		if (k == n) {
			puts("Chef");
			continue;
		}
		else if (k == 0) {
			printf("%s\n", (sum % 2) ? "Mom" : "Chef");
			continue;
		}
		a[k++] = sum + 1;
		sort(a, a + k);
		k = unique(a, a + k) - a;
		int f, last = 1;
		long long s = 0ll;
		for (int i = 0; i < k; ++i) {
			if (a[i] == sum + 1) {
				if (a[i] % 2)	f = 0;
				else f = 1;
				break;
			}
			if ((s + (a[i] - 1 + last) * (a[i] - last) / 2) >= a[i]) {
				s += (a[i] - 1 + last) * (a[i] - last) / 2;
				last = a[i] + 1;
				continue;
			}
			if (a[i] % 2)	f = 0;
			else f = 1;
			break;
		}
		printf("%s\n", f ? "Mom" : "Chef");
	}
	return 0;
}
