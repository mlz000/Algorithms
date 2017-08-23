Point gao(Point a, Point b, Point c) {
	Line u, v;
	u.a.x = (a.x + b.x) * 0.5;
	u.a.y = (a.y + b.y) * 0.5;
	u.b.x = u.a.x - (u.a.y - a.y);
	u.b.y = u.a.y + (u.a.x - a.x);
	v.a.x = (a.x + c.x) * 0.5;
	v.a.y = (a.y + c.y) * 0.5;
	v.b.x = v.a.x - (v.a.y - a.y);
	v.b.y = v.a.y + (v.a.x - a.x);
	return inter(u.a, u.b - u.a, v.a, v.b - v.a);
}
int main() {
	int n;
	while (scanf("%d", &n) && n) {
		for (int i = 1; i <= n; ++i)	scanf("%lf%lf", &p[i].x, &p[i].y);
		random_shuffle(p + 1, p + n + 1);
		o = p[1];
		for (int i = 1; i <= n; ++i) {
			if (sgn(dis(o, p[i]) - r) <= 0)	continue;
			o.x = (p[i].x + p[1].x) * 0.5, o.y = (p[i].y + p[1].y) * 0.5, r = dis(p[i], p[1]) * 0.5;
			for (int j = 2; j < i; ++j) {
				if (sgn(dis(o, p[j]) - r) <= 0)	continue;
				o.x = (p[i].x + p[j].x) * 0.5, o.y = (p[i].y + p[j].y) * 0.5, r = dis(p[i], p[j]) * 0.5;
				for (int k = 1; k < j; ++k) {
					if (sgn(dis(o, p[k]) - r) <= 0)	continue;
					o = gao(p[i], p[j], p[k]);
					r = dis(o, p[i]);
				}
			}
		}
		printf("%.2lf %.2lf %.2lf\n", o.x, o.y, r);
	}
	return 0;
}
