#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ls (rt << 1)
#define rs (rt << 1 | 1)
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
const int N = 1005;
double f[N], g[N];
int main() {
	int T, n;
	read(T);
	while (T--) {
		read(n);
		n = min(n, 1000);
		double p, q;
		scanf("%lf%lf", &p, &q);
		f[0] = 0, g[0] = 1;
		for (int i = 1; i <= n; ++i) {
			if (f[i - 1] > g[i - 1])	p = 1 - p, q = 1 - q;
			f[i] = (p * g[i - 1] + (1 - p) * q * f[i - 1]) / (1 - (1 - p) * (1 - q));
			g[i] = (q * f[i - 1] + (1 - q) * p * g[i - 1]) / (1 - (1 - p) * (1 - q));
			if (f[i - 1] > g[i - 1])	p = 1 - p, q = 1 - q;
		}
		printf("%.8lf\n", f[n]);
	}
	return 0;
}
