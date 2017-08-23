#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
double y;
inline double f(double x) {
	return 6.0*x*x*x*x*x*x*x + 8 * x*x*x*x*x*x + 7 * x*x*x + 5 * x*x - y * x;
}
inline double ff(double x) {
	return 42.0 * x*x*x*x*x*x + 48.0 * x*x*x*x*x + 21.0 * x*x + 10.0 * x - y;
}
inline double fff(double x) {
	return 252.0 * x*x*x*x*x + 240.0 * x*x*x*x + 42.0 * x + 10.0;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%lf", &y);
		double x = 100.0;
		for (int i = 1; i <= 100; ++i) {
			x -= ff(x) / fff(x);
		}
		printf("%.4lf\n", f(x));
	}
	return 0;
}
