#include <bits/stdc++.h>
using namespace std;
const int N = 205;
double a[N], b[N], suma[N], sumb[N];
int main() {
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; ++tt) {
		printf("Case #%d: ", tt);
		double L, W, X, Y, dx, dy;
		scanf("%lf%lf", &L, &W);
		scanf("%lf%lf%lf%lf", &X, &Y, &dx, &dy);
		int m;
		scanf("%d", &m);
		double ans = 1.0;
		while (m--) {
			double x;
			int n;
			scanf("%lf%d", &x, &n);
			suma[0] = 0.0;
			for (int i = 1; i <= n; ++i)	scanf("%lf", &a[i]), suma[i] = suma[i - 1] + a[i];
			sumb[0] = 0.0;
			for (int i = 1; i < n; ++i)	scanf("%lf", &b[i]), sumb[i] = sumb[i - 1] + b[i];
			double left = W - suma[n] - sumb[n - 1];
			double y = Y + (x - X) * dy / dx;
			double t = 0.0;
			double l, r;
			for (int i = 0; i <= n; ++i) {
				if (i == 0)	l = y, r = left;
				else if (i == n)	l = 0.0, r = y - suma[n] - sumb[n - 1];
				else l = max(0.0, y - suma[i] - sumb[i]), r = min(left, y - suma[i] - sumb[i - 1]);
				if (r >= l)	t += r - l;
			}
			ans *= t / left;
		}
		printf("%.5lf\n", ans);
	}
	return 0;
}
