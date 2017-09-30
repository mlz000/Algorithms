#include <bits/stdc++.h>
using namespace std;
int a, b, f, k;
int main() {
	scanf("%d%d%d%d", &a, &b, &f, &k);
	int np = 0, nf = b, ans = 0;
	for (int i = 1; i <= k; ++i) {
		if (nf < abs(f - np)) {
			puts("-1");
			return 0;
		}
		int t = a + (i != k ? (a - abs(f - np)) : 0);
		if (t > nf)	np = f, ++ans, nf = b;
		int now = i & 1 ? a : 0;
		if (abs(now - np) <= nf)	nf -= abs(now - np);
		else {
			puts("-1");
			return 0;
		}
		np = i & 1 ? a : 0;
	}
	printf("%d\n", ans);
	return 0;
}
