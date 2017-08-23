#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct Point{
	double x;
	double y;
	Point(double p = 0, double q = 0) : x(p), y(q) {}
}p[N];
struct poly {
	double s;
	int id;
}a[N];
double Cross(Point p, Point q){
    return p.x * q.y - p.y * q.x;
}
Point operator - (Point p, Point q){
	return Point(p.x - q.x, p.y - q.y);
}
bool cmp(const poly &a, const poly &b) {
	return a.s < b.s;
}
int ans[N];
int main() {
	int n, m, T;
	scanf("%d", &T);
	while (T--) {
		memset(a, 0, sizeof(a));
		int t = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &m);
			for (int j = 0; j < m; ++j)	scanf("%lf%lf", &p[j].x, &p[j].y);
			a[i].s = 0;
			for (int j = 1; j < m - 1; ++j)
				a[i].s += Cross(p[j] - p[0], p[j + 1] - p[0]);
			a[i].id = i;
			a[i].s = fabs(a[i].s);	
		}
		sort(a + 1, a + n + 1, cmp);
		for (int i = 1; i <= n; ++i)
			ans[a[i].id] = i - 1;
		for (int i = 1; i <= n; ++i)	printf("%d ", ans[i]);
		puts("");
	}
	return 0;
}
