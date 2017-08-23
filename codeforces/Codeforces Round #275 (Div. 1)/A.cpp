#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int l = 1, r = n;
	for (int i = 1; i <= k; ++i) {
		if (i & 1)	printf("%d ", l++);
		else printf("%d ", r--);
	}
	if (k & 1)	for (int i = k + 1; i <= n; ++i)	printf("%d ", l++);
	else	for (int i = k + 1; i <= n; ++i)	printf("%d ", r--);
	return 0;
}
