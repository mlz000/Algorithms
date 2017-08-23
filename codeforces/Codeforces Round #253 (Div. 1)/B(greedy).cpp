#include <bits/stdc++.h>
using namespace std;
const int N = 105;
double a[N];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)	scanf("%lf", &a[i]);
	sort(a, a + n);
	double ans = 0.0, now = 1.0;
	for (int i = n - 1; i >= 0; --i)
		if (ans * (1.0 - a[i]) + now * a[i] > ans) {
			ans = ans * (1.0 - a[i]) + now * a[i];
			now *= 1.0 - a[i];
		}
	printf("%.10lf\n", ans);
	return 0;
}
