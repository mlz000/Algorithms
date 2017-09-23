#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int main() {
	int n, x;
	scanf("%d%d", &n, &x);
	if (n == 1) puts("YES"), printf("%d\n", x);
	else if (n == 2) {
		if (x == 0)	puts("NO");
		else {
			puts("YES");
			printf("%d %d\n", (1 << 18), (1 << 18) | x);
		}
	}
	else {
		int t = 0;
		puts("YES");
		for (int i = 1; i <= n - 3; ++i)	printf("%d ", i), t ^= i;
		printf("%d %d %d\n", 1 << 18, 1 << 19, ((1 << 18) | (1 << 19) | x) ^ t);
	}
	return 0;
}
