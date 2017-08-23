#include <cstdio>
#include <cmath>
#define rep(n) for (int i = 0; i < n; i++)
int t, x, a, b, c;
void change(int dx) {
	x += dx;
	if (fabs(dx) == 1) a--;
	else if (fabs(dx) == 2) b--;
	else c--;
	printf(" %d", x);
}
int main() {
	freopen("jumping.in", "r", stdin);
	freopen("jumping.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &a, &b, &c);
		x = 0;
		printf("%d", x);
		if (c%3 == 0) {
			int k = c/3;
			rep(k) change(3);
			change(1);
			rep(k) change(-3);
			change(1);
			rep(k) change(3);
		} else if (c%3 == 1) {
			int k = c/3;
			rep(k+1) change(3);
			change(-2);
			rep(k) change(-3);
			change(1);
			rep(k) change(3);
			change(2);
		} else {
			int k = c/3+1;
			rep(k) change(3);
			change(-1);
			rep(k-1) change(-3);
			change(-1);
			rep(k) change(3);
		}
		while (a > 1) change(1);
		int t = b;
		rep((t+1)/2) change(2);
		change((t%2 == 0)? 1: -1);
		rep(t/2) change(-2);
		puts("");
	}
	return 0;
}
