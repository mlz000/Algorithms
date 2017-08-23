#include <bits/stdc++.h>
using namespace std;
struct point {
	double x, y;
	point(double x = 0, double y = 0):x(x), y(y){}
}a, b, c, d;
point operator - (point p, point q) {
	return point(p.x - q.x, p.y - q.y);
}
point operator + (point p, point q) {
	return point(p.x + q.x, p.y + q.y);
}
point operator * (point p, double a) {
	return point(p.x * a, p.y * a);
}
point operator / (point p, double a) {
	return point(p.x / a, p.y / a);
}
inline double sqr(double x) {
	return x * x;
}
inline double dis(point p, point q) {
	return sqrt(sqr(p.x - q.x) + sqr(p.y - q.y));
}
double p, q, r;
inline double work(point t, point u) {
	return dis(t, a) / p + dis(t, u) / r + dis(u, d) / q;
}
double gao(point t) {
	point l = c, r = d;
	for (int i = 1; i <= 300; ++i) {
		point mid = l + (r - l) / 3.0;
		point mmid = l + (r - l) / 3.0 * 2.0;
		double t1 = work(t, mid), t2 = work(t, mmid);
		if (t1 > t2)	l = mid;
		else r = mmid;
	}
	return work(t, l);
}
int main() {
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y, &p, &q, &r);
	point l = a, r = b;
	for (int i = 1; i <= 300; ++i) {
		point mid = l + (r - l) / 3.0;
		point mmid = l + (r - l) / 3.0 * 2.0;
		double t1 = gao(mid), t2 = gao(mmid);
		if (t1 > t2)	l = mid;
		else r = mmid;
	}
	printf("%.2lf\n", gao(l));
	return 0;
}
