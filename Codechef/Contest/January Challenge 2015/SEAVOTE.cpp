#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int b[N];
int main() {
	int T, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int sum1 = 0, sum2 = 0, f = 1;
		for (int i = 1; i <= n; ++i)	scanf("%d", &b[i]);
		for (int i = 1; i <= n; ++i) {
			if (b[i] >= 101) {
				f = 0;
				break;
			}
			if (b[i]) {
				sum1 += b[i] - 1;
				sum2 += b[i];
			}
		}
		printf("%s\n", (f && sum1 < 100 && sum2 >= 100) ? "YES" : "NO");
	}
	return 0;
}
