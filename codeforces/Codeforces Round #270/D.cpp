#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int n, d[N][N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)	
		for (int j = 1; j <= n; ++j)
			scanf("%d", &d[i][j]);
	bool f = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			if (d[i][j] != d[j][i])	f = 0;
			if (i == j && d[i][j] != 0)	f = 0;
			if (i != j && d[i][j] == 0)	f = 0;
		}
	for (int i = 1; i <= n; ++i) {
		int pos, Min = (int)1e9+5;
		for (int j = 1; j <= n; ++j) {
			if (i == j)	continue;
			if (d[i][j] < Min)	Min = d[i][j], pos = j;
		}
		for (int j = 1; j <= n; ++j) {
			if (j == i || j == pos)	continue;
			if (abs(d[i][j] - d[pos][j]) != Min) {
				f = 0;
				break;
			}
		}
	}
	printf("%s", f ? "YES" : "NO");
	return 0;
}
