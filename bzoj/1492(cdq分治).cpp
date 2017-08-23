#include <bits/stdc++.h>//cdq∑÷÷Œ
using namespace std;
const int N = 100005;
struct point {
	double x, y;
}f[N], t[N];
int n, m, p[N], s[N];
double x[N], y[N], v[N], ra[N];
bool operator < (point a, point b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }
bool cmp(const int &p, const int &q) {
	return x[p] * y[q] < x[q] * y[p];
}
double det(point a, point b, point c) {
	return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
}
double calc(point p, int i) {
	return p.x * x[i] + p.y * y[i];
}	
void cdq(int l, int r, double ss) {
	if (l == r) {
		v[l] = max(v[l], ss);
		f[l].y = v[l] / (x[l] * ra[l] + y[l]);
		f[l].x = f[l].y * ra[l];
		return;
	}
	int mid = l + r >> 1, m1 = l, m2 = mid + 1, bk = 0, ft = 0;
	for (int i = l; i <= r; ++i) {
		if (p[i] <= mid)	s[m1++] = p[i];
		else	s[m2++] = p[i];
	}
	memcpy(p + l, s + l, sizeof(int) * (r - l + 1));
	cdq(l, mid, ss);
	for (int i = l; i <= mid; ++i) {
		while (bk > 1 && det(t[bk - 2], t[bk - 1], f[i]) >= 0)	--bk;
		t[bk++] = f[i];
	}
	for (int i = mid + 1; i <= r; ++i) {
		while (ft < bk - 1 && calc(t[ft], p[i]) < calc(t[ft + 1], p[i]))	++ft;
		v[p[i]] = max(v[p[i]], calc(t[ft], p[i]));
	}
	cdq(mid + 1, r, v[mid]);
	merge(f + l, f + mid + 1, f + mid + 1, f + r + 1, t);
	memcpy(f + l, t, sizeof(point) * (r - l + 1));
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)	{
		scanf("%lf%lf%lf", &x[i], &y[i], &ra[i]);
		p[i] = i;
	}
	sort(p, p + n, cmp);
	cdq(0, n - 1, m);
	printf("%.3lf\n", v[n - 1]);
	return 0;
}
