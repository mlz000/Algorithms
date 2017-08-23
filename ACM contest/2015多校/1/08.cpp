#include <bits/stdc++.h>//计算几何
using namespace std;
double ab, bc, cd, da, ef;
const double eps = 1e-8;
int sgn(double x){
    if(fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}
struct Point{
	double x;
	double y;
	Point(double p = 0, double q = 0) : x(p), y(q) {}
	Point operator - (const Point &a) {
		return Point(x - a.x, y - a.y);
	}
	Point operator + (const Point &a){
		return Point(x + a.x, y + a.y);
	}
	Point operator * (const double &a){
		return Point(x * a, y * a);
	}
	Point operator / (const double &a){
		return Point(x / a, y / a);
	}
	Point rot(const double &rad){
		return Point(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad));
	}
	bool operator == (const Point &a) {
		return (sgn(x - a.x) == 0 && sgn(y - a.y) == 0);
	}
	void out() {
		printf("%.6lf %.6lf\n", x, y);
	}
};
struct Circle {
	Point o;
	double r;
	Circle() {}
	Circle(Point o, double r) : o(o), r(r) {}
	bool operator == (const Circle &a) {  
		return o == a.o && fabs(r - a.r) < eps;  
	}  
};
Point A, B, C, D;
typedef Point Vector;
double dot(Point p, Point q){
	return p.x * q.x + p.y * q.y;
}
double Cross(Point p, Point q){
    return p.x * q.y - p.y * q.x;
}
double len(Point x) {
	return sqrt(dot(x, x));
}
void circle_cross(Circle p, Circle q, Point &u, Point &v) {//两圆交点  
    if (p == q) {  
        u = p.o + Point(0, p.r);  
        v = p.o - Point(0, p.r);  
        return;  
    }  
    double a = q.o.x - p.o.x, b = q.o.y - p.o.y;  
    double c = (p.r * p.r - q.r * q.r + a * a + b * b) / 2;  
    if (fabs(a) > eps && fabs(b) > eps) {  
        double delta = b * b * c * c - (a * a + b * b) * (c * c - p.r * p.r * a * a);  
        if (sgn(delta) <= 0)  delta = 0;  
        u.y = (b * c + sqrt(delta)) / (a * a + b * b);  
        v.y = (b * c - sqrt(delta)) / (a * a + b * b);  
        u.x = (c - b * u.y) / a;  
        v.x = (c - b * u.y) / a;  
    } 
	else if (fabs(a) > eps && fabs(b) < eps) {  
		u.x = v.x = c / a;  
		double tmp = p.r * p.r - u.x * u.x;  
		if (sgn(tmp) <= 0)  
			tmp = 0;  
		u.y = sqrt(tmp);  
		v.y = -u.y;  
	} 
	else if (fabs(a) < eps && fabs(b) > eps) {  
		u.y = v.y = c / b;  
		double tmp = p.r * p.r - u.y * u.y;  
		if (sgn(tmp) <= 0)  
			tmp = 0;  
		u.x = sqrt(tmp);  
		v.x = -u.x;  
	}  
	u = u + p.o;  
	v = v + p.o;  
}  
void gao() {
	Point A, B, C, D, G, a1, tmp;
	C = Point(0.0, 0.0), B = Point(bc, 0.0);
	circle_cross(Circle(C, da), Circle(B, ef * 2), a1, tmp);//a'
	G = a1 + B - C;
	circle_cross(Circle(C, cd), Circle(G, ab), D, tmp);//d
	A = D + B - G;
	A.out(), B.out(), C.out(), D.out();
}
int main() {
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; ++tt) {
		printf("Case #%d:\n", tt);
		scanf("%lf%lf%lf%lf%lf", &ab, &bc, &cd, &da, &ef);
		gao();
	}
	return 0;
}
