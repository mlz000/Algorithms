#include <bits/stdc++.h>
using namespace std;
const int N = 40;
int a[N][N];
int main() {
	int n;
	scanf("%d", &n);
	a[0][n / 2] = 1;
	int x = 0, y = n / 2;
	for (int i = 2; i <= n * n; ++i) {
		if (x == 0 && y != n - 1) {
			a[n - 1][y + 1] = i;
			x = n - 1, ++y;
		}
		else if (x != 0 && y == n - 1) {
			a[x - 1][0] = i;
			--x, y = 0;
		}
		else if (x == 0 && y == n - 1) {
			a[x + 1][y] = i;
			++x;
		}
		else {
			if (a[x - 1][y + 1] == 0)	a[x - 1][y + 1] = i, --x, ++y;
			else a[x + 1][y] = i, ++x;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)	printf("%d ", a[i][j]);
		puts("");
	}
	return 0;
}
