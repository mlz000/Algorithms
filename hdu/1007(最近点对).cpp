//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
const int N = 100005;
int n, a[N], idx[N];
pair<double, double> p[N];
inline double sqr(double x) {
	return x * x;
}
double inline dis(int a, int b) {
	return sqrt(sqr(p[a].F - p[b].F) + sqr(p[a].S - p[b].S));
}
bool cmpx(const int &a,const int &b) {
	return p[a].F < p[b].F;
}
bool cmpy(const int &a,const int &b) {
	return p[a].S < p[b].S;
}
double find(int l, int r) {
	if (l == r - 1)	return dis(idx[l], idx[r]);
	if (l == r - 2)	return min(dis(idx[l], idx[l + 1]), min(dis(idx[l], idx[l + 2]), dis(idx[l + 1], idx[l + 2])));
	int mid = l + r >> 1;
	double t = min(find(l, mid), find(mid + 1, r));
	int cnt = 0;
	for (int i = l; i <= r; ++i) {
		if (abs(p[idx[i]].F - p[idx[mid]].F) <= t)	a[++cnt] = idx[i];
	}
	sort(a + 1, a + cnt + 1, cmpy);
	for (int i = 1; i <= cnt; ++i)
		for (int j = i + 1; j <= cnt; ++j) {
			if (p[a[j]].S - p[a[i]].S >= t)	break;
			t = min(t, dis(a[i], a[j]));
		}
	return t;
}
int main() {
	while (scanf("%d", &n) && n) {
		for (int i = 1; i <= n; ++i) {
			double x, y;
			scanf("%lf%lf", &x, &y);
			p[i] = mp(x, y);
			idx[i] = i;
		}
		sort(idx + 1, idx + n + 1, cmpx);
		double ans = find(1, n);
		printf("%.2lf\n", ans * 0.5);
	}
	return 0;
}
