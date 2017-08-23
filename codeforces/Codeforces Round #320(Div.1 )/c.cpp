#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 5;
int n;
double a[N];
double get(double x) {
	double mn = 0, mx = 0, sum = 0;
	for (int i = 1; i <= n; ++i) {
		sum += a[i] - x;
		mn = min(mn, sum);
		mx = max(mx, sum);
	}
	return mx - mn;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)	scanf("%lf", &a[i]);
	double l = -10000.0, r = 10000.0;
	for (int i = 1; i <= 300; ++i) {
		double m = (l + r) * 0.5;
		double mm = (m + r) * 0.5;
		double t = get(m);
		double tt = get(mm);
		if (t < tt) r = mm;
		else l = m;
	}
	printf("%.10lf\n", get(l));
	return 0;
}
