#include <bits/stdc++.h>
using namespace std;
int gao(int a, int b, int c) {
	int x = 0, y = 0, step = 0;	
	while (x != c && y != c) {
		if (x == 0) {
			x = a;
			++step;
		}
		else if (y == b) {
			y = 0;
			++step;
		}
		else {
			int sum = x + y;
			y = sum < b ? sum : b;
			x = sum - y;
			++step;
		}
	}
	return step;
}
int main() {
	int T, a, b, c;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &a, &b, &c);
		if (c > max(a, b) || c % __gcd(a, b))	puts("-1");
		else {
			printf("%d\n", min(gao(a, b, c), gao(b, a, c)));
		}
	}
	return 0;
}
