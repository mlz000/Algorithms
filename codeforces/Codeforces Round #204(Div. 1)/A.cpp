#include <bits/stdc++.h>
using namespace std;
const int N = 4005;
double a[N];
int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	double ans = 1e15, t = 0.0;
	for (int i = 1; i <= n * 2; ++i) {
		scanf("%lf", &a[i]);
		a[i] = a[i] - int(a[i]);
		t += a[i];
		if (a[i] > 0) 	++cnt;
	}
	for (int i = cnt - n; i <= n; ++i)	ans = min(ans, abs(i - t));
	printf("%.3lf\n", abs(ans));
	return 0;
}
