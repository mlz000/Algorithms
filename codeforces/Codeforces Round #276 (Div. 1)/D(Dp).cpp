#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int a[N];
long long cur, c1, c2;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]);
	c1 = -a[1], c2 = a[1];
	for (int i = 1; i <= n; ++i) {
		cur = max(0ll, max(c1 + a[i], c2 - a[i]));
		c1 = max(c1, cur - a[i + 1]);
		c2 = max(c2, cur + a[i + 1]);
	}
	printf("%I64d\n", cur);
	return 0;
}
