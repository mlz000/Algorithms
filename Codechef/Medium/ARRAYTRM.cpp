#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N], b[N];
int main() {
	int T, n, k;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		memset(b, 0, sizeof(b));
		for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]), ++b[a[i] % (k + 1)];
		bool f = 0;
		for (int i = 0; i <= k; ++i)	
			if (b[i] >= n - 1)	f = 1;
		printf("%s\n", f ? "YES" : "NO");
	}
	return 0;
}
