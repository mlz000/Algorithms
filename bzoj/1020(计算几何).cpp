#include <bits/stdc++.h>//µü´ú
using namespace std;
const int N = 35;
const double eps = 1e-16, inf = 1e12;
const double Pi = acos(-1.0);
int n, m, cnt[N];
double ans;
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
struct Point{
	double x;
	double y;
	Point(double p = 0, double q = 0) : x(p), y(q) {}
}p[N], q[N][N];
typedef Point Vector;
struct Seg {
	Point a, b;
	Seg() {}
	Seg(const Point &a, const Point &b) : a(a), b(b) {}
};
struct Node {
	Point p;
	double d;
	Node() {}
	Node (const Point &p, double d) : p(p), d(d) {}
};
Point operator - (Point p, Point q){
	return Point(p.x - q.x, p.y - q.y);
}
Point operator + (Point p, Point q){
	return Point(p.x + q.x, p.y + q.y);
}
Point operator * (Point p, double q){
	return Point(p.x * q, p.y * q);
}
double operator * (Point p, Point q){
	return p.x * q.x + p.y * q.y;
}
Point operator / (Point p, double q){
	return Point(p.x / q, p.y / q);
}
double operator % (Point p, Point q){
    return p.x * q.y - p.y * q.x;
}
Point rot(Point p, double rad){
	return Point(p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
}
int sgn(double x){
    if(fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}
bool operator < (const Point &p, const Point &q){
    return p.x < q.x || (p.x == q.x && p.y < q.y);
}
bool operator == (const Point p, const Point q){
	return (sgn(p.x - q.x) == 0 && sgn(p.y - q.y) == 0);
}
double len(Point x) {return sqrt(x * x);}
void init() {
	read(n), read(m);
	for (int i = 1; i <= m; ++i)	scanf("%lf%lf", &p[i].x, &p[i].y);
	for (int i = 1; i <= n; ++i) {
		read(cnt[i]);
		for (int j = 1; j <= cnt[i]; ++j)	scanf("%lf%lf", &q[i][j].x, &q[i][j].y);
	}
}
inline bool is_on(const Point &a,const Point &b,const Point &c) {
	return !sgn((b - a) % (c - a)) && sgn((a.x - b.x) * (a.x - c.x)) <= 0 && sgn((a.y - b.y) * (a.y - c.y)) <= 0;
}
inline bool is_cross(const Point &a, const Point &b, const Point &c, const Point &d) {
	return sgn(((c - a) % (b - a)) * ((d - a) % (b - a))) <= 0 && sgn(((a - c) % (d - c)) * ((b - c) % (d - c))) <= 0;
}
bool is_in(Point p, Point q[], int n) {
	int tot = 0;
	for (int i = 1; i <= n; ++i)
		if (is_on(p, q[i], q[i % n + 1]))	return 1;
	Point ray(-10001, p.y + 0.1), ta(p.x, p.y + 0.1);
	for (int i = 1; i <= n; ++i)
		if (is_cross(ray, ta, q[i], q[i % n + 1]))	++tot;
	return tot & 1;
}
bool check(Point p) {
	for (int i = 1; i <= n; ++i)
		if (is_in(p, q[i], cnt[i]))	return 1;
	return 0;
}
Point calc (const Point &a, const Vector &b, const Point &c, const Vector &d) {
	Vector u = a - c;
	double t = (d % u) / (b % d);
	return a + b * t;
}
Node work(const Point &a, const Point &b, const Point &c) {
	if (b == c)	return Node(b, len(b - a));
	Point v1 = c - b, v2 = a - b, v3 = a - c;
	if (sgn(v1 * v2) <= 0)	return Node(b, len(v2));
	if (sgn(v1 * v3) >= 0)	return Node(c, len(v3));
	Point t = calc(a, Point(-v1.y, v1.x), b, v1);
	return Node(t, len(a - t));
}
Node find(Point p) {
	if (check(p))	return Node(p, 0.0);
	Node t;
	t.d = inf;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= cnt[i]; ++j) {
			Node tt = work(p, q[i][j], q[i][j % cnt[i] + 1]);
			if (sgn(t.d - tt.d) >= 0)	t = tt;	
		}
	ans = max(ans, t.d);
	return t;
}
void gao() {
	queue<Seg> Q;
	for (int i = 1; i < m; ++i)	Q.push(Seg(p[i], p[i + 1])), find(p[i]);
	find(p[m]);
	while (Q.size()) {
		Seg t = Q.front(); 
		Q.pop();
		Point p1 = find(t.a).p, p2 = find(t.b).p, l = t.a, r = t.b, mid = (l + r) * 0.5;
		while (len(r - l) > 1e-4) {
			mid = (l + r) * 0.5;
			if (len(mid - p1) < len(mid - p2))	l = mid;
			else r = mid;
		}
		double tmp = max(len(l - p1), len(l - p2));
		find(l);
		if (ans + 1e-4 < tmp)	Q.push(Seg(t.a, mid)), Q.push(Seg(mid, t.b));
	}
}
int main() {
	init();
	gao();
	printf("%.2lf\n", ans);
	return 0;
}
