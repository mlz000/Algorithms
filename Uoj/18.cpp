#include <bits/stdc++.h>
using namespace std;
const int N = 21;
int x[N], y[N], a[N];
int main() {
	int d, n;
	scanf("%d%d", &d, &n);
	for (int i = 0; i < n; ++i)	scanf("%d%d%d", &x[i], &y[i], &a[i]);
	int ans = 0, sum = 0;
	for (int i = 0; i <= 128; ++i)
		for (int j = 0; j <= 128; ++j) {
			int t = 0;
			for (int k = 0; k < n; ++k)
				if (x[k] >= i - d && x[k] <= i + d && y[k] >= j - d && y[k] <= j + d)	t += a[k];
			if (t > sum)	sum = t, ans = 1;
			else if (t == sum)	++ans;
		}
	printf("%d %d\n", ans, sum);
	return 0;
}
