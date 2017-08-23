#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
double r1, r2;
struct S {
	double f(double x) {
		return sqrt((r1 * r1 - x * x) * (r2 * r2 - x * x));
	}
	double calc(double s, double fl, double fr, double fmid) {
		return (fl + fr + 4 * fmid) * s / 6;
	}
	double simpson(double l, double mid, double r, double fl, double fmid, double fr, double tot) {
		double m1 = (l + mid) * 0.5, m2 = (mid + r) * 0.5;
		double fm1 = f(m1), fm2 = f(m2);
		double t1 = calc(mid - l, fl, fmid, fm1), t2 = calc(r - mid, fmid, fr, fm2);
		if (fabs(t1 + t2 - tot) <= eps)	return t1 + t2;
		else return simpson(l, m1, mid, fl, fm1, fmid, t1) + simpson(mid, m2, r, fmid, fm2, fr, t2);
	}
}s;
int main() {
	freopen("twocyl.in", "r", stdin);
	freopen("twocyl.out", "w", stdout);
	scanf("%lf%lf", &r1, &r2);
	if (r1 > r2)	swap(r1, r2);
	double l = 0, r = r1, mid = (l + r) * 0.5;
	double fl = s.f(l), fmid = s.f(mid), fr = s.f(r);
	double ans = s.simpson(l, mid, r, fl, fmid, fr, s.calc(r - l, fl, fr, fmid));
	printf("%.4lf\n", ans * 8);
	return 0;
}
