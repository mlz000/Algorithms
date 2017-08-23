#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int a[N];
int main() {
	int n;
	long long ans = 0;
	scanf("%d", &n);
	int cnt = -1;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[++cnt]);
		while (cnt > 1 && a[cnt - 1] <= a[cnt - 2] && a[cnt - 1] <= a[cnt]) {
			ans += min(a[cnt - 2], a[cnt]);
			a[cnt - 1] = a[cnt];
			--cnt;
		}
	}
	for (int i = 1; i < cnt; ++i)	ans += min(a[i - 1], a[i + 1]);
	printf("%I64d\n", ans);
	return 0;
}
