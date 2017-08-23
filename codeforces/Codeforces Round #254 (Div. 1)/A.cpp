#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int w[N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)	scanf("%d", &w[i]);
	double ans = 0.0;
	for (int i = 1, x, y, z; i <= m; ++i) {
		scanf("%d%d%d", &x, &y, &z);
		ans = max(ans, (double)(w[x] + w[y]) / (double)z );
	}
	printf("%.12lf\n", ans);
	return 0;
}
