#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
int main() {
	int T, n;
	long long s;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%lld", &n, &s);
		int ans = 0;
		for (int i = n; i >= 1; --i) {
			if ((LL)i * (i + 1) / 2 + (n - i) <= s) {
				ans = i;
				break;
			}
		}
		printf("%d\n", n - ans);
	}
	return 0;
}
