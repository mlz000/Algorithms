#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N = 55;
int a[N];
int calc(int x) {
	for (int i = 0;; ++i)	if ((1 << i) >= x)	return i;
}
int main() {
	int T, n, m, k;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; ++tt) {
		printf("Case #%d: ", tt);
		scanf("%d%d%d", &n, &m, &k);
		printf("%I64d ", (long long)n * m * k - 1ll);
		long long ans = calc(n) + calc(m) + calc(k);
		printf("%I64d\n", ans);
	}
	return 0;
}
