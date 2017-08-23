#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
inline void read(int &t) {
    int f = 1;char c;
    while (c = getchar(), c < '0' || c > '9') if (c == '-') f = -1;
    t = c - '0';
    while (c = getchar(), c >= '0' && c <= '9') t = t * 10 + c - '0';
    t *= f;
}
const int N = 10005;
double x[N], y[N], w[N];
inline double sqr(double x) {
    return x * x;
}
int main() {
    int n;
    scanf("%d", &n);
    double nx = 0, ny = 0;
    for (int i = 1; i <= n; ++i) scanf("%lf%lf%lf", &x[i], &y[i], &w[i]), nx += x[i], ny += y[i];
    nx /= n, ny /= n;
    for (double T = 1e4; T >= 1e-8; T *= 0.95) {
        double tx = 0, ty = 0;
        for (int i = 1; i <= n; ++i) {
            double l = sqrt(sqr(nx - x[i]) + sqr(ny - y[i]));
            tx += w[i] * (x[i] - nx) / l;
            ty += w[i] * (y[i] - ny) / l;
        }
        nx += tx * T;
        ny += ty * T;
    }
    printf("%.3lf %.3lf\n", nx, ny);
    return 0;
}
