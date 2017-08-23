#include <bits/stdc++.h>
using namespace std;
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
const double eps = 1e-12;
const int N = 100005;
typedef pair<double, double> pii;
vector<pii> a;
int n;
bool check(double x) {
	double last = 0.0;
	for (int i = 0; i < a.size(); ++i) {
		double l = max(last, a[i].F);
		double r = l + x;
		if (r < a[i].S || abs(r - a[i].S) < eps)	last = r;
		else return 0;
	}
	return 1;
}
int main() {
	freopen("caravan.in", "r", stdin);
	freopen("caravan.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		double x, y;
		scanf("%lf%lf", &x, &y);
		a.pb(mp(x, y));
	}
	sort(a.begin(), a.end());
	double l = 0.0, r = 1e6, now;
	for (int i = 1; i <= 400; ++i) {
		double mid = (l + r) * 0.5;
		if (check(mid))	l = now = mid;
		else r = mid;
	}
	long long x, y;
	for (int i = 1; i <= (int)1e6; ++i) {
		y = i;
		x = i * now;
		double t = (double)x / y;
		if (abs(t - now) < eps)	break;
		t = (double)(x + 1) / y;
		if (abs(t - now) < eps) {
			++x;
			break;
		}
		t = (double)(x - 1) / y;
		if (abs(t - now) < eps)	{--x;break;}
	}
	long long t = __gcd(x, y);
	printf("%I64d/%I64d", x / t, y / t);
	return 0;
}
